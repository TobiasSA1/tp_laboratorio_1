#include <stdio.h>

/*
*
*\brief Pide que ingreses un valor y lo valida por si es 0
*\param A, va a ser donde se guarden los numeros que ingrese el usuario
*\return Retorna el valor del numero ingresado
*
*/

int pedirNumero(int A)
{
    printf("\nIngrese un numero:");
    scanf("%d",&A);
    while (A==0)
    {
    printf("\nEl numero ingresado es incorrecto.Ingrese un numero:");
    scanf("%d",&A);
    }
    return A;
}
/*
*
*\brief Suma dos numeros
*\param A, es un numero a sumar
*\param B, es el otro numero a sumar
*\return Retorna la suma entre ambos
*
*/
int OperacionSuma (int A,int B)
{
    return A+B;
}
/*
*
*\brief Resta dos numeros
*\param A, es un numero a restar
*\param B, es el otro numero a restar
*\return Retorna la resta entre ambos
*
*/
int OperacionResta (int A,int B)
{
    return A-B;
}
/*
*
*\brief Divide dos numeros
*\param A, es un numero a multiplicar
*\param B, es el otro numero a multiplicar
*\return Retorna la multiplicacion entre ambos
*
*/
int OperacionMultiplicacion (int A,int B)
{

    return A*B;
}
/*
*
*\brief Divide dos numeros
*\param A, es el divisor
*\param B, es el dividendo
*\return Retorna la division entre ambos
*
*/

int OperacionDivision (int A,int B)
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

