#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"

int getInt(char* text)
{
    char num[11];

    do
    {
        puts(text);
        fflush(stdin);
        gets(num);

    }while(!validationInt(num));

    return atoi(num);
}

int validationInt(char* string)
{
    int i;
    int validacion = 1;

    for(i=0;i<strlen(string);i++)
    {
        if(string[i]<48 || string[i]>57)
        {
            validacion = 0;
            break;
        }
    }

    if(validacion == 0)
    {
            printf("\nDebe ingresar un numero entero\n\n");
    }

    return validacion;
}

int validationString(char* string)
{
    int i;
    int validacion = 1;

    strlwr(string);

    for(i=0;i<strlen(string);i++)
    {
        if(string[i]<97 || string[i]>122)
        {
            validacion = 0;
            break;
        }
    }
    if(validacion == 0)
    {
        printf("\nDebe ingresar solo letras...\n\n");
    }
    return validacion;
}


int validationFloat(char* string)
{
    int i;
    int puntosCont = 0;
    int validacion = 1;

    for(i=0;i<strlen(string);i++)
    {
        if(string[i] == '.')
        {
            puntosCont++;
        }
        else if(string[i] < 48 || string[i] > 57)
        {
            validacion = 0;
            break;
        }
    }

    if(puntosCont>1)
    {
        validacion = 0;
    }

    if(validacion == 0)
    {
        printf("\nDebe ingresar bien el valor\n\n");
    }
    return validacion;
}

float getFloat(char* text)
{
    char string[20];
    float num;

    do{
        puts(text);
        fflush(stdin);
        gets(string);

    }while(!validationFloat(string));

    num = atof(string);

    return num;
}

void getString(char* text,char* string)
{
        fflush(stdin);
        puts(text);
        gets(string);
}
