#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define CANTPROG 3
#define CANTPROY 4
#define CANTPROG_PROY 12
#define CANTCAT 4
int main()
{
    eProgramador equipo[CANTPROG];
    eProyecto proy[CANTPROY];
    eProg_proy relacion[CANTPROG_PROY];
    eCategoria cat[CANTCAT];
    int opcion;


    inicializarVector(equipo,CANTPROG);
    inicializarEn0(relacion,CANTPROG_PROY);
    ingresarUsuarios(equipo,CANTPROG);
    cargarProyecto(proy,CANTPROY);
    cargarProg_proy(relacion,CANTPROG_PROY);
    cargarCat(cat,CANTCAT);

    printf("Ingrese la opcion: ");
    scanf("%d",&opcion);



    switch(opcion)
    {
        case 1:
            system("cls");
            mostrarProg_Proy(equipo,proy,relacion,CANTPROG,CANTPROY,CANTPROG_PROY);
            break;

        case 2:
            system("cls");
            mostrarCadaProyecto(equipo,proy,relacion,CANTPROG,CANTPROY,CANTPROG_PROY);
            break;

        case 3:
            saladrioProg(equipo,relacion,cat,CANTPROG,CANTPROG_PROY,CANTCAT);
            break;

        case 4:
            proyectoConMasProg(equipo,proy,relacion,CANTPROG,CANTPROY,CANTPROG_PROY);
            break;


        default:
            printf("Reingrese la opcion:");
    }

    return 0;
}
