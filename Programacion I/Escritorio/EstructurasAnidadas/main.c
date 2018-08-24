#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define TAMPROG 3
#define TAMPROY 4
#define TAMPROG_PROY 12

int main()
{
    eProgramador programadores[TAMPROG];
    eProyecto proyectos[TAMPROY];
    eProg_proy relacion[TAMPROG_PROY];

    int opcion;
    printf("Ingrese la opcion :");
    scanf("%d",&opcion);

    switch(opcion)
    {


        case 1:
            cargarProgramadores(programadores,TAMPROG);
            printf("-----PROGRAMADORES----\n");
            mostrarProgramadores(programadores,TAMPROG);
            cargarProyectos(proyectos,TAMPROG_PROY);
            printf("-------PROYECTOS--------\n");
            mostrarProyectos(proyectos,TAMPROY);
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            break;
    }

    return 0;
}
