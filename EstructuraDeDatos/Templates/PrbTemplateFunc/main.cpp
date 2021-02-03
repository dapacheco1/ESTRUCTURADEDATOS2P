// PrbTemplateFunc
#include <iostream>
#include "CVector.h"
using namespace std;

template<class T> T maxi(T a, T b)
   { return (a > b) ? a : b; }; // L10

int main() { // =====================
  CVector v1(2, 3), v2(1, 5);
  int x = 2, y = 3;
  cout << "Mayor: " << maxi(x, y) << endl; // M3
  cout << "Mayor: " << maxi(v1, v2).GetX() << ", "
    << maxi(v1,v2).GetY() << endl; // M4
  return 0;
}
