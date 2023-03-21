#include <iostream>

#ifdef _MSC_VER
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "AffichageTxt.h"

using namespace std;

void txtAff(WinTXT & win, Jungle &j)
{

    win.clear();
    // Affichage du singe
    win.print(j.get_singe().getpos().x, j.get_singe().getpos().y, 'S');
    win.print(j.get_curseur().x, j.get_curseur().y, '*');
    for (unsigned int  i=0 ; i< j.get)
    win.draw();
}

void txtAff2(WinTXT & win,  Jungle &j)
{

    win.clear();
    // Affichage du singe
    win.print(j.get_singe().getpos().x, j.get_singe().getpos().y, 'S');
    win.draw();
}


void collisiontxt(Jungle &j, double angle, double t, WinTXT & win)
{

    double dt = 0.1;
    //Singe si;
    do
    {
        t += dt;
        //calcule le mouvement parabolique
       // si.set_pos(j.get_singe().calcule_pos(angle, t));
        //j.set_singe(si);
       

        j.get_singe().set_pos(j.get_singe().calcule_pos(angle, t));  //get singe rend une copie du singe, et quand j'ai modifié pour rendre le singe après les .set() ne marchent pas 
        
        cout<<"Position singe x : "<<j.get_singe().getpos().x<<" et y :"<<j.get_singe().getpos().y<<endl;


        txtAff2(win, j);

        #ifdef _MSC_VER
        Sleep(100);
        #else
        usleep(100000);
        #endif
        cout << endl; 


        if (j.get_singe().getpos().y >=j.get_dimy())
        {
            j.get_singe().set_nb_vie(j.get_singe().get_nb_vie() - 1);
            j.setCollision_sol(true);
        }
    } while (!j.getCollision_sol());
    t = 0;

    if (j.getCollision_sol())
    {
        cout << "Perdu!" << endl;
    }
    j.set_etat(0);
}

void txtBoucle(Jungle &j)
{
    // Creation d'une nouvelle fenetre en mode texte

    WinTXT win(j.get_dimx(), j.get_dimy());

    bool ok = true;
    int c;
    double t = 0;
    double angle;

    do
    {

        txtAff(win, j);
        #ifdef _MSC_VER
        Sleep(100);
        #else
        usleep(100000);
        #endif
        cout << endl;

       

        cout << "Tapez h : bouge curseur vers le haut ; Tapez b : bouge curseur vers le bas ; Tapez e: valider"<<endl;
        //cout<<"Pour bouger votre curseur vers le haut tapez h."<< endl;
        //cout<<"Pour bouger valider, tapez e."<< endl;

        angle = j.get_singe().calculeAlpha(j.get_curseur());
        cout << "angle : " << angle << endl;
        if (j.getCollision_sol())
        {
            cout << "Perdu!" << endl;

        }
        c = win.getCh();
        switch (c)
        {
        case 'h':
            if (j.get_etat() == 0)
                j.set_curseur(make_vec2(j.get_curseur().x, j.get_curseur().y - 1));
            break;
        case 'b':
            if (j.get_etat() == 0)
                j.set_curseur(make_vec2(j.get_curseur().x, j.get_curseur().y + 1));
            break;
        case 'e':
            j.set_etat(1);
            collisiontxt(j, angle, t, win);
            break;
        case 'q':
            ok = false;
            break;
        }

    } while (ok);
}
