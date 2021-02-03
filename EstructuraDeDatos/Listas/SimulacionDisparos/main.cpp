#include "CLstSEInsel.h"
#define CapacidadCaja 100
#define CapacidadAlimentadora 6
using namespace std;

void encabezado()
{
	printf("                                            Universidad De Las Fuerzas Armadas                                                                                                    'ESPE'\n");
    printf("\n");
    printf("                                    Ingenieria en tegnologias de la informacion  \n");
    printf("                                           \t Estructura de Datos      \n");
    printf("\n\n Realizado por: GRUPO 5 \n");
    printf("\t\t Crespo Teresa \n");
    printf("\t\t Loachamin Gisselle \n");
    printf("\t\t Noboa Andrés \n");
    printf("\t\t Oñate Paul \n");
    printf("\t\t Pacheco Danny \n");
    printf(" Nrc: 2865\n");
    printf(" Fecha: 15 de Enero de 2021 \n");
    printf(" Noviembre 2020 - Abril 2021\n\n");
    printf("\n\t\t\t\t\t############################################\n");
	printf("\t  \t\t\t  \t Listas y Pilas \n");
	printf("\n\t\t\t\t\t############################################\n\n");
}

int Elemento::m_Indicador = 0; // Solo claves
int main()
{
    encabezado();
    int i, nDisp;
    CLstSEInsel Caja, Pistola, Historial;
    Elemento X;
    LISTA P = NULL;
    Caja.IniciaCola();
    Pistola.IniciaCola();
    Historial.IniciaCola();
    cout<<"INGRESAR EL NUMERO DE DISPAROS: ";
    cin>>nDisp;
    // Cargar la caja:
    for (i = 1; i <= CapacidadCaja; i ++) {
        X.SetClave(i);
        Caja.InsCola(X);
    }
    Caja.EscribeLista("\nPROYECTILES EN LA CAJA INICIALMENTE");
    // Simulacion de los disparos:
    for(i = 1; i<=nDisp && Caja.GetPrimero() != NULL; i+= 6)
    {
        if(Pistola.GetPrimero() == NULL)
        {
            for(int j = 1; j<=CapacidadAlimentadora && Caja.GetPrimero() != NULL; j++){
                Caja.Retira(X);
                Pistola.Empuja(X);
            }

        }
        // Disparar
        cout<<"Disparos realizados: ";
        for(int j = 1; j<= CapacidadAlimentadora && Pistola.GetPrimero() != NULL && j<=(nDisp-i+1); j ++ ){
            Pistola.Retira(X);
            Historial.InsCola(X);
            X.Mostrar();
        }
        cout << endl;
    }
    cout << "LUEGO DE LA SIMULACION LOS OBJETOS QUEDAN EN EL SIGUIENTE ESTADO: \n";
        Caja.EscribeLista("\nPROYECTILES QUE QUEDAN EN LA CAJA: ");
        Pistola.EscribeLista("\nPROYECTILES QUE QUEDAN EN LA PISTOLA: ");
        Historial.EscribeLista("\nHISTORIAL DE PROYECTILES: ");
    return 0;
}
