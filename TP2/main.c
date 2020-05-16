#include <stdio.h>
#include <string.h>
#define T 10
#define LIBRE 0
#define OCUPADO 1
#include "Employees.h"

int main()
{
    eEmployee ArrayEmployees[T];

    initializeState(ArrayEmployees,T);


    char opcion;
    do
    {
        printf("MENU DE OPCIONES: \n");
        printf("\ta. ALTA\n\tb. BAJA\n\tm. MODIFICAR\n\tl. LISTAR\n\ts. Salir\nElija una opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);

        switch(opcion)
        {
            case 'a':

               loadListEmployees(ArrayEmployees,T);

            break;
            case 'b':
                removeEmployee(ArrayEmployees,T);


            break;
            case 'm':
                modifyEmployees(ArrayEmployees, T);

            break;
            case 'l':
                sortEmployeesByName_Sector(ArrayEmployees,T);
                printAllEmployees(ArrayEmployees,T);
                salary(ArrayEmployees,T);
            break;

            default:printf("\nLa opcion ingresada es incorrecta o esta en MAYUSCULA.\n\n");

        }
    }while(opcion!='s');




    return 0;
}
