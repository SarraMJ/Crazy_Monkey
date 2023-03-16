#ifndef _AFFICHAGESDL2_H
#define _AFFICHAGESDL2_H

#include </usr/include/SDL2/SDL.h>
#include </usr/include/SDL2/SDL_image.h>
#include </usr/include/SDL2/SDL_ttf.h>
#include </usr/include/SDL2/SDL_mixer.h>

#include "Jungle.h"

//! \brief Pour gérer une image avec SDL2
class Image {

private:

    SDL_Surface * m_surface;
    SDL_Texture * m_texture;
    bool m_a_change;

public:

    /**
     * @brief constructeur par defaut de la classe image
     * 
     */
    Image () ;
    /**
     * @brief Destructeur d ela classe image 
     * 
     */
    ~Image();

    /**
     * @brief télécharge un fichier 
     * 
     * @param[in] filename 
     * @param[in] renderer 
     */
    void telecharger_fichier (const char* filename, SDL_Renderer * renderer);

    /**
     * @brief télécharger à partir d'une surface
     * 
     * @param[in] renderer 
     */
    void telecharger_apartir_surface_courante(SDL_Renderer * renderer);

    /**
     * @brief dessiner la fenetre 
     * 
     * @param[in] renderer 
     * @param[in] x 
     * @param[in] y 
     * @param[in] w 
     * @param[in] h 
     */
    void dessiner (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    /**
     * @brief accesseur de la donnée membre texture
     * 
     * @return SDL_Texture* 
     */
    SDL_Texture * getTexture() const;

    /**
     * @brief mutateur de la donnée membre surface
     * 
     * @param surf 
     */
    void setSurface(SDL_Surface * surf);
};



/**
    La classe gerant le jeu avec un affichage SDL
*/
class AffichageSDL {

private :

	Jungle jungle;

    SDL_Window * fenetre;
    SDL_Renderer * renderer;

    TTF_Font * police;
    Image police_im;
    SDL_Color couleur;

    Mix_Chunk * son;
    bool avec_son;

    Image im_singe;
    Image im_arbre;
    Image im_serpent;
    Image im_banane_mag;
    Image im_coffret_banane;

    bool souris;
    bool touche;

public :

    /**
     * @brief Constructeur par défaut de la classe SDLSimple
     * 
     */
    AffichageSDL ();

    /**
     * @brief Destructeur de la classe SDLSimple
     * 
     */
    ~AffichageSDL ();

    /**
     * @brief prend en considèration l'interaction de l'utilisateur avec l'interface
     * 
     */
    void sdlBoucle ();

    /**
     * @brief affiche la fenetre sdls
     * 
     */
    void sdlAff ();
};

#endif