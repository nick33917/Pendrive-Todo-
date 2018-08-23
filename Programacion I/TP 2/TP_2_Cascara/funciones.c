#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void estadosEn0(EPersona personas[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        personas[i].estado=0;
    }
}

int buscarPorDni(EPersona lista[], int docum, int tam)
{
    int indice=-1,i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].dni==docum && lista[i].estado ==1)
        {
            indice=i;
            break;
        }

    }

    return indice;

}


void ordenarNombre(EPersona lista[],int tam)
{
    char buffer[50];
    int aux, i, j;
    EPersona auxEPersona;

    //
    //printf("lista -> Nombre: %s - Edad: %d - DNI: %d - Estado: %d", lista[0].nombre, lista[0].edad, lista[0].dni, lista[0].estado );
    //
    //return;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre) >0 )
            {
                auxEPersona = lista[j];
                lista[j] = lista[i];
                lista[i] = auxEPersona;

                /*strcpy(buffer,lista[j].nombre);
                strcpy(lista[j].nombre,lista[i].nombre);
                strcpy(lista[i].nombre,buffer);

                aux=lista[j].edad;
                lista[j].edad=lista[i].edad;
                lista[i].edad=aux;

                aux=lista[j].dni;
                lista[j].dni=lista[i].dni;
                lista[i].dni=aux; */



            }
        }

    }

}
void mostrarPersona(EPersona unaPersona)
{
    printf("%d\t %s\t %d\t \n",unaPersona.dni,unaPersona.nombre,unaPersona.edad);

}

void mostrarPersonas(EPersona lista[],int tam)
{
    int flag=-1, i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            mostrarPersona(lista[i]);
            flag=1;
        }

    }
    if(flag==-1)
    {
        printf("No hay ninguna persona cargada para mostrar\n");
    }


}

int obtenerEspacioLibre(EPersona lista[],int tam)
{
    int indice=-1, i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;

}

void altaPersona(EPersona lista[],int tam,int maximo)
{
    EPersona nuevaPersona;
    int lugar;
    int esta;
    int dni;
    int aux;
    char buffer[2000];
    lugar=obtenerEspacioLibre(lista,tam);
    if(lugar==-1)
    {
        printf("No hay mas lugar para cargar Personas !!! \n");

    }
    else
    {
        printf("Ingrese el dni: ");
        scanf("%d",&dni);
        esta=buscarPorDni(lista,dni,tam);
        if(esta!=-1)
        {
            printf("\nEl dni: %d  ya fue ingresado !!!",dni);


        }
        else
        {
            while(validarDni(dni)==0)
            {
                printf("\nReingrese el dni: ");
                scanf("%d",&dni);
            }
            nuevaPersona.dni=dni;

            printf("\nIngrese el nombre: ");
            fflush(stdin);
            gets(buffer);
            while(validarNombre(buffer,maximo)==0)
            {
                printf("\nReingre el nombre: ");
                fflush(stdin);
                gets(buffer);
            }
            strcpy(nuevaPersona.nombre,buffer);

            printf("\nIngrese la edad: ");
            scanf("%d",&aux);
            while(validarEdad(aux)==0)
            {
                printf("\nReingrese la Edad: ");
                scanf("%d",&aux);

            }
            nuevaPersona.edad=aux;

            nuevaPersona.estado=1;
            lista[lugar]=nuevaPersona;


        }

    }


    printf("\n");

    printf("nuevaPersona -> Nombre: %s - Edad: %d - DNI: %d - Estado: %d\n", nuevaPersona.nombre, nuevaPersona.edad, nuevaPersona.dni, nuevaPersona.estado );
    printf("lista -> Nombre: %s - Edad: %d - DNI: %d - Estado: %d", lista[0].nombre, lista[0].edad, lista[0].dni, lista[0].estado );


}

void bajaPersona(EPersona lista[],int tam)
{
    int dni;
    int i;
    char eliminar='n';
    printf("Ingrese el dni de la persona a buscar: ");
    scanf("%d",&dni);
    i=buscarPorDni(lista, dni, tam);
    if(i!=-1)
    {
        printf("\tLos datos de la persona son: \nDNI----------NOMBRE--------EDAD\n");
        printf("%d     %s        %d\n",lista[i].dni,lista[i].nombre,lista[i].edad);
        printf("Desea dar de baja del sistema a esta persona? s/n: ");
        fflush(stdin);
        scanf("%c",&eliminar);
        if(eliminar=='s')
        {
            printf("\nLa persona fue dada de baja\n");
            lista[i].estado=0;

        }
        else
        {
            printf("\nLa persona no fue dada de baja\n");

        }

    }
    else
    {
        printf("\nEl documento no se encontro en el sistema\n");

    }


}


int validarNombre(char aux[],int maximo)
{
    int flag=0;
    if(strlen(aux)<maximo-1)
    {
        flag=1;
    }
    return flag;
}

int validarEdad(int anios)
{
    int flag=0;
    if(anios>0 && anios<130)
    {
        flag=1;
    }

    return flag;
}

int validarDni(int doc)
{
    int flag=0;
    if(doc>0)
    {
        flag=1;
    }
    return flag;
}







