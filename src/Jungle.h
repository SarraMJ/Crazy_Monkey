#ifndef _JUNGLE_H
#define _JUNGLE_H
#include </usr/include/SDL2/SDL.h>
#include </usr/include/SDL2/SDL_image.h>
#include "Arbre.h"
#include "Singe.h"

/**
 * @brief une classe qui représente une jungle avec ses  composantes.
 * 
 */
class Jungle
{
private:

    unsigned int dimx, dimy;
    Arbre * tab_arbre;
    unsigned int nb_arbre;
    unsigned int nb_serpent;
    float temps_partie; //en seconde
    Singe s;
    int etat; // si = 0 alors au joueur de choisir l'angle, si = 1 alors le singe bouge
    bool collision_arbre;
    bool collision_sol;
   
public:

    /**
     * @brief Constructeur par défaut de la classe jungle
     * 
     */
    Jungle();

    /**
     * @brief Constructeur par copie
     * 
     * @param[in] x 
     * @param[in] y 
     * @param[in] a 
     * @param[in] nbs
     * @param[in] nba
     * @param[in] temps
     * @param[in] sin 
     * @param[in] e
     * @param[in] ca
     * @param[in] cs
     */
    Jungle(unsigned int x, unsigned int y, Arbre * a,unsigned int nbs, unsigned int nba, float temps, const Singe & sin, int e, bool ca, bool cs);

    /**
     * @brief Destructeur
     * 
     */
    ~Jungle();

    /**
     * @brief Accesseur de la dimension x de la fenêtre
     * 
     * @return unsigned int 
     */
    unsigned int get_dimx() const;

    /**
     * @brief Accesseur de la dimension y de la fenêtre
     * 
     * @return unsigned int 
     */
    unsigned int get_dimy() const;

    /**
     * @brief Accesseur du pointeur vers le tableau d'arbre
     * 
     * @return Arbre* 
     */
    Arbre getTab_arbre(unsigned int indice) const;

    /**
     * @brief Acesseur du nombre d'arbre
     * 
     * @return unsigned int 
     */
    unsigned int getNb_serpent() const;

    /**
     * @brief Accesseur du singe
     * 
     * @return Singe 
     */
    Singe get_singe() const;

    /**
     * @brief Mutateur du singe
     * 
     * @param sin 
     */
    void set_singe(const Singe &sin);


    /**
     * @brief Vérifie la collision du singe avec un arbre ou le sol et fait voler le singe
     *  
     * 
     * @param[in] angle 
     */
    void collision(double angle, double t);

    /**
     * @brief Affiche le jeu
     * 
     */
    void afficher();
};


#endif 
