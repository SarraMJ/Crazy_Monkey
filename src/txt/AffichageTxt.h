#ifndef _AFFICHAGETXT_H
#define _AFFICHAGETXT_H
#include "../core/Jungle.h"
#include "winTxt.h"



    /**
 * @brief Affiche les éléments
 * 
 * 
 * @param[in] j 
 */
void txtAff(WinTXT & win, const Jungle & j);

void txtAff2(WinTXT & win, const Jungle & j);

void collisiontxt(Jungle & j, double angle, double t, WinTXT & win);

/**
 * @brief Affichage en mode txt
 * 
 * @param[in] j 
 */
void txtBoucle ( Jungle & j);

#endif