#include "point.hpp"

/// La constante taille existe et est fixée dans le fichier point.hpp

//-------------------------
// Exercice 3 - Question a
//-------------------------

/// A VOIR
void
Point::dessine(){

    double X = x;
    double Y = y;
    defini_couleur_dessin(cyan);
   dessine_rectangle(X-taille,Y-taille,2*taille+1,2*taille+1);
   //dessine_rectangle(100,100,10,10);
}

//-------------------------
// Exercice 3 - Question b
//-------------------------

bool
Point::est_proche(int cx,int cy){

}
