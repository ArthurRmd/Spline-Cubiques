#include "point.hpp"

/// La constante taille existe et est fixée dans le fichier point.hpp

//-------------------------
// Exercice 3 - Question a
//-------------------------

void
Point::dessine(){
    double X = x;
    double Y = y;
    defini_couleur_dessin(cyan);
    dessine_rectangle(X-taille,Y-taille,2*taille+1,2*taille+1);
}

//-------------------------
// Exercice 3 - Question b
//-------------------------

bool
Point::est_proche(int cx,int cy){
    if((x+(2*taille+1))>cx && (x-(2*taille+1))<cx && (y+(2*taille+1))>cy && (y-(2*taille+1))<cy){
        cout<<"proche"<<endl;
        return true;
    } else {
        cout<<"pas proche"<<endl;
        return false;
    }
}
