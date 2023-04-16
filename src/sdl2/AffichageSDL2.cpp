
#include <iostream>
#include <cassert>
#include <time.h>
#include <stdlib.h>
#include "AffichageSDL2.h"

using namespace std;

float temps()
{
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC; // conversion des ms en secondes en divisant par 1000
}

// ============= CLASS IMAGE =============== //

Image::Image() : m_surface(nullptr), m_texture(nullptr), m_a_change(false)
{
}

Image::~Image()
{
    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);

    m_surface = nullptr;
    m_texture = nullptr;
    m_a_change = false;
}

void Image::telecharger_fichier(const char *filename, SDL_Renderer *renderer)
{
    m_surface = IMG_Load(filename);
    if (m_surface == nullptr)
    {
        string nfn = string("../") + filename;
        cout << "Error: cannot load " << filename << ". Trying " << nfn << endl;
        m_surface = IMG_Load(nfn.c_str());
        if (m_surface == nullptr)
        {
            nfn = string("../") + nfn;
            m_surface = IMG_Load(nfn.c_str());
        }
    }
    if (m_surface == nullptr)
    {
        cout << "Error: cannot load " << filename << endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface *surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(m_surface, SDL_PIXELFORMAT_ARGB8888, 0);
    SDL_FreeSurface(m_surface);
    m_surface = surfaceCorrectPixelFormat;

    m_texture = SDL_CreateTextureFromSurface(renderer, surfaceCorrectPixelFormat);
    if (m_texture == NULL)
    {
        cout << "Error: problem to create the texture of " << filename << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::telecharger_apartir_surface_courante(SDL_Renderer *renderer)
{
    m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);
    if (m_texture == nullptr)
    {
        cout << "erreur:probleme de création de la texture à partir de la surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::dessiner(SDL_Renderer *renderer, int x, int y, int w, int h)
{
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = (h < 0) ? m_surface->h : h;

    if (m_a_change)
    {
        ok = SDL_UpdateTexture(m_texture, nullptr, m_surface->pixels, m_surface->pitch);
        assert(ok == 0);
        m_a_change = false;
    }

    ok = SDL_RenderCopy(renderer, m_texture, nullptr, &r);
    assert(ok == 0);
}

SDL_Texture *Image::getTexture() const { return m_texture; }

SDL_Surface *Image::getSurface() const { return m_surface; }

void Image::setSurface(SDL_Surface *surf) { m_surface = surf; }

// ============= CLASS SDLJEU =============== //

AffichageSDL::AffichageSDL()
{

    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
        cout << "No sound !!!" << endl;
        // SDL_Quit();exit(1);
        avec_son = false;
    }
    else
        avec_son = true;

    // Creation de la fenetre
    fenetre = SDL_CreateWindow("Crazy Monkey", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, jungle.get_dimx(), jungle.get_dimy(), SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (fenetre == nullptr)
    {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);

    // IMAGES
    im_singe.telecharger_fichier("data/img/singe.png", renderer);
    im_arbre.telecharger_fichier("data/img/arbre.png", renderer);
    im_serpent.telecharger_fichier("data/img/serpent.png", renderer);

    // FONTS
    police = TTF_OpenFont("data/fonts/Samson.ttf", 50);
    if (police == nullptr)
        police = TTF_OpenFont("../data/fonts/Samson.ttf", 50);
    if (police == nullptr)
    {
        cout << "Failed to load Samson.ttf! SDL_TTF Error: " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
    police_couleur.r = 0;
    police_couleur.g = 0;
    police_couleur.b = 0;

    // titre
    im_police.setSurface(TTF_RenderText_Solid(police, "Crazy Monkey", police_couleur));
    im_police.telecharger_apartir_surface_courante(renderer);

    // message perdu
    im_perdu.setSurface(TTF_RenderText_Solid(police, "Perdu!", police_couleur));
    im_perdu.telecharger_apartir_surface_courante(renderer);

    // Remplir l'écran de bleu ciel
    SDL_SetRenderDrawColor(renderer, 166, 223, 255, 255);
    SDL_RenderClear(renderer);
}

AffichageSDL::~AffichageSDL()
{
    if (avec_son)
        Mix_Quit();
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}

// dessine les images
void AffichageSDL::sdlAff()
{
    // Afficher le singe
    im_singe.dessiner(renderer, jungle.s.getpos().x - jungle.s.getrayon(), jungle.s.getpos().y - jungle.s.getrayon(), 2 * jungle.s.getrayon(), 2 * jungle.s.getrayon());
    // Afficher les arbres
    for (unsigned int i = 0; i < jungle.nb_arbre; i++)
    {
        im_arbre.dessiner(renderer, jungle.tab_arbre[i].getCentre().x - jungle.tab_arbre[i].getRayon(), jungle.tab_arbre[i].getCentre().y - jungle.tab_arbre[i].getRayon(), 2 * jungle.tab_arbre[i].getRayon(), 2 * jungle.tab_arbre[i].getRayon());
        // Afficher le serpent (si y en a un)
        if (jungle.tab_arbre[i].getSerpent())
            im_serpent.dessiner(renderer, jungle.tab_arbre[i].getCentre().x - jungle.tab_arbre[i].getRayon() + 50, jungle.tab_arbre[i].getCentre().y - jungle.tab_arbre[i].getRayon() - 45, 60, 60);
    }
    // Titre du jeu
    SDL_Rect positionTitre({70, 0, 200, 60});
    SDL_RenderCopy(renderer, im_police.getTexture(), nullptr, &positionTitre);

    // Message perdu
    if (jungle.temps_partie == 0)
    {
        SDL_Rect positionTitre({(int)jungle.dimx / 2 - 75, (int)jungle.dimy / 2 - 50, 300, 120});
        SDL_RenderCopy(renderer, im_perdu.getTexture(), nullptr, &positionTitre);
    }
}

Uint32 chrono_callback(Uint32 interval, void *param)
{
    int *chrono = (int *)param;
    (*chrono)--;
    return interval;
}

void AffichageSDL::sdlBoucle()
{

    SDL_Event events;
    double angle;
    bool quit = false;
    jungle.temps_partie = 5;
    chrono_id = SDL_AddTimer(1000, chrono_callback, &jungle.temps_partie);

    // tant que ce n'est pas la fin ...
    while (!quit)
    {
        // tant qu'il y a des évenements à traiter (cette boucle n'est pas bloquante)

        SDL_RenderClear(renderer);
        sdlAff();

        // affiche le chronomètre en noir, et s'il reste moins que 10sec en rouge
        if (jungle.temps_partie < 10)
            chrono_couleur = {255, 0, 0};
        string temps_partie_str = to_string(jungle.temps_partie);
        im_chrono.setSurface(TTF_RenderText_Solid(police, temps_partie_str.c_str(), chrono_couleur));
        im_chrono.telecharger_apartir_surface_courante(renderer);
        im_chrono.dessiner(renderer, jungle.dimx / 2, 10, 120, 60);

        // quand le temps est fini, le chronomètre reste à 1 et ne part pas au négatif
        if (jungle.temps_partie <= 0)
        {
            jungle.temps_partie = 0;
            SDL_RemoveTimer(chrono_id);
        }

        while (SDL_PollEvent(&events))
        {

            if (events.type == SDL_QUIT)
                quit = true;
            switch (events.type)
            {
            case SDL_KEYDOWN:
                switch (events.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    quit = true;
                    break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (jungle.temps_partie > 0)
                {
                    if (jungle.get_etat() == 0)
                    {

                        angle = jungle.s.calculeAlpha(make_vec2(events.button.x, events.button.y));
                        cout << angle << " marche" << endl;
                        jungle.etat = 1;
                    }
                }
                // SDL_RenderClear(renderer);
                // sdlAff();
                break;
            }
        }

        if (jungle.get_etat() == 1)
        {
            double t = 0;
            double dt = 0.1;
            SDL_RenderClear(renderer);
            do
            {

                t += dt;
                // calcule le mouvement parabolique

                jungle.s.set_pos(jungle.s.calcule_pos(angle, t));

                SDL_RenderClear(renderer);
                sdlAff();
                SDL_RenderPresent(renderer);

            } while ((!jungle.collisionsol()) || (!jungle.collisionarbre()) || (jungle.temps_partie > 0));
        }

        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }
}