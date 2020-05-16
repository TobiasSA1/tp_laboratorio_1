#include <stdio.h>
#include <string.h>
#define T 10
#define LIBRE 0
#define OCUPADO 1
#include "Employees.h"

/**
 * @brief Inicializa el estado del empleado
 * @param ArrayEmployees
 * @param el tamaño del array
 * @return Una nueva matriz C = AxB.
 */
void initializeState(eEmployee ArrayEmployees[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        ArrayEmployees[i].isEmpty = LIBRE;

    }
}

/**
 * @brief Busca espacios libres
 * @param ArrayEmployees
 * @param el tamaño del array
 * @return el indice, si encontro o no un espacio libre
 */

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

/**
 * @brief Carga de empleados
 * @return El empleado cargado
 */

eEmployee addEmployee()

{
    eEmployee miEmployee;

        printf("Ingrese el id: \n");
        scanf("%d", &miEmployee.id);

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

/**
 * @brief Remueve empleados en base al ID
 * @param ArrayEmployees
 * @param el tamaño del array
 * @return
 */

int removeEmployee(eEmployee ArrayEmployees[], int tam)
{
    int auxInt;
    int i;

    printf("\nIngrese el id a eliminar:\n ");
    scanf("%d", &auxInt);
    for(i=0; i<tam;i++)
    {
        if(auxInt == ArrayEmployees[i].id)
        {
            ArrayEmployees[i].isEmpty=LIBRE;
            break;
        }
        else
        {
             printf("El id ingresado no es valido\n");break;
        }
    }


}

/**
 * @brief Modifica empleados en base al ID
 * @param ArrayEmployees
 * @param el tamaño del array
 * @return
 */

int modifyEmployees(eEmployee ArrayEmployees[], int tam)
{
    int auxInt;
    int i;
    char opcion;

    printf("Ingrese el id a modificar: \n");
    scanf("%d", &auxInt);

    for(i=0; i<tam;i++)
    {
        if(auxInt == ArrayEmployees[i].id)
        {
        printf("MENU DE OPCIONES \n");
        printf("a. Nuevo sector\nb. Nuevo salario\nc. Nuevo nombre\nd. Nuevo apellido\ns. Salir\nElija una opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);

         switch(opcion)
        {
            case 'a':
            printf("Ingrese el nuevo sector: \n");
            scanf("%d", &ArrayEmployees[i].sector); break;

            case 'b':
            printf("Ingrese el nuevo salario: \n");
            scanf("%f", &ArrayEmployees[i].salary); break;

            case 'c':
            printf("Ingrese nombre: \n");
            fflush(stdin);
            fgets(ArrayEmployees[i].name, 51, stdin);break;

            case 'd':
            printf("Ingrese apellido: \n");
            fflush(stdin);
            fgets(ArrayEmployees[i].lastName, 51, stdin);break;

            case 's':
            printf("Salio del modificar datos!\n"); break;

            default:printf("\nLa opcion ingresada es incorrecta o esta en MAYUSCULA.\n");

        }
    }
    }
}

/**
 * @brief Muestra todos empleados
 * @param ArrayEmployees
 * @param el tamaño del array
 * @return
 */

void printAllEmployees(eEmployee ArrayEmployees[], int tam)
{
    int i;
    printf("ID:\t SECTOR:\t SALARIO:\t NOMBRE:\t  APELLIDO:\t\n");
    for(i=0; i< tam; i++)
    {
        if(ArrayEmployees[i].isEmpty==OCUPADO)
       {
           printEmployees(ArrayEmployees[i]);
       }
    }
}

/**
 * @brief Muestra un empleado
 * @param ArrayEmployees
 * @param el tamaño del array
 * @return
 */

void printEmployees(eEmployee miEmployee)
{

            printf("%d\t %d\t %f\t %s\t %s\t\n",miEmployee.id,miEmployee.sector,miEmployee.salary,miEmployee.name,miEmployee.lastName);

}

/**
 * @brief Carga el searchFree y si retorna un -1 carga la funcion addEmployee para cargar un empleado
 * @param ArrayEmployees
 * @param el tamaño del array
 * @return
 */

void loadListEmployees(eEmployee ArrayEmployees[], int tam)
{
    int indice;
    indice = searchFree(ArrayEmployees, tam);
    if(indice != -1)
    {
        ArrayEmployees[indice] = addEmployee();
    }
    else
    {
        printf("No hay lugar.\n");
    }

}

/**
 * @brief Ordena los empleados por sector y nombre
 * @param ArrayEmployees
 * @param el tamaño del array
 * @return
 */

void sortEmployeesByName_Sector(eEmployee ArrayEmployees[], int tam)
{
    int i;
    int j;
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
                   }
               }
            }
        }

    }
}

/**
 * @brief Muestra el total de salario, el promedio de salario y el total de empleados que superan ese promedio
 * @param ArrayEmployees
 * @param el tamaño del array
 * @return
 */


int salary(eEmployee ArrayEmployees[], int tam)
{
    int i;
    int j;
    int contSalaryEmployees=0;
    int contEmployees=0;
    float acumEmployees=0;
    float promedio;
    int retorno=0;

    for(i=0; i<tam; i++)
    {
        if(ArrayEmployees[i].isEmpty==1)
        {
            acumEmployees=acumEmployees+ArrayEmployees[i].salary;
            contEmployees++;
            retorno=1;
        }
    }

    promedio=(float)acumEmployees/contEmployees;

    for(j=0; j<tam; j++)
    {
        if(ArrayEmployees[j].salary>promedio&&ArrayEmployees[j].isEmpty==1)
        {
            contSalaryEmployees++;
        }
    }

    if (retorno==1)
    {
        printf("\nProm salarios: %.2f\n",promedio);
        printf("\nTotal global de salarios: %.2f\n",acumEmployees);
        printf("\nTotal empleados que superan el promedio de salario: %d\n\n",contSalaryEmployees);
    }
    return retorno;
}
