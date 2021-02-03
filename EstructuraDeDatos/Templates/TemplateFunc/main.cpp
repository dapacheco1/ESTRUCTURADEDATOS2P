// TemplateFunc
#include <iostream>
using namespace std;
class Vector {
  public:
    float x, y;
    bool operator>(Vector v) {
       // L6 operador > para la clase
       return ((x * x + y * y) > (v.x * v.x + v.y * v.y))
        ? true: false;
    }
};
template<class T> T maxi(T a, T b)
   { return (a > b) ? a : b; }; // L10
int main() { // =====================
  Vector v1 = {2, 3}, v2 = {1, 5};
  int x = 2, y = 3;
  cout << "Mayor: " << maxi(x, y) << endl; // M3
  cout << "Mayor: " << maxi(v1, v2).x << ", "
    << maxi(v1,v2).y << endl; // M4
  return 1;
}
