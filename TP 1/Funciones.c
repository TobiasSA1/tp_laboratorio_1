#include <stdio.h>

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
int OperacionDivision (int A,int B)
{
    return A/B;
}

int OperacionFactoriales (int A)
{
    int r1=1;
    for(int i = 1; i <= A; i++)
    {
        r1 = r1 * i;
    }
    return r1;
}
