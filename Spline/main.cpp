#include "interface.hpp"
#include "polynome.hpp"
#include "spline.hpp"

int main(int argc,char* argv[]){

/// TEST ICI

/// FIN TEST

   // Creation d'une interface graphique de 450x580
  initialise_interface(800,600);

  // La varible quitter vaudra true si l'utilisateur demande à quitter
  bool quitter=false;

  // Evenements de l'interface
  SDL_Event ev;
  SDL_KeyboardEvent kev;
  SDL_MouseButtonEvent mbev;
  SDL_MouseMotionEvent mev;

  // Spline qu'on va creer et afficher
  Spline spline;

  //! Boucle des evements
  while(not quitter){

    //! Detection d'un evenement
    while(SDL_PollEvent(&ev)!= 0){
      switch(ev.type){
      case SDL_QUIT:
	// Fermeture fenetre demandée
	quitter=true;
	break;
      case SDL_KEYDOWN:
	// Touche enfoncée
	// Detection de la touche enfoncée
	kev=ev.key;
	switch(kev.keysym.sym){
	  // Touche Q
	case SDLK_q:
	  quitter=true;
	  break;
	  // Touche S
	case SDLK_s:
	  // Calcule la spline
	  spline.calcule();
	  break;
	case SDLK_r:
	  // Remet la spline a zero
	  spline.reset();
	default:
	  break;
	}
	break;
      case SDL_MOUSEBUTTONDOWN:
	mbev=ev.button;
	switch(mbev.button){
	case SDL_BUTTON_LEFT:
	  //-------------------------
	  // Exercice 5 - Question b
	  //-------------------------
	  if(spline.lire_statut()==EnConstruction){
	    spline.ajoute_point(mbev.x,mbev.y);
	    //spline.dessine_points();


	  }

	  //--------------------------
	  // Exercice 10 - Question b
	  //--------------------------

	  break;
	}
      case SDL_MOUSEMOTION:
	mev=ev.motion;
	//--------------------------
	// Exercice 11 - Question d
	//--------------------------


	break;
      case SDL_MOUSEBUTTONUP:
	//--------------------------
	// Exercice 11 - Question f
	//--------------------------


	break;
      default:
	break;
      }
    }
    // Efface l'écran
    efface();



/*
    Point a;
    a.x = 0;
    a.y = 0;
    a.dessine();

/*
     Point A;
        A.x =mbev.x;
        A.y =mbev.y;
        A.dessine();
*/
    /// TEST
    spline.dessine_points();
    /// TEST

    // Dessine la spline
    spline.dessine();
    // Rafraichi l'écran
    rafraichissement();
    // Attend 20 ms
    SDL_Delay(20);
  }
  ferme_interface();

  return 0;
}
