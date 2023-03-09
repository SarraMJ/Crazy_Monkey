#ifndef _ARBRE_H
#define _ARBRE_H
#include "Serpent.h"

class Arbre
{
private:
    bool banane_magique; 
    bool coffret_bananes;
    Serpent * s ; 
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
     * @param rayon 
     * @param centre 
     */
    Arbre(bool m, bool c, Serpent * serpent, Vec2 rayon, int centre);

    /**
     * @brief Destructeur
     * 
     */
    ~Arbre();

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
     * @brief Accesseur au pointeur du serpent
     * 
     * @return Serpent* 
     */
    Serpent * getSerpent() const;

    /**
     * @brief Accesseur vers min
     * 
     * @return Vec2 
     */
    Vec2 getCentre() const;

    /**
     * @brief Accesseur vers max
     * 
     * @return int 
     */
    int getRayon() const;

};
#endif