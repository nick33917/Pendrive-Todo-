#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void altaCliente(ePersona clientes[])
{
    int i;
    for(i=0; i<2; i++)
    {
        printf("ingrese el nombre: ");
        fflush(stdin);
        gets(clientes[i].nombre);

        printf("ingrese el apellido: ");
        fflush(stdin);
        gets(clientes[i].apellido);

        printf("ingrese el dni: ");
        scanf("%d",&clientes[i].dni);

        printf("ingrese el edad: ");
        scanf("%d",&clientes[i].edad);
    }


}

void mostrarClientes(ePersona clientes[])
{
    int i;
    for(i=0;i<2;i++)
    {
        printf("%s   %s   %d   %d \n",clientes[i].nombre,clientes[i].apellido,clientes[i].dni,clientes[i].edad);
    }
}
