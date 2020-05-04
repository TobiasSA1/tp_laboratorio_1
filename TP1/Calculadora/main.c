#include <stdio.h>
#include "LlamadoFunciones.h"

int main()
{
/////////////////////////////////
int A=0;
int B=0;
int SUMA=0;
int RESTA=0;
int MULTIPLICACION=0;
int DIVISION=0;
int FACTORIALA=0;
int FACTORIALB=0;
int opcion;
do
{
/////////////////////////////////
printf("\n///////////////////////////////////////\n");
printf("\n1). Ingresar 2 numeros para calcular. A=%d  B=%d",A,B);
printf("\n2). Realizar todas las operaciones.");
printf("\n        1 -Sumar");
printf("\n        2 -Restar");
printf("\n        3 -Multiplicar");
printf("\n        4 -Factorial");
printf("\n        5 -Dividir");
printf("\n        6 -Salir");
printf("\n3). Informar resultados.");
printf("\n///////////////////////////////////////\n");
printf("\nIngrese su opcion:");
scanf("%d",&opcion);
/////////////////////////////////
switch(opcion)
{
    case 1: A=pedirNumero(A);
            B=pedirNumero(B);break;

    case 2:
        if(A==0&&B==0)
    {    printf("\n***************************************\n");
         printf("Debe ingresar valores primero");
         printf("\n***************************************\n");break;
    }
    else {
            SUMA=OperacionSuma(A,B);
            RESTA=OperacionResta(A,B);
            MULTIPLICACION=OperacionMultiplicacion(A,B);
            DIVISION=OperacionDivision(A,B);
            FACTORIALA=OperacionFactoriales(A);
            FACTORIALB=OperacionFactoriales(B);break;
            }

    case 3:
       if(A==0&&B==0)

    {   printf("\n***************************************\n");
        printf("Debe ingresar valores primero");
        printf("\n***************************************\n");break;
    }
            if (SUMA==0&&RESTA==0&&MULTIPLICACION==0&&DIVISION==0)
    {   printf("\n***************************************\n");
        printf("\nDebe calcular los valores primero\n");
        printf("\n***************************************\n");break;
    }
            printf("\nLa suma es: %d\n",SUMA);
            printf("\nLa resta es: %d\n",RESTA);
            printf("\nLa multiplicacion es: %d\n",MULTIPLICACION);
            printf("\nEl factorial del primer numero es: %d\n",FACTORIALA);
            printf("\nEl factorial del segundo numero es: %d\n",FACTORIALB);

            if(B==0)
                {
            printf("\nLa division no se puede realizar");break;
                }
            else
                {
                    printf("\nLa division es: %d\n",DIVISION);break;
                }

    case 4: printf("\nCerraste la calculadora.");break;

    default: printf("\n///////////////////////////////////////\n");
             printf("\nOpcion incorrecta, vuelva a ingresar una opcion.\n");
             printf("\n///////////////////////////////////////\n");break;


}
/////////////////////////////////

}
while(opcion!=4);
}


