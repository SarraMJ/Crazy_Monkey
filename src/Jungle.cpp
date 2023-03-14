#include <iostream>
#include "Jungle.h"

using namespace std;


Jungle::Jungle(unsigned int x, unsigned int y, Arbre * a, unsigned int nbs, unsigned int nba, float temps, const Singe & sin, int e) {
    dimx = x;
    dimy = y;
    tab_arbre = a;
    nb_serpent = nbs;
    nb_arbre = nba;
    temps_partie = temps;
    s = sin;
    etat = e;
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


void Jungle::collision(double angle, double t) {

    bool collision_arbre = false;
    bool collision_sol;
    do {

        
        s.set_pos(s.calcule_pos(angle, t));

        for (unsigned int i = 0; i < nb_arbre; i++) {
             if (distance(s.getpos(), tab_arbre[i].getCentre()) <= (s.getrayon() + tab_arbre[i].getRayon())) {
                Vec2 pos_init = make_vec2(tab_arbre[i].getCentre().x, tab_arbre[i].getCentre().y + tab_arbre[i].getRayon() + s.getrayon());
                s.set_pos_init(pos_init);
                collision_arbre = true;
             }
            
        }

        if (distance(s.getpos(), make_vec2(s.getpos().x, 0)) <= s.getrayon()) {
            s.set_nb_vie(s.get_nb_vie() - 1);
            collision_sol = true;

        }
    }
    while (!collision_arbre || !collision_sol);

    if (collision_arbre) {
        for (unsigned int i = 0; i < nb_arbre; i++) {
             if (tab_arbre[i].getSerpent()) 
                s.set_nb_vie(s.get_nb_vie() - 1);
              if (tab_arbre[i].getBanane_magique()) {
                if (s.get_nb_vie() == 4)
                    temps_partie += 10; 
                else s.set_nb_vie(s.get_nb_vie() + 1);
                }
             }
    }

    if (collision_sol) {
        cout<<"Perdu!"<<endl;
    }

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
    window = SDL_CreateWindow("Module Image", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    SDL_RenderClear(renderer);

      SDL_Surface* surface = IMG_Load("data/singe.png");
    if (surface == NULL) {
        printf("Erreur lors du chargement de l'image: %s\n", IMG_GetError());
        exit(1);
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (texture == NULL) {
        printf("Erreur lors de la conversion de la surface en texture: %s\n", SDL_GetError());
        exit(1);
    }


}



void Jungle::afficherBoucle() {
    
    SDL_Event events;
    double angle;
	bool quit = false; 

    // Chargement des images
    //const char * image_singe = "data/singe.png";


    // tant que ce n'est pas la fin ...
	while (!quit) {


		// tant qu'il y a des évenements à traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events)) {
			if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
			else if (events.type == SDL_MOUSEBUTTONDOWN) {    

                        angle = s.calculeAlpha(make_vec2( events.button.x, events.button.y));
			}
		}


		//affiche
        SDL_Rect rect = { s.getpos_init().x - s.getrayon(), s.getpos().y -  s.getrayon(), s.getrayon(), s.getrayon() };

        SDL_RenderCopyEx(renderer,texture, NULL, &rect, 0, NULL, SDL_FLIP_NONE);
        
      /*      // Création d'une texture de cercle pour le masque
    SDL_Texture* circleMask = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                                                 SDL_TEXTUREACCESS_TARGET,
                                                 dimx, dimy);
    SDL_SetRenderTarget(renderer, circleMask);

    // Dessin du cercle sur la texture de cercle
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    for (unsigned int y = 0; y < dimy; y++) {
        for (unsigned int x = 0; x < dimx; x++) {
            int dx = x - s.getpos().x ;
            int dy = y - s.getpos().y;
            if (sqrt(dx*dx + dy*dy) <= s.getrayon()) {
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }
    */


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

void Jungle::afficher() {
    afficherInit();
    afficherBoucle();
    afficherDetruit();
}


