
#include "AffichageTxt.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    termClear();
    float temps = 90;
    Arbre * tab = new Arbre[6];
    Singe sin(4, make_vec2(5,15), 2, 80, 9.81);
    Vec2 cur=make_vec2(sin.getpos().x+20,sin.getpos().y);
    Jungle j(30,30, tab, 6, 1, temps, sin, 0,cur, false, false);
    txtBoucle(j);
    termClear();
    return 0;
}