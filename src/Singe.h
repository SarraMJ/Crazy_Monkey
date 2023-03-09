#ifndef _SINGE_H
#define _SINGE_H
#include"Vec2.h"

class Singe
{
private:

    Vec2 position;
    float masse;
    unsigned int nb_vie;

public:

    Vec2 Vitesse;
    Vec2 force;

    /**
     * @brief Constructeur de la classe Singe
     * 
     * @param[in] viesInit 
     * @param[in] position 
     * @param[in] force 
     * @param[in] mas 
     * @param[in] vites 
     */
    Singe(unsigned int viesInit, Vec2 position, Vec2 force, float mas, Vec2 vites );

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
     * @brief accesseur de la donnée membre masse
     * 
     * @return float 
     */
    float getmasse()const;

    /**
     * @brief mutateur de la donnée membre nb_vie
     * 
     * @param[in] nb 
     */
    void set_nb_vie(unsigned int nb);


    /**
     * @brief mutateur de la donnée membre ancienne_pos
     * 
     * @param[in] v 
     */
    void setpos(const Vec2 & v);
    void setmasse(float mas);

     /**
     * @brief convertit les angles  en degrès à des angles en radiants
     * 
     * @param[in] rad 
     * @return float 
     */
    float to_degree(float rad)const;

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
};



#endif
