#ifndef _MOUVEMENT_H
#define _MOUVEMENT_H
#include"Vec2.h"

class Mouvement
{
private:
    Vec2 Vitesse;
    Vec2 force;
    Vec2 position;
    float masse;

public:

    /**
     * @brief Construit un nouveau mouvement qui met tou à zèro.
     * 
     */
    Mouvement();

    /**
     * @brief  récupère la donnée membre vitesse.
     * 
     * @return Vec2 
     */
    
    Vec2 getVitesse()const;
    /**
     * @brief récupère la donnée membre force.
     * 
     * @return Vec2 
     */
    Vec2 getForce()const;
    /**
     * @brief récupère la donnée membre position
     * 
     * @return Vec2 
     */
    Vec2 getPosition()const;
    /**
     * @brief récupère la donnée membre masse.
     * 
     * @return float 
     */
    float getMasse()const;

    /**
     * @brief modifie la valeur de la vitesse
     * 
     * @param[in] v 
     */
    void setVitesse(const Vec2 & v);
    /**
     * @brief  modifie la valeur de la force
     * 
     * @param[in] f 
     */
    void setForce(const Vec2 & f);

    /**
     * @brief  modifie la valeur de la position
     * 
     * @param[in] p 
     */
    void setPosition(const Vec2 & p);

    /**
     * @brief  modifie la valeur de la masse
     * 
     * @param[in] m 
     */
    void setMasse(float m);

    /**
     * @brief convertit les angles  en degrès à des angles en radiants
     * 
     * @param[in] rad 
     * @return float 
     */
    float to_degree(float rad);

    /**
     * @brief convertit les angles  en radiants à des angles en degrès.
     * @param[in] deg 
     * @return float 
     */
    float to_rad(float deg); 


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
    Vec2 rotate(Vec2 p, float cx, float cy, float theta_deg);

};
#endif

