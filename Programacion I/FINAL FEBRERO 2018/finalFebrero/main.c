#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
#include "funciones.h"

int main()
{
    ArrayList* ventas =al_newArrayList();
    ArrayList* clientes = al_newArrayList();
    char seguir='s';
    int opcion;
    char aux[200];
  //  lecturaClientes(clientes,"clientes.txt");
  //  lecturaVentas(ventas,"ventas.txt");

    while(seguir=='s')
    {
        system("cls");
        printf("**************Compania de servicios de Marketing*************\n\n");
        printf("1- Alta Persona\n");
        printf("2- Modificar Persona\n");
        printf("3- Baja Persona\n");
        printf("4- Printeo\n");
        printf("5- Leer archivos de clientes\n");
        printf("6- Realizar Venta\n");
        printf("7- Generar informe de ventas por producto\n");
        printf("8- Generar informe de ventas de fecha\n");
        printf("9- MostrarVentas\n");
        printf("10- Salir\n");
        printf("Ingrese la opcion: ");
        scanf("%d",&opcion);
        system("cls");


        switch(opcion)
        {
        case 1:
            altaPersona(clientes,"clientes.txt");
            system("pause");
            break;
        case 2:
            modificarCliente(clientes,"clientes.txt");
            system("pause");
            break;
        case 3:
            bajaCliente(clientes,"clientes.txt");
            system("pause");
            break;
        case 4:
            ordenaYmuestra(clientes);
            system("pause");
            break;

        case 5:
            printf("Ingrese el nombre del archivo: ");
            fflush(stdin);
            gets(aux);
            lecturaClientes(clientes,aux);
            system("pause");
            break;
        case 6:
            altaVenta(ventas);
            system("pause");
            break;
        case 7:
            generarCsvVentas(ventas,clientes);
            system("pause");
            break;
        case 8:
            generarCsvVentasdeFecha(ventas,clientes);
            system("pause");
            break;
        case 9:
            mostrarVentas(ventas);
            system("pause");
            break;
        case 10:
            seguir='n';
            break;
        }
    }
    return 0;
}
