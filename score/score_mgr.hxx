#ifndef SCORE_MGR_HXX
#define SCORE_MGR_HXX

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

#include "score_mgr.h"

using namespace std;

template <typename T>
void nsScore::WriteScore (T & MeilleursScores, const string NomFichier)
{

    ofstream FichierScore ;
    FichierScore.open(NomFichier, ofstream::out);
    for (unsigned i = 0 ; i < MeilleursScores.size() ; ++i)
    {
        FichierScore << MeilleursScores[i] << endl ;
    }
}//Pour enregistré les scores dans le txt

template<typename T>
bool nsScore::InclureScore (TableauScore & MeilleursScores, const T & ScoreCourant, TableauNom & MeilleursNom , const string & NomJoueur)
{
    bool Present (false);
    unsigned Indice = 0 ;
    for (unsigned i = 0 ; i < MeilleursScores.size(); ++i)
    {
        if (ScoreCourant >= MeilleursScores[i])
        {
            stringstream Str;
            Present = true ;
            Indice = i ;
            break ;
        }
    }
    if (Present == false)
        return false;

    MeilleursScores[MeilleursScores.size()-1] = ScoreCourant ;
    MeilleursNom[MeilleursNom.size()-1] = NomJoueur ;

    if( Indice + 1 >= MeilleursScores.size())
    {
        return true;
    }

    for (unsigned i = Indice ; i < MeilleursScores.size(); ++i)
    {
        swap(MeilleursScores[i], MeilleursScores[MeilleursScores.size()-1]);
        swap(MeilleursNom[i], MeilleursNom[MeilleursNom.size()-1]);
    }
    return true;
} //si le score du joueur se doit d'etre present dans le tableau des meilleurs score cette fonction l'ajoute au bonne endroit

template<typename T>
bool nsScore::EnregistrerScoreFinPartie (const std::string &NomJoueur, const T & ScoreJoueur)
{
    ExistFichier();
    bool Inclut ;

    TableauScore MeilleursScores (0);
    TableauNom TableauJoueur (0);
    ReadScore(MeilleursScores);
    ReadNom(TableauJoueur);
    Inclut = InclureScore(MeilleursScores, ScoreJoueur,TableauJoueur, NomJoueur);
    TriDesScores(MeilleursScores, TableauJoueur);
    if (Inclut)
    {
        WriteScore(MeilleursScores, NomFichierScore);
        WriteScore(TableauJoueur, NomFichierJoueur);
    }

    return Inclut;
}
#endif // SCORE_MGR_HXX
