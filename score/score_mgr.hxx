#ifndef SCORE_MGR_HXX
#define SCORE_MGR_HXX

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

#include"score_mgr.h"

using namespace std;

template <typename T>
void WhriteScore (T & MeilleursScores, const string NomFichier)
{

    ofstream FichierScore ;
    FichierScore.open(NomFichier, ofstream::out);
    for (unsigned i = 0 ; i < MeilleursScores.size() ; ++i)
    {
        FichierScore << MeilleursScores[i] << endl ;
    }
}//Pour enregistré les scores dans le txt

template<typename T>
bool InclureScore (TableauScore & MeilleursScores, const T & ScoreCourant,TableauNom & TableauJoueur , const string & NomJoueur, MinGL &window)
{
    bool Present (false);
    unsigned Indice = 0 ;
    for (unsigned i = 0 ; i < MeilleursScores.size(); ++i)
    {
        if (ScoreCourant >= MeilleursScores[i])
        {
            stringstream Str;
            Str << "Bravo " << NomJoueur << " ton score est " << ScoreCourant << endl;
            window << nsGui::Text(Vec2D(window.getWindowSize().x/4, 20+150), Str.str(), KRed, GlutFont::BITMAP_HELVETICA_12);
            Present = true ;
            Indice = i ;
            break ;
        }
    }
    if (Present == false)
    {
        stringstream Str;
        Str << "Bravo " << NomJoueur << " ton score est " << ScoreCourant << endl
            << "Mais il ne fait partie des 10 meilleurs il n'est donc pas enregistrer" ;
        window << nsGui::Text(Vec2D(window.getWindowSize().x/4, 20+150), Str.str(), KRed, GlutFont::BITMAP_HELVETICA_12);

        return false ;
    }

    MeilleursScores[MeilleursScores.size()-1] = ScoreCourant ;
    TableauJoueur[TableauJoueur.size()-1] = NomJoueur ;

    if( Indice + 1 >= MeilleursScores.size())
    {
        return true;
    }

    for (unsigned i = Indice ; i < MeilleursScores.size(); ++i)
    {
        swap(MeilleursScores[i], MeilleursScores[MeilleursScores.size()-1]);
        swap(TableauJoueur[i], TableauJoueur[TableauJoueur.size()-1]);
    }
    return true;
} //si le score du joueur se doit d'etre present dans le tableau des meilleurs score cette fonction l'ajoute au bonne endroit

template<typename T>
void FinDePartieScore (const T & ScoreJoueur, MinGL &window, const std::string &NomJoueur)
{
    ExistFichier();
    bool Inclut ;

    TableauScore MeilleursScores (0);
    TableauNom TableauJoueur (0);
    MeilleursScores = ReadScore(MeilleursScores);
    TableauJoueur = ReadNom(TableauJoueur);
    Inclut = InclureScore(MeilleursScores, ScoreJoueur,TableauJoueur, NomJoueur, window);
    MeilleursScores = TriDesScores(MeilleursScores, TableauJoueur);
    if (Inclut)
    {
        WhriteScore(MeilleursScores, NomFichierScore);
        WhriteScore(TableauJoueur, NomFichierJoueur);
    }
    AfficheScore(MeilleursScores, TableauJoueur, window);
}
#endif // SCORE_MGR_HXX
