#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
#include "funciones.h"
int main()
{
    ArrayList* lista = al_newArrayList();
    ArrayList* lista_negra = al_newArrayList();
    ArrayList* depurada = al_newArrayList();
    ArrayList* sublist= al_newArrayList();
    FILE* destinatarios;
    FILE* black_list;
    char seguir='s';
    int opcion;


    while(seguir=='s')
    {
        system("cls");
        printf("1- Parseo Archivo Lista\n");
        printf("2- Mostrar Personas Lista\n");
        printf("3- Parseo Archivo ListaNegra\n");
        printf("4- Mostrar Personas Lista Negra\n");
        printf("5- Mostrar lista depurada\n");
        printf("6- Mostrar lista depurada y ordenada alfabeticamente\n");
        printf("7- Crear una subLista de la lista destinatarios del indice 3 al 6\n");
        printf("8- Salir\n\n");
        printf("Ingrese la opcion: ");
        scanf("%d",&opcion);
        system("cls");


        switch(opcion)
        {
        case 1:
            destinatarios= fopen("destinatarios.csv","r");
            if(destinatarios!=NULL && lista!=NULL)
            {
                parserPersona(destinatarios,lista);
                printf("Parse Destinatarios OK!!!\n\n");
            }
            system("pause");
            break;
        case 2:
            print_Lista(lista);
            system("pause");
            break;
        case 3:
            black_list= fopen("black_list.csv","r");
            if(black_list!=NULL && lista_negra!=NULL)
            {
                parserPersona(black_list,lista_negra);
                printf("Parse Black_List OK !!!\n\n");
            }
            system("pause");
            break;
        case 4:
            print_Lista(lista_negra);
            system("pause");
            break;
        case 5:
            depurar(lista,lista_negra,depurada);
            print_Lista(depurada);
            system("pause");
            break;
        case 6:
            depurar(lista,lista_negra,depurada);
            depurada->sort(depurada,ordenamiento,1);
            print_Lista(depurada);
            system("pause");
        case 7:
            sublist=sublist->subList(lista,3,6);
            print_Lista(sublist);
            system("pause");
            break;

        case 8:
            seguir='n';
            break;
        default:
            printf("Opcion Incorrecta , Reingrese la opcion!!!\n");
            system("pause");
            break;
        }
    }

    return 0;
}
