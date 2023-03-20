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
    curseur = make_vec2(s.getpos().x + 5, s.getpos().y);
    collision_arbre =false;
    collision_sol = false; 
}
   

Jungle::Jungle(unsigned int x, unsigned int y, Arbre * a, unsigned int nbs, unsigned int nba, float temps, const Singe & sin, int e, Vec2 curs, bool ca, bool cs) {
    dimx = x;
    dimy = y;
    tab_arbre = a;
    nb_serpent = nbs;
    nb_arbre = nba;
    temps_partie = temps;
    s = sin;
    etat = e;
    curseur = curs;
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

Singe Jungle::get_singe()  const{
    return s;
}

int Jungle::get_etat() const {
    return etat;
}

bool Jungle::getCollision_arbre() const {
    return collision_arbre;
}

bool Jungle::getCollision_sol() const {
    return collision_sol;
}

Vec2 Jungle::get_curseur() const {
    return curseur;
}

void Jungle::set_singe(const  Singe & sin) {
    s = sin;
}

void Jungle::set_etat(int e) {
    etat = e;
}

void Jungle::setCollision_arbre(bool a) {
    collision_arbre = a;
}

void Jungle::setCollision_sol(bool c) {
    collision_sol = c;
}

void Jungle::set_curseur(Vec2 c) {
    curseur = c;
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

void Jungle::colSol() {
    if (s.getpos().y <= 0) {
            s.set_nb_vie(s.get_nb_vie() - 1);
            collision_sol = true;

        }
        if (collision_sol) {
        cout<<"Perdu!"<<endl;
    }

}

void Jungle::posi(double angle, double t, double dt) {

    t += dt;
        //calcule le mouvement parabolique
        s.set_pos(s.calcule_pos(angle, t));
}

void Jungle::collisiontxt(double angle, double t) {

    double dt = 0.01;
    do {
        t += dt;
        //calcule le mouvement parabolique
        s.set_pos(s.calcule_pos(angle, t));
        
       
        if (s.getpos().y <= 0) {
            s.set_nb_vie(s.get_nb_vie() - 1);
            collision_sol = true;

        }
    } while (!collision_sol); //!collision_arbre ||
    t = 0;


    if (collision_sol) {
        cout<<"Perdu!"<<endl;
    }
    etat = 0;

}
