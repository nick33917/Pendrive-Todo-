#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT 2
int main()
{
    ePersona clientes[CANT];
    altaCliente(clientes);
    printf("\n NOMBRE ---- APELLIDO ----- DNI ----EDAD \n\n");
    mostrarClientes(clientes);
    return 0;
}
