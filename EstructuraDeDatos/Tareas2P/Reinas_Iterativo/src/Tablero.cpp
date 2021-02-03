#include "Tablero.h"
#include <stdlib.h>
using namespace std;

// Grupo 5

bool tablero[MAX_REINAS][MAX_REINAS];


//constructor

Tablero::Tablero()
{

}

//destructor 

Tablero::~Tablero()
{

}


// Funcion utilizada para dibujar el tablero en un archivo.txt
void Tablero::DibujarTablero(int n, unsigned long int numSol, ofstream &out)
{
    int i, j, q;
    out << "\nSolucion #" << numSol;
    out << " al Puzzle " << n << "-Reinas:\n";

    // Dibuja la cabeza del tablero
    for (q = 0; q < n; q++)
        out << "|---";
    out << "|\n";

    // Dibuja el resto del tablero
    for (i = 0; i < n; i++)
    {
        // Dibuja la mitad del tablero , incluyendo las reinas
        for (j = 0; j < n; j++)
        {
            out << "|";
            if (tablero[j][i])
                out << " Q ";
            else
                out << "   ";
        }
        // dibujando divisores en el tablero , y el final del tablero
        out << "|\n";
        for (q = 0; q < n; q++)
            out << "|---";
        out << "|\n";
    }
    out << endl;
}


// limpia todo el tablero asignando valor false
void Tablero::LimpiarTablero(int n)
{
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            tablero[i][j] = false;
}
/* REALIZA UN LOOP A TODA LA PILA DE REINAS , Y ASIGNA SUS POSICIONES EN EL TABLERO
 * DE AJEDREZ */
void Tablero::Colocarpiezasentablero(vector<int> &filas)
{
	for(size_t i = 0; i < filas.size(); i++)
        tablero[i][filas[i]] = true;
}

bool Tablero::UltimaPiezaValida(int n, vector<int> &filas)
{
    int fila = filas.back();
    int col = filas.size() - 1;
    // Verifica si la ultima reina esta fuera del tablero 
    if (fila >= n)
		return false;

    // Si no , verifica la validez de su posicion en el tablero
    for(size_t i = 0; i < filas.size() - 1; i++)
    {
        if (fila == filas[i])
			return false;

        if (abs(fila - filas[i]) == abs(col - int(i)))
			return false;
    }
    return true;
}

void Tablero::EncontrarSoluciones(int n)
{
    // USANDO A PUSH_BACK() / POP_BACK() DEL VECTOR COMO PILA
    vector<int> filas;
    bool fin = false;
    unsigned long int soluciones = 0;
    int fila;

    ofstream outfile;
    string filename;
    stringstream IntToStr;
    IntToStr << n;
    filename = IntToStr.str() + "-Reinas.txt";;
    outfile.open(filename.c_str());
    // ASIGNA LA PRIMERA PIEZA
    filas.push_back(0);

    cout << "\nTrabajando...";
    // REALIZA UN LOOP HASTA QUE TODAS LAS SOLUCIONES SON ENCONTRADAS
    while (!fin)
    {
        if (!UltimaPiezaValida(n, filas))
        {
            // COMO LA ULTIMA POSICION ES INVALIDA , ENCUENTRA ULTIMA VALIDA

            fila = filas.back();// REGISTRA LA ULTIMA FILA 
            // SI ESTA FUERA DEL TABLERO, REGRESA A LA ULTIMA PIEZA VALIDA

            if (fila >= n)
            {
                do
                {
                    // ASEGURANDOSE QUE NO HAYAN SIDO ENCONTRADAS TODAS LAS SOLUCIONES
                    if (filas.size() > 1)
                    {
                        filas.pop_back(); //REMOVER LA ULTIMA PIEZA INVALIDA
                        fila = filas.back();// REGISTRAR LA ULTIMA FILA CORRECTA
                        filas.pop_back();// REMOVER ESA PIEZA
                        filas.push_back(fila + 1);// INTENTAR CON LA SIGUIENTE FILA
                        fila = filas.back();//VERIFICAR SI LA FILA ESTA EN LIMITES
                    }
                    else //FUERON ENCONTRADAS TODAS LAS SOLUCIONES
                    {
                        fin = true;
                        break; // ROMPE EL CICLO
                    }
                    // RETROCEDE MIENTRAS SEA NECESARIO
                } while (filas.back() >= n);
            }
            else // ESTABA DENTRO DE LIMITE, PERO NO ES CORRECTO, PRUEBA LA SIG FILA
            {
                filas.pop_back();
                filas.push_back(fila + 1);
            }
        }
        else // LA ULTIMA REINA ESTA CORRECTA
        {
            if (filas.size() == n) // VERIFICAR SI ENCONTRAMOS SOLUCION
            {
                soluciones++;
                LimpiarTablero(n);
                Colocarpiezasentablero(filas);
                DibujarTablero(n, soluciones, outfile);
                // CONTINUA ENCONTRANDO MAS SOLUCIONES SI LAS HAY
                fila = filas.back();
                filas.pop_back();
                filas.push_back(fila + 1);
                // MUESTRA UNA VERIFICACION PARA QUE EL USUARIO SEPA QUE EL PROGRAMA ESTA CORRIENDO
                if (soluciones % (n * n) == 0)
					cout << ".";
            }
            // SI NO FUE ENCONTRADA SOLUCION, SIGUE A LA SIGUIENTE COLUMNA
            else filas.push_back(0);
        }
    }

    outfile.close();

    cout << "\n\n\n===== TODAS LOS " << soluciones << " RESULTADOS ENCONTRADOS! =====\n";
    cout << "(Mire " << n << "-Reinas.txt para ver los resultados)\n\n";


}
