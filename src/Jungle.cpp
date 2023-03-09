#include <iostream>
#include "Jungle.h"

using namespace std;


Jungle::Jungle(unsigned int x, unsigned int y, Arbre * a, unsigned int nb, const Singe & sin) {
    dimx = x;
    dimy = y;
    tab_arbre = a;
    nb_serpent = nb;
    s = sin;
}

Jungle::~Jungle() {
    
    if (tab_arbre != nullptr) {
        delete [] tab_arbre;
        tab_arbre =nullptr;
    }
    
}

unsigned int Jungle::get_dimx() const {
    return dimx;
 }

unsigned int Jungle::get_dimy() const {
    return dimy;
  }

  Arbre Jungle::getTab_arbre(unsigned int indice) const {
    return tab_arbre[indice];
 }

 unsigned int Jungle::getNb_serpent() const {
    return nb_serpent;
 }

Singe Jungle::get_singe() const {
    return s;
}

void Jungle::set_singe(const  Singe & sin) {
    s = sin;
}


void Jungle::afficherInit() {
if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }


    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
        // Creation de la fenetre
    window = SDL_CreateWindow("Module Image", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 200, 200, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    SDL_RenderClear(renderer);
}


void Jungle::afficherBoucle() {
    
    SDL_Event events;
	bool quit = false; 

    // tant que ce n'est pas la fin ...
	while (!quit) {


		// tant qu'il y a des évenements à traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events)) {
			if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
			else if (events.type == SDL_KEYDOWN) {              // Si une touche est enfoncee
				switch (events.key.keysym.scancode) {
				case SDL_SCANCODE_T:
					 {
                        zoom = zoom * 1.5;

                     }
					break;
				case SDL_SCANCODE_G:
					    {
                        zoom = zoom * 0.5; 
                       
                        }
					break;
                case SDL_SCANCODE_ESCAPE:
                    quit = true;

                    break;
				default: break;
				}
			}
		}

 
	
        float xcenter = ((200 - (dimx * zoom))/ 2); //calcule la coordonnée x du centre de l'image 
        float ycenter = ((200 - (dimy * zoom))/ 2); //calcule la coordonnée y du centre de l'image 
        for (unsigned int i = 0; i <dimx; i++) {
                            for (unsigned int j=0; j<dimy; j++) {
                                Pixel pi = getPix(i, j);
                                SDL_SetRenderDrawColor(renderer, pi.getRouge(), pi.getVert(), pi.getBleu(), 255);
                                SDL_Rect zoomy; 
                                zoomy.h = zoom;
                                zoomy.w = zoom;
                                zoomy.x = (float)(i*zoom+xcenter);
                                zoomy.y= (float)(j*zoom+ycenter);
                                SDL_RenderFillRect(renderer, &zoomy); 
                            }
                        }


		//affiche
        
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);

	}
}

void Jungle::afficherDetruit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}


