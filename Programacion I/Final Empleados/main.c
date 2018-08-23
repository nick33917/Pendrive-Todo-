#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
#include "funciones.h"
int main()
{
    ArrayList* empleados=al_newArrayList();
    ArrayList* registros=al_newArrayList();
    eEmpleado* aux3;
    FILE* empleado;
    FILE* registro;
    int i;
    int aux2;
    int opcion;
    int aux;
    aux2 = parser_Empleado(empleados,"empleados.txt",empleado);
    if(aux2==1)
    {
        printf("se cargaron los datos en memoria\n");
    }

    printf("ingrese una opcion: ");
    scanf("%d",&opcion);
    switch(opcion)
    {
    case 1:

        aux = altaEmpleado(empleados,empleado,"empleados.txt");

        if(aux)
        {
            printf("se cargo correctamente\n\n");
        }
        else
        {
            printf("no se pudo cargar\n\n");
        }
        break;
    case 2:
        modificarEmpleado(empleados,empleado,"empleados.txt");
        system("pause");
        break;
    case 3:
        printeo(empleados);
        system("pause");
        break;
    }

    return 0;
}
