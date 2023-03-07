#ifndef _SERPENT_H
#define _SERPENT_H
#include "Vec2.h"

class Serpent
{
private:

    Vec2 position ; 

public:

    /**
     * @brief Constructeur par défaut
     * 
     */
    Serpent();

    /**
     * @brief Constructeur par copie
     * 
     */
    Serpent(Vec2 p);


    /**
     * @brief Accesseur  pour la position
     * 
     * @param[out] Vec2
     */
    Vec2 getPosition() const;

    /**
     * @brief Mutateur pour la position
     * 
     */
    void setPosition(Vec2 p);

};



#endif