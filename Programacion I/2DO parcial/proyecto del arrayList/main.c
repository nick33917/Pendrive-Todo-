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
    ePersona* personas;
    ePersona* personasDepuradas;
    ePersona* personas_negra;
    int i;
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

        scanf("%d",&opcion);
        system("cls");


        switch(opcion)
        {
        case 1:
            destinatarios= fopen("destinatarios.csv","r");
            if(destinatarios!=NULL && lista!=NULL)
            {
                parserPersona(destinatarios,lista);
                printf("Todo OK !!!");
            }
            system("pause");
            break;
        case 2:
            for(i=0; i<lista->size; i++)
            {
                personas=(ePersona*)lista->get(lista,i);
                printf("%s   %s \n",personas->nombre,personas->mail);
            }
            system("pause");
            break;
        case 3:
            black_list= fopen("black_list.csv","r");
            if(black_list!=NULL && lista_negra!=NULL)
            {
                parserPersona(black_list,lista_negra);
                printf("Todo OK !!!");
            }
            system("pause");
            break;
        case 4:
            for(i=0; i<lista_negra->size; i++)
            {
                personas_negra=(ePersona*)lista_negra->get(lista_negra,i);
                printf("%s   %s \n",personas_negra->nombre,personas_negra->mail);
            }
            system("pause");
            break;
        case 5:
            depurar(lista,lista_negra,depurada);
            for(i=0; i<depurada->len(depurada); i++)
            {
                personasDepuradas=(ePersona*)depurada->get(depurada,i);
                printf("%s   %s \n",personasDepuradas->nombre,personasDepuradas->mail);
            }
            system("pause");
            break;
        case 6:
            depurar(lista,lista_negra,depurada);
            for(i=0; i<depurada->len(depurada); i++)
            {
                depurada->sort(depurada,ordenamiento,1);
                personasDepuradas=(ePersona*)depurada->get(depurada,i);
                printf("%s   %s \n",personasDepuradas->nombre,personasDepuradas->mail);
            }
            system("pause");
        case 7:
            sublist=sublist->subList(lista,3,6);
            for(i=0; i<sublist->size; i++)
            {
                personas_negra=(ePersona*)sublist->get(sublist,i);
                printf("%s   %s \n",personas_negra->nombre,personas_negra->mail);

            }
            system("pause");
            break;

        case 8:
            seguir='n';
            break;

        }
    }

    return 0;
}
