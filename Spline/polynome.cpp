#include "polynome.hpp"
#include <cassert>

//-------------------------
// Exercice 1 - Question a
//-------------------------
Polynome::Polynome(){
    /// erreur assertion
    for(size_t i=0; i<=4; ++i){
        coeffs[i]=0;
    }
}

//-------------------------
// Exercice 1 - Question b
//-------------------------

Polynome::Polynome(const Polynome& P){
/*
    Polynome PP;
    for(size_t i=0;i<=4;++i){
        PP[i]=P[i];
    }
*/
}

//------------
// Exercice 2
//------------

///
/// j'ai pas compris le but :/
/// "fonction permettant d'évaluer le polynôme courant en t"
/// je suis pas sûr pour le p=1 et le i<=4
///
double
Polynome::operator()(double t) const{
    double p=1; // puissance de t ???
    double s=0;
    for(size_t i=0;i<=4;++i){ /// 4 => coeffs[4]
        s=s+coeffs[i]*p;
        p=p*t;
    }
    return s;
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
