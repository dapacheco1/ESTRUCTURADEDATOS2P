// CListaSE.cpp
#include "CListaSE.h"
CListaSE::CListaSE()
{
 //ctor
}
CListaSE::~CListaSE()
{
 //dtor
}
LISTA CListaSE::Obtiene(const LISTA P, Elemento X)
{
 LISTA Q = (LISTA) new CListaSE;
 Q->SetDato(X);
 Q->SetSUC(P);
  return Q;
}
