#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

    Employee *auxEmployee;

    char id[9];
    char nombre[50];
    char horas[15];
    char sueldo[16];
    char auxString[65];

    int error = 0;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fscanf(pFile,"%[^\n]\n",auxString);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);

            auxEmployee = employee_newParametros(id,nombre,horas,sueldo);

            ll_add(pArrayListEmployee,auxEmployee);
        }
        error = 1;
    }
    return error;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee *auxEmployee ;

    int error = 0;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            auxEmployee = employee_new();

            if(fread(auxEmployee,sizeof(Employee),1,pFile) == 1)
            {
                ll_add(pArrayListEmployee,auxEmployee);
            }
        }
        error = 1;
    }
    return error;
}
