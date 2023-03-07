#ifndef _NIVEAU_H
#define _NIVEAU_H
#include"Temps.h"
#include"Jungle.h"

class Niveau
{
private:
    unsigned int niveau;
    Temps temps_jeu;
    Jungle jungle;


public:
    /**
     * @brief Construit un nouveau niveu qui est pris en paramètre.
     * 
     * @param[in] n
     */
    Niveau(unsigned int n );

    /**
     * @brief getniv retourne la donnée membre 
     * 
     * @return unsigned int& 
     */
    unsigned int & getniv() const; 

    /**
     * @brief  gettemps retourne la donnée membre temps_jeu.
     * 
     * @return Temps& 
     */
    Temps & gettemps ()const;

    /**
     * @brief getjung retorune la donnée membre jungle.
     * 
     * @return Jungle 
     */
    Jungle & getjung()const;

    /**
     * @brief  le mutateur qui modifie la valeur de la donnée membre niveau.
     * 
     * @param[in] n 
     */
    void setniveau(unsigned int n);

    /**
     * @brief le mutateur qui modifie la valeur de la donnée membre temps_jeu.
     * 
     * @param[in] t 
     */
    void settemps(const Temps & t );

    /**
     * @brief le mutateur qui modifie la valeur de la donnée membre jungle.
     * 
     * @param[in] jungle1 
     */
    void setjung(const Jungle & jungle1);

    /**
     * @brief calcule le temps ecoulé depuis le debut du jeu.
     * 
     * @param[in] temps2 
     * @return Temps 
     */
    Temps calculeTempsJeu(const Temps & temps2);
    
};
#endif



