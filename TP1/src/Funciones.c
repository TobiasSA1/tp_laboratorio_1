#include <stdio.h>
#include <string.h>
#include "Funciones.h"




int menu(float A,float B)
{
    int opcion;
    /* printf("\n/////////////CALCULADORA///////////////");*/
    printf("1). Ingresar 1er operando. A=%.2f",A);
    printf("\n2). Ingresar 2do operando. B=%.2f",B);
    printf("\n3). Realizar todas las operaciones.");
    printf("\n         -Sumar");
    printf("\n         -Restar");
    printf("\n         -Multiplicar");
    printf("\n         -Factorial");
    printf("\n         -Dividir");
    printf("\n         -Salir");
    printf("\n4). Informar resultados.");
    printf("\n5). Cerrar calculadora.\n");
    /*printf("\n///////////////////////////////////////\n");*/
    printf("Ingrese su opcion:");
    scanf("%d",&opcion);

    return opcion;
}


float pedirNumero(float A)
{
    printf("\nIngrese un numero:");
    scanf("%f",&A);
    return A;
}

float OperacionSuma(float A,float B)
{
	float suma;
    suma=A+B;
    return suma;
}

float OperacionResta(float A,float B)
{
	float resta;
    resta=A-B;
    return resta;
}

float OperacionMultiplicacion(float A,float B)
{
	float multiplicacion;
    multiplicacion=A*B;
    return multiplicacion;
}


float OperacionDivision(float A,float B)
{

    	float division;
        division=(float)A/B;
        return division;

}


float OperacionFactorial(float num)
{
	float factorial=1;
    for(int i = 1; i <= num; i++)
    {
        factorial = factorial * i;
    }
    return factorial;
}
