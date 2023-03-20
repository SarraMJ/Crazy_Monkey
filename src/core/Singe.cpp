#include <iostream>
#include "Singe.h"
#include <math.h>

using namespace std;

Singe::Singe()
{   
    nb_vie_init= 4;
    nb_vie=nb_vie_init; 
    pos_init.x=5;
    pos_init.y=15;
    position = pos_init;
    v0=15;
    rayon=10;
    g=9.81;
}

Singe::Singe(unsigned int viesInit, Vec2 p, double r, double v, double gr) {
    nb_vie = viesInit;
    nb_vie_init= viesInit;
    pos_init=p;
    position = pos_init;
    rayon=r;
    v0 = v;
    g=gr;

}

unsigned int Singe::get_nb_vie() const {
return nb_vie;
}

Vec2 Singe::getpos()const {
    return position;
}

double Singe::get_v0() const {
    return v0;
}

unsigned int Singe::get_nb_vie_init() const
{
    return nb_vie_init;
}

 Vec2 Singe::getpos_init() const
 {
    return pos_init;
 }

 double Singe::getG()const
 {
    return g;
 }
 double Singe::getrayon()const{
    return rayon;
 }

void Singe::set_nb_vie(unsigned int nb) {
    nb_vie = nb;
}

void Singe::set_nb_vie_init(unsigned int nb)
{
    nb_vie_init=nb;
}

void Singe::set_g(double p)
{
    g=p;
}

void Singe::set_pos(const Vec2 & v)
{
    position= v;
}

void Singe::set_pos_init(const Vec2 &ve)
{
    pos_init=ve;
}

void Singe::setrayon(double r)
{
    rayon=r;
}

void Singe::set_v0(double v)
{
    v0=v;
}


Vec2 Singe::calcule_pos(double angle, double t) {
   Vec2 p;
    p.x= v0*cos(angle)*t + pos_init.x;
    p.y= (0.5*g*t*t-v0*sin(angle)*t+pos_init.y);
    return p;
}

double Singe::calculeAlpha(const Vec2 & pos_curseur) const
{
    double alpha;
    alpha= - atan((pos_curseur.y-pos_init.y)/(pos_curseur.x-pos_init.x));
    return alpha;
}

