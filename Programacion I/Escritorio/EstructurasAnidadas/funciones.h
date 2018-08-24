#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[20];
    int sueldo;

}eProgramador;


typedef struct
{
    int idProy;
    char descrip[20];
    int valorHs;

}eProyecto;


typedef struct
{
    int idProg;
    int idProy;
    int hsTrab;

}eProg_proy;

void cargarProgramadores(eProgramador[],int);

void cargarProyectos(eProyecto[],int);

void mostrarProgramadores(eProgramador[],int);

void mostrarProyectos(eProyecto[],int);



