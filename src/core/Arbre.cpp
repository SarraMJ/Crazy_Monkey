#include <iostream>
#include "Arbre.h" 

using namespace std; 

Arbre::Arbre() {
    banane_magique = false;
    coffret_bananes = false;
    serpent = false;
    centre = make_vec2(200,500);
    rayon =  100; 
}

Arbre::Arbre(bool m, bool c, bool s, Vec2 cen, int r) {
    banane_magique = m;
    coffret_bananes = c;
    serpent = s;
    centre = cen;
    rayon = r;
}




bool Arbre::getBanane_magique() const {
    return banane_magique;
}


bool Arbre::getCoffret_bananes() const {
    return coffret_bananes;
}

bool Arbre::getSerpent() const {
    return serpent;
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
