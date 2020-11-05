#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Validaciones.h"

int main()
{
    int opcion;
    int barrera=0;

    LinkedList* pArrayListEmployee = ll_newLinkedList();

    do{
        menu();

        opcion = getInt("\nIngrese una opcion:");

        switch(opcion)
        {
            case 1: if(controller_loadFromText("data.csv",pArrayListEmployee))
                    {
                    printf("\nSe cargaron los datos.\n");

                    }

                    else
                    {
                    printf("\nNo se cargaron los datos.\n");
                    }
                break;

            case 2: if(controller_loadFromBinary("data.bin",pArrayListEmployee))
                    {
                    printf("\nSe cargaron los datos.\n");

                    }

                    else
                    {
                    printf("\nNo se cargaron los datos.\n");
                    }
                break;

            case 3:

                        if(controller_addEmployee(pArrayListEmployee))
                        {
                        printf("\nSe agrego el empleado.\n");
                        }

                        else
                        {
                        printf("\nNo se pudo agregar el empleado.\n");
                        }
                break;

            case 4:
                        if(controller_editEmployee(pArrayListEmployee))
                        {
                        printf("\nSe edito el empleado.\n");
                        }

                        else
                        {
                        printf("\nNo se pudo editar el empleado.\n");
                        }
                break;

            case 5:
                    if(controller_removeEmployee(pArrayListEmployee))
                    {
                    printf("\nSe removio el empleado.\n");
                    }

                    else
                    {
                    printf("\nNo se pudo remover el empleado.\n");
                    }
                break;

            case 6:
                    if(controller_ListEmployee(pArrayListEmployee)==0)
                    {
                    printf("\nNo hay lista.\n");
                    }


                break;

            case 7:
                    if(controller_sortEmployee(pArrayListEmployee))
                    {
                    printf("\nSe ordeno la lista.\n");
                    }

                    else
                    {
                    printf("No se pudo ordenar la lista.\n");
                    }
                break;

            case 8:
                    printf("\nSi no cargo los datos del archivo, se sobreescribiran. ¿Desea cargarlos y luego guardar?: \n");
                    printf("1 Si\n2 No\n");
                    printf("Ingrese su opcion: ");
                    scanf("%d",&barrera);

                        switch(barrera)
                        {
                            case 1:

                                controller_loadFromText("data.csv",pArrayListEmployee);
                                if(controller_saveAsText("data.csv",pArrayListEmployee))
                                {
                                printf("\nSe guardo correctamente\n");
                                }

                                else
                                {
                                printf("\nNo se pudo guardar\n");
                                }
                            break;

                            case 2:
                                if(controller_saveAsText("data.csv",pArrayListEmployee))
                                {
                                printf("\nSe guardo correctamente\n");
                                }

                                else
                                {
                                printf("\nNo se pudo guardar\n");
                                }
                            break;
                        }
                break;

            case 9:
                    printf("\nSi no cargo los datos del archivo, se sobreescribiran. Desea cargarlos y luego guardar?: \n");
                    printf("1 Si\n2 No\n");
                    printf("Ingrese su opcion: ");

                    scanf("%d",&barrera);

                        switch(barrera)
                        {
                            case 1:

                                controller_loadFromBinary("data.bin",pArrayListEmployee);

                                if(controller_saveAsBinary("data.bin",pArrayListEmployee))
                                {
                                printf("\nSe guardo correctamente\n");
                                }

                                else
                                {
                                printf("\nNo se pudo guardar\n");
                                }
                            break;


                            case 2:
                                if(controller_saveAsBinary("data.bin",pArrayListEmployee))
                                {
                                printf("\nSe guardo correctamente\n");
                                }

                                else
                                {
                                printf("\nNo se pudo guardar\n");
                                }
                            break;

                            default: printf("\nOpcion invalida\n");
                    }
                break;

            case 10:break;

            default: printf("\nOpcion invalida\n");break;
        }
    }while(opcion != 10);

    return 0;
}
