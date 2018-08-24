#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;

    int contId = 0;

    ArrayList* listaClientes = al_newArrayList();
    ArrayList* listaServicios = al_newArrayList();


    while(seguir=='s')
    {
        printf("1- Alta de cliente\n");
        printf("2- Modificacion del cliente\n");
        printf("3- Baja del cliente\n");
        printf("4- Listar clientes\n");
        printf("5- Importar servicios tecnicos desde csv\n");
        printf("6- Ingresar un servicio tecnico\n");
        printf("7- Finalizar un servicio tecnico\n");
        printf("8- Exportar servicios tecnicos de un cliente\n");
        printf("9- Imprimir servicios tecnicos por productos\n");
        printf("10- Informar\n");

        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            contId++;
            alta_cliente(listaClientes, contId);
            break;
        case 2:
            system("cls");
            modif_cliente(listaClientes);
            break;
        case 3:
            system("cls");
            baja_cliente(listaClientes);
            break;
        case 4:
            system("cls");
            ordenar(listaClientes);
            imprimirClientes(listaClientes);
            break;
        case 5:
            system("cls");
            importar_Servicios(listaClientes, listaServicios);
            imprimirServicios(listaServicios);
            break;
        case 6:
            system("cls");
            alta_servicio(listaServicios, listaClientes);
            imprimirServicios(listaServicios);
            break;
        case 7:
            system("cls");
            finalizarServicio(listaServicios);
            imprimirServicios(listaServicios);
            break;
        case 8:
            system("cls");
            break;
        case 9:
            system("cls");
            ordenarS(listaServicios);
            imprimirServicios(listaServicios);
            break;
        case 10:
            system("cls");
            break;
        default:
            system("cls");
            printf("Error, ingrese una opcion valida... \n");
            break;
        }
    }

    return 0;
}
