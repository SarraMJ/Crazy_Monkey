#ifndef _SINGE_H
#define _SINGE_H
#include"Vec2.h"

class Singe
{
private:

    unsigned int nb_vie;
    unsigned int nb_vie_init;
    unsigned int v0; 
    float g;
    Vec2 position;
    Vec2 pos_init;
    float rayon;
public:
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
     * @brief accesseur de la donnée membre nb_vie_init
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
     * @brief accesseur de la donnée membre pos_init
     * 
     * @return Vec2 
     */
    Vec2 getpos_init() const;

    /**
     * @brief accesseur de la donnée membre g 
     * 
     * @return float 
     */
    float getG()const;


    /**
     * @brief Accesseur de la donnée membre v0
     * 
     * @return unsigned int 
     */
    unsigned int get_v0() const;

    /**
     * @brief Accesseur de la donnée membre rayon
     * 
     * @return float 
     */
    float getrayon()const;

    /**
     * @brief mutateur de la donnée membre nb_vie
     * 
     * @param[in] nb 
     */
    void set_nb_vie(unsigned int nb);
    
    /**
     * @brief mutateur de la donnée membre nb_vie_init
     * 
     * @param[in] nb 
     */
    void set_nb_vie_init(unsigned int nb);

    /**
     * @brief  mutateur de la donnée membre v0
     * 
     * @param[in] v 
     */
    void set_v0(unsigned int v);

    /**
     * @brief  mutateur de la donnée membre pos_init
     * 
     * @param[in] v 
     */
    void set_pos_init(const Vec2 & v);
    
    /**
     * @brief  mutateur de la donnée membre g
     * 
     * @param[in] p 
     */
    void set_g(float p);

    /**
     * @brief  mutateur de la donnée membre position
     * 
     * @param[in] v 
     */
    void set_pos(const Vec2 & v);

    /**
     * @brief mutateur de la donnée membre rayon
     * 
     * @param[in] r 
     */
    void setrayon(float r);



    /**
     * @brief convertit les angles en radiants à des angles en degrès.
     * @param[in] deg 
     * @return float 
     */
    float to_rad(float deg)const; 



   
   
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

/**
 * @brief calcule l'angle alpha formée par la position initiale du singe et la position de l'utilisateur.
 * 
 * @param[in] pos_curseur 
 * @return float 
 */
float calculeAlpha( const Vec2 & pos_curseur) const;

};

#endif