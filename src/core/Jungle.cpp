#include <iostream>
#include "Jungle.h"

using namespace std;


Jungle::Jungle()
{   
    Singe singe;

    dimx = 1000;
    dimy = 800;
    tab_arbre = new Arbre[4];
    nb_serpent =1;
    nb_arbre = 4;
    tab_arbre[0].setCentre(make_vec2(s.getpos().x+400,s.getpos().y+100));
    for (unsigned int i=1; i< nb_arbre; i++)
    {   
        tab_arbre[i].setCentre(make_vec2((tab_arbre[i-1].getCentre().x+400),tab_arbre[i-1].getCentre().y));
    }
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

Singe Jungle::get_singe() const {
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

unsigned int Jungle::get_nb_arbre()const
{
    return nb_arbre;
}

void Jungle::set_singe(const  Singe & sin) {
    s = sin;
}
void Jungle::set_dimx(unsigned int x)
{
    dimx=x;
}
void Jungle::set_dimy(unsigned int y)
{
    dimy=y;
}

void Jungle::set_nb_arbre(unsigned int nb)
{
    nb_arbre=nb;
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

void Jungle::collision(double angle) {

    double t = 0;
    double dt = 0.1;

    do {

        t += dt;
        //calcule le mouvement parabolique
        
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



bool Jungle::collisionsol() {
   
    if (distance(s.getpos(), make_vec2(s.getpos().x, dimy)) <= s.getrayon())
                    {
                        s.set_nb_vie(s.get_nb_vie() - 1);
                        cout<<"collision détéctée avec le sol"<<endl;
                        etat = 0;
                         s.set_pos_init(s.getpos());
                         return true;
                        
                    }
    return false;
}

bool Jungle::collisionarbre() {

    Vec2 arbre_cote_gauche_haut;
    Vec2 arbre_cote_droit_bas;
    Vec2 singe_cote_gauche_haut =  make_vec2(s.getpos().x  - s.getrayon(), s.getpos().y - s.getrayon());

    Vec2 singe_cote_droit_bas = make_vec2(s.getpos().x  + s.getrayon(), s.getpos().y + s.getrayon());


     for (unsigned int i = 0; i < nb_arbre; i++) {

        arbre_cote_gauche_haut = make_vec2(tab_arbre[i].getCentre().x - tab_arbre[i].getRayon(), tab_arbre[i].getCentre().y - tab_arbre[i].getRayon());
        arbre_cote_droit_bas = make_vec2(tab_arbre[i].getCentre().x + tab_arbre[i].getRayon(), tab_arbre[i].getCentre().y + tab_arbre[i].getRayon());
        if ( (singe_cote_gauche_haut.x <= arbre_cote_droit_bas.x) && (singe_cote_droit_bas.x >= arbre_cote_gauche_haut.x) && (singe_cote_droit_bas.y >= arbre_cote_gauche_haut.y ) && (singe_cote_gauche_haut.y <= arbre_cote_droit_bas.y)) {
            etat = 0;
            s.set_pos_init(s.getpos());
            cout<<"collision détectée avec l'arbre "<<i<<endl;
            return true;
        }
           
    }
    return false;
}

/*

     for (unsigned int i = 0; i < nb_arbre; i++) {
                        if (distance(s.getpos(), tab_arbre[i].getCentre()) <= ( s.getrayon() + tab_arbre[i].getRayon()) )
                    {
                        etat = 0;
                        s.set_pos_init(s.getpos());
                        cout<<"collision détectée avec l'arbre"<<endl;
                        return true;
                    }
        }
*/