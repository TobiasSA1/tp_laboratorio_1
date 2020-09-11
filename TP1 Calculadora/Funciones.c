#include <stdio.h>
#include <string.h>

int pedirNumero(int A)
{
    printf("\nIngrese un numero:");
    scanf("%d",&A);
    while (A==0)
    {
    printf("\nEl numero ingresado es incorrecto.\nIngrese un numero:");
    scanf("%d",&A);
    }
    return A;
}

int OperacionSuma (int A,int B)
{
    return A+B;
}

int OperacionResta (int A,int B)
{
    return A-B;
}

int OperacionMultiplicacion (int A,int B)
{

    return A*B;
}


float OperacionDivision (int A,int B)
{
    return A/B;
}

/*
*
*\brief Toma el valor ingresado por el usuario y realiza un factorial
*\param A, es el numero a realizar dicha operacion
*\return retorna el valor de los factoriales
*
*/

int OperacionFactoriales (int A)
{
    int r1=1;
    for(int i = 1; i <= A; i++)
    {
        r1 = r1 * i;
    }
    return r1;
}

