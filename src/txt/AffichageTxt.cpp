#include <iostream>

#ifdef _MSC_VER
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "AffichageTxt.h"

void txtAff(WinTXT & win, const Jungle & j) {
    const Singe& sin=j.get_singe();

    win.clear();
    //Affichage du singe
    win.print(j.get_singe().getpos().x, j.get_singe().getpos().y, 'S');
    win.print(j.get_curseur().x, j.get_curseur().y, '*');
    win.draw();
}



void txtBoucle(const Jungle & j) {
    //Creation d'une nouvelle fenetre en mode texte
    WinTXT win(j.get_dimx(), j.get_dimy());

    bool ok = true;
    int c;
    double angle, t;

    do {
        txtAff(win, j);

        #ifdef _MSC_VER
        Sleep(100);
        #else
        usleep(1000000);
        #endif 
        
        //j.collision(angle, t);

        c = win.getCh();
		switch (c) {
			case '72':
				j.set_curseur(make_vec2(j.get_curseur().x, j.get_curseur().y+5));
				break;
			case '80':
				j.set_curseur(make_vec2(j.get_curseur().x, j.get_curseur().y-5));
				break;
			case 'q':
				ok = false;
				break;
		}

    } while (ok);
}
