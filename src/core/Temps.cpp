#include <iostream>
#include "Temps.h"

using namespace std;

Temps::Temps() {
    min = 0;
    sec = 0;
}

Temps::Temps(unsigned int m, unsigned int s) {
    min = m ;
    sec = s;
}

unsigned int Temps::getMin() const{
    return min;
}

unsigned int Temps::getSec() const{
    return sec;
}

void Temps::setSec(unsigned int s) {
    sec = s;
}

void Temps::setMin(unsigned int m) {
    min = m;
}
