#ifndef _ARBRE_H
#define _ARBRE_H

#include "Serpent.h"

/**
 * @brief la classe arbre représente un arbre et ses composants.
 * 
 */
class Arbre
{
private:
    bool banane_magique; 
    bool coffret_bananes;
    bool serpent; 
    Vec2 centre; 
    int rayon;

public:

    /**
     * @brief Constructeur par défaut
     * 
     */
    Arbre();

    /**
     * @brief Constructeur par copie
     * 
     * @param m 
     * @param c 
     * @param serpent 
     * @param cen
     * @param r 
     */
    Arbre(bool m, bool c, bool s, Vec2 cen, int r);



    /**
     * @brief Accesseur au bool banane_magique
     * 
     * @return true 
     * @return false 
     */
    bool getBanane_magique() const;

    /**
     * @brief Accesseur au bool coffret_bananes
     * 
     * @return true 
     * @return false 
     */
    bool getCoffret_bananes() const;

    /**
     * @brief Accesseur du  serpent
     * 
     * @return Serpent
     */
    bool getSerpent() const;

    /**
     * @brief Accesseur au centre
     * 
     * @return Vec2 
     */
    Vec2 getCentre() const ;

    /**
     * @brief Accesseur au rayon
     * 
     * @return int 
     */
    int getRayon() const;

    /**
     * @brief mutateur de la donnée membre Centre.
     * 
     * @param[in] V 
     */
    void setCentre(Vec2 V);

    /**
     * @brief mutateur du serpent
     * 
     * @param[in] se 
     */
    void set_serpent(bool se);

};

#endif