#ifndef POINT_HPP
#define POINT_HPP

#include "interface.hpp"

static const int taille=4;

class Point{
    /// Oui je sais on vous à dit de faire des accesseurs pour les données membres d'une classe
    /// Ici Point est plus une structure C qu'une classe à proprement parler :-)
public:
    double x,y;

    //! Dessine un point à l'écran
    void dessine();

    //! Teste si le point courant est proche de (cx,cy)
    bool est_proche(int cx,int cy);
};

#endif
