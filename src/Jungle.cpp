#include <iostream>
#include "Jungle.h"

using namespace std;


Jungle::Jungle()
{   
    Singe singe;

    dimx = 800;
    dimy = 800;
    tab_arbre = new Arbre[6];
    nb_serpent =1;
    nb_arbre = 6;
    temps_partie =90;
    s = singe;
    etat = 0;
    collision_arbre =false;
    collision_sol = false; 
}
   

Jungle::Jungle(unsigned int x, unsigned int y, Arbre * a, unsigned int nbs, unsigned int nba, float temps, const Singe & sin, int e, bool ca, bool cs) {
    dimx = x;
    dimy = y;
    tab_arbre = a;
    nb_serpent = nbs;
    nb_arbre = nba;
    temps_partie = temps;
    s = sin;
    etat = e;
    collision_arbre = ca;
    collision_sol = cs; 
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


    do {

        //calcule le mouvement parabolique
        s.set_pos(s.calcule_pos(angle, t));
        cout << s.getpos().x << " " << s.getpos().y << endl;
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
             if (tab_arbre[i].getSerpent() != nullptr) {
                if (distance(tab_arbre[i].getSerpent()->getPosition(), s.getpos()) <= s.getrayon() + tab_arbre[i].getSerpent()->getRayon())
                    s.set_nb_vie(s.get_nb_vie() - 1);
             } 
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
    etat = 0;

}



