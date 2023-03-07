#include <iostream>
#include "Mouvement.h"

using namespace std;


Mouvement::Mouvement()
{
    vitesse=;

}













float to_degree(float rad)
{
    return 180.f * rad/M_PI;
}

float to_rad(float deg)
{
    return M_PI*deg/180.f;
}

Vec2 rotate(Vec2 p, float cx, float cy, float theta_deg)
{
    Vec2 rot = make_Vec2_expo( 1, to_rad(theta_deg));
    Vec2 tr = make_Vec2( cx, cy);
    return ((p-tr)*rot)+tr;
}
