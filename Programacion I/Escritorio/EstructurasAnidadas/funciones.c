#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
//carga los programadores//
void cargarProgramadores(eProgramador lista[],int tamprogramadores)
{
    int id[]= {1,2,3};
    char nombre[][20]= {"Lucas","Juan","Martin"};
    int i;

    for(i=0;i<tamprogramadores;i++)
    {
        lista[i].id=id[i];
        strcpy(lista[i].nombre,nombre[i]);
    }
}

void cargarProyectos(eProyecto trabajos[],int tamproyecto)
{
    int idProy[]={10,11,12,13};
    char descrip[][20]={"SS.Gestion","Afip","Arba","Web Service"};
    int valorxHs[]={50,100,150,170};
    int i;

    for(i=0;i<tamproyecto;i++)
    {
        trabajos[i].idProy=idProy[i];
        strcpy(trabajos[i].descrip,descrip[i]);
        trabajos[i].valorHs=valorxHs[i];
    }
}

void mostrarProgramadores(eProgramador lista[],int tamprogramadores)
{
    int i;
    for(i=0;i<tamprogramadores;i++)
    {
        printf("%d     %s\n",lista[i].id,lista[i].nombre);
        printf("---------------------------------\n");
    }

}

void mostrarProyectos(eProyecto trabajos[],int tamproyecto)
{
    int i;
    for(i=0;i<tamproyecto;i++)
    {
        printf("%d     %s     %d\n",trabajos[i].idProy,trabajos[i].descrip,trabajos[i].valorHs);
    }

}



