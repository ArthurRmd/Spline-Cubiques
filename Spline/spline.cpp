#include "spline.hpp"

//-------------------------
// Exercice 5 - Question a
//-------------------------

void Spline::ajoute_point(int x,int y){
    Point A;
    A.x = x;
    A.y = y;

    if (n < POINTS_MAX){
        P[n]= A;
        n++;
     }
     else{
        cout<<"Erreur"<<endl;
     }

     cout<<"La valeur de N est" << n <<endl;
}

//-------------------------
// Exercice 5 - Question c
//-------------------------

void Spline::dessine_points(){

    if ( n== 20){
         cout<< "ok"<< endl;
        Point A;

        for( size_t i=0; i<20; i++){
            A = P[i];
            cout<<A.x<<endl;
            A.dessine();
        }
    }

}

//-------------------------
// Exercice 5 - Question d
// Exercice 8 - Question b
//-------------------------

void
Spline::dessine(){

}

//------------
// Exercice 6
//------------

void
Spline::calcule_Ainverse(){
  //!\ Zone protégée /!\
  // On commence par ajouter artificiellement un point vallant P[0]
  P[n++]=P[0];
  // Fin de zone protégée

  //------------
  // Question a
  //------------

  //------------
  // Question b
  //------------

}

//------------
// Exercice 7
//------------

void Spline::calcule(){
  //------------
  // Question a
  //------------

  //------------
  // Question b
  //------------

  /*Matrice Bx(n,1);
  Bx[0][0]=0;
  Bx[n-1][0]=6*(P[1].x-P[0].x+P[n-2].x-P[n-1].x);
  for(size_t i=1;i<=n-2;i++){
    Bx[i][0]=6*(P[i+1].x-2*P[i].x+P[i-1].x);
  }
  Matrice s=Ainverse*Bx;*/

  //------------
  // Question c
  //------------

  /*for(size_t i=0;i<n-1;++i){
    // Coefficient de X^3
    q[i][3]=(s[i+1][0]-s[i][0])/6;

    // Coefficient de X^2
    q[i][2]=s[i][0]/2;
    r[i][2]=t[i][0]/2;

    // Coefficient de X^1
    q[i][1]=P[i+1].x-P[i].x-(s[i+1][0]-s[i][0])/6-s[i][0]/2;

    // Coefficient de X^0
    q[i][0]=P[i].x;
    }*/
}

//-------------------------
// Exercice 8 - Question a
//-------------------------

void Spline::dessine_spline(){

}

//------------
// Exercice 9
//------------

void
Spline::reset(){

}

//--------------------------
// Exercice 10 - Question a
//--------------------------

void
Spline::selectionne_point(int x,int y){

}

//--------------------------
// Exercice 11 - Question c
//--------------------------

void
Spline::deplace_point(int x,int y){

}

//--------------------------
// Exercice 11 - Question e
//--------------------------

void
Spline::fin_deplacement(){

}

//---------------------------
// Fin de la zone a modifier
//---------------------------

Spline::Spline(){
  statut=EnConstruction;
  point_selectionne=-1;
  n=0;
}

StatutSpline
Spline::lire_statut(){
  return statut;
}


