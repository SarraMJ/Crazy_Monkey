#include <iostream>
#include "Jungle.h"

using namespace std;

int main() {
    
    float temps = 90;
    Arbre * tab = new Arbre[6];
    Singe sin(4, make_vec2(80,250), 10, 70, 9.81);
    Jungle j(800, 800, tab, 6, 1, temps, sin, 0);
    j.afficher();
}