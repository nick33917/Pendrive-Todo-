#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    Employee* lista = al_newArrayList();
    if(lista==NULL)
    {
        printf("No se pudo reservar memoria");
        exit(1);
    }

    FILE* f= fopen("data.csv","r");
    if(f==NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }

    parserEmployee(f, lista);

    /*Employee* unEmpleado;

    unEmpleado = employee_new();

    unEmpleado->id=120;
    strcpy(unEmpleado->name,"Juan");
    strcpy(unEmpleado->lastName,"Nicolas");
    unEmpleado->isEmpty=0;

    employee_print(unEmpleado);*/

    return 0;
}
