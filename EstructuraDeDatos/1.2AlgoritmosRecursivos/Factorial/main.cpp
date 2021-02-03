// Factorial
#include <iostream>
using namespace std;
double FacR(int X) {
 if (X < 2) return 1;
 return X * FacR(X - 1);
}
int main()
{
 int n;
 for (;;) {
 cout << "Ingresar un entero (salir < 0 o > 20): ";
 cin >> n;
 if (n < 0 || n > 20) break;
 cout << "Factorial(" << n << ") = " << FacR(n) << endl;
 }
 return 0;
}
