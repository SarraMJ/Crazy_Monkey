#include <iostream>
#include "Singe.h"
#include <math.h>

using namespace std;


Singe::Singe(unsigned int viesInit, Vec2 p, unsigned int vitesseInit,float r, float gr) {
    nb_vie = viesInit;
    nb_vie_init= viesInit;
    pos_init=p;
    position = pos_init;
    v0 = vitesseInit;
    rayon=r;
    g=gr;

}

Singe::~Singe() {

}

unsigned int Singe::get_nb_vie() const {
return nb_vie;
}

Vec2 Singe::getpos()const {
    return position;
}

unsigned int Singe::get_v0() const {
    return v0;
}

void Singe::set_nb_vie(unsigned int nb) {
    nb_vie = nb;
}


float Singe::to_rad(float deg)const {
    return M_PI*deg/180.f;
}

float Singe::calculeX(float angle, float t) {
    return cos(angle)*v0* t;
}

float Singe::calculeY(float angle, float t) {
    return -0.5*9.81*t*t+sin(angle)*v0* t; // + hauteur ? 
}


