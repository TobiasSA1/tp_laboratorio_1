#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 999
#define LIBRE 1
#define OCUPADO 0
#include "Employees.h"

int main()
{
    eEmployee ArrayEmployees[TAM];
    int inicializar;
    inicializar = initEmployees(ArrayEmployees,TAM);

    char opcion;
    int id;
    int barrera=-1;
    int legajo = 0;
    printf("******************");
    do
    {
        printf("\nMENU DE OPCIONES: \n");
        printf("\ta. ALTA\n\tb. BAJA\n\tm. MODIFICAR\n\tl. LISTAR\n\ts. Salir\nElija una opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);

        switch(opcion)
        {
            case 'a':
               legajo++;
               loadListEmployees(ArrayEmployees,TAM,legajo);
               barrera = 1;

            break;
            case 'b':
                if(barrera==1)
                {
                    printf("\nIngrese el id a eliminar:\n ");
                    scanf("%d", &id);
                    removeEmployee(ArrayEmployees,TAM,id);
                }
                else
                {
                    printf("Debe realizar primero la alta de empleados.");
                }



            break;
            case 'm':
                if(barrera==1)
                {
                printAllEmployees(ArrayEmployees,TAM);
                modifyEmployees(ArrayEmployees,TAM);
                }
                else
                {
                    printf("Debe realizar primero la alta de empleados.");
                }

            break;
            case 'l':
                if(barrera==1)
                {
                sortEmployeesByName_Sector(ArrayEmployees,TAM);
                printAllEmployees(ArrayEmployees,TAM);
                salary(ArrayEmployees,TAM);
                }
                else
                {
                    printf("Debe realizar primero la alta de empleados.");
                }

            break;

            default:printf("\nLa opcion ingresada es incorrecta o esta en MAYUSCULA.\n\n");

        }
    }while(opcion!='s');


    return 0;


}
