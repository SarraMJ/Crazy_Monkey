#ifndef _TEMPS_H
#define _TEMPS_H

/**
 * @class Temps
 * @brief Classe temps qui stocke les minutes et les secondes 
 * 
 */
class Temps {

    private: 

    unsigned int min;  
    unsigned int sec; 

    public : 

    /**
     * @brief Constructeur par défaut
     * 
     */
    Temps(); 

    /**
     * @brief Constructeur par copie
     * 
     * @param[in] m 
     * @param[in] s 
     */
    Temps(unsigned int m, unsigned int s);

    /**
     * @brief Accesseur qui récupère les secondes

     * 
     * @return unsigned int& 
     */
    unsigned int  getSec() const;

    /**
     * @brief Accesseur qui récupère les minutes 
     * 
     * @return unsigned int& 
     */
    unsigned int getMin() const ; // on a enlevé le & car ça marchait pas sans, à revoir si il faut le mettre dans les deux get

    /**
     * @brief Mutateur qui modifie la composante seconde
     * 
     * @param[in] s 
     */
    void setSec(unsigned int s);

    /**
     * @brief Mutateur qui modifie la composante minute
     * 
     * @param[in] m 
     */
    void setMin(unsigned int m);



};

#endif