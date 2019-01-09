#ifndef MATRICE_HPP
#define MATRICE_HPP

#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>

using namespace std;

/**
 * Classe permettant de représeanter
 * les matrices à coefficients réels
 */

class Matrice{
private:
  //! Classe privée représentant la ligne d'une matrice
  class Ligne;
  //! Nombre de lignes de la matrice
  size_t nl;
  //! Nombre de colonnes de la matrice
  size_t nc;
  //! Tableau de coefficients de la matrice
  double* coeffs;
public:
  //! Construit une matrice vide
  Matrice();

  //! Construit une matrice carrée nulle
  //! \param n nombre de lignes et de colonnes
  explicit Matrice(size_t n);

  //! Construit une matrice rectangulaire nulle
  //! \param n nombre de lignes
  //! \param m nombre de colonnes
  Matrice(size_t n,size_t m);

   //! Construit une matrice rectangulaire a partir d'une liste de coefficient
  //! \param n nombre de lignes
  //! \param m nombre de colonnes
  Matrice(size_t n,size_t m,initializer_list<double> l);

  //! Constructeur par recopie
  Matrice(const Matrice& M);

  //! Constructeur par déplacement
  Matrice(Matrice&& M);

  //! Destructeur
  ~Matrice();

  //! Operateur d'assignement
  Matrice& operator=(const Matrice& M);

  //! Operateur de déplacement
  Matrice& operator=(Matrice&& L);

  //! Retourne le nombre de lignes
  size_t lignes() const;

  //! Retourne le nomnre de colonnes
  size_t colonnes() const;


  //! Donne acces au coefficient i,j de la matrice
  //! \param i indice de la ligne du coefficient entre 0 et lignes()-1
  //! \param j indice de la colonne du coefficient entre 0 et colonnes()-1
  double& acces(size_t i,size_t j);
  double acces(size_t i,size_t j) const;

  //! Retourne la ligne i
  //! \param i numéro de ligne compris entre 0 et lignes()-1
  Ligne operator[](size_t i);

  //! Retourne la ligne i
  //! \param i numéro de ligne compris entre 0 et lignes()-1
  const Ligne operator[](size_t i) const;

  //! Teste si deux matrices sont égales
  bool operator==(const Matrice& M) const;

  //! Teste si deux matrices sont différentes
  bool operator!=(const Matrice& M) const;

  //! Retourne la somme de deux matrices
  Matrice operator+(const Matrice& M) const;

  //! Retourne la différence de deux matrices
  Matrice operator-(const Matrice& M) const;

  //! Retourne le produit d'une matrice par un scalaire a
  Matrice operator*(const double& a) const;
  friend Matrice operator*(const double& a,const Matrice& M);

  //! Retourne le produit de deux matrices
  Matrice operator*(const Matrice& M) const;

  //! Echange la ligne i et la ligne j de la matrice
  //! Li<->Lj
  //! \param i numéro de ligne entre 0 et lignes()
  //! \param j numéro de ligne entre 0 et lignes()
  void echange_lignes(size_t i,size_t j);

  //! Multiplie la ligne i de la matrice par un scalaire a
  //! Li<-aLi
  //! \param i numéro de la ligne à multiplier, compris entre 0 et lignes()
  //! \param a sacalaire mutipliant la ligne
  void multiplie_ligne(size_t i,double a);

  //! Ajoute un mutltiple d'une ligne par un scalaire à une autre
  //! Li<-Li+aLj
  //! \param i numéro de ligne entre 0 et lignes()
  //! \param j numéro de ligne entre 0 et lignes()
  //! \param a sacalaire mutipliant la ligne i
  void ajoute_multiple_ligne(size_t i,size_t j,double a);

  //! Retourne la matrice échelonné réduite obtenue de la
  //! matrice courante par le pivot de Gauss
  Matrice Gauss() const;

  //! Retourne le rang de la matrice courante
  size_t rang() const;

  //! Retourne le déterminant de la matrice courante
  double determinant() const;

  //! Retourne l'inverse de la matrice courante
  Matrice inverse() const;

  //! Operateur d'affichage
  friend ostream& operator<<(ostream& os,const Matrice& M);
};

/**
   Classe représentant une ligne de matrice
 */

