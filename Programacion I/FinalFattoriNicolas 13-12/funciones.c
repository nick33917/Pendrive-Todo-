#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"
#include "funciones.h"


int altaCliente(ArrayList* cliente)
{
    int returnAux=0;
    int flag=0;
    int i;
    int aux;
    char aux2 [200];
    eCliente* persona;
    eCliente* auxPer;
    persona = new_cliente();
    if( persona!=NULL)
    {

        setId(cliente,persona);

        printf("Ingrese el dni del empleado: ");
        scanf("%d",&aux);

        setDni(persona,aux);

        printf("ingrese el nombre del empleado: ");
        fflush(stdin);
        gets(aux2);

        setNombre(persona,aux2);

        printf("ingrese el apellido del empleado: ");
        fflush(stdin);
        gets(aux2);

        setApellido(persona,aux2);


        for(i=0; i<cliente->len(cliente); i++)
        {
            auxPer =(eCliente*)cliente->get(cliente,i);
            if(auxPer->dni == persona->dni)
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            cliente->add(cliente,persona);
            returnAux=1;

        }

    }
    return returnAux;

}

void modificarCliente(ArrayList* cliente)
{
    int id;
    int i;
    char aux2 [200];
    int aux;
    int opcion;
    char seguir='s';
    eCliente* auxPer;
    printf("Ingrese el id del cliente a modificar: ");
    scanf("%d",&id);

    for(i=0; i<cliente->len(cliente); i++)
    {
        auxPer =(eCliente*)cliente->get(cliente,i);
        if(auxPer->idEmpleado == id)
        {
            while(seguir=='s')
            {
                system("cls");
                printf("1- Modificar nombre\n");
                printf("2- Modificar apellido\n");
                printf("3- Modificar dni\n");
                printf("4- Salir\n");
                printf("Ingrese la opcion: ");
                scanf("%d",&opcion);
                system("cls");


                switch(opcion)
                {
                case 1:
                    printf("Ingrese el Nuevo Nombre del empleado: ");
                    fflush(stdin);
                    gets(aux2);
                    setNombre(auxPer,aux2);
                    system("pause");
                    break;
                case 2:
                    printf("Ingrese el Nuevo apellido del empleado: ");
                    fflush(stdin);
                    gets(aux2);
                    setApellido(auxPer,aux2);
                    system("pause");
                    break;
                case 3:
                    printf("Ingrese el Nuevo dni del empleado: ");
                    scanf("%d",&aux);
                    setDni(auxPer,aux);
                    system("pause");
                    break;
                case 4:
                    seguir='n';
                    break;


                }

            }
            break;
        }
    }

}


void bajaCliente(ArrayList* cliente)
{
    int i;
    int id;
    eCliente* auxPer;
    printf("Ingrese el id del cliente a modificar: ");
    scanf("%d",&id);

    for(i=0; i<cliente->len(cliente); i++)
    {
        auxPer =(eCliente*)cliente->get(cliente,i);
        if(auxPer->idEmpleado == id)
        {
            cliente->remove(cliente,i);
            break;
        }
    }
}

void setId(ArrayList* cliente , eCliente* persona)
{
    persona->idEmpleado=(cliente->len(cliente))+1;
}

void setDni(eCliente* persona, int aux)
{
    persona->dni=aux;
}

void setNombre(eCliente* persona, char* nombre)
{
    if(nombre!=NULL)
    {
        strcpy(persona->nombre,nombre);
    }
}
void setApellido(eCliente* persona, char* apellido)
{
    if(apellido!=NULL)
    {
        strcpy(persona->apellido,apellido);
    }

}


int compararApellido(void* apellido1,void* apellido2)
{
    int aux=0;
    if(strcmp(((eCliente*)apellido1)->apellido,((eCliente*)apellido2)->apellido)> 0)
    {
        aux=1;
    }
    return aux;
}

void ordenarYMuestra(ArrayList* cliente)
{
    if(cliente!=NULL)
    {
        cliente->sort(cliente,compararApellido,1);
        printeo(cliente);

    }

}

void lecturaArchivoTexto(ArrayList* servicios,char* path,FILE* service)

{
    int aux=-1;
    eServicio* servicio;
    int flag;
    char auxNombre[200];

    char auxDni[200];
    char auxCodigo[200];
    char auxCosto[200];
    char auxEstado[200];
    char auxNroServicio[200];
    char auxApellido[200];
    personal=fopen(path,"r");
    if(service!=NULL && servicio!=NULL)
    {
        while(!feof(personal))
        {

            fscanf(service,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s",auxNombre,auxApellido,auxDni,auxCodigo,auxCosto,auxEstado,auxNroServicio);
            service=new_servicio();

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
/*
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
*/
eCliente*  new_cliente()
{
    eCliente* cliente;
    cliente = (eCliente*)malloc(sizeof(eCliente));
    if(cliente!=NULL)
    {
        cliente->idEmpleado=0;
        cliente->dni=0;
        strcpy(cliente->nombre," ");
        strcpy(cliente->apellido," ");

    }
    return cliente;
}

eServicio*  new_servicio()
{
    eServicio* servicio;
    servicio = (eServicio*)malloc(sizeof(eServicio));
    if(servicio!=NULL)
    {
        strcpy(servicio->nombre,"");
        strcpy(servicio->apellido,"");
        servicio->dni=0;
        strcpy(servicio->codigo,"");
        servicio->costo=0;
        servicio->id=0;
        servicio->estado=0;
        servicio->nroServicio=0;

    }
    return cliente;
}


void printeo(ArrayList* cliente)
{
    eCliente* persona;
    int i;
    if(cliente!=NULL)
    {
        for(i=0; i<cliente->len(cliente); i++)
        {
            persona=(eCliente*)cliente->get(cliente,i);
            printf("%d  %s  %s  %d\n",persona->idEmpleado,persona->nombre,persona->apellido,persona->dni);
        }
    }
}

/*
void lecturaBinario(ArrayList* cliente, char* path, FILE* clientes)
{
    eCliente* persona;
    int cant;
    clientes = fopen(path,"rb");
    if(cliente!=NULL && clientes!=NULL)
    {
        while(!feof(clientes))
        {
            persona=new_cliente();
            fread(persona, sizeof(eCliente), 1,clientes);
            cliente->add(cliente,persona);

        }
    }

    fclose(clientes);

}

void EscrituraBinario(eCliente* cliente, char* path, FILE* clientes)
{
    clientes = fopen(path,"rb+");
    if(clientes==NULL)
    {
        clientes = fopen(path,"wb");

        if(cliente!=NULL && clientes!=NULL)
        {

            fseek(clientes, 0L, SEEK_END);
            fwrite(cliente, sizeof(eCliente), 1,clientes);

        }
    }
    fclose(clientes);

}

*/


