#include "polynome.hpp"
#include <cassert>
#include <math.h>

//-------------------------
// Exercice 1 - Question a
//-------------------------
Polynome::Polynome(){
    for(size_t i=0; i<4; ++i){
        coeffs[i]=0;
    }
}

//-------------------------
// Exercice 1 - Question b
//-------------------------

Polynome::Polynome(const Polynome& P){
    Polynome PP;
    for(size_t i=0;i<4;++i){
        PP[i]=P[i];
    }
}

//------------
// Exercice 2
//------------

///
/// j'ai pas compris le but :/
/// "fonction permettant d'évaluer le polynôme courant en t"
/// je suis pas sûr pour le p=1 et le i<4
/// x^3 x^2 x^1
double
Polynome::operator()(double t) const{
    double valeur = 0;

    valeur = valeur + (pow( t, 3.0 )* coeffs[3]);
    valeur = valeur + (pow( t, 2.0 )* coeffs[2]);
    valeur = valeur + (pow( t, 1.0 )* coeffs[1]);
    valeur += coeffs[0];

    return valeur;

}

//------------------------
// Fin du code a modifier
//------------------------

Polynome::~Polynome(){
}

double&
Polynome::operator[](size_t i){
  assert(i<=3);
  return coeffs[i];
}

double
Polynome::operator[](size_t i) const{
  assert(i<=3);
  return coeffs[i];
}

Polynome&
Polynome::operator=(const Polynome& P){
  for(size_t i=0;i<4;++i){
    coeffs[i]=P.coeffs[i];
  }
  return *this;
}

ostream&
operator<<(ostream& os,const Polynome &P){
  for(int i=3;i>=0;--i){
    if(P[i]!=0){
      if(P[i]<0){
	if(i<3){
	  os<<' ';
	}
	if(P[i]==-1){
	  if(i>1){
	    os<<"- x^"<<i;
	  }
	  else if(i==1){
	    os<<"- x";
	  }
	  else{//i==0
	    os<<"- 1";
	  }
	}
	else{
	  //P[i]==-1
	  if(i>1){
	    os<<"- "<<-P[i]<<"x^"<<i;
	  }
	  else if(i==1){
	    os<<"- "<<-P[i]<<"x";
	  }
	  else{//i==0
	    os<<"- "<<-P[i];
	  }
	}
      }
      else{
	//P[i]>0
	if(i<3){
	  os<<" + ";
	}
	if(P[i]==1){
	  if(i>1){
	    os<<"x^"<<i;
	  }
	  else if(i==1){
	    os<<"x";
	  }
	  else{//i==0
	    os<<"1";
	  }
	}
	else{
	  //P[i]!=1
	  if(i>1){
	    os<<P[i]<<"x^"<<i;
	  }
	  else if(i==1){
	    os<<P[i]<<"x";
	  }
	  else{//i==0
	    os<<P[i];
	  }
	}
      }
    }
  }
  return os;
}
