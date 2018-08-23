#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
#include "funciones.h"
#define PATH "clientes.bin"
int main()
{
    ArrayList* cliente=al_newArrayList();
    ArrayList* servicios=al_newArrayList();
    char seguir='s';
    int opcion;
    lecturaArchivo(PATH,cliente);
    while(seguir=='s')
    {
        system("cls");
        printf("**************Compania de servicios de Marketing*************\n\n");
        printf("1- Alta Persona\n");
        printf("2- Modificar Persona\n");
        printf("3- Baja Persona\n");
        printf("4- Printeo\n");
        printf("5- Leer servicios y mostrarlo\n");
        printf("6- Alta servicio\n");
        printf("7- Baja servicio\n");
        printf("8- Mostrar servicios\n");
        printf("9- Salir\n");
        printf("Ingrese la opcion: ");
        scanf("%d",&opcion);
        system("cls");


        switch(opcion)
        {
        case 1:
            altaPersona(cliente,PATH);
            system("pause");
            break;
        case 2:
            modificarCliente(cliente,PATH);
            system("pause");
            break;
        case 3:
            bajaCliente(cliente,PATH);
            system("pause");
            break;
        case 4:
            ordenaYmuestra(cliente);
            system("pause");
            break;

        case 5:
            lecturaCsv(servicios);
            system("pause");
            break;
         case 6:
             altaServicio(cliente,servicios,"servicios.csv");
             system("pause");
             break;
        case 7:
            bajaLogicaServicio(servicios,"servicios.csv");
            system("pause");
            break;
        case 8:
           mostrarServicios(servicios);
           system("pause");
            break;
        case 9:
            seguir='n';
            break;

        }
    }
    return 0;
}
