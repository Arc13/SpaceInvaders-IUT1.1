#ifndef MYCONSTANT_H
#define MYCONSTANT_H

#pragma once

/*!
  * \file MyConstant.h
  * \author Alison Palatuik
  * \date 13/01/2020
  * \brief Fichier décrivant l'ensemble des alias vers les types utilisés dans le jeu
  * \version 1.0
  * \bug Aucun connu
  */

#include <string>

namespace nsGame
{
    //Constantes de couleur
    /*!
     * \brief Alias remetant la couleur du texte du terminal à sa valeur par défaut.
     */
    const std::string KReset   ("0");

    /*!
     * \brief Alias mettant en noir la couleur du texte du terminal.
     */
    const std::string KNoir    ("30");
    /*!
     * \brief Alias mettant en rouge la couleur du texte du terminal.
     */
    const std::string KRouge   ("31");

    /*!
     * \brief Alias mettant en vert la couleur du texte du terminal.
     */
    const std::string KVert    ("32");

    /*!
     * \brief Alias mettant en jaune la couleur du texte du terminal.
     */
    const std::string KJaune   ("33");

    /*!
     * \brief Alias mettant en bleu la couleur du texte du terminal.
     */
    const std::string KBleu    ("34");

    /*!
     * \brief Alias mettant en mangenta la couleur du texte du terminal.
     */
    const std::string KMAgenta ("35");

    /*!
     * \brief Alias mettant en cyan la couleur du texte du terminal.
     */
    const std::string KCyan    ("36");

    // Constantes pour les touches
    /*!
     * \brief Alias vers la touche servant à se déplacer à droite.
     */
    const char KRight               = 'x';  // déplacement vers la droite

    /*!
     * \brief Alias vers la touche servant à se déplacer à gauche.
     */
    const char KLeft                = 'w';  // Déplacement vers la gauche

    /*!
     * \brief Alias vers la touche servant à lancer une torpille.
     */
    const char KShoot               = ' ';  // Lancer de torpille

    //  Constantes liées à l'envahisseur
    /*!
     * \brief Couleur de l'envahisseur.
     */
    const std::string KInvadersColor (KJaune);  // Couleur de l'envahisseur

    /*!
     * \brief Caractèrere formant l'envahisseur.
     */
    const char KInsideInvader       = 'W';  // caractèrere formant l'envahisseur

    /*!
     * \brief Caractèrere formant le missile.
     */
    const char KMissile             = ':';  // missile

    /*!
     * \brief Nombre de fois où l'envahisseur tire un missile par rapport à son déplacement.
     */
    const unsigned KMissileRatio = 2; // nombre de fois où l'envahisseur tire un missile par rapport à son déplacement

    // Constantes liées au joueur
    /*!
     * \brief Couleur liée à mes objets (vaisseaux et tropilles).
     */
    const std::string KMyColor (KVert); // Ma couleur

    /*!
     * \brief Caractèrere formant mon vaisseau.
     */
    const char KInsideMe            = 'X'; // caractèrere formant mon vaisseau

    /*!
     * \brief Caractèrere formant ma torpille.
     */
    const char KTorpedo             = '.'; // caractèrere formant ma torpille

    /*!
     * \brief Nombre de caractères qui forment mon vaisseau.
     */
    const unsigned KMySize          = 1; //  nombre de caractères qui forment mon vaisseau


    /*!
     * \brief Nombre de fois où c'est le tour du joueur pour un tour de l'envahisseur.
     */
    const unsigned KRatioMeInvaders = 5; // Nombre de fois où c'est le tour du joueur pour un tour de l'envahisseur


    // Constantes liées à l'eapace (l'écran)
    /*!
     * \brief Alias vers une case vide à l'écran.
     */
    const char KEmpty               = ' ';  // case vide de l'écran
    /*!
     * \brief Nombre de lignes de l'écran (de l'espace).
     */
    const unsigned KSizeLine   = 12;   // Nombre de lignes de l'écran (de l'espace)

    /*!
     * \brief Nombre de colonnes de l'écran (de l'espace).
     */
    const unsigned KSizeSpace  = 13;   // Nombre de colonnes de l'écran (de l'espace)

    /*!
     * \brief Nombre de caractères qui forment l'envahisseur.
     */
    const unsigned KInvadersSize    =  KSizeSpace - 4;   // nombre de caractères qui forment l'envahisseur

    /*!
     * \brief Nombre de lignes que les envahisseurs envahissent.
     */
    const unsigned KInvadersLines   = 5;    // Nombre de lignes que les envahisseurs envahissent.

    /*!
     * \brief Numéro de colonne où commence l'envahisseur.
     */
    const unsigned KBegInvader = 2;    // Numéro de colonne où commence l'envahisseur

    /*!
     * \brief Numéro de colonne où commence le joueur.
     */
    const unsigned KBegMe      = KSizeLine / 2;  // Numéro de colonne où commence le joueur

    /*!
     * \brief Alias vers une ligne vide de l'espace.
     */
    const std::string KEmptyLine (KSizeSpace, KEmpty);  // Une ligne vide de la matrice

    /*!
     * \brief Niveau maximal du jeu.
     */
    const unsigned KMaxLevel = 4; // Niveau maximal du jeu.
} // namespace nsGame

#endif // MYCONSTANT_H
