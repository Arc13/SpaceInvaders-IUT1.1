/**
  *
  * @author Colin Laugier
  *
  * @date 09/01/20
  *
  * @brief Fichier pour la config
  *
  * */

#ifndef COMMANDE_H
#define COMMANDE_H

#include <vector>
#include <string>

#include "gui/text.h"
#include "gui/star_background.h"

#include "graph/rgbacolor.h"
#include "graph/vec2d.h"

/**
 * @namespace nsConfig
 * @brief Espace de nom pour le gestionnaire de configuration utilisateur
 */
namespace nsConfig {

/**
 * @brief TableauCommande est un vecteur de char, contenant la configuration utilisateur
 */
typedef std::vector<char> TableauCommande ;

/**
 * @brief KDefaultRightKey représente la touche directionnelle droite par défaut, 'd'
 */
const char KDefaultRightKey ('d');

/**
 * @brief KDefaultLeftKey représente la touche directionnelle gauche par défaut, 'q'
 */
const char KDefaultLeftKey ('q');

/**
 * @brief KDefaultFirekey représente la touche de tir par défaut, ' ' (Espace)
 */
const char KDefaultFirekey (' ');

/**
 * @brief KDefaultDifficulty représente la difficulté par défaut, normal
 */
const char KDefaultDifficulty ('1');

/**
 *@brief KTabDirection est une description des différentes touches
 */
const std::vector<std::string> KTabDirection {("' : pour aller à droite "),("' : pour aller à gauche "),("' : pour tirer ")};

/**
 * @brief NomFichierCommande est le nom du fichier de configuration
 */
const std::string NomFichierCommande ("Config.txt");

/**
 * @brief Lis le fichier de configuration et place son contenu dans Commande
 * @param[in, out] Commande : Tableau qui va contenir la configuration
 * @fn void ReadCommande (TableauCommande & Commande);
 */
void ReadCommande (TableauCommande & Commande);

/**
 * @brief Ecris le fichier de configuration selon la configuration contenue dans Commande
 * @param[in] Commande : Tableau qui contient la configuration
 * @fn void WriteCommande (const TableauCommande & Commande);
 */
void WriteCommande (const TableauCommande & Commande);

/**
 * @brief Initialise le tableau de configuration Commande avec des valeurs par défaut
 * @param[in, out] Commande : Tableau de configuration a initialiser
 * @fn void InitCommande (TableauCommande & Commande);
 */
void InitCommande (TableauCommande & Commande);

/**
 * @brief Affiche les différentes touches a l'écran
 * Déprécié par le panneau de configuration
 * @param[in, out] window : La fenêtre d'affichage
 * @fn void AfficheCommande (MinGL &window);
 */
void AfficheCommande (MinGL &window);

/**
 * @brief Change les contrôles de la configuration via le terminal
 * Déprécié par le panneau de configuration
 * @param[in, out] window : La fenêtre d'affichage
 * @fn void ChangerCommande (MinGL &window);
 */
void ChangerCommande (MinGL &window);

}

#endif // COMMANDE_H
