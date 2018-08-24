#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
#include "funciones.h"

int main()
{
    ArrayList* ventas =al_newArrayList();;
    ArrayList* clientes = al_newArrayList();;
    char seguir='s';
    int opcion;
    lecturaClientes(clientes,"clientes.txt");
  //  lecturaVentas(ventas,"ventas.txt");

    while(seguir=='s')
    {
        system("cls");
        printf("**************Compania de servicios de Marketing*************\n\n");
        printf("1- Alta Persona\n");
        printf("2- Modificar Persona\n");
        printf("3- Baja Persona\n");
        printf("4- Printeo\n");
     /*   printf("5- Leer servicios y mostrarlo\n");
        printf("6- Alta servicio\n");
        printf("7- Baja servicio\n");
        printf("8- Mostrar servicios\n");
      */ printf("9- Salir\n");
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
            seguir='n';
            break;

        }
    }
    return 0;
}
