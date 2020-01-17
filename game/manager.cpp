/*!
  * \file SpaceInvader_AC.cpp
  * \author Alain Casali Marc Laporte
  * \date 7 janvier 2016
  * \brief Projet de C++ simulant un SpaceInvader
  * \version 1.0
  * \bug Aucun connu
  */

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <fstream>
#include <cstdlib> //rand ()
#include <ctime> //time ()
#include <termios.h> //termios
#include <cstdio> // getchar
#include "manager_type.h"
#include "manager.h"
#include "manager_const.h"
using namespace std;
using namespace nsGame;

namespace nsGame
{

    void PutCVPosition (const CVPosition & VPos, char Car, CVString & Space)
    {
        for (const CPosition & Pos : VPos)
            Space[Pos.first][Pos.second] = Car;
    } // PutCVPosition()

    void PutAllObjects (const CAObject & Obj, CVString & Space)
    {
        for (string & Line : Space)
            Line = KEmptyLine;

        PutCVPosition (Obj[0], KInsideInvader, Space);
        PutCVPosition (Obj[1], KMissile, Space);
        PutCVPosition (Obj[2], KInsideMe, Space);
        PutCVPosition (Obj[3], KTorpedo, Space);
    } // PutAllObjects()

    void InitSpace (CVString & Space, CAObject & Obj)
    {
        // L'espace de jeu
        Space.resize(KSizeLine);
        for (string & Line : Space)
            Line = KEmptyLine;

        // Les envahisseurs
        Obj[0].resize(KInvadersSize * KInvadersLines);
        for (unsigned i (0); i < Obj[0].size(); ++i)
            Obj[0][i] = make_pair (i % KInvadersLines, KBegInvader + i % KInvadersSize);

        // Le joueur
        AddPlayer(Space, Obj);
    } // InitSpace()

    void AddPlayer(CVString &Space, CAObject &Obj)
    {
        Obj[2].resize(KMySize);
        for (unsigned i(0); i < Obj[2].size(); ++i)
            Obj[2][i] = make_pair (Space.size() - 1, KBegMe + i);
    } // AddPlayer()

    void MaxX (const CVPosition & VPos, CPosition & MaxPos)
    {
        MaxPos = VPos [0];
        for (unsigned i (1); i < VPos.size(); ++i)
            if (MaxPos.second < VPos[i].second)
                MaxPos = VPos[i];
    } // MaxX()

    void MaxY (const CVPosition & VPos, CPosition & MaxPos)
    {
        MaxPos = VPos [0];
        for (unsigned i (1); i < VPos.size(); ++i)
            if (MaxPos.first < VPos[i].first)
                MaxPos = VPos[i];
    } // MaxY()


    void MinX (const CVPosition & VPos, CPosition & MinPos)
    {
        MinPos = VPos [0];
        for (unsigned i (1); i < VPos.size(); ++i)
            if (MinPos.second > VPos[i].second)
                MinPos = VPos[i];
    } // MinX()

    bool MoveLeft (CVPosition & VPos)
    {
        CPosition MinPos;
        MinX (VPos, MinPos);
        if (0 == MinPos.second) return false;

        for (CPosition & Pos : VPos)
            --Pos.second;
        return true;
    } // MoveLeft()

    bool MoveRight (const CVString & Space, CVPosition & VPos)
    {
        CPosition MaxPos;
        MaxX (VPos, MaxPos);
        if (Space[MaxPos.first].size() - 1 == MaxPos.second) return false;

        for (CPosition & Pos : VPos)
            ++Pos.second;

        return true;
    } // MoveRight()

    void MoveDown (CVPosition & VPos)
    {
        for (CPosition & Pos : VPos)
            ++ Pos.first;
    } // MoveDown()

    void MoveUp (CVPosition & VPos)
    {
        for (CPosition & Pos : VPos)
            -- Pos.first;
    } //MoveUp()

    void ManageMe (const CVString & Space, CAObject &Obj)
    {
        char Move;
        //fonction en C qui permet de lire un caractère. cin ne fonctionnant pas dans cette configuration
        //cin >> Move;
        read (STDIN_FILENO, &Move, 1);
        switch (Move)
        {
        case KLeft:
            MoveLeft (Obj[2]);
            break;
        case KRight :
            MoveRight (Space, Obj[2]);
            break;
        case KShoot:
            Obj[3].push_back(Obj[2][rand () % Obj[2].size ()]);
            break;
        }
    } // ManageMe()

    unsigned CollisionBetweenObjectsAndShips (CVPosition & Objects, CVPosition & StarShips)
    {
        unsigned colisionCounter = 0;
        for (unsigned i (0); i < Objects.size (); ++i)
        {
            // Collision entre les missiles et moi
            for (unsigned j (0); j < StarShips.size (); )
            {
                if (Objects[i] == StarShips[j])
                {
                    colisionCounter += StarShips[j].first;

                    StarShips.erase (StarShips.begin () + j);
                    Objects.erase (Objects.begin () + i);
                }
                else ++j;
            }
        }

        return colisionCounter;
    } //CollisionBetweenMissilesAndI()

    void CollisionBetweenMissilesAndTorpedos (CVPosition & Missiles, CVPosition & Torpedos)
    {
        //la boucle est un peu bizare, mais elle permet de gérer
        //deux colisions en même temps entre deux missiles et torpilles
        //sur deux case differentes
        //tout ça à cause du .erase () qui supprime la case courante
        //=> on ne doit pas incrementer l'indice de boucle dans ce cas

        for (unsigned i (0); i < Missiles.size (); )
        {
            //collision entre les missiles et les torpilles
            unsigned j (0);
            for (; j < Torpedos.size (); ++j)
            {
                if (Missiles[i] != Torpedos[j]) continue;

                Torpedos.erase (Torpedos.begin () +j);
                Missiles.erase (Missiles.begin () +i);
                break;
            }

            if (j == Torpedos.size ()) ++i;
        }
    } //CollisionBetweenMissilesAndTorpedos()

    void ManageCollisions (CAObject & Obj, unsigned &Score)
    {
        CollisionBetweenMissilesAndTorpedos         (Obj[1], Obj[3]);
        CollisionBetweenObjectsAndShips             (Obj[1], Obj[2]);
        Score = CollisionBetweenObjectsAndShips     (Obj[3], Obj[0]);
    } // ManageCollisions()

    unsigned Victory (const CVString & Space, const CAObject & Obj)
    {
        if (0 == Obj[0].size ()) return 1;
        else if (0 == Obj[2].size()) return 2;
        else if (Obj[0][Obj[0].size() - 1].first == Obj[2][0].first) return 3;

        return 0;
    } // Victory()

    void DeleteMissiles (const CVString & Space, CVPosition & Missiles)
    {
        for (unsigned i (0); i < Missiles.size(); )
        {
            if (Missiles[i].first == Space.size())
                Missiles.erase(Missiles.begin()+i);
            else ++i;
        }
    } // DeleteMissiles()

    void DeleteTorpedos (CVPosition & Torpedos)
    {
        for (unsigned i (0); i < Torpedos.size(); )
        {
            if (unsigned (-1) == Torpedos[i].first)
                Torpedos.erase(Torpedos.begin()+i);
            else  ++i;
        }
    } // DeleteTorpedos()

}

