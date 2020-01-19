/**
 * @file score_mgr.h
 * @brief Les fonctions de score
 * @author LAUGIER Colin
 * @version 1.0
 * @date 09 janvier 2020
 */

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
 * @brief Un vecteur d'unsigned qui contient le score des joueurs
 */
typedef std::vector<unsigned> TableauScore ;

/**
 * @brief Un vecteur de string qui contient le nom des joueurs
 */
typedef std::vector<std::string> TableauNom ;

/**
 * @brief Le nom du fichier où nous stockons les scores
 */
const std::string NomFichierScore ("Score.txt");

/**
 * @brief Le nom du fichier où nous stockons le nom des joueurs
 */
const std::string NomFichierJoueur ("Joueur.txt");

/**
 * @brief La taille d'un TableauScore et d'un TableauNom
 *
 * Ceci définit le nombre de score a enregistrer, et par conséquent le nombre de places sur le podium
 */
const unsigned TailleTableauScore (10);

/**
 * @brief Lis les scores depuis le fichier <NomFichierScore> et les places dans MeilleursScore
 * @param[in, out] MeilleursScores : Le tableau qui contient les <TailleTableauScore> meilleurs scores
 * @fn void ReadScore (TableauScore & MeilleursScores);
 */
void ReadScore (TableauScore & MeilleursScores);

/**
 * @brief Lis le nom des joueurs depuis le fichier <NomFichierJoueur> et les places dans MeilleursNom
 * @param[in, out] MeilleursNom : Le tableau qui contient les <TailleTableauScore> noms des meilleurs joueurs
 * @fn void ReadNom (TableauNom & MeilleursNom);
 */
void ReadNom (TableauNom & MeilleursNom);

/**
 * @brief Ecris les scores dans le fichier NomFichier
 * @param[in, out] MeilleursScores : Le tableau qui contient les <TailleTableauScore> meilleurs scores
 * @param[in, out] NomFichier : Le nom du fichier où sauvegarder les scores
 * @fn void WriteScore (T & MeilleursScores, const std::string NomFichier);
 */
template <typename T>
void WriteScore (T & MeilleursScores, const std::string NomFichier);

/**
 * @brief Initialise tous les scores de MeilleursScores a 0
 * @param[in, out] MeilleursScores : Le tableau qui contient les <TailleTableauScore> meilleurs scores
 * @fn void InitScore (TableauScore & MeilleursScores);
 */
void InitScore (TableauScore & MeilleursScores);

/**
 * @brief Initialise tous les noms des joueurs a "Personne"
 * @param[in, out] MeilleursNom : Le tableau qui contient les <TailleTableauScore> noms des meilleurs joueurs
 * @fn void InitJoueur (TableauNom & MeilleursNom);
 */
void InitJoueur (TableauNom & MeilleursNom);

/**
 * @brief Affiche les <TailleTableauScore> meilleurs scores a la fenêtre passée en paramètre
 * @param[in, out] window : La fenêtre d'affichage
 * @param[in, out] MeilleursScores : Le tableau qui contient les <TailleTableauScore> meilleurs scores
 * @param[in, out] MeilleursNom : Le tableau qui contient les <TailleTableauScore> noms des meilleurs joueurs
 * @fn void AfficheTopScores (MinGL &window, const TableauScore & MeilleursScores, const TableauNom & MeilleursNom);
 */
void AfficheTopScores (MinGL &window, const TableauScore & MeilleursScores, const TableauNom & MeilleursNom);

/**
 * @brief Trie les deux tableaux par ordre décroissant des scores
 * @param[in, out] MeilleursScores : Le tableau qui contient les <TailleTableauScore> meilleurs scores
 * @param[in, out] MeilleursNom : Le tableau qui contient les <TailleTableauScore> noms des meilleurs joueurs
 * @fn void TriDesScores (TableauScore & MeilleursScores, TableauNom & TableauJoueur);
 */
void TriDesScores (TableauScore & MeilleursScores, TableauNom & TableauJoueur);

/**
 * @brief Insère un couple score et nom de joueur dans leurs vecteurs respectifs, en le triant
 * @param[in, out] MeilleursScores : Le tableau qui contient les <TailleTableauScore> meilleurs scores
 * @param[in] ScoreCourant : Le score a rajouter dans le vecteur
 * @param[in, out] MeilleursNom : Le tableau qui contient les <TailleTableauScore> noms des meilleurs joueurs
 * @param[in] NomJoueur : Le nom du joueur a rajouter dans le vecteur
 * @return Un booléen indiquant si le score a bien été rajouté au classement.
 * Si l'on renvoie false, cela veut dire que ScoreCourant est inférieur au plus petit score de MeilleursScores
 * @fn bool InclureScore (TableauScore & MeilleursScores, const T & ScoreCourant, TableauNom & TableauJoueur , const std::string & NomJoueur);
 */
template<typename T>
bool InclureScore (TableauScore & MeilleursScores, const T & ScoreCourant, TableauNom & MeilleursNom, const std::string & NomJoueur);

/**
 * @brief Créent les fichiers <NomFichierScore> et <NomFichierJoueur> s'ils n'existent pas, en initialisant leurs contenus avec respectivement les fonctions InitScore et InitJoueur
 * @fn void ExistFichier ();
 */
void ExistFichier ();

/**
 * @brief Enregistre le score et le nom du joueur en fin de partie
 * @param[in] NomJoueur : Le nom du joueur a enregistrer
 * @param[in] ScoreJoueur : Le score du joueur a enregistrer
 * @return Un booléen indiquant si le score a bien été rajouté au classement.
 * Si l'on renvoie false, cela veut dire que ScoreCourant est inférieur au plus petit score de MeilleursScores
 * @fn bool EnregistrerScoreFinPartie (const std::string &NomJoueur, const T & ScoreJoueur);
 */
template<typename T>
bool EnregistrerScoreFinPartie (const std::string &NomJoueur, const T & ScoreJoueur);

/**
 * @brief Charge les scores depuis les fichiers, et les affichent a l'écran
 * @param[in, out] window : La fenêtre d'affichage
 * @fn void ChargerEtAfficherTopScores (MinGL &window);
 */
void ChargerEtAfficherTopScores (MinGL &window);

}

#include "score_mgr.hxx"

#endif // SCORE_MGR_H
