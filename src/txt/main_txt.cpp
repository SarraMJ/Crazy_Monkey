
#include "AffichageTxt.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    termClear();
    Jungle ji;
    AffichageTxt AF;
    AF.txtBoucle(ji);
    termClear();
    return 0;
}