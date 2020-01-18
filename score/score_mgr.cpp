/**
  *
  * @author Laugier Colin
  *
  * @date 09/01/20
  *
  * @brief Les fonctions de scores
  *
  * */

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

#include"score_mgr.h"
#include"score_mgr.hxx"

#include "gui/text.h"
#include "gui/star_background.h"

#include "graph/rgbacolor.h"
#include "graph/vec2d.h"


using namespace std;
typedef vector<unsigned> TableauScore ;
typedef vector<string> TableauNom ;

TableauScore ReadScore (TableauScore & MeilleursScores)
{
    ifstream FichierScore ;
    FichierScore.open(NomFichierScore, ifstream::in);
    string ValeursCourante ;
    unsigned  i = 0 ;
    while (true)
    {
        getline(FichierScore, ValeursCourante);
        if (FichierScore.eof()) break ;
        MeilleursScores.push_back(stoul(ValeursCourante)) ;
        ++i ;
    }
    return MeilleursScores ;
}//Fonction pour lire les scores du TXT

TableauNom ReadNom (TableauNom & MeilleursNom)
{
    ifstream FichierNom ;
    FichierNom.open(NomFichierJoueur, ifstream::in);
    string ValeursCourante ;
    unsigned  i = 0 ;
    while (true)
    {
        getline(FichierNom, ValeursCourante);
        if (FichierNom.eof()) break ;
        MeilleursNom.push_back(ValeursCourante) ;
        ++i ;
    }
    return MeilleursNom ;
}//Fonction pour lire les scores du TXT

TableauScore InitScore (TableauScore & MeilleursScores)
{
    for (unsigned i = 0 ; i < MeilleursScores.size() ; ++i)
    {
        MeilleursScores[i] = 0 ;
    }
    return MeilleursScores ;
}//fonction pour initialisé tout les scores a  dans le cas ou le fichier est perdu

TableauNom InitJoueur (TableauNom & MeilleursNom)
{
    for (unsigned i = 0 ; i < MeilleursNom.size() ; ++i)
    {
        MeilleursNom[i] = "Personne" ;
    }
    return MeilleursNom ;
}//fonction pour initialisé tout les scores a  dans le cas ou le fichier est perdu

void AfficheScore (const TableauScore & MeilleursScores, const TableauNom & TableauJoueur, MinGL &window )
{
    for (unsigned  i = 0 ; i < MeilleursScores.size(); ++i)
    {
        stringstream Str;
        Str <<setw(5) << i+1 << ". " << setw(5) << MeilleursScores[i] << setw(25) << TableauJoueur[i] ;
        window << nsGui::Text(Vec2D(window.getWindowSize().x/4, 20*i+150), Str.str(), KBlue, GlutFont::BITMAP_HELVETICA_12);

    }
}// Affiche les scores

TableauScore TriDesScores (TableauScore & MeilleursScores, TableauNom & TableauJoueur)
{
    vector<int> TabUn ;
    vector<string> TabDeux ;
    for (unsigned i = 0 ; i < MeilleursScores.size(); ++i)
    {
        int OUI = MeilleursScores[i] ;
        TabUn.push_back(OUI);
        TabDeux.push_back(TableauJoueur[i]);
    }
    for (unsigned i = 0 ; i < TabUn.size(); ++i)
    {
        for (unsigned j = 1 ; j < TabUn.size(); ++j)
        {
            if (TabUn[j] >= TabUn[j-1])
            {
                swap(TabUn[j], TabUn[j-1]);
                swap(TabDeux[j], TabDeux[j-1]);
            }
        }
    }
    for (unsigned i = 0 ; i < MeilleursScores.size(); ++i)
    {
        MeilleursScores[i] = TabUn[i];
        TableauJoueur[i] = TabDeux[i];
    }
    return MeilleursScores ;
} // Met dans l'ordre les scores

void ExistFichier ()
{
    fstream FichierScore;
    FichierScore.open(NomFichierScore, ifstream::in);
    if (!FichierScore.is_open())
    {
        TableauScore MeilleursScores (TailleTableauScore) ;
        MeilleursScores = InitScore(MeilleursScores);
        WhriteScore(MeilleursScores, NomFichierScore);
        cerr << "Le fichier \"" << NomFichierScore <<  "\" n'a pas ete trouve sur l'ordinateur, un nouveau vierge a ete cree" << endl ;
    }
    fstream FichierJoueur;
    FichierScore.open(NomFichierJoueur, ifstream::in);
    if (!FichierScore.is_open())
    {
        TableauNom MeilleursNom (TailleTableauScore) ;
        MeilleursNom = InitJoueur(MeilleursNom);
        WhriteScore(MeilleursNom, NomFichierJoueur);
        cerr << "Le fichier \"" << NomFichierJoueur <<  "\" n'a pas ete trouve sur l'ordinateur, un nouveau vierge a ete cree" << endl ;
    }
}// si le fichier n'esxiste pas on le creer en prevenant l'user

void DebutDeJeu (MinGL &window)
{
    TableauScore MeilleursScores (0) ;
    TableauNom TableauJoueur (0);
    ExistFichier();
    MeilleursScores = ReadScore(MeilleursScores);
    TableauJoueur = ReadNom(TableauJoueur);
    AfficheScore(MeilleursScores, TableauJoueur, window);
}


