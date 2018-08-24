#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"
#include "funciones.h"


int altaEmpleado(ArrayList* empleados,FILE* personal,char* path)
{
    int returnAux=0;
    int flag=0;
    int i;
    eEmpleado* persona;
    eEmpleado* auxPer;
    persona = new_empleado();
    if( persona!=NULL)
    {
        printf("Ingrese el Id del empleado: ");
        scanf("%d",&persona->idEmpleado);

        printf("Ingrese el dni del empleado: ");
        scanf("%d",&persona->dni);

        printf("ingrese el nombre del empleado: ");
        fflush(stdin);
        gets(persona->nombre);

        printf("ingrese el apellido del empleado: ");
        fflush(stdin);
        gets(persona->apellido);


        for(i=0; i<empleados->len(empleados); i++)
        {
            auxPer =(eEmpleado*)empleados->get(empleados,i);
            if(auxPer->dni == persona->dni)
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            EscribirEnArchivo(persona,personal,path);
            returnAux=1;

        }

    }
    return returnAux;

}

void modificarEmpleado(ArrayList* empleados,FILE* personal,char* path)
{
    int id;
    int i;
    int flag=0;
    int opcion;
    char seguir ='s';
    eEmpleado* auxPer;
    auxPer=new_empleado();

    if(personal!=NULL && empleados!=NULL && auxPer!=NULL)
    {

        printf("Ingrese el Id del empleado: ");
        scanf("%d",&id);
        for(i=0; i<empleados->len(empleados); i++)
        {
            auxPer =(eEmpleado*)empleados->get(empleados,i);
            if(auxPer->idEmpleado == id)
            {
                printf("Ingrese el nuevo nombre: ");
                fflush(stdin);
                gets(auxPer->nombre);

                printf("Ingrese el nuevo apellido: ");
                fflush(stdin);
                gets(auxPer->apellido);

                printf("Ingrese el nuevo dni: ");
                scanf("%d",&auxPer->dni);

                empleados->push(empleados,i,auxPer);
                break;
            }
        }
        escribirArchivoModif_Baja(personal,path,empleados);



    }

    fclose(personal);

}
int parser_Empleado(ArrayList* empleados,char* path,FILE* personal)
{
    int aux=-1;
    eEmpleado* persona;
    int flag;
    char auxId[200];
    char auxNombre[200];
    char auxDni[200];
    char auxApellido[200];
    personal=fopen(path,"r");
    if(personal!=NULL && empleados!=NULL)
    {
        while(!feof(personal))
        {

            fscanf(personal,"%[^,],%[^,],%[^,],%s",auxId,auxNombre,auxApellido,auxDni);
            persona=new_empleado();

            persona->idEmpleado=atoi(auxId);
            strcpy(persona->nombre,auxNombre);
            strcpy(persona->apellido,auxApellido);
            persona->dni=atoi(auxDni);

            empleados->add(empleados,persona);

        }
        aux=1;
    }
    fclose(personal);


    return aux;

}

void escribirArchivoModif_Baja(FILE* personal,char* path,ArrayList* empleado)
{
    eEmpleado* persona;
    persona=new_empleado();
    personal= fopen(path,"w");
    int i;
    if(personal!=NULL && empleado!=NULL)
    {
        for(i=0; i<empleado->len(empleado); i++)
        {
            persona=(eEmpleado*)empleado->get(empleado,i);
            fseek(personal,0l,SEEK_END);
            fprintf(personal,"%d , %s, %s, %d\n",persona->idEmpleado,persona->nombre,persona->apellido,persona->dni);

        }

    }
    fclose(personal);

}


void EscribirEnArchivo(eEmpleado* persona,FILE* personal,char* path)
{
    personal= fopen(path,"r+");
    if(personal==NULL)
    {
        personal= fopen(path,"w+");
        if(personal==NULL)
        {
            printf("El archivo no se pudo abrir\n\n");
        }
    }
    if(personal!=NULL && persona!=NULL)
    {

        fseek(personal,0l,SEEK_END);
        fprintf(personal,"%d,%s,%s,%d\n",persona->idEmpleado,persona->nombre,persona->apellido,persona->dni);

    }
    fclose(personal);

}

eEmpleado* new_empleado()
{
    eEmpleado* empleado;
    empleado = (eEmpleado*)malloc(sizeof(eEmpleado));
    if(empleado!=NULL)
    {
        empleado->idEmpleado=0;
        empleado->dni=0;
        strcpy(empleado->nombre," ");
        strcpy(empleado->apellido," ");

    }
    return empleado;
}

void set_id(eEmpleado* empleado,int id)
{
    empleado->idEmpleado=id;
}


void printeo(ArrayList* empleado)
{
    eEmpleado* persona;
    int i;
    if(empleado!=NULL)
    {
        for(i=0; i<empleado->len(empleado); i++)
        {

            persona=(eEmpleado*)empleado->get(empleado,i);
            printf("%d  %s  %s  %d\n",persona->idEmpleado,persona->nombre,persona->apellido,persona->dni);
        }
    }
}
