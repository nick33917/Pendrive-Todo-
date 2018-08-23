#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Estructura.h"
#include "Parser.h"

int main()
{
    char seguir='s';
    int opcion=0;

    char path1[150];
    char path2[150];

    int respuesta;

    ArrayList* listaBlanca = al_newArrayList();
    ArrayList* listaNegra = al_newArrayList();
    ArrayList* listaFinal = al_newArrayList();

    while(seguir=='s')
    {
        printf("1- Cargar destinatarios\n");
        printf("2- Cargar lista negra\n");
        printf("3- Depurar\n");
        printf("4- Listar\n");
        printf("5- Salir\n");

        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");

            printf("Ingrese nombre del archivo 1 (Destinatarios): ");
            scanf("%s",path1);

            //strcpy(path1, "destinatarios.csv");

            FILE* pFileListaB;

            if((pFileListaB=fopen(path1, "r+"))==NULL)
            {
                printf("No se ha podido leer los archivos\n");
                exit(1);
            }

            //Parseo la lista blanca
            respuesta = parserGenerico(pFileListaB, listaBlanca, path1);

            if(respuesta == 0)
            {
                printf("Se han cargado los destinatarios correctamente!\n");
            }
            else
                printf("Error!!!, fallo al cargar los destinatarios!\n");

            break;
        case 2:
            system("cls");

            printf("Ingrese nombre del archivo 2 (Black List): ");
            scanf("%s",path2);

            FILE* pFileListaN;

            //strcpy(path2, "black_list.csv");

            if((pFileListaN=fopen(path2, "r+"))==NULL)
            {
                printf("No se ha podido leer los archivos\n");
                exit(1);
            }

            //Parseo la lista negra
            respuesta = parserGenerico(pFileListaN, listaNegra, path2);

            if(respuesta == 0)
            {
                printf("Se ha cargado la Black List correctamente!\n");
            }
            else
                printf("Error!!!, fallo al cargar la Black List!\n");

            break;
        case 3:
            system("cls");
            //Hago la lista definitiva
            respuesta = listaDefinitiva(listaBlanca, listaNegra, listaFinal);

            if(respuesta == 0)
            {
                printf("Se ha depurado correctamente!\n");
            }
            else
                printf("Error!!!, fallo al depurar!\n");
            break;
        case 4:
            system("cls");
            ordenar(listaFinal);
            printf("------------------------------------------------------------\n");
            printf("LISTA FINAL (DEPURADA): \n");
            printf("------------------------------------------------------------\n");
            imprimir(listaFinal);
            printf("------------------------------------------------------------\n");
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            system("cls");
            printf("Error, ingrese una opcion valida... \n");
            break;
        }
    }


    return 0;
}
