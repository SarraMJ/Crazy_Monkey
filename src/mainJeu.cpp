#include <iostream>
#include "Jungle.h"

using namespace std;

int main() {
    
    float temps = 90;
    Arbre * tab = new Arbre[6];
    Singe sin;
    Jungle j(500, 500, tab, 6, 1, temps, sin, 0);
    j.afficher();
}