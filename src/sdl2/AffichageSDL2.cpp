
#include <iostream>
#include <cassert>
#include <time.h>
#include <stdlib.h>
#include"AffichageSDL2.h" 

using namespace std; 

float temps () {
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC;  // conversion des ms en secondes en divisant par 1000
}

// ============= CLASS IMAGE =============== //

Image::Image () : m_surface(nullptr), m_texture(nullptr), m_a_change(false) {
}

Image::~Image()
{
    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);

    m_surface = nullptr;
    m_texture = nullptr;
    m_a_change = false;
}

void Image::telecharger_fichier (const char* filename, SDL_Renderer * renderer) {
    m_surface = IMG_Load(filename);
    if (m_surface == nullptr) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        m_surface = IMG_Load(nfn.c_str());
        if (m_surface == nullptr) {
            nfn = string("../") + nfn;
            m_surface = IMG_Load(nfn.c_str());
        }
    }
    if (m_surface == nullptr) {
        cout<<"Error: cannot load "<< filename <<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(m_surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(m_surface);
    m_surface = surfaceCorrectPixelFormat;

    m_texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (m_texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::telecharger_apartir_surface_courante (SDL_Renderer * renderer) {
    m_texture = SDL_CreateTextureFromSurface(renderer,m_surface);
    if (m_texture == nullptr) {
        cout << "erreur:probleme de création de la texture à partir de la surface " << endl; 
        SDL_Quit();
        exit(1);
    }
}

void Image::dessiner (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = (h<0)?m_surface->h:h;

    if (m_a_change) {
        ok = SDL_UpdateTexture(m_texture,nullptr,m_surface->pixels,m_surface->pitch);
        assert(ok == 0);
        m_a_change = false;
    }

    ok = SDL_RenderCopy(renderer,m_texture,nullptr,&r);
    assert(ok == 0);
}

SDL_Texture * Image::getTexture() const {return m_texture;}

void Image::setSurface(SDL_Surface * surf) {m_surface = surf;}


// ============= CLASS SDLJEU =============== //




AffichageSDL::AffichageSDL() {


        //Initalisation jungle avec les bonnes dimensions
        //Singe s;
        //s.set_pos_init(make_vec2(150,150));
        //s.setrayon(40);
        //jungle.set_singe(s);
        jungle.set_dimx(800);
        jungle.set_dimy(800);
        //jungle.s.set_pos(make_vec2(100,400));
        //jungle.s.setrayon(70);


    
       // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
        cout << "No sound !!!" << endl;
        //SDL_Quit();exit(1);
        avec_son = false;
    }
    else avec_son = true;

    // Creation de la fenetre
    fenetre = SDL_CreateWindow("Crazy Monkey", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, jungle.get_dimx(), jungle.get_dimy(), SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (fenetre == nullptr) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

    renderer = SDL_CreateRenderer(fenetre,-1,SDL_RENDERER_ACCELERATED);

    // IMAGES
    im_singe.telecharger_fichier("data/singe.png",renderer);
    im_arbre.telecharger_fichier("data/arbre.png", renderer);

    //Remplir l'écran de bleu ciel
    SDL_SetRenderDrawColor(renderer, 166,223,255,255);
    SDL_RenderClear(renderer);


}


AffichageSDL::~AffichageSDL() {
    if (avec_son) Mix_Quit();
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}

//dessine les images
void AffichageSDL::sdlAff()
{
    
    im_singe.dessiner(renderer, jungle.s.getpos().x - jungle.s.getrayon(), jungle.s.getpos().y - jungle.s.getrayon(), jungle.s.getrayon(), jungle.s.getrayon());
    for (unsigned int i = 0; i <jungle.nb_arbre; i++) {
        im_arbre.dessiner(renderer, jungle.tab_arbre[i].getCentre().x - jungle.tab_arbre[i].getRayon(), jungle.tab_arbre[i].getCentre().y - jungle.tab_arbre[i].getRayon(), jungle.tab_arbre[i].getRayon(), jungle.tab_arbre[i].getRayon());

    }
}


void AffichageSDL::sdlBoucle()
{

    SDL_Event events;
    double angle;
    bool quit = false;

    // tant que ce n'est pas la fin ...

    while (!quit)
    {
        // tant qu'il y a des évenements à traiter (cette boucle n'est pas bloquante)
    
        SDL_RenderClear(renderer);
        sdlAff();
        while (SDL_PollEvent(&events))
        {

            if (events.type == SDL_QUIT)
                quit = true;
            switch (events.type)
            {
            case SDL_KEYDOWN :
                switch (events.key.keysym.sym) 
                {
                case SDLK_ESCAPE:
                    quit = true;
                    break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN :
                if (jungle.get_etat() == 0) {
                        
                        angle = jungle.s.calculeAlpha(make_vec2(events.button.x, events.button.y));
                        cout << angle << " marche" << endl;
                        jungle.etat = 1;
                    }
               // SDL_RenderClear(renderer);
                //sdlAff();
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
                
                     

                } while (!jungle.collisionsol() || (!jungle.collisionarbre())) ;
                
                   
            }
            
            SDL_RenderPresent(renderer);
            SDL_RenderClear(renderer);
        }
        

    
}


/*
void AffichageSDL::sdlBoucle()
{

    SDL_Event events;
    double angle;
    bool quit = false;

    // tant que ce n'est pas la fin ...

    while (!quit)
    {
        // tant qu'il y a des évenements à traiter (cette boucle n'est pas bloquante)
    
        while (SDL_PollEvent(&events))
        {

            if (events.type == SDL_QUIT)
                quit = true;

           if (jungle.get_etat() == 0) 
           {
                 if (events.type == SDL_MOUSEBUTTONDOWN)
                {
                    //if (jungle.get_etat() == 0) {
                        angle = jungle.s.calculeAlpha(make_vec2(events.button.x, events.button.y));
                        cout << angle << "marche" << endl;
                        jungle.set_etat(1);
                    //}
                    
                }
                SDL_RenderClear(renderer);
                sdlAff();
                
            }
            else if (jungle.get_etat() == 1)
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
                    
                    if (distance(jungle.s.getpos(), make_vec2(jungle.s.getpos().x, jungle.dimy)) <= jungle.s.getrayon())
                    {
                        jungle.s.set_nb_vie(jungle.s.get_nb_vie() - 1);
                        jungle.collision_sol = true;
                    }
                } while (!jungle.collision_sol);
                
                    
                    
            }
            
            SDL_RenderPresent(renderer);
            SDL_RenderClear(renderer);
        }
        

    }
}

*/ 

