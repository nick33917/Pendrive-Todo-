#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Funciones.h"

/*** ------------- ***/
/*** CONSTRUCTOR 1 ***/
/*** ------------- ***/
eCliente* new_cliente()
{
    eCliente* returnAux;

    returnAux = (eCliente*)malloc(sizeof(eCliente));

    if(returnAux != NULL)
    {
        returnAux->id = 0;
        strcpy(returnAux->nombre, "");
        strcpy(returnAux->apellido, "");
        strcpy(returnAux->dni, "");
    }

    return returnAux;
}
int cliente_setId(eCliente* unCliente, int id)
{
    int returnAux = -1;

    if(id >=0)
    {
        unCliente->id= id;
        returnAux = 0;
    }

    return returnAux;
}
void cliente_setNombre(eCliente* unCliente, char* nombre)
{
    strcpy(unCliente->nombre, nombre);
}
void cliente_setApellido(eCliente* unCliente, char* apellido)
{
    strcpy(unCliente->apellido, apellido);
}
void cliente_setDni(eCliente* unCliente, char* dni)
{
    strcpy(unCliente->dni, dni);
}
/*** ------------- ***/
/*** CONSTRUCTOR 2 ***/
/*** ------------- ***/
eServicio* new_servicio()
{
    eServicio* returnAux;

    returnAux = (eServicio*)malloc(sizeof(eServicio));

    if(returnAux != NULL)
    {
        returnAux->idCliente = 0;
        returnAux->idServicio = 0;
        strcpy(returnAux->codProducto,"");
        strcpy(returnAux->fechaIngreso,"");
        returnAux->costoReparacion = 0;
        returnAux->estado = 0;
    }

    return returnAux;
}
int servicio_setIdCliente(eServicio* unServicio, int id)
{
    int returnAux = -1;

    if(id >=0)
    {
        unServicio->idCliente= id;
        returnAux = 0;
    }

    return returnAux;
}
int servicio_setCodProducto(eServicio* unServicio, char* codigo)
{
    strcpy(unServicio->codProducto, codigo);
}
int servicio_setCostoReparacion(eServicio* unServicio, float costo)
{
    int returnAux = -1;

    if(costo >=0)
    {
        unServicio->costoReparacion= costo;
        returnAux = 0;
    }

    return returnAux;
}
void servicio_setEstado(eServicio* unServicio, int estado)
{
    unServicio->estado = estado;
}
int servicio_setIdServicio(eServicio* unServicio, int id)
{
    int returnAux = -1;

    if(id >=0)
    {
        unServicio->idServicio= id;
        returnAux = 0;
    }

    return returnAux;
}
void servicio_setFechaIngreso(eServicio* unServicio, char* fecha)
{
    strcpy(unServicio->fechaIngreso, fecha);
}
/*** -------------- ***/
/*** ABRIR ARCHIVO  ***/
/*** -------------- ***/
FILE* abrir_ArchivoBinario(char* path, int modo)
{
    FILE* pFile;

    if(modo == 0) //Leer y escribir
    {

        if((pFile = fopen(path,"rb+")) == NULL)
        {
            if((pFile = fopen(path,"wb+")) == NULL)
            {
                printf("Error, no se ha podido cargar el archivo!\n");
            }

        }

    }
    else if(modo == 1)//Leer
    {
        if((pFile = fopen(path,"rb+")) == NULL)
        {
            printf("Error, no se ha podido cargar el archivo!\n");
        }
    }
    else if(modo == 2)//Escribir
    {
        if((pFile = fopen(path,"wb+")) == NULL)
        {
            printf("Error, no se ha podido cargar el archivo!\n");
        }
    }
    return pFile;
}
FILE* abrir_ArchivoTxt(char* path, int modo)
{
    FILE* pFile;

    if(modo == 0) //Leer y escribir
    {

        if((pFile = fopen(path,"r+")) == NULL)
        {
            if((pFile = fopen(path,"w+")) == NULL)
            {
                printf("Error, no se ha podido cargar el archivo!\n");
            }

        }

    }
    else if(modo == 1)//Leer
    {
        if((pFile = fopen(path,"r+")) == NULL)
        {
            printf("Error, no se ha podido cargar el archivo!\n");
        }
    }
    else if(modo == 2)//Escribir
    {
        if((pFile = fopen(path,"w+")) == NULL)
        {
            printf("Error, no se ha podido cargar el archivo!\n");
        }
    }
    return pFile;
}
/*** ------------ ***/
/*** ALTA CLIENTE ***/
/*** ------------ ***/
int alta_cliente(ArrayList* listaClientes, int id)
{
    int returnAux = -1;

    FILE* archivoBinario = abrir_ArchivoBinario("clientes.bin",0);

    char auxNombre[200];
    char auxApellido[200];
    char auxDni[200];

    if(archivoBinario != NULL && listaClientes != NULL)
    {
        printf("Ingrese su nombre: ");
        scanf("%s",auxNombre);

        printf("Ingrese su apellido: ");
        scanf("%s",auxApellido);

        printf("Ingrese DNI:");
        scanf("%s", auxDni);

        eCliente* unCliente;

        unCliente = new_cliente();

        /** USAR SETTERS **/
        if(unCliente != NULL)
        {
            cliente_setId(unCliente, id);
            cliente_setNombre(unCliente, auxNombre);
            cliente_setApellido(unCliente, auxApellido);
            cliente_setDni(unCliente, auxDni);

            listaClientes->add(listaClientes, unCliente);
        }

        fseek(archivoBinario, 0L, SEEK_END);
        fwrite(unCliente, sizeof(eCliente), 1, archivoBinario);
        fclose(archivoBinario);

        returnAux = 0;
    }

    return returnAux;

}
int modif_cliente(ArrayList* listaClientes)
{
    int returnAux = -1;

    FILE* archivoBinario = abrir_ArchivoBinario("clientes.bin",2);

    char auxNombre[200];
    char auxApellido[200];
    char auxDni[200];

    int id;
    int cant;
    int flag =0;

    int x,i;

    eCliente* modifCliente;

    modifCliente = new_cliente();

    if(archivoBinario != NULL && listaClientes != NULL)
    {

        printf("Ingrese ID a modificar: ");
        scanf("%d", &id);

        for(x = 0; x<listaClientes->len(listaClientes); x++)
        {
            eCliente* originalCliente = (eCliente*)listaClientes->get(listaClientes, x);

            if(id == originalCliente->id)
            {
                //Si encuentro el id saco al cliente del ArrayList
                listaClientes->remove(listaClientes, x);
                flag = 1;
            }

        }

        if(flag == 1)
        {
            //Despues de sacar al cliente del ArrayList pido nuevos datos

            printf("Ingrese nuevos datos!\n");

            printf("Ingrese nuevo nombre: ");
            scanf("%s",auxNombre);

            printf("Ingrese nuevo apellido: ");
            scanf("%s",auxApellido);

            printf("Ingrese DNI:");
            scanf("%s", auxDni);

            cliente_setNombre(modifCliente,auxNombre);
            cliente_setApellido(modifCliente,auxApellido);
            cliente_setDni(modifCliente,auxDni);
            cliente_setId(modifCliente, id);

            listaClientes->add(listaClientes, modifCliente);

        }
        else
        {
            printf("No se ha encontrado el cliente\n");
        }

        for(i = 0; i<listaClientes->len(listaClientes); i++)
        {
            eCliente* unCliente = (eCliente*)listaClientes->get(listaClientes, i);

            fseek(archivoBinario, 0L, SEEK_END);
            fwrite(unCliente, sizeof(eCliente), 1, archivoBinario);
            fclose(archivoBinario);
        }

        returnAux = 0;

    }

    return returnAux;

}
int baja_cliente(ArrayList* listaClientes)
{
    int returnAux = -1;

    FILE* archivoBinario = abrir_ArchivoBinario("clientes.bin",2);

    char auxNombre[200];
    char auxApellido[200];
    char auxDni[200];

    int id;
    int cant;
    int flag =0;

    int x,i;

    eCliente* modifCliente;

    modifCliente = new_cliente();

    if(archivoBinario != NULL && listaClientes != NULL)
    {

        printf("Ingrese ID a borrar: ");
        scanf("%d", &id);

        for(x = 0; x<listaClientes->len(listaClientes); x++)
        {
            eCliente* originalCliente = (eCliente*)listaClientes->get(listaClientes, x);

            if(id == originalCliente->id)
            {
                //Si encuentro el id saco al cliente del ArrayList
                listaClientes->remove(listaClientes, x);
                flag = 1;
            }

        }
        if(flag != 1)
        {
            printf("No se ha encontrado el cliente\n");
        }

        for(i = 0; i<listaClientes->len(listaClientes); i++)
        {
            eCliente* unCliente = (eCliente*)listaClientes->get(listaClientes, i);

            fseek(archivoBinario, 0L, SEEK_END);
            fwrite(unCliente, sizeof(eCliente), 1, archivoBinario);
            fclose(archivoBinario);
        }

        returnAux = 0;

    }

    return returnAux;

}
void imprimirClientes(ArrayList* listaClientes)
{
    eCliente* unCliente;

    int i;


    for(i = 0; i<listaClientes->len(listaClientes) ; i++)
    {
        unCliente = (eCliente*)listaClientes->get(listaClientes, i);

        printf("NOMBRE: %s\tAPELLIDO: %s\tID:%d\tDNI:%s\n",unCliente->nombre, unCliente->apellido,unCliente->id,unCliente->dni);
    }
}
void ordenar(ArrayList* listaClientes)
{
    eCliente* unCliente;
    listaClientes->sort(listaClientes,strcmp(unCliente->apellido, unCliente->apellido),1);
}
int importar_Servicios(ArrayList* listaClientes, ArrayList* listaServicios)
{

    int returnAux = -1;

    char auxIdCliente[200];
    char auxIdServicio[200];
    char auxCodProducto[200];
    char auxFechaIngreso[200];
    char auxCostoReparacion[200];

    char auxNombre[200];
    char auxApellido[200];
    char auxDni[200];

    char auxEstado[200];

    int i;

    FILE* pFile = abrir_ArchivoTxt("servicios.csv",0);

    int flag1 = 0;
    int flag2 = 0;

    if(pFile != NULL && listaClientes != NULL && listaServicios != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxNombre, auxApellido, auxDni, auxCodProducto, auxCostoReparacion, auxEstado, auxIdCliente);

            eServicio* unServicio = new_servicio();

            if(unServicio != NULL)
            {
                for(i = 0; i<listaClientes->len(listaClientes); i++)
                {
                    eCliente* unCliente = listaClientes->get(listaClientes, i);

                    if((unCliente->id == atoi(auxIdCliente)))
                    {
                        flag1 = 1;
                    }
                }

                int x;
                for(x = 0; x<listaServicios->len(listaServicios); x++)
                {
                    eServicio* unServicio = listaServicios->get(listaServicios,x);

                    if((unServicio->idCliente != atoi(auxIdCliente)))
                    {
                        flag1 = 1;
                    }
                }

                if(flag1 == 0 && flag2 == 0)
                {
                    servicio_setIdCliente(unServicio,atoi(auxIdCliente));
                    servicio_setIdServicio(unServicio, atoi(auxIdServicio));
                    servicio_setCodProducto(unServicio, atoi(auxCodProducto));
                    servicio_setCostoReparacion(unServicio, atof(auxCostoReparacion));

                    listaServicios->add(listaServicios,unServicio);
                }



            }


        }

        fclose(pFile);

        returnAux = 0;
    }

    return returnAux;
}
int alta_servicio(ArrayList* listaServicios, ArrayList* listaClientes)
{
    int returnAux = -1;

    FILE* archivoBinario = abrir_ArchivoBinario("servicios.bin",0);

    int auxIdCliente;
    int auxIdServicio;
    char auxCodProducto[200];
    char auxFechaIngreso[200];

    printf("Ingrese ID del cliente: ");
    scanf("%d",&auxIdCliente);

    int i;
    int flag=0;

    if(archivoBinario != NULL && listaClientes != NULL && listaServicios != NULL)
    {

        for(i = 0; i<listaClientes->len(listaClientes); i++)
        {
            eCliente* unCliente = (eCliente*)listaClientes->get(listaClientes, i);

            if(auxIdCliente == unCliente->id)
            {
                flag=1;
                printf("Id encontrado!\n");

                printf("Codigo de producto: ");
                scanf("%s", auxCodProducto);


                printf("Fecha de ingreso:");
                scanf("%s",auxFechaIngreso);

                eServicio* unServicio = new_servicio();

                if(unServicio != NULL)
                {
                    servicio_setIdServicio(unServicio, listaServicios->len(listaServicios)-1);
                    servicio_setIdCliente(unServicio, auxIdCliente);
                    servicio_setCodProducto(unServicio, auxCodProducto);
                    servicio_setFechaIngreso(unServicio, auxFechaIngreso);
                    servicio_setEstado(unServicio, 1);

                    listaServicios->add(listaServicios, unServicio);
                }

            }
        }

        if(flag == 0)
        {
            printf("Id de cliente no encontrado!\n");
        }

        int j;
        for(j = 0; j<listaServicios->len(listaServicios); j++)
        {
            eServicio* unServicio = (eServicio*)listaServicios->get(listaServicios, j);

            fseek(archivoBinario, 0L, SEEK_END);
            fwrite(unServicio, sizeof(eServicio), 1, archivoBinario);
            fclose(archivoBinario);
        }


        returnAux = 0;
    }

    return returnAux;

}
void imprimirServicios(ArrayList* listaServicios)
{
    eServicio* unServicio;

    int i;

    for(i = 0; i<listaServicios->len(listaServicios) ; i++)
    {
        unServicio = (eServicio*)listaServicios->get(listaServicios, i);

        if(unServicio->estado == 1)
        {
        printf("ID CLIENTE: %d ID SERVICIO: %d COD PRODUCTO: %s FECHA INGRESO: %s COSTO REPARACION: %f\n",unServicio->idCliente, unServicio->idServicio, unServicio->codProducto, unServicio->fechaIngreso, unServicio->costoReparacion);
        }
    }
}
int finalizarServicio(ArrayList* listaServicios)
{
    int returnAux = -1;

    FILE* archivoBinario = abrir_ArchivoBinario("servicios.bin",0);

    int id;

    printf("Ingrese ID del servicio: ");
    scanf("%d",&id);

    float costoReparacion;

    int i;
    for(i = 0; i<listaServicios->len(listaServicios); i++)
    {
        eServicio* servicio = (eServicio*)listaServicios->get(listaServicios, i);

        if(id == servicio->idServicio)
        {
            printf("Ingresese el costo de la reparacion: ");
            scanf("%f",&costoReparacion);

            servicio_setCostoReparacion(servicio,costoReparacion);
            servicio_setEstado(servicio,0);//cambio el estado
        }
    }

}
void ordenarS(ArrayList* listaServicios)
{
    eServicio* unServicio;
    listaServicios->sort(listaServicios,strcmp(unServicio->codProducto, unServicio->codProducto),1);
}
