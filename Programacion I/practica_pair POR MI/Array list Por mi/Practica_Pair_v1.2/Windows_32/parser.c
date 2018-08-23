#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include <string.h>


int parserEmployee(FILE* pFile, ArrayList* pArrayListEmployee)
{
    Employee* nuevoEmpleado;
    char auxNombre[51];
    char auxApellido[51];
    char auxId[10];
    char auxEmpty[10];
    if(pFile ==NULL || pArrayListEmployee==NULL)
    {
        printf("No hay mas lugar en memoria \n!!!");
        return -1;

    }

    while(!feof(pFile))
    {

        fscanf(pFile,"%[^,],%[^,],%[^,],%s \n)",auxId,auxNombre,auxApellido,auxEmpty);
        nuevoEmpleado=employee_new();
        if(nuevoEmpleado!=NULL)
        {

            nuevoEmpleado->id=atoi(auxId);
            strcpy(nuevoEmpleado->name,auxNombre);
            strcpy(nuevoEmpleado->name,auxApellido);
            if(strcmp(auxEmpty,"false")==0)
            {
                nuevoEmpleado->isEmpty=0;
            }
            else
            {
                nuevoEmpleado->isEmpty=0;

            }
        }

    }
    return 1;
}
