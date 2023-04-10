#include <iostream>

#ifdef _MSC_VER
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "AffichageTxt.h"

using namespace std;


AffichageTxt::AffichageTxt()
{
    WinTXT w(30, 30);
    win = w;  
}

void AffichageTxt:: txtAff(const Jungle &j)
{

    win.clear();
    // Affichage du singe
    //win.print(j.s.getpos().x, j.s.getpos().y, 'S');
    win.print(j.s.getpos().x, j.s.getpos().y, 'S');
    win.print(j.curseur.x, j.curseur.y, '*');
   for (unsigned int i=0 ; i< j.nb_arbre;i++)
    {
        win.print(j.tab_arbre[i].getCentre().x,j.tab_arbre[i].getCentre().y,'A');
    } 
    win.draw();
}

void AffichageTxt:: txtAff2(const Jungle &j)
{
    win.clear();
    // Affichage du singe
    win.print(j.s.getpos().x, j.s.getpos().y, 'S');
    //win.print(j.s.getpos().x, j.s.getpos().y, 'S');
    for (unsigned int i=0 ; i< j.nb_arbre;i++)
    {
        win.print(j.tab_arbre[i].getCentre().x,j.tab_arbre[i].getCentre().y,'A');
    } 
    win.draw();
}


void AffichageTxt:: collisiontxt(Jungle &j, double angle, double t)
{

    double dt = 0.1;
    //Singe si;
    do
    {
        t += dt;
        //calcule le mouvement parabolique
       // si.set_pos(j.s.calcule_pos(angle, t));
        //j.set_singe(si);
       

        j.s.set_pos(j.s.calcule_pos(angle, t));  //get singe rend une copie du singe, et quand j'ai modifié pour rendre le singe après les .set() ne marchent pas 
        
        cout<<"Position singe x : "<<j.s.getpos().x<<" et y :"<<j.s.getpos().y<<endl;


        txtAff2(j);

        #ifdef _MSC_VER
        Sleep(100);
        #else
        usleep(100000);
        #endif
        cout << endl; 


        if (j.s.getpos().y >=j.dimy)
        {
            j.s.set_nb_vie(j.s.get_nb_vie() - 1);
            j.collision_sol=true;
        }
    } while (!j.collision_sol);
    t = 0;

    if (j.collision_sol)
    {
        cout << "Perdu!" << endl;
    }
    j.set_etat(0);
}

void AffichageTxt::txtBoucle(Jungle &j)
{
    // Creation d'une nouvelle fenetre en mode texte

    WinTXT win(j.get_dimx(), j.get_dimy());

    bool ok = true;
    int c;
    double t = 0;
    double angle;

    do
    {

        txtAff(j);
        #ifdef _MSC_VER
        Sleep(100);
        #else
        usleep(100000);
        #endif
        cout << endl;

       

        cout << "Tapez h : bouge curseur vers le haut ; Tapez b : bouge curseur vers le bas ; Tapez e: valider"<<endl;
        //cout<<"Pour bouger votre curseur vers le haut tapez h."<< endl;
        //cout<<"Pour bouger valider, tapez e."<< endl;

        angle = j.s.calculeAlpha(j.curseur);
        cout << "angle : " << angle << endl;
        if (j.collision_sol)
        {
            cout << "Perdu!" << endl;

        }
        c = win.getCh();
        switch (c)
        {
        case 'h':
            if (j.etat == 0)
                j.curseur= (make_vec2(j.curseur.x, j.curseur.y - 1));
            break;
        case 'b':
            if (j.etat == 0)
                j.curseur= (make_vec2(j.curseur.x, j.curseur.y + 1));
            break;
        case 'e':
            j.etat=1;
            collisiontxt(j, angle, t);
            break;
        case 'q':
            ok = false;
            break;
        }

    } while (ok);
}
