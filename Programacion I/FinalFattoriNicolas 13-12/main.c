#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
#include "funciones.h"
int main()
{
    ArrayList* cliente=al_newArrayList();
    ArrayList* servicios=al_newArrayList();
    FILE* clientes;
    FILE* servicios;
    int i;
    char seguir='s';
    int opcion;
    int aux;
    //  printeo(cliente);
    while(seguir=='s')
    {
        system("cls");
        printf("**************Compania de servicios de Marketing*************\n\n");
        printf("1- Alta persona\n");
        printf("2- Printeo\n");
        printf("3- salir\n");
        printf("4- modificar empleado\n");
        printf("Ingrese la opcion: ");
        scanf("%d",&opcion);
        system("cls");


        switch(opcion)
        {
        case 1:
            aux=altaCliente(cliente);
            if(aux==1)
            {
                printf("se cargo corrctamente");
            }
            system("pause");
            break;
        case 2:
            modificarCliente(cliente);
            break;
        case 3:
            bajaCliente(cliente);
            break;
        case 4:
            ordenarYMuestra(cliente);
            system("pause");
            break;

        case 5:
            seguir='n';
            break;


        }
    }

    return 0;
}
