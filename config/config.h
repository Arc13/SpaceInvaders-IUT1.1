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
 * @brief TableauCommande is a vector of char, is a vector content the 3 commands
 */
typedef std::vector<char> TableauCommande ;

/**
 * @brief KDefaultRigthKey is d buy default
 */
const char KDefaultRightKey ('d');

/**
 * @brief KDefaultLeftKey is q buy default
 */
const char KDefaultLeftKey ('q');

/**
 * @brief KDefaultFirekey is ' ' buy default
 */
const char KDefaultFirekey (' ');

/**
 * @brief KDefaultFirekey is ' ' buy default
 */
const char KDefaultDifficulty ('0');

/**
 *@brief KTabDirection is for decripting to the user the command key
 */
const std::vector<std::string> KTabDirection {("' : pour aller à droite "),("' : pour aller à gauche "),("' : pour tirer ")};

/**
 * @brief NomFichierCommande is the name of the file command
 */
const std::string NomFichierCommande ("Config.txt");

/**
 * @brief ReadCommande is for Read the Key command on the FichierCommande file
 * @param Commande is content the Key command
 * @return
 */
TableauCommande ReadCommande (TableauCommande & Commande);

/**
 * @brief WriteCommande is for whrite the key command on the FichierCommande file
 * @param Commande is content the key command
 */
void WriteCommande (TableauCommande & Commande);

/**
 * @brief InitCommande is for init the command is the FichierCommande disapear
 * @param Commande is content the key command
 * @return
 */
TableauCommande InitCommande (TableauCommande & Commande);

/**
 * @brief AfficheCommande is for display command key
 */
void AfficheCommande (MinGL &window);

/**
 * @brief ChangerCommande
 */
void ChangerCommande (MinGL &window);

}

#endif // COMMANDE_H
