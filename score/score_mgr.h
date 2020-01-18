#ifndef SCORE_MGR_H
#define SCORE_MGR_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>

#include "gui/text.h"
#include "gui/star_background.h"

#include "graph/rgbacolor.h"
#include "graph/vec2d.h"

/**
 * @namespace nsScore
 * @brief Espace de nom pour le gestionnaire de scores
 */
namespace nsScore {

/**
 * @brief TableauScore is a vector of sting for content score's player
 * @fn typedef vector<unsigned> TableauScore ;
 */
typedef std::vector<unsigned> TableauScore ;
/**
 * @brief TableauNom is a vector of sting for content player's name
 * @fn typedef vector<string> TableauNom ;
 */
typedef std::vector<std::string> TableauNom ;

/**
 * @brief "NomFichierScore" is the file where we stock  the score
 * @fn const string NomFichierScore ("Score.txt");
 */
const std::string NomFichierScore ("Score.txt");
/**
 * @brief "NomFichierJoueur" is the file where we stock  the player's name
 * @fn const string NomFichierJoueur ("Joueur.txt");
 */
const std::string NomFichierJoueur ("Joueur.txt");
/**
 * @brief "TailleTableau" is the size of the "TableauScore" and "TableauNom"
 * @fn const unsigned TailleTableauScore (10);
 */
const unsigned TailleTableauScore (10);

/**
 * @brief Read the score in the "NomFichierScore" file for whrite un "MeilleursScores"
 * @param[in/out] MeilleursScores : It's a TableauScore wich content the 10 best scores
 * @param[out] TableauNom :  Return MeilleursScores
 * @fn TableauScore ReadScore (TableauScore & MeilleursScores);
 */
TableauScore ReadScore (TableauScore & MeilleursScores);

/**
 * @brief Read the score in the "NomFichierScore" file for whrite un "MeilleursScores"
 * @param[in/out] MeilleursScores : It's a TableauScore wich content the 10 best scores
 * @param[out] TableauNom :  Return MeilleursScores
 * @fn TableauScore ReadScore (TableauScore & MeilleursScores);
 */
TableauNom ReadNom (TableauNom & MeilleursNom);

/**
 * @brief Whrite the scores on the "NomFichier" file
 * @param[in] MeilleursScores : It's a TableauScore wich content the 10 best scores
 * @param[in/out] NomFichier : This is the name of the file in which we save the score
 * @fn template <typename T> void WhriteScore (T & MeilleursScores, const string NomFichier);
 */
template <typename T>
void WriteScore (T & MeilleursScores, const std::string NomFichier);

/**
 * @brief If the file containing the scores disappears we create a new one thanks to the "ExistFichier" function which we initialize to 0
 * @param[in/out] MeilleursScores : It's a TableauScore wich content the 10 best scores
 * @param[out] TableauNom :  Return MeilleursScores
 * @fn TableauScore InitScore (TableauScore & MeilleursScores);
 */
TableauScore InitScore (TableauScore & MeilleursScores);

/**
 * @brief If the file containing the best players disappears we create a new one thanks to the "ExistFichier" function which we initialize to "Personne"
 * @param[in/out] MeilleursScores : It's a TableauScore wich content the 10 best scores
 * @param[out] TableauNom :  Return MeilleursScores
 * @fn TableauNom InitJoueur (TableauNom & MeilleursNom);
 */
TableauNom InitJoueur (TableauNom & MeilleursNom);

/**
 * @brief Displays scores
 * @param[in/out] MeilleursScores : It's a TableauScore wich content the 10 best scores
 * @param[in/out] TableauJoueur : It's a TableauNom wich content the 10 best players
 * @fn void AfficheScore (TableauScore & MeilleursScores, TableauNom & TableauJoueur);
 */
void AfficheScore (const TableauScore & MeilleursScores, const TableauNom & TableauJoueur, MinGL &window);

/**
 * @brief Sort the scores in descending order
 * @param[in/out] MeilleursScores : It's a TableauScore wich content the 10 best scores
 * @param[in/out] TableauJoueur : It's a TableauNom wich content the 10 best players
 * @param[out] TableauNom :  Return MeilleursScores
 * @fn TableauScore TriDesScores (TableauScore & MeilleursScores, TableauNom & TableauJoueur);
 */
TableauScore TriDesScores (TableauScore & MeilleursScores, TableauNom & TableauJoueur);

/**
 * @brief Allows to include a score is a player name in their associated vector
 * @param[in/out] MeilleursScores : It's a TableauScore wich content the 10 best scores
 * @param[in/out] TableauJoueur : It's a TableauNom wich content the 10 best players
 * @param[in] :ScoreCourant : The score that we include in the vector
 * @param[in] : NomJoueur : The player that we include in his vector
 * @param[out] : bool : we return a bouleen, because we need to know if the score is in the top 10 and therefore if it is included
 * @fn template<typename T> bool InclureScore (TableauScore & MeilleursScores, const T & ScoreCourant,TableauNom & TableauJoueur , const string & NomJoueur);
 */
template<typename T>
bool InclureScore (TableauScore & MeilleursScores, const T & ScoreCourant,TableauNom & TableauJoueur , const std::string & NomJoueur);

/**
 * @brief If the files do not exist, create them and initialize them using the "InitScore" and "InitJoueur" functions
 * @fn void ExistFichier ();
 */
void ExistFichier ();

/**
 * @brief the so-called function when the player has finished a game
 * @param[in] :ScoreCourant : The score of the player when he finished a game
 * @fn template<typename T> void FinDePartieScore (const T & ScoreJoueur);
 */
template<typename T>
bool EnregistrerScoreFinPartie (const std::string &NomJoueur, const T & ScoreJoueur);

/**
 * @This is the so-called function to display the scores from the main menu
 * @fn void DebutDeJeu ();
 */
void AfficherTopScores (MinGL &window);

}

#include "score_mgr.hxx"

#endif // SCORE_MGR_H
