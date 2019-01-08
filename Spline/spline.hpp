#ifndef SPLINE_HPP
#define SPLINE_HPP
#include "polynome.hpp"
#include "matrice.hpp"
#include "interface.hpp"
#include "point.hpp"

#define POINTS_MAX 20

enum StatutSpline{EnConstruction,Statique,Dynamique};

class Spline{
private:
    //! Points de controle de la spline
    Point P[POINTS_MAX+1];

    //! Nombre de points de controle utilisé
    size_t n;

    //! Polynomes décrivants la spline
    Polynome q[POINTS_MAX+1];
    Polynome r[POINTS_MAX+1];

    //! Inverse de la matrice A
    Matrice Ainverse;

    //! Point de controle selectionne. Vaut -1 si aucun point séléctionne.
    int point_selectionne;

    //! Statut de la spline
    StatutSpline statut;

public:
    //! Constructeur de la spline
    Spline();

    //! Retourne le statut de la spline
    StatutSpline lire_statut();

    //! Ajoute un point de controle a la spline
    void ajoute_point(int x,int y);

    //! Dessine les points de controle de la spline
    void dessine_points();

    //! Calcule la matrice inverse de A
    void calcule_Ainverse();

    //! Calcule la spline
    void calcule();

    //! Dessine la spline
    void dessine_spline();

    //! Dessine les points de controles et la spline
    void dessine();

    //! Remet la spline dans son etat initial
    void reset();

    //! Permet de selectionner un point
    void selectionne_point(int x,int y);

    //! Deplace le point sectionne
    void deplace_point(int x,int y);

    //! Arrete le deplacement du point
    void fin_deplacement();
};

#endif
