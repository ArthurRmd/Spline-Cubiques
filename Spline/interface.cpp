#include "interface.hpp"


void initialise_interface(int l,int h){
  // Initialise la SDL
  if(SDL_Init(SDL_INIT_VIDEO)<0){
    cout << "Erreur lors du chargement de la SDL : "<<SDL_GetError()<<endl;
    SDL_Quit();
    return;
  }

  // Crée la fenêtre et l'afficheur associé
  if(SDL_CreateWindowAndRenderer(l, h, 0, &fenetre, &afficheur)<0){
    cout <<"Erreur lors de la creation de la fenetre SDL : "<<SDL_GetError()<<endl;
    SDL_Quit();
    return;
  }

  // Efface la fenêtre
  efface();
  rafraichissement();
}

void defini_couleur_dessin(SDL_Colour c){
  couleur_dessin=c;
  SDL_SetRenderDrawColor(afficheur,c.r,c.g,c.b,SDL_ALPHA_OPAQUE);
}

void dessine_ligne(int x1,int y1,int x2,int y2){
  SDL_RenderDrawLine(afficheur,x1,y1,x2,y2);
}

void dessine_rectangle(int x,int y,int l,int h){
  SDL_Rect rect;
  rect.x=x;
  rect.y=y;
  rect.w=l;
  rect.h=h;
  SDL_RenderDrawRect(afficheur,&rect);
}

void efface(){
  // Choisie la couleur de fond
   SDL_SetRenderDrawColor(afficheur,couleur_fond.r,couleur_fond.g,couleur_fond.b,SDL_ALPHA_OPAQUE);

   // Rempli toute la fenetre
   SDL_RenderClear(afficheur);

   // Choisie la couleur de dessin
   SDL_SetRenderDrawColor(afficheur,couleur_dessin.r,couleur_dessin.g,couleur_dessin.b,SDL_ALPHA_OPAQUE);
}

void ferme_interface(){
  if(afficheur){
    SDL_DestroyRenderer(afficheur);
  }
  if(fenetre){
    SDL_DestroyWindow(fenetre);
  }
  SDL_Quit();
}

void rafraichissement(){
  SDL_RenderPresent(afficheur);
}

void rempli_rectangle(int x,int y,int l,int h){
  SDL_Rect rect;
  rect.x=x;
  rect.y=y;
  rect.w=l;
  rect.h=h;
  SDL_RenderFillRect(afficheur, &rect);
}