class Matrice::Ligne{
private:
  //! Coeffisient de la ligne
  double* coeffs;
  //! Taille de la ligne
  size_t taille;

public:
  //! Construit la ligne i de la matrice M
  Ligne(const Matrice*, size_t i);

  //! Destructeur
  ~Ligne();

  //! Retourne le coefficient j de la ligne
  //! \param j indice du coefficient entre 0 et taille-1
  double& operator[](size_t j);
  double operator[](size_t j) const;
};

//*********************
//* Fonctions inlines *
//*********************

inline
Matrice::Matrice():Matrice(0,0){
}

inline
Matrice::Matrice(size_t n):Matrice(n,n){

}

inline
Matrice::Matrice(size_t n,size_t m):nl(n),nc(m){
  if(nc*nl==0){
    coeffs=nullptr;
  }
  else{
    coeffs=new double[n*m];
    for(size_t i=0;i<n*m;++i){
      coeffs[i]=0;
    }
  }
}

inline
Matrice::Matrice(size_t n,size_t m,initializer_list<double> l):nl(n),nc(m){
  assert(n*m==l.size());
   if(nc*nl==0){
    coeffs=nullptr;
  }
  else{
    coeffs=new double[n*m];
    size_t i=0;
    for(auto it=l.begin();it!=l.end();++it){
      coeffs[i]=*it;
      ++i;
    }
  }
}

inline
Matrice::Matrice(const Matrice& M):nl(M.nl),nc(M.nc){
  if(nl*nc==0){
    coeffs=nullptr;
  }
  else{
    coeffs=new double[nl*nc];
    memcpy(coeffs,M.coeffs,nl*nc*sizeof(double));
  }
}

inline
Matrice::Matrice(Matrice&& M):nl(M.nl),nc(M.nc),coeffs(M.coeffs){
  M.coeffs=nullptr;
  M.nl=M.nc=0;
}
inline
Matrice::~Matrice(){
  if(coeffs!=nullptr) delete[] coeffs;
}

inline
Matrice&
Matrice::operator=(const Matrice& M){
  if(nl*nc!=M.nl*M.nc and coeffs!=nullptr){
    delete[] coeffs;
  }
  nl=M.nl;
  nc=M.nc;
  if(nl*nc==0){
    coeffs=nullptr;
  }
  else{
    coeffs=new double[nl*nc];
    memcpy(coeffs,M.coeffs,nl*nc*sizeof(double));
  }
  return *this;
}

inline
Matrice&
Matrice::operator=(Matrice&& M){
  if(coeffs!=nullptr){
    delete[] coeffs;
  }
  nl=M.nl;
  nc=M.nc;
  coeffs=M.coeffs;
  M.coeffs=nullptr;
  M.nc=M.nl=0;
  return *this;
}


inline size_t
Matrice::lignes() const{
  return nl;
}

inline size_t
Matrice::colonnes() const{
  return nc;
}

inline double&
Matrice::acces(size_t i,size_t j){
  assert(i<nl and j<nc);
  return coeffs[i*nc+j];
}

inline double
Matrice::acces(size_t i,size_t j) const{
  assert(i<nl and j<nc);
  return coeffs[i*nc+j];
}

inline Matrice::Ligne
Matrice::operator[](size_t i){
  assert(i<nl);
  return Ligne(this,i);
}

inline const Matrice::Ligne
Matrice::operator[](size_t i) const{
  assert(i<nl);
  return Ligne(this,i);
}

inline Matrice
operator*(const double& a,const Matrice& M){
  return M*a;
}

inline
ostream& operator<<(ostream& os,const Matrice& M){
  if (M.nl*M.nc==0){
    return os<<"Martice vide"<<endl;
  }
  os<<setprecision(4);
  for(size_t i=0;i<M.nl;++i){
    os<<'[';
    for(size_t j=0;j<M.nc;++j){
      os<<M.acces(i,j)<<'\t';
    }
    os<<']'<<endl;
  }
  return os;
}

inline
Matrice::Ligne::Ligne(const Matrice* M,size_t i){
  coeffs=&M->coeffs[i*M->nc];
  taille=M->nc;
}

inline
Matrice::Ligne::~Ligne(){
}

inline
double&
Matrice::Ligne::operator[](size_t j){
  assert(j<taille);
  return coeffs[j];
}

inline
double
Matrice::Ligne::operator[](size_t j) const{
  assert(j<taille);
  return coeffs[j];
}

#endif
