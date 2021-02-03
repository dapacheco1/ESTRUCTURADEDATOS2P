// Ackermann
#include <iostream>
#define MaxX 4
#define MaxY 20
using namespace std;
// Prototipos
long Ackermann(long X, long Y);
// Funciones
int main()
{
 long X, Y;
 for (;;) {
 cout << "Ingresar X (salir < 0 o > " << MaxX << "): ";
 cin >> X;
 if (X < 0 || X > MaxX) break;
 cout << "Ingresar Y (salir < 0 o > " << MaxY << "): ";
 cin >> Y;
 if (Y < 0 || Y > MaxY) break;
 cout << "Ackermann(" << X << ", " << Y << ") = " <<
 Ackermann(X, Y) << endl;
 }
 return 0;
}
long Ackermann(long X, long Y)
{ // Ackermann
 if (X == 0)
 return (Y + 1);
 else if (Y == 0)
 return Ackermann(X - 1, 1);
 else
 return Ackermann(X - 1,Ackermann(X, Y - 1));
} // Ackermann
