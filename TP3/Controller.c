#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "Validaciones.h"
#include "parser.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;

    int error;

    pArchivo = fopen(path,"r");

    error = parser_EmployeeFromText(pArchivo,pArrayListEmployee);

    fclose(pArchivo);

    return error;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;

    int error;

    pArchivo = fopen(path,"rb");

    error = parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);

    fclose(pArchivo);

    return error;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int error = 0;

    if(pArrayListEmployee != NULL)
    {
        Employee* employee;
        Employee auxEmployee;

        auxEmployee.id = autoIncrementID(pArrayListEmployee);

        getString("Ingrese su nombre: ",auxEmployee.nombre);

        auxEmployee.horasTrabajadas = getInt("Ingrese la cantidad de horas trabajadas: ");

        auxEmployee.sueldo = getInt("Igrese su sueldo: ");

        employee = employee_new();
        *employee = auxEmployee;
        ll_add(pArrayListEmployee,employee);

        system("cls");
        error = 1;
    }
    return error;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;

    int id;
    int indice;
    int opcion;
    char auxString[50];

    int error = 0;

    if(pArrayListEmployee != NULL)
    {
        id = getInt("Ingrese el ID del empleado: ");

        indice = findEmployeeById(pArrayListEmployee,id);

        if(indice != -1)
        {
            auxEmployee = ll_get(pArrayListEmployee,indice);

            do{
                printf("\nIngrese el campo que quiere modificar: \n\n");

                opcion = getInt("1 Nombre\n2 Horas trabajadas\n3 Sueldo\n4 Salir \n\nIngrese una opcion: ");

                switch(opcion)
                {
                    case 1: getString("Ingrese nuevo nombre:",auxString);
                            employee_setNombre(auxEmployee,auxString);break;
                        //employee_setNombre(auxEmployee,getString("Ingrese nuevo nombre:",auxString));break;/No se puede porque getString es void/

                    case 2: employee_setHorasTrabajadas(auxEmployee,getInt("Ingresar nuevas horas trabajadas: "));break;

                    case 3: employee_setSueldo(auxEmployee,getInt("Ingresar nuevao sueldo: "));break;

                    case 4: break;

                    default: printf("\nOpcion invalida\n");break;
                }

            }while(opcion!=4);

            system("cls");
            error = 1;
        }
    }
    return error;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int indice;
    int error = 0;

    if(pArrayListEmployee != NULL)
    {
        id = getInt("Ingresar id del empleado a Eliminar: ");

        indice = findEmployeeById(pArrayListEmployee,id);

        if(indice != -1)
        {
            error = !ll_remove(pArrayListEmployee,indice);
        }
    }
    system("cls");
    return error;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int size;

    int error = 0;

    if(pArrayListEmployee != NULL)
    {
        size = ll_len(pArrayListEmployee);

        printf("  ID\t    NOMBRE   HORAS T.  SUELDO\n");

        for(int i=0; i<size; i++)
        {
            auxEmployee =(Employee*) ll_get(pArrayListEmployee, i);

            employeeToShow(*auxEmployee);
        }
        error = 1;
    }

    return error;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int error = 1;

    printf("Ordenamiento por... ");
    printf("1 Nombre.");
    printf("2 ID. ");

    do
    {
        opcion = getInt("Ingresar opcion:");

        if(opcion == 1)
        {
            printf("Ordenamiento: ");
            printf("1 Ascendente.");
            printf("2 Descendente. ");

            opcion = getInt("Ingresar opcion:");

            if(opcion == 1)
            {
                ll_sort(pArrayListEmployee,&cmpemployeeName,1);
            }
            else if (opcion == 2)
            {
                ll_sort(pArrayListEmployee,&cmpemployeeName,0);
            }
        }
        if (opcion == 2)
        {
            printf("Ordenamiento: ");
            printf("1 Ascendente.");
            printf("2 Descendente. ");

            opcion = getInt("Ingresar opcion:");

            if(opcion == 1)
            {
                ll_sort(pArrayListEmployee,&cmpemployeeId,1);
            }
            else if (opcion == 2)
            {
                ll_sort(pArrayListEmployee,&cmpemployeeId,0);
            }
        }

        else
        {
            printf("Opcion invalida:\n");
        }

    }while(opcion != 1 || opcion != 2);

    system("cls");

    return error;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* auxEmployee;

    int size;
    int error = 0;
    int i;

    if(pArrayListEmployee != NULL)
    {
        size = ll_len(pArrayListEmployee);

        pArchivo = fopen(path,"w");

        if(pArchivo != NULL)
        {
            fprintf(pArchivo,"ID,NOMBRE,HORASTRABAJADAS,SUELDO\n");

            for(i=0;i<size;i++)
            {
                auxEmployee = ll_get(pArrayListEmployee,i);

                fprintf(pArchivo,"%d,%s,%d,%d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
            }

            fclose(pArchivo);
            error = 1;
        }
    }

    return error;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee *auxEmployee;

    int i;
    int size;
    int error = 0;

    if(pArrayListEmployee != NULL)
    {
        size = ll_len(pArrayListEmployee);

        pArchivo = fopen(path,"wb");

        if(pArchivo != NULL)
        {
            for(i=0;i<size;i++)
            {
                auxEmployee = ll_get(pArrayListEmployee,i);

                fwrite(auxEmployee,sizeof(Employee),1,pArchivo);
            }

            fclose(pArchivo);
            error = 1;
        }
    }
    return error;
}

int findEmployeeById(LinkedList* pArrayListEmployee,int id)
{
    Employee* auxEmployee;

    int size;
    int auxId;
    int i;

    size = ll_len(pArrayListEmployee);

    for(i=0;i<size;i++)
    {
        auxEmployee = ll_get(pArrayListEmployee,i);

        employee_getId(auxEmployee,&auxId);

        if(auxId == id)
        {
            return i;
        }
    }
    return -1;
}

void menu()
{
    printf("Menu de opciones: \n");

    printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf(" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf(" 3. Alta de empleado\n");
    printf(" 4. Modificar datos de empleado\n");
    printf(" 5. Baja de empleado\n");
    printf(" 6. Listar empleados\n");
    printf(" 7. Ordenar empleados\n");
    printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf(" 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n");
}
