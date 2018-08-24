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

    ArrayList* listaClientes = al_newArrayList();
    ArrayList* listaVentas = al_newArrayList();

    parser_cliente(listaClientes); /** CARGO EL ARCHIVO EN MEMORIA (EN LA LISTA) **/
    parser_venta(listaVentas); /** CARGO EL ARCHIVO EN MEMORIA (EN LA LISTA) **/

    while(seguir=='s')
    {
        printf("1- Alta de cliente\n");
        printf("2- Modificacion del cliente\n");
        printf("3- Baja del cliente\n");
        printf("4- Listar clientes\n");
        printf("5- Realizar una venta\n");
        printf("6- Anular una venta\n");
        printf("7- Informar ventas\n");
        printf("8- Informar ventas por producto\n");
        printf("9- Generar informe de ventas\n");
        printf("10- Listar clientes\n");

        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            alta_cliente(listaClientes);
            break;
        case 2:
            system("cls");
            modif_cliente(listaClientes);
            break;
        case 3:
            system("cls");
            baja_cliente(listaClientes, listaVentas);
            break;
        case 4:
            system("cls");
            imprimir_clientes(listaClientes);
            break;
        case 5:
            system("cls");
            alta_venta(listaVentas, listaClientes);
            break;
        case 6:
            system("cls");
            baja_venta(listaVentas);
            break;
        case 7:
            system("cls");
            imprimir_ventas(listaVentas, listaClientes);
            break;
        case 8:
            system("cls");
            break;
        case 9:
            system("cls");
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
