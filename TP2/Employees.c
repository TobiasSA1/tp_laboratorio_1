#include <stdio.h>
#include <string.h>
#define LIBRE 1
#define OCUPADO 0
#include "Employees.h"
/////////////////////////////////////////////////
int initEmployees(eEmployee ArrayEmployees[], int tam)
{
    int error = 1;
    int i;
    if(ArrayEmployees!=NULL && tam >0)
    {
        for(i=0; i<tam; i++)
        {
        ArrayEmployees[i].isEmpty = LIBRE;

        }
        error = 0;
    }
    return error;

}
/////////////////////////////////////////////////
int printEmployees(eEmployee miEmployee)
{
    {
    printf("%3d\t %6d\t %20f\t %5s\t %5s",miEmployee.id,miEmployee.sector,miEmployee.salary,miEmployee.name,miEmployee.lastName);
    }
 return 0;

}
/////////////////////////////////////////////////
int printAllEmployees(eEmployee ArrayEmployees[], int tam)
{
    int i;
    int error = 1;
    if(ArrayEmployees!=NULL&&tam >0)
    {
        printf("\nID:\t SECTOR:\t SALARIO:\t NOMBRE:\t  APELLIDO:\t\n");
        for(i=0; i< tam; i++)
        {
            if(ArrayEmployees[i].isEmpty==OCUPADO)
            {
           printEmployees(ArrayEmployees[i]);
           error = 0;
            }
        }
    }
    return error;
}

/////////////////////////////////////////////////

eEmployee addEmployee()

{
    eEmployee miEmployee;

        printf("Ingrese el sector: \n");
        scanf("%d", &miEmployee.sector);

        printf("Ingrese el salario: \n");
        scanf("%f", &miEmployee.salary);

        printf("Ingrese nombre: \n");
        fflush(stdin);
        fgets(miEmployee.name, 51, stdin);

        printf("Ingrese apellido: \n");
        fflush(stdin);
        fgets(miEmployee.lastName, 51, stdin);

        miEmployee.isEmpty =  OCUPADO;

    return miEmployee;

}

int searchFree(eEmployee ArrayEmployees[],int tam)
{
    int i;
    int indice=-1;
    for(i=0; i<tam; i++)
    {
        if(ArrayEmployees[i].isEmpty==LIBRE)
        {
            indice = i;
            break;
        }
   }
   return indice;
}

void loadListEmployees(eEmployee ArrayEmployees[], int tam ,int legajo)
{
    int indice;
    indice = searchFree(ArrayEmployees, tam);
    if(indice != -1)
    {
        ArrayEmployees[indice] = addEmployee();
        ArrayEmployees[indice].id = legajo;
    }
    else
    {
        printf("No hay lugar.\n");
    }

}


/////////////////////////////////////////////////

int salary(eEmployee ArrayEmployees[], int tam)
{
    int i;
    int j;
    int contSalaryEmployees=0;
    int contEmployees=0;
    float acumEmployees=0;
    float promedio;
    int error=0;

    for(i=0; i<tam; i++)
    {
        if(ArrayEmployees[i].isEmpty==OCUPADO)
        {
            acumEmployees=acumEmployees+ArrayEmployees[i].salary;
            contEmployees++;
            error=1;
        }
    }

    promedio=(float)acumEmployees/contEmployees;

    for(j=0; j<tam; j++)
    {
        if(ArrayEmployees[j].salary>promedio&&ArrayEmployees[j].isEmpty==OCUPADO)
        {
            contSalaryEmployees++;
        }
    }

    if (error==1)
    {
        printf("\nProm salarios: %.2f\n",promedio);
        printf("\nTotal global de salarios: %.2f\n",acumEmployees);
        printf("\nTotal empleados que superan el promedio de salario: %d\n\n",contSalaryEmployees);
    }
    return error;
}

/////////////////////////////////////////////////

int sortEmployeesByName_Sector(eEmployee ArrayEmployees[], int tam)
{
    int i;
    int j;
    int error = 2;
    eEmployee auxEmployee;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(ArrayEmployees[i].sector>ArrayEmployees[j].sector)
            {
                auxEmployee = ArrayEmployees[i];
                ArrayEmployees[i] = ArrayEmployees[j];
                ArrayEmployees[j] = auxEmployee;
                error = 1;
            }
            else
            {
               if(ArrayEmployees[i].sector==ArrayEmployees[j].sector)
               {
                   if(strcmp(ArrayEmployees[i].name,ArrayEmployees[j].name)>0)
                   {
                        auxEmployee = ArrayEmployees[i];
                        ArrayEmployees[i] = ArrayEmployees[j];
                        ArrayEmployees[j] = auxEmployee;
                        error = 0;
                   }
               }
            }
        }

    }
  return error;
}

/////////////////////////////////////////////////

int modifyEmployees(eEmployee ArrayEmployees[], int tam)
{
    int auxInt;
    int i;
    int error = 1;
    char opcion;

    printf("Ingrese el id a modificar: \n");
    scanf("%d", &auxInt);

    for(i=0; i<tam;i++)
    {
        if(auxInt == ArrayEmployees[i].id)
        {
        printf("\nMENU DE OPCIONES \n");
        printf("a. Nuevo sector\nb. Nuevo salario\nc. Nuevo nombre\nd. Nuevo apellido\ns. Salir\nElija una opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);

         switch(opcion)
        {
            case 'a':
            printf("Ingrese el nuevo sector: \n");
            scanf("%d", &ArrayEmployees[i].sector);
            error = 0;
            break;

            case 'b':
            printf("Ingrese el nuevo salario: \n");
            scanf("%f", &ArrayEmployees[i].salary);
            error = 0;
            break;

            case 'c':
            printf("Ingrese nombre: \n");
            fflush(stdin);
            fgets(ArrayEmployees[i].name, 51, stdin);
            error = 0;
            break;

            case 'd':
            printf("Ingrese apellido: \n");
            fflush(stdin);
            fgets(ArrayEmployees[i].lastName, 51, stdin);
            error = 0;
            break;

            case 's':
            printf("Salio del modificar datos!\n"); break;

            default:printf("\nLa opcion ingresada es incorrecta o esta en MAYUSCULA.\n");

        }
    }
    }
    return error;

}
/////////////////////////////////////////////////

int removeEmployee(eEmployee ArrayEmployees[], int tam, int id)
{

    int indice;
    int i;

    indice = findEmployeeById(ArrayEmployees,tam,id);

    for(i=0; i<tam;i++)
    {
        if(indice == ArrayEmployees[i].id)
        {
            ArrayEmployees[i].isEmpty=LIBRE;
            break;
        }


    }

  return 0;
}

int findEmployeeById(eEmployee ArrayEmployees[], int tam,int id)
{
    int i;
    int indice;
    for(i=0; i<tam; i++)
    {
        if (ArrayEmployees[i].id == id && ArrayEmployees[i].isEmpty == OCUPADO)
            {
                indice = ArrayEmployees[i].id;break;
            }
    }

 return indice;
}


