#include <iostream>
#include "Serpent.h"

using namespace std; 

Serpent::Serpent() {

    position = make_vec2(0,0);
}

Serpent::Serpent(Vec2 p) {
    position = p ; 
}


Vec2 Serpent::getPosition() const {
    return position; 
}

void Serpent::setPosition(Vec2 p) {
    position = p;
}

double Serpent::getRayon()const
{
    return rayon;
}

void Serpent:: setRayon(double r)
{
    rayon=r;
}