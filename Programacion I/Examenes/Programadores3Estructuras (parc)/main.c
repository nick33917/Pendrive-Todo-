#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lib.h"

#define TAMPROG 50
#define TAMPROY 1000
#define TAMCATE 3

int main()
{
    char continuar='s';
    int opcion;

    eProgramador prog[TAMPROG];
    eProyecto proyec[TAMPROY];
    eCategoria cate[TAMCATE];

    fInicializarEstados(prog,TAMPROG);
    fCargarCategorias(cate,TAMCATE);
    fCargarProyectos(proyec);

    while(continuar=='s')
    {
        printf("1- Alta de programador\n");
        printf("2- Modificar datos del programador\n");
        printf("3- Baja del programador\n");
        printf("4- Asignar programador a proyecto\n");
        printf("5- Listado de programadores\n");
        printf("6- Listado de todos los proyectos\n");
        printf("7- Listar proyectos de programador\n");
        printf("8- Proyecto demandante\n");
        printf("9- Salir\n");

        printf("Introduce una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                fLimpiar();
                break;
            case 2:
                fLimpiar();
                break;
            case 3:
                fLimpiar();
                break;
            case 4:
                fLimpiar();
                break;
            case 5:
                fLimpiar();
                break;
            case 6:
                fLimpiar();
                break;
            case 7:
                fLimpiar();
                break;
            case 8:
                fLimpiar();
                break;
            case 9:
                continuar='n';
                break;
        }
    }
    return 0;
}
