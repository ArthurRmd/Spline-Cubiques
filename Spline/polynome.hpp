#ifndef POLYNOME_HPP
#define POLYNOME_HPP

#include <iostream>

using namespace std;

class Polynome{
private:
  double coeffs[4]; 
public:
  //! Crée le polynome nul
  Polynome();

  //! Crée le polynome ax^3+bx^2+cx+d
  Polynome(double a,double b,double c,double d);
  
  //! Constructeur par recopie
  Polynome(const Polynome& P);
  
  //! Destructeur
  ~Polynome();

  //! Opérateur d'affectation : P=Q
  Polynome& operator=(const Polynome& P);

  //! Permet d'accéder aux coefficients du polynome : P[i] 
  double& operator[](size_t i);
  double operator[](size_t i) const;
    
  //! Evalue le polynome en t : P(t)
  double operator()(double t) const;
};


ostream& operator<<(ostream& os,const Polynome &P);

#endif
