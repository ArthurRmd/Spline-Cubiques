#ifndef INTERFACE
#define INTERFACE

#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

typedef SDL_Colour Couleur;

static SDL_Window *fenetre=NULL;
static SDL_Renderer* afficheur=NULL;

//static int hauteur,largeur;

static const Couleur blanc={255,255,255,255};
static const Couleur bleu={0,0,255,255};
static const Couleur cyan={0,255,255,255};
static const Couleur gris={120,120,120,255};
static const Couleur jaune={255,255,0,255};
static const Couleur noir={0,0,0,255};
static const Couleur orange={255,165,0,255};
static const Couleur rouge={255,0,0,255};
static const Couleur vert={0,255,0,255};
static const Couleur violet={255,0,255,255};

static Couleur couleur_fond=noir;
static Couleur couleur_dessin=blanc;

// Initialise l'interface  avec une fenetre
// de largeur l et une hauteur h
void initialise_interface(int l,int h);

// Defini la couleur pour dessiner
void defini_couleur_dessin(Couleur c);

// Dessine une ligne (x1,y1) -- (x2,y2)
void dessine_ligne(int x1,int y1,int x2,int y2);

// Dessine un rectangle de largeur l et de hauteur h
// Le coint inferieur gauche est en (x,y)
void dessine_rectangle(int x,int y,int l,int h);

// Efface toute la fenêtre
void efface();

// Fermer l'interface
void ferme_interface();

// Rafraichi la fenêtre (double-buffering)
void rafraichissement();

// Dessine un rectangle rempli de largeur l et de hauteur h
// Le coint inferieur gauche est en (x,y)
void rempli_rectangle(int x,int y,int w,int h);




#endif
