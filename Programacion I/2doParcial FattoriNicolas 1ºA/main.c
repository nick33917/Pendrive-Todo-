#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
#include "funciones.h"

int main()
{
    ArrayList* lista = al_newArrayList();
    ArrayList* lista_negra = al_newArrayList();
    ArrayList* depurada = al_newArrayList();

    FILE* destinatarios;
    FILE* black_list;
    char seguir='s';
    int opcion;
    char archivoLista [30];
    char archivoListaNegra [30];
    int aux;

    while(seguir=='s')
    {
        system("cls");
        printf("**************Compania de servicios de Marketing*************\n\n");
        printf("1- Parseo Archivo Lista\n");
        printf("2- Parseo Archivo Black_List\n");
        printf("3- Genero Lista Depurada\n");
        printf("4- Mostrar lista depurada\n");
        printf("5- Salir\n\n");
        printf("Ingrese la opcion: ");
        scanf("%d",&opcion);
        system("cls");


        switch(opcion)
        {
        case 1:
           // printf("Ingrese el nombre del archivo: ");
            //fflush(stdin);
           // gets(archivoLista);
            destinatarios= fopen("destinatarios.csv","r");
            if(destinatarios!=NULL && lista!=NULL)
            {
                parserPersona(destinatarios,lista);
                printf("Archivo Destinatario Cargado!!!\n\n");
            }
            else
            {
                printf("No se pudo cargar el archivo!!!\n\n");
            }
            system("pause");
            break;
        case 2:
            //printf("Ingrese el nombre del archivo: ");
            //fflush(stdin);
            //gets(archivoListaNegra);
            black_list= fopen("black_list.csv","r");
            if(black_list!=NULL && lista_negra!=NULL)
            {
                parserBlackList(black_list,lista_negra,lista);
                printf("Archivo Black_List Cargado!!!\n\n");
            }
            else
            {
                printf("No se pudo cargar el archivo!!!\n\n");
            }
            system("pause");
            break;
        case 3:
            aux = depurar(lista,lista_negra,depurada);
            if(aux)
            {
                printf("La lista depurada fue creada!!!\n");
            }
            else
            {
                printf("La lista depurada no se pudo crear!!!\n\n");

            }
            system("pause");
            break;
        case 4:
            mostrarLista(depurada);
            system("pause");
            break;
        case 5:
            mostrarLista(lista_negra);
            system("pause");
            //seguir='n';
            break;
        default:
            printf("La opcion ingresada es incorrecta, Reeingrese la opcion !!!\n\n");
            system("pause");
            break;

        }
    }

    return 0;
}
