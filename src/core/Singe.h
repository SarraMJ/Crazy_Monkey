#ifndef _SINGE_H
#define _SINGE_H
#include"Vec2.h"

/**
 * @brief Classe qui représente un singe et ses composants 
 * 
 */

class Singe
{
private:

    unsigned int nb_vie;
    unsigned int nb_vie_init;
    double v0; 
    double g;
    Vec2 position;
    Vec2 pos_init;
    double rayon;

public:

    /**
     * @brief constructeur par défaut de la classe Singe.
     * 
     */
    Singe();

    /**
     * @brief Constructeur de la classe Singe
     * 
     * @param[in] viesInit 
     * @param[in] p
     * @param[in] vitesseInit
     * @param[in] v
     */
    Singe(unsigned int viesInit, Vec2 p,double r, double v, double gr);

    

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
    unsigned int get_nb_vie_init() const;

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
     * @return double 
     */
    double getG()const;


    /**
     * @brief Accesseur de la donnée membre v0
     * 
     * @return unsigned int 
     */
    double get_v0() const;

    /**
     * @brief Accesseur de la donnée membre rayon
     * 
     * @return double 
     */
    double getrayon()const;

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
    void set_v0(double v);

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
    void set_g(double p);

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
    void setrayon(double r);



  
/**
 * @brief Calcule la nouvelle position du singe  
 * 
 * @param angle 
 * @param[in] t
 * @return Vec2
 */
Vec2 calcule_pos(double angle, double t);

;

/**
 * @brief calcule l'angle alpha formé par la position initiale du singe et la position de l'utilisateur.
 * 
 * @param[in] pos_curseur 
 * @return double 
 */
double calculeAlpha(const Vec2 & pos_curseur) const;

};

#endif