#ifndef _SINGE_H
#define _SINGE_H
#include"Vec2.h"

class Singe
{
private:

    Vec2 position;
    //float masse;
    unsigned int nb_vie;
    unsigned int v0; 

public:


    //Vec2 Vitesse;
    //Vec2 force;


    /**
     * @brief Constructeur de la classe Singe
     * 
     * @param[in] viesInit 
     * @param[in] p
     * @param[in] vitesseInit
     * @param[in] v
     */
    Singe(unsigned int viesInit, Vec2 p, unsigned int vitesseInit);

    /**
     * @brief Destructeur
     * 
     */
    ~Singe();


    /**
     * @brief accesseur de la donnée membre nb_vie
     * 
     * @return unsigned int 
     */
    unsigned int get_nb_vie() const;

    /**
     * @brief accesseur de la donnée membre position
     * 
     * @return Vec2 
     */
    Vec2 getpos()const;



    /**
     * @brief Accesseur de la donnée membre v0
     * 
     * @return unsigned int 
     */
    unsigned int get_v0() const;


    /**
     * @brief mutateur de la donnée membre nb_vie
     * 
     * @param[in] nb 
     */
    void set_nb_vie(unsigned int nb);
    


    /**
     * @brief convertit les angles  en radiants à des angles en degrès.
     * @param[in] deg 
     * @return float 
     */
    float to_rad(float deg)const; 

     /**
     * @brief calcule l'équation du mouvement parabolique.
     * 
     * @return float 
     */
    float calcule_eqpara();

    /**
     * @brief fait la rotation d'un objet
     * 
     * @param[in] p 
     * @param[in] cx 
     * @param[in] cy 
     * @param[in] theta_deg 
     * @return Vec2 
     */

    Vec2 rotation(Vec2 p, float cx, float cy, float theta_deg);

    /**
     * @brief ajoute une force à une ancienne force.
     * 
     * @param[in] f 
     */
    void rajouteForce (Vec2 f);


/**
 * @brief Calcule la coordonnée x de ... 
 * 
 * @param angle 
 * @param[in] t
 * @return float 
 */
float calculeX(float angle, float t);

/**
 * @brief Calcule la coordonnée Y de la position de notre objet sur la parabole au temps t
 * 
 * @param angle 
 * @param t 
 * @return float 
 */
float calculeY(float angle, float t);


};

#endif