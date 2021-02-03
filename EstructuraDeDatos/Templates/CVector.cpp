// CVector.cpp
#include "CVector.h"

CVector::CVector(int a, int b)
{
    //ctor
    x = a;
    y = b;
}

CVector::~CVector()
{
    //dtor
}

bool CVector::operator > (CVector v) {
   // L6 operador > para la clase
   return ((x * x + y * y) > (v.x * v.x + v.y * v.y))
        ? true: false;
}
