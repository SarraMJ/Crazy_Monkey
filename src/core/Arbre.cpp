#include <iostream>
#include "Arbre.h" 

using namespace std; 

Arbre::Arbre() {
    banane_magique = false;
    coffret_bananes = false;
    s = nullptr;
    centre = make_vec2(200,500);
    rayon =  150; 
}

Arbre::Arbre(bool m, bool c, Serpent * serpent, Vec2 cen, int r) {
    banane_magique = m;
    coffret_bananes = c;
    s = serpent;
    centre = cen;
    rayon = r;
}


Arbre::~Arbre() {
    if(s!= nullptr)
    {
        delete s;
        s=nullptr;
    } 
}

bool Arbre::getBanane_magique() const {
    return banane_magique;
}


bool Arbre::getCoffret_bananes() const {
    return coffret_bananes;
}

Serpent * Arbre::getSerpent() const {
    return s;
}

Vec2 Arbre::getCentre() const  {
    return centre;
}

int Arbre::getRayon() const {
    return rayon;
}

void Arbre:: setCentre(Vec2 v)
{
    centre=make_vec2(v.x,v.y);
}
