#include <iostream>
#include "Jungle.h"

using namespace std;


Jungle::Jungle(){
    dimx = 500;
    dimy = 500; 
    tab_arbre = new Arbre[6];
    nb_serpent = 1;
    //il manque singe + revoir les valeurs de la jungle

}

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

