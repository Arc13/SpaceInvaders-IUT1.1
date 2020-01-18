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

#include "score_mgr.h"
#include "score_mgr.hxx"

#include "../gui/text.h"
#include "../gui/star_background.h"

#include "graph/rgbacolor.h"
#include "graph/vec2d.h"

using namespace std;
typedef vector<unsigned> TableauScore ;
typedef vector<string> TableauNom ;

void nsScore::ReadScore (TableauScore & MeilleursScores)
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
}//Fonction pour lire les scores du TXT

void nsScore::ReadNom (TableauNom & MeilleursNom)
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
}//Fonction pour lire les scores du TXT

void nsScore::InitScore (TableauScore & MeilleursScores)
{
    for (unsigned i = 0 ; i < MeilleursScores.size() ; ++i)
    {
        MeilleursScores[i] = 0 ;
    }
}//fonction pour initialisé tout les scores a  dans le cas ou le fichier est perdu

void nsScore::InitJoueur (TableauNom & MeilleursNom)
{
    for (unsigned i = 0 ; i < MeilleursNom.size() ; ++i)
    {
        MeilleursNom[i] = "Personne" ;
    }
}//fonction pour initialisé tout les scores a  dans le cas ou le fichier est perdu

void nsScore::AfficheTopScores (MinGL &window, const TableauScore & MeilleursScores, const TableauNom & MeilleursNom)
{
    window << nsGui::Text(Vec2D(window.getWindowSize().x / 2, 130), "Top scores",
                          RGBAcolor(128, 128, 128), GlutFont::BITMAP_HELVETICA_18, nsGui::Text::ALIGNH_CENTER);

    for (unsigned  i = 0 ; i < MeilleursScores.size(); ++i)
    {
        stringstream Str;
        Str << setw(5) << i + 1 << ". " << setw(5) << MeilleursScores[i] << setw(25) << MeilleursNom[i];
        window << nsGui::Text(Vec2D(window.getWindowSize().x / 2, 20 * i + 200), Str.str(),
                              KBlue, GlutFont::BITMAP_HELVETICA_12, nsGui::Text::ALIGNH_CENTER);

    }
}// Affiche les scores

void nsScore::TriDesScores (TableauScore & MeilleursScores, TableauNom & TableauJoueur)
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
} // Met dans l'ordre les scores

void nsScore::ExistFichier ()
{
    fstream FichierScore;
    FichierScore.open(NomFichierScore, ifstream::in);
    if (!FichierScore.is_open())
    {
        TableauScore MeilleursScores (TailleTableauScore) ;
        InitScore(MeilleursScores);
        WriteScore(MeilleursScores, NomFichierScore);
        cerr << "Le fichier \"" << NomFichierScore <<  "\" n'a pas ete trouve sur l'ordinateur, un nouveau vierge a ete cree" << endl ;
    }
    fstream FichierJoueur;
    FichierScore.open(NomFichierJoueur, ifstream::in);
    if (!FichierScore.is_open())
    {
        TableauNom MeilleursNom (TailleTableauScore) ;
        InitJoueur(MeilleursNom);
        WriteScore(MeilleursNom, NomFichierJoueur);
        cerr << "Le fichier \"" << NomFichierJoueur <<  "\" n'a pas ete trouve sur l'ordinateur, un nouveau vierge a ete cree" << endl ;
    }
}// si le fichier n'esxiste pas on le creer en prevenant l'user

void nsScore::ChargerEtAfficherTopScores (MinGL &window)
{
    TableauScore MeilleursScores (0) ;
    TableauNom TableauJoueur (0);
    ExistFichier();
    ReadScore(MeilleursScores);
    ReadNom(TableauJoueur);
    AfficheTopScores(window, MeilleursScores, TableauJoueur);
}


