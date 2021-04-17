#include <stdio.h>
#include <string.h>
#include "Funciones.h"

int main()
{
/////////////////////////////////
	setbuf(stdout, NULL);
    float A=0;
    float B=0;
    float SUMA=0;
    float RESTA=0;
    float MULTIPLICACION=0;
    float DIVISION=0;
    float FACTORIALA=0;
    float FACTORIALB=0;

    int flagA=0;
    int flagB=0;
    int flagOperacion=0;
    int opcion;

    do
    {
        opcion=menu(A,B);

        switch(opcion)
        {

        case 1:
            A=pedirNumero(A);
            flagA=1;
            break;

        case 2:
            B=pedirNumero(B);
            flagB=1;
            break;

        case 3:
            if(flagA==0&&flagB==0)
            {
                printf("\n***************************************\n");
                printf("Debe ingresar valores primero");
                printf("\n***************************************\n");
                break;
            }
            else
            {
                printf("\n///////////////////////////////////////\n");
                printf("\nSe realizaron las operaciones.\n");
                printf("\n///////////////////////////////////////\n");
                SUMA=OperacionSuma(A,B);
                RESTA=OperacionResta(A,B);
                MULTIPLICACION=OperacionMultiplicacion(A,B);
                if(B==0) {
                printf("\nLa division no se puede realizar");
                  } else {
                	  DIVISION=OperacionDivision(A,B);
                  }
                FACTORIALA=OperacionFactorial(A);
                FACTORIALB=OperacionFactorial(B);
                flagOperacion=1;
                break;
            }

        case 4:
            if(flagA==0&&flagB==0)

            {
                printf("\n***************************************\n");
                printf("Debe ingresar valores en ambos operando");
                printf("\n***************************************\n");
                break;
            }
            if (flagOperacion==0)
            {
                printf("\n***************************************\n");
                printf("\nDebe calcular los valores primero\n");
                printf("\n***************************************\n");
                break;
            }
            else
            {
                printf("\nLa suma es: %.2f\n",SUMA);
                printf("\nLa resta es: %.2f\n",RESTA);
                printf("\nLa multiplicacion es: %.2f\n",MULTIPLICACION);
                printf("\nEl factorial del primer numero es: %.2f\n",FACTORIALA);
                printf("\nEl factorial del segundo numero es: %.2f\n",FACTORIALB);
                printf("\nLa division es: %.2f\n",DIVISION);
                    break;

            }
        case 5:
            printf("\nCerraste la calculadora.");
            break;

        default:
            printf("\n///////////////////////////////////////\n");
            printf("\nOpcion incorrecta, vuelva a ingresar una opcion.\n");
            printf("\n///////////////////////////////////////\n");
            break;


        }

    }
    while(opcion!=4);
}
