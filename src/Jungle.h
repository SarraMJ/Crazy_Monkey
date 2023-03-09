#ifndef _JUNGLE_H
#define _JUNGLE_H

#include "Arbre.h"
#include "Singe.h"

class Jungle
{
private:

    unsigned int dimx, dimy;
    Arbre * tab_arbre;
    unsigned int nb_serpent;
    Singe s;

   
public:

    /**
     * @brief Constructeur par défaut
     * 
     */
    Jungle();

    /**
     * @brief Constructeur par copie
     * 
     * @param[in] x 
     * @param[in] y 
     * @param[in] a 
     * @param[in] sin 
     */
    Jungle(unsigned int x, unsigned int y, Arbre * a, Singe sin);

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
    void set_singe(const & Singe sin);
};


#endif 
