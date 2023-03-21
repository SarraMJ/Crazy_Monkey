#ifndef _AFFICHAGETXT_H
#define _AFFICHAGETXT_H
#include "../core/Jungle.h"
#include "winTxt.h"



 /**
  * @brief Affiche les éléments de la fenétre
  * 
  * @param[in] win 
  * @param[in] j 
  */
void txtAff(WinTXT & win, Jungle & j);

/**
 * @brief affiche seulement l singe avce la nouvelle position.
 * 
 * @param[in] win 
 * @param[in] j 
 */
void txtAff2(WinTXT & win, Jungle & j);

/**
 * @brief calcule si il ya  collision du singe avec les autres elements de la fenetre.
 * 
 * @param[in] j 
 * @param[in] angle 
 * @param[in] t 
 * @param[in] win 
 */
void collisiontxt(Jungle & j, double angle, double t, WinTXT & win);

/**
 * @brief Affichage en mode txt
 * 
 * @param[in] j 
 */
void txtBoucle ( Jungle & j);

#endif