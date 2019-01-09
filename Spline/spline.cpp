#include "spline.hpp"

//-------------------------
// Exercice 5 - Question a
//-------------------------

void Spline::ajoute_point(int x,int y){
    Point A;
    A.x = x;
    A.y = y;
    if(n<POINTS_MAX){
        P[n]=A;
        n++;
     } else {
        cout<<"Erreur"<<endl;
     }
     cout<<"La valeur de N est "<<n<<endl;
}

//-------------------------
// Exercice 5 - Question c
//-------------------------

void Spline::dessine_points(){
    Point A;
    for(size_t i=0; i<n; i++){
        A=P[i];
        A.dessine();
    }
}

//-------------------------
// Exercice 5 - Question d
// Exercice 8 - Question b
//-------------------------

void
Spline::dessine(){
    for(size_t i=0 ; i<n; ++i){
        P[i].dessine();
    }
    if(statut==Statique || statut==Dynamique){
        dessine_spline();
    }
}

//------------
// Exercice 6
//------------

void
Spline::calcule_Ainverse(){

    //!\ Zone protégée /!\
    // On commence par ajouter artificiellement un point vallant P[0]
    P[n++]=P[0];
    //!\ Fin de zone protégée /!\

  //------------
  // Question a
  //------------

  statut=Statique;

  //------------
  // Question b
  //------------

    Matrice temp(n);

    for(size_t i=0; i<n; ++i){
        for(size_t j=0; j<n; ++j){
            if(i==0){
                if(j==0){
                    temp.acces(i,j)=1;
                }
                else if(j==n-1){
                    temp.acces(i,j)=-1;
                }
            }
            else if(i==n-1){
                if(j==0 || j==n-1){
                    temp.acces(i,j)=2;
                }
                else if(j==n-2 || j==1){
                    temp.acces(i,j)=1;
                }

            }
            else if(j==i-1 || j-2==i-1){
                    temp.acces(i,j)=1;
            }
            else if(j-1==i-1){
                temp.acces(i,j)=4;
            }
        }
    }
    cout<<temp<<endl;
    Ainverse=temp.inverse();
}

//------------
// Exercice 7
//------------

void Spline::calcule(){

  //------------
  // Question a
  //------------

    if(statut==EnConstruction){
        calcule_Ainverse();
    }

  //------------
  // Question b
  //------------

  Matrice Bx(n,1);
  Bx[0][0]=0;
  Bx[n-1][0]=6*(P[1].x-P[0].x+P[n-2].x-P[n-1].x);
  for(size_t i=1;i<=n-2;i++){
    Bx[i][0]=6*(P[i+1].x-2*P[i].x+P[i-1].x);
  }
  Matrice s=Ainverse*Bx;

  Matrice By(n,1);
  By[0][0]=0;
  By[n-1][0]=6*(P[1].y-P[0].y+P[n-2].y-P[n-1].y);
  for(size_t i=1;i<=n-2;i++){
    By[i][0]=6*(P[i+1].y-2*P[i].y+P[i-1].y);
  }
  Matrice t=Ainverse*Bx;

  //------------
  // Question c
  //------------

    for(size_t i=0;i<n-1;++i){
        // Coefficient de X^3
        q[i][3]=(s[i+1][0]-s[i][0])/6;
        r[i][3]=(t[i+1][0]-t[i][0])/6;

        // Coefficient de X^2
        q[i][2]=s[i][0]/2;
        r[i][2]=t[i][0]/2;

        // Coefficient de X^1
        q[i][1]=P[i+1].x-P[i].x-(s[i+1][0]-s[i][0])/6-s[i][0]/2;
        r[i][1]=P[i+1].y-P[i].y-(t[i+1][0]-t[i][0])/6-t[i][0]/2;

        // Coefficient de X^0
        q[i][0]=P[i].x;
        r[i][0]=P[i].y;
    }

}

//-------------------------
// Exercice 8 - Question a
//-------------------------

void Spline::dessine_spline(){
    defini_couleur_dessin(bleu);
    for(size_t i=0;i<(n-1); ++i){
        for(double j=0; j<1; j+=0.001){
            dessine_rectangle(q[i](j),r[i](j),2,2);
        }
    }
}

//------------
// Exercice 9
//------------

void
Spline::reset(){
    cout<<"On efface"<<endl;
    statut=EnConstruction;
    n=0;
}

//--------------------------
// Exercice 10 - Question a
//--------------------------

void
Spline::selectionne_point(int x,int y){
    size_t i=1;
    int ok=0;
    while(i<n-1 && ok==0){
        if(P[i].est_proche(x,y)==true){
            point_selectionne=i;
            ok=1;
            statut=Dynamique;
        }
        if(ok==0){
            point_selectionne=-1;
        }
        ++i;
    }
}

//--------------------------
// Exercice 10 - Question c
//--------------------------

void
Spline::deplace_point(int x,int y){
    if(point_selectionne!=-1){
        Point A;
        A.x=x;  // parametre x
        A.y=y;  // parametre y
        P[point_selectionne]=A; // Point A
        calcule();
    }
}

//--------------------------
// Exercice 10 - Question e
//--------------------------

void
Spline::fin_deplacement(){
    statut=Statique;
    point_selectionne=-1;
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
