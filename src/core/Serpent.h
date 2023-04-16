#ifndef _SERPENT0_H
#define _SERPENT_H
#include "Vec2.h"

/**
 * @brief Classe qui représente un serpent et ses composants.
 *
 */

class Serpent
{
private:
    Vec2 position;
    double rayon;

public:
    /**
     * @brief Constructeur par défaut
     *
     */
    Serpent();

    /**
     * @brief Constructeur par copie
     *
     * param[in] p
     */
    Serpent(Vec2 p);

    /**
     * @brief Accesseur  pour la position
     *
     * @return Vec2
     */
    Vec2 getPosition() const;

    /**
     * @brief Mutateur pour la position
     *
     * param[in] p
     */
    void setPosition(Vec2 p);

    /**
     * @brief accesseur de la donnée membre rayon
     *
     * @return double
     */
    double getRayon() const;

    /**
     * @brief mutateur de la donnée membre rayon
     *
     * @param[in] r
     */
    void setRayon(double r);
};

#endif