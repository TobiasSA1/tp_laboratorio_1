#include <stdlib.h>
#include "Employee.h"
#include <string.h>
#include <stdio.h>

Employee* employee_new()
{
    Employee *employee =(Employee*)malloc(sizeof(Employee));
    return employee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee *employee;
    employee = employee_new();

    employee->id = atoi(idStr);
    strcpy(employee->nombre,nombreStr);
    employee->horasTrabajadas = atoi(horasTrabajadasStr);
    employee->sueldo = atoi(sueldoStr);

    return employee;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int error = 0;

    if(this != NULL)
    {
        strcpy(this->nombre,nombre);
        error = 1;
    }

    return error;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int error = 0;

    if(this != NULL)
    {
        strcpy(nombre,this->nombre);
        error = 1;
    }

    return error;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int error = 0;

    if(this != NULL)
    {
        this->sueldo = sueldo;
        error = 1;
    }

    return error;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int error = 0;

    if(this != NULL)
    {
        *sueldo = this->sueldo;
        error = 1;
    }
    return error;
}

int employee_setId(Employee* this,int id)
{
    int error = 0;

    if(this != NULL)
    {
        this->id = id;
        error = 1;
    }
    return error;
}
int employee_getId(Employee* this,int* id)
{
    int error = 0;

    if(this != NULL)
    {
        *id = this->id;
        error = 1;
    }

    return error;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int error = 0;

    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        error = 1;
    }

    return error;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajdas)
{
    int error = 0;

    if(this != NULL)
    {
        *horasTrabajdas = this->horasTrabajadas;
        error = 1;
    }

    return error;
}

int cmpemployeeName(void* employee, void* employee2)
{
    employee = (Employee*) employee;
    employee2 = (Employee*) employee2;

    char nombre[128];
    char nombre2[128];

    int error = 0;

    if (employee != NULL && employee2 != NULL)
    {
        employee_getNombre(employee,nombre);
        employee_getNombre(employee2,nombre2);
        error = strcmpi(nombre, nombre2);
    }
    return error;
}

int cmpemployeeId(void* employee, void* employee2)
{
    employee = (Employee*) employee;
    employee2 = (Employee*) employee2;

    int id;
    int id2;

    int error = 0;

    if(employee != NULL && employee2 != NULL)
    {
        employee_getId(employee,&id);
        employee_getId(employee2,&id2);
        if(id > id2)
        {
            error = 1;
        }
        else
        {
            if(id < id2)
            {
                error = -1;
            }
        }
    }
    return error;
}

void employeeToShow(Employee employee)
{
    printf("%4d %13s %6d %9d\n",employee.id,employee.nombre,employee.horasTrabajadas,employee.sueldo);
}

int autoIncrementID(LinkedList* pArrayListEmployee)
{
    Employee *employee;

    int i;
    int id;
    int size;
    int lastId;

    size = ll_len(pArrayListEmployee);

    if(size == 0)
    {
        id = 1;
    }

    else
    {
        for(i=0;i<size;i++)
        {
            employee = ll_get(pArrayListEmployee,i);

            employee_getId(employee,&id);

            if(i == 0 || lastId < id )
            {
                lastId = id;
            }
        }
        id = lastId +1;
    }
    return id;
}


