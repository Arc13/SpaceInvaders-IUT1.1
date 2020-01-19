/**
  * @file manager.h
  * @author PALATUIK Alison
  * @date 13 Janvier 2020
  * @brief Fichier décrivant l'ensemble des alias vers les types utilisés dans le jeu
  * @version 1.0
  * @bug Aucun connu
  */

#ifndef MANAGE_H
#define MANAGE_H

#include "manager_type.h"

/**
 * @namespace nsGame
 * @brief Espace de nom pour les mécaniques de jeu
 */
namespace nsGame
{
    /**
     * @fn void PutCVPosition (const CVPosition & VPos, char Car, CVString & Space)
     * @brief Permet d'insérer le carcactère passé en second paramètre à toutes les positions souhaitées (1er paramètre) de l'espace de jeu (3ème paramètre).
     * @param[in] VPos Vecteur de CPosition
     * @param[in] Car Caractère à insérer dans l'esapce
     * @param\[in, out] Space Espace de jeu
     */
    void PutCVPosition (const CVPosition & VPos, char Car, CVString & Space);

    /**
     * @brief Vide l'espace de jeu, puis insère tous les objets du jeu.
     * @param Obj [in] Liste des objets à insérer
     * @param Space [in, out] Espace de jeu
     */
    void PutAllObjects (const CAObject & Obj, CVString & Space);

    /**
     * @brief Permet d'initialiser l'espace de jeu et de définir les coordonnées des objets à placer au lancement du jeu.
     * @param Space [out] Espace de jeu
     * @param Obj [out] Liste des objets à placer au début du jeu
     */
    void InitSpace (CVString & Space, CAObject & Obj);

    /**
     * @brief Rajoute un joueur dans les objets à placer.
     * @param Space [out] Espace de jeu
     * @param Obj [out] Liste des objets à placer au début du jeu
     */
    void AddPlayer (CVString & Space, CAObject & Obj);

    /**
     * @brief Trouve le maximum d'un vecteur de CPosition de la coordonées en X (abscisse).
     * @param VPos [in] Vecteur de CPosition
     * @param MaxPos [out] Valeur maximale pour X
     */
    void MaxX (const CVPosition & VPos, CPosition & MaxPos);

    /**
     * @brief Trouve le maximum d'un vecteur de CPosition de la coordonées en Y (ordonnée).
     * @param VPos [in] Vecteur de CPosition
     * @param MaxPos [out] Valeur maximale pour Y
     */
    void MaxY (const CVPosition & VPos, CPosition & MaxPos);

    /**
     * @brief Trouve le minimum d'un vecteur de CPosition de la coordonées en X (abscisse).
     * @param VPos [in] Vecteur de CPosition
     * @param MinPos [out] Valeur minimale pour X
     */
    void MinX (const CVPosition & VPos, CPosition & MinPos);

    /**
     * @brief Simule un déplacement gauche en retranchant une unité de déplacement à toutes les abscisses des objets en paramètre.
     * @param VPos [in, out] Vecteur de CPosition
     * @return Vrai si la plus petite des abscisses ne vaut pas 0, faux sinon
     */
    bool MoveLeft (CVPosition & VPos);

    /**
     * @brief Simule un déplacement droit en ajoutant une unité de déplacement à toutes les abscisses des objets en paramètre.
     * @param Space [in] Espace de jeu
     * @param VPos [in, out] Vecteur de CPosition
     * @return Vrai si la plus grande des abscisses ne vaut pas n'est pas sur la dernière case de l'espace de jeu, faux sinon
     */
    bool MoveRight (const CVString & Space, CVPosition & VPos);

    /**
     * @brief Simule un déplacement bas en ajoutant une unité de déplacement à toutes les ordonnées des objets en paramètre.
     * @param VPos [in, out] Vecteur de CPosition
     */
    void MoveDown (CVPosition & VPos);

    /**
     * @brief Simule un déplacement haut en ajoutant une unité de déplacement à toutes les ordonnées des objets en paramètre.
     * @param VPos [in, out] Vecteur de CPosition
     */
    void MoveUp (CVPosition & VPos);

    /**
     * @brief Récupère l'heure système.
     */
    int GetTime();

    /**
     * @brief ManageInvaders Simule le jeu de l'envahisseur.
     * @param Obj [in, out] Liste des objets du jeu
     * @param ShootPerSecond [in, out] Le nombre de tirs que fait l'invader par second (lancer un missile, d'une position au hasard, au dessous d'une de ses positions).
     */
    void ManageInvaders (CAObject &Obj, unsigned & ShootPerSecond);

    /**
     * @brief Gère les collisions entre les objets et les vaisseaux. Si une collision est détéctée (même coordonées pour un objet et une partie d'un vaisseau), l'objet et la partie du vaisseau diparaissent
     * @param Objects [in, out] Vecteur des positions des objects à traiter
     * @param StarShips [in, out] Vecteur des positions des vaisseaux à traiter
     */
    unsigned CollisionBetweenObjectsAndShips (CVPosition & Objects, CVPosition & StarShips);

    /**
     * @brief Gère les collisions (multiples) entre les missiles et les tropilles
     * @param Missiles [in, out] Vecteur des positions des missiles
     * @param Torpedos [in, out] Vecteur des positions des torpilles
     */
    void CollisionBetweenMissilesAndTorpedos (CVPosition & Missiles, CVPosition & Torpedos);

    /**
     * @brief Gère toutes les collisions du jeu
     * @param [in, out] Obj Liste des objets du jeu
     * @param [in, out] Score Nombre abstrait de vaisseaux touchés
     */
    void ManageCollisions (CAObject & Obj, unsigned &Score);

    /**
     * @brief Teste si l'envahisseur ou si le joueur ont gagné.
     * @param Obj [in] Liste des objets du jeu
     * @return 0 si ni l'envahisseur ou le joueur ont gagné, 1 si c'est le joueur, 2 si c'est l'envahisseur et 3 si l'envahisseur est tout en bas
     */
    unsigned Victory (const CAObject & Obj);

    /**
     * @brief Supprime les missiles qui sortent de l'espace de jeu.
     * @param [in] Space Espace de jeu
     * @param Missiles [in, out] Vecteur des positions des missiles
     */
    void DeleteMissiles (const CVString & Space, CVPosition & Missiles);

    /**
     * @brief Supprime les tropilles qui sortent de l'espace de jeu.
     * @param Torpedos [in, out] Vecteur des positions des torpilles
     */
    void DeleteTorpedos (CVPosition & Torpedos);

}//namespace nsSpaceInvader_AC

#endif // MANAGE_H
