#include "matrice.hpp"


/// A completer ///


bool Matrice::operator==(const Matrice& M) const{
  if(nl!=M.nl or nc!=M.nc){
    return false;
  }
  for(size_t k=0;k<nc*nl;++k){
    if(coeffs[k]!=M.coeffs[k]){
      return false;
    }
  }
  return true;
}

bool Matrice::operator!=(const Matrice& M) const{
  if(nl!=M.nl or nc!=M.nc){
    return true;
  }
  for(size_t k=0;k<nc*nl;++k){
    if(coeffs[k]!=M.coeffs[k]){
      return true;
    }
  }
  return false;
}

Matrice
Matrice::operator+(const Matrice& M) const{
  assert(nl==M.nl and nc==M.nc);
  Matrice R(nl,nc);
  for(size_t k=0;k<nl*nc;++k){
    R.coeffs[k]=coeffs[k]+M.coeffs[k];
  }
  return R;
}

Matrice
Matrice::operator-(const Matrice& M) const{
  assert(nl==M.nl and nc==M.nc);
  Matrice R(nl,nc);
  for(size_t k=0;k<nl*nc;++k){
    R.coeffs[k]=coeffs[k]-M.coeffs[k];
  }
  return R;
}

Matrice
Matrice::operator*(const double& a) const{
  Matrice R(nl,nc);
  for(size_t k=0;k<nl*nc;++k){
    R.coeffs[k]=a*coeffs[k];
  }
  return R;
}

Matrice
Matrice::operator*(const Matrice& M) const{
  assert(nc==M.nl);
  Matrice R(nl,M.nc);
  for(size_t i=0;i<nl;++i){
    for(size_t j=0;j<M.nc;++j){
      double c=0;
      for(size_t k=0;k<nc;++k){
	c+=acces(i,k)*M.acces(k,j);
      }
      R.acces(i,j)=c;
    }
  }
  return R;
}

void
Matrice::echange_lignes(size_t i,size_t j){
  assert(i<nl and j<nl);
  double temp;
  for(size_t k=0;k<nc;++k){
    temp=acces(i,k);
    acces(i,k)=acces(j,k);
    acces(j,k)=temp;
  }
}

void
Matrice::multiplie_ligne(size_t i,double a){
  assert(i<nl and a!=0);
  for(size_t k=0;k<nc;++k){
    acces(i,k)*=a;
  }
}

void
Matrice::ajoute_multiple_ligne(size_t i,size_t j,double a){
  assert(i<nl and j<nl and i!=j);
  for(size_t k=0;k<nc;++k){
    acces(i,k)+=a*acces(j,k);
  }
}

Matrice
Matrice::Gauss() const{
  Matrice R=*this;
  size_t np=0; //np=0
  for(size_t j=0;j<nc;++j){
    for(size_t p=np;p<nl;++p){ //j->np
      if(R.acces(p,j)!=0){
	R.multiplie_ligne(p,1.0/R.acces(p,j));
	for(size_t k=0;k<nl;++k){
	  if(k!=p){
	    R.ajoute_multiple_ligne(k,p,-R.acces(k,j));
	  }
	}
	R.echange_lignes(np,p); //j->np
	++np; //np++
	break;
      }
    }
  }
  return R;
}

/*
size_t
Matrice::rang() const{
}
*/

/*
double
Matrice::determinant() const{
}
*/

Matrice
Matrice::inverse() const{
  assert(nl==nc);
  Matrice R=*this;
  Matrice I(nl,nc);
  for(size_t i=0;i<nl;++i){
    I.acces(i,i)=1;
  }
  size_t np=0;
  for(size_t j=0;j<nc;++j){
    for(size_t p=np;p<nl;++p){
      if(R.acces(p,j)!=0){
        double a=1.0/R.acces(p,j);
	R.multiplie_ligne(p,a);
	I.multiplie_ligne(p,a);
	for(size_t k=0;k<nl;++k){
	  if(k!=p){
	    a=-R.acces(k,j);
	    R.ajoute_multiple_ligne(k,p,a);
	    I.ajoute_multiple_ligne(k,p,a);
	  }
	}
	R.echange_lignes(np,p);
	I.echange_lignes(np,p);
	++np;
	break;
      }
    }
  }
  if(R.acces(nl-1,nc-1)==0){
    cout<<"Matrice pas inversible"<<endl;
    return Matrice();
  }
  return I;
}
