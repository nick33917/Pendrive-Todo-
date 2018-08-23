#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define TAM 2



int main()
{
    EPersona personas[TAM];


    char seguir='s';
    int opcion=0;

    estadosEn0(personas,TAM);



    while(seguir=='s')
    {
        printf("--------------------Sistema para Alta y Baja de personas--------------------\n\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        system("cls");



        switch(opcion)
        {
        case 1:

            /* for(int i=0;i<TAM;i++)
            {
                if(personas[i].estado==0)
                {
                    printf("Ingrese el nombre de la persona: ");
                    fflush(stdin);
                    gets(buffer);
                    while(strlen(buffer)>MAX-1)
                    {
                        printf("Reingrese el Nombre: ");
                        fflush(stdin);
                        gets(buffer);
                    }
                    strcpy(personas[i].nombre,buffer);

                    printf("Ingrese la edad: ");
                    scanf("%d",&personas[i].edad);

                    printf("Ingrese el dni: ");
                    scanf("%d",&personas[i].dni);

                    personas[i].estado=1;

                    break;


                }
                if(personas[TAM].estado==1)

                {
                    printf("no hay mas lugar!!!\n");


                }


            } */
            altaPersona(personas,TAM,MAX);


            break;
        case 2:
            /*printf("Ingrese el dni de la persona a buscar: ");
            scanf("%d",&auxDni);
            indice=buscarPorDni(personas, auxDni , TAM);
            if(indice!=-1)
            {
                printf("Los datos de la persona son: \n \t%d \t%s \t%d",personas[indice].dni,personas[indice].nombre,personas[indice].edad);
                printf("Desea dar de baja del sistema a esta persona? s/n: ");
                fflush(stdin);
                scanf("%c",&eliminar);
                if(eliminar=='s')
                {
                    printf("La persona fue dada de baja");
                    personas[indice].estado=0;
                    break;
                }
                else
                {
                    printf("La persona no fue dada de baja");

                }

            }
            else
            {
                printf("El documento no se encontro en el sistema");

            } */
            bajaPersona(personas,TAM);

            break;
        case 3:
            ordenarNombre(personas,TAM);
            mostrarPersonas(personas,TAM);
            break;
        case 4:
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("La opcion ingresada no es valida !!!\n");
        }

        if(opcion!=5)
        {
            system("pause");
        }

        system("cls");
    }

    return 0;
}






