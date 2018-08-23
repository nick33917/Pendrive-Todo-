#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
//#include "funciones.h"



void mostrarPeliculas(EMovie);

int main()
{
    char seguir='s';
    int opcion=0;
    EMovie pelicula;
    int flag;




    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificiar pelicula\n");
        printf("4- Generar pagina web\nn");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {


        case 1:
            system("cls");
            flag=altaPelicula(pelicula);
            if(flag)
            {
                printf("\n\nLa pelicula se cargo exitosamente.\n\n");
            }
            else
            {
                printf("\n\nLa pelicula no se pudo cargar.\n\n");
            }

            break;
        case 2:
            system("cls");
            flag=bajaPelicula(pelicula);
            if(flag)
            {
                printf("\n\nLa pelicula se borro exitosamente.\n\n");
            }
            else
            {
                printf("\n\nLa pelicula no se encontro.\n\n");
            }

            break;
        case 3:
            system("cls");
            flag=modificarPelicula(pelicula);
            if(flag)
            {
                printf("\n\nLa pelicula se modifico exitosamente.\n\n");
            }
            else
            {
                printf("\n\nLa pelicula no se encontro.\n\n");
            }

            break;
        case 4:
            system("cls");
            mostrarPeliculas(pelicula);
            break;


        case 5:
            seguir='n';
            break;


        }
    }
    return 0;

}




