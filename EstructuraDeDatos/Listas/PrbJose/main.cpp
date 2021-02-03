// PrbJose
#include "CLstCirSEInsel.h"
#include "CAleatorios.h"
using namespace std;
CLstCirSEInsel L;
int NumPart;
void Procesa();
int Elemento::m_Indicador = 2; // Claves y datos
int main()
{
 cout << "SIMULACION DEL PROBLENA DE JOSE" << endl;
 NumPart = L.LeeLista();
 Procesa();
 return 0;
}
void Procesa()
{ // Procesa
 if (L.GetUltimo()) {
 int I, N;
 Elemento X;
 CAleatorios al(0);
 L.EscribeLista("Lista original de hombres:");
 cout << "Orden de salida de los hombres:\n";
 while (L.GetUltimo()) {
 for (I = 1, N = al.Aleatorio(1, NumPart); I < N; I++)
 L.SetUltimo(L.GetUltimo()->GetSUC());
 cout << "Se contaron " << N
 << " participantes, SALE:";
 L.SetUltimo(L.EliDespues(
 L.GetUltimo(), X));
 NumPart--;
 if (!L.GetUltimo())
 cout << "\nEl hombre que gana, por quedar "
 "en el circulo es:\n";
 L.Escribir(X, "");
 }
 }
 else
 cout << "ERROR: LA LISTA SE ENCUENTRA VACIA\n";
} // Procesa
