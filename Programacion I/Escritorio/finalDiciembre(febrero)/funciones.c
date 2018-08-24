#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"
#include "funciones.h"

//------------------------------------------------------------------------------//

void altaPersona(ArrayList* cliente, char* path)
{
    eCliente* persona;
    persona=new_cliente();
    eCliente* auxPer;
    int flag=0;
    int flag2=0;
    int i;
    int aux;
    char buffer [200];

    printf("\nIngrese el dni del cliente: ");
    scanf("%d",&aux);

    for(i=0; i<cliente->len(cliente); i++)
    {
        auxPer=(eCliente*)cliente->get(cliente,i);
        if(auxPer->dni==aux)
        {
            flag=1;
            break;
        }
    }

    if(!flag)
    {
        setDni(persona,aux);

        printf("\nIngrese el Nombre del cliente: ");
        fflush(stdin);
        gets(buffer);
        setNombre(persona,buffer);

        printf("\nIngrese el Apellido del cliente: ");
        fflush(stdin);
        gets(buffer);
        setApellido(persona,buffer);

        setId(cliente,persona);

        cliente->add(cliente,persona);

        escrituraArchivo(path,cliente);

        flag2=1;

    }
    else
    {
        printf("El dni ya existe\n\n");
    }


    if(flag2)
    {

        printf("\n El cliente se cargo Correctamente\n");
    }


}

//------------------------------------------------------------------------------//

void modificarCliente(ArrayList* cliente, char* path)
{
    eCliente* persona;
    int aux;
    int aux2;
    char buffer [200];
    int i;
    int flag=0;

    printf("\nIngrese el id para modificar: ");
    scanf("%d",&aux);

    for(i=0; i<cliente->len(cliente); i++)
    {
        persona=(eCliente*)cliente->get(cliente,i);
        if(persona->idEmpleado==aux)
        {
            printf("\nIngrese el nuevo nombre: ");
            fflush(stdin);
            gets(buffer);
            setNombre(persona,buffer);

            printf("\nIngrese el nuevo Apellido: ");
            fflush(stdin);
            gets(buffer);
            setApellido(persona,buffer);

            printf("\nIngrese el nuevo dni: ");
            scanf("%d",&aux2);
            setDni(persona,aux2);

            escrituraArchivo(path,cliente);
            flag=1;
            break;

        }

    }

    if(!flag)
    {
        printf("El cliente no se encontro\n");
    }

}

//------------------------------------------------------------------------------//

void bajaCliente(ArrayList* cliente,char* path)
{
    int aux;
    int i;
    int flag=0;
    eCliente* auxPer;
    printf("\nIngrese el id para eliminar: ");
    scanf("%d",&aux);

    for(i=0; i<cliente->len(cliente); i++)
    {
        auxPer=(eCliente*)cliente->get(cliente,i);
        if(auxPer->idEmpleado == aux)
        {
            cliente->remove(cliente,i);
            escrituraArchivo(path,cliente);
            flag=1;

        }
    }

    if(!flag)
    {
        printf("\nEl id no se encontro!!!\n");
    }

}

//------------------------------------------------------------------------------//

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

//------------------------------------------------------------------------------//

void mostrarClientes(ArrayList* clientes)
{
    eCliente* persona;
    int i;
    if(clientes!=NULL)
    {
        for(i=0; i<clientes->len(clientes); i++)
        {
            persona=(eCliente*)clientes->get(clientes,i);
            printf("%d   %s   %s    %d \n",persona->idEmpleado,persona->nombre,persona->apellido,persona->dni);

        }
    }

}

//------------------------------------------------------------------------------//

void lecturaArchivo(char* path, ArrayList* clientes)
{
    eCliente* cliente;
    eCliente aux;
    FILE* archivo;
    int cant;
    archivo=fopen(path,"rb");
    if(archivo!=NULL)
    {
        rewind(archivo);
        while(!feof(archivo))
        {
            cant=fread(&aux,sizeof(eCliente),1,archivo);

            if(cant)
            {
                cliente = new_cliente();

                cliente->idEmpleado=aux.idEmpleado;
                strcpy(cliente->nombre,aux.nombre);
                strcpy(cliente->apellido,aux.apellido);
                cliente->dni=aux.dni;

                clientes->add(clientes,cliente);


            }

        }


    }

    fclose(archivo);

}

//------------------------------------------------------------------------------//

void escrituraArchivo(char* path,ArrayList* clientes)
{
    eCliente* auxPer;
    FILE* archivo;
    int i;

    archivo=fopen(path,"wb");
    if(archivo!=NULL && path!=NULL)
    {
        for(i=0; i<clientes->len(clientes); i++)
        {
            auxPer=(eCliente*)clientes->get(clientes,i);
            fseek(archivo,0l,SEEK_END);
            fflush(stdin);
            fwrite(auxPer,sizeof(eCliente),1,archivo);
        }


    }
    fclose(archivo);

}

//------------------------------------------------------------------------------//

void setId(ArrayList* cliente, eCliente* persona)
{
    persona->idEmpleado=(cliente->len(cliente))+1;
}

//------------------------------------------------------------------------------//

void setDni(eCliente* persona, int aux)
{
    persona->dni=aux;
}

//------------------------------------------------------------------------------//

void setNombre(eCliente* persona, char* nombre)
{
    if(nombre!=NULL)
    {
        strcpy(persona->nombre,nombre);
    }
}

//------------------------------------------------------------------------------//

void setApellido(eCliente* persona, char* apellido)
{
    if(apellido!=NULL)
    {
        strcpy(persona->apellido,apellido);
    }

}

//------------------------------------------------------------------------------//

int compararApellido(void* apellido1,void* apellido2)
{
    int aux=0;
    if(strcmp(((eCliente*)apellido1)->apellido,((eCliente*)apellido2)->apellido)> 0)
    {
        aux=1;
    }
    return aux;
}

//------------------------------------------------------------------------------//

void ordenaYmuestra(ArrayList* cliente)
{
    if(cliente!=NULL)
    {
        cliente->sort(cliente,compararApellido,1);
        mostrarClientes(cliente);

    }

}

//------------------------------------------------------------------------------//

void lecturaCsv(ArrayList* servicios)
{
    char nombre[200], apellido[200], dni [200], codigo[200], costo[200], estado[200], nroServicio[200], path [200];
    int flag=0;
    FILE* archivo;
    eServicio* tareas;

    printf("Ingrese el path del archivo: ");
    fflush(stdin);
    gets(path);
    archivo = fopen(path,"r");
    if(archivo!=NULL && path!=NULL)
    {
        // pongo esta linea para que no me muestre la 1er linea del archivo //
        fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",nombre,apellido,dni,codigo,costo,estado,nroServicio);
        flag=1;

        while(!feof(archivo))
        {
            fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",nombre,apellido,dni,codigo,costo,estado,nroServicio);
            tareas = new_servicio();
            if(tareas!=NULL)
            {
                tareas->dni = atoi(dni);
                tareas->costo = atof (costo);
                tareas->estado = atoi(estado);
                tareas->nroServicio = atoi(nroServicio);
                strcpy(tareas->nombre,nombre);
                strcpy(tareas->apellido,apellido);
                strcpy(tareas->codigo,codigo);
            }

            servicios->add(servicios,tareas);
        }

    }

    if(flag)
    {
        printf("\nEl archivo se leyo correctamente\n");
    }

    fclose(archivo);


}

//------------------------------------------------------------------------------//

eServicio* new_servicio()
{
    eServicio* servicio;
    servicio = (eServicio*)malloc(sizeof(eServicio));
    if(servicio!=NULL)
    {
        servicio->dni = 0;
        servicio->costo = 0;
        servicio->estado = 0;
        servicio->nroServicio = 0;
        strcpy(servicio->nombre," ");
        strcpy(servicio->apellido," ");
        strcpy(servicio->codigo," ");

    }

    return servicio;

}

//------------------------------------------------------------------------------//

void mostrarServicios(ArrayList* servicios)
{
    eServicio* tarea;
    int i;
    for(i=0;i<servicios->len(servicios);i++)
    {
        tarea=(eServicio*)servicios->get(servicios,i);
        printf("%s   %s   %d   %s   %f   %d   %d\n",tarea->nombre,tarea->apellido,tarea->dni,tarea->codigo,tarea->costo,tarea->estado,tarea->nroServicio);

    }
}

//------------------------------------------------------------------------------//

void altaServicio(ArrayList* cliente, ArrayList* servicios ,char* path)
{
    eCliente* auxper;
    eServicio* tarea;
    tarea=new_servicio();
    int aux;
    float aux2;
    char buffer [200];
    int i;
    int flag=0;
    int flag2=0;

    printf("\nIngrese el id: ");
    scanf("%d",&aux);

    for(i=0;i<cliente->len(cliente);i++)
    {
        auxper=(eCliente*)cliente->get(cliente,i);
        if(auxper->idEmpleado == aux)
        {
            strcpy(tarea->nombre,auxper->nombre);
            strcpy(tarea->apellido,auxper->apellido);
            tarea->dni = auxper->dni;
            flag=1;
            break;
        }

    }

    if(flag)
    {
        printf("\nIngrese el codigo del producto: ");
        fflush(stdin);
        gets(buffer);
        setCodigo(tarea,buffer);

        printf("\nIngrese el costo de reparacion: ");
        scanf("%f",&aux2);
        setCosto(tarea,aux2);

        printf("\nIngrese el nro de servicio: ");
        scanf("%d",&aux);
        setNroServicio(tarea,aux);

        setEstado(tarea,1);

        servicios->add(servicios,tarea);

        escrituraTexto(servicios,path);

        flag2=1;


    }
    else
    {
        printf("\nNo se encontro el id del cliente\n");
    }


    if(flag2)
    {
        printf("\nEl servicio se cargo correctamente\n");
    }

}

//------------------------------------------------------------------------------//

void setCodigo(eServicio* tarea, char* codigo)
{
    if(tarea!=NULL)
    {
        strcpy(tarea->codigo,codigo);
    }

}

//------------------------------------------------------------------------------//

void setCosto(eServicio* tarea, float costo)
{
    if(tarea!=NULL)
    {
        tarea->costo = costo;
    }

}

//------------------------------------------------------------------------------//

void setNroServicio(eServicio* tarea, int nroServicio)
{
    if(tarea!=NULL)
    {
        tarea->nroServicio = nroServicio;
    }

}

//------------------------------------------------------------------------------//

void setEstado(eServicio* tarea, int estado)
{
    if(tarea!=NULL)
    {
        tarea->estado = estado;

    }
}

//------------------------------------------------------------------------------//

void escrituraTexto(ArrayList* servicios, char* path)
{
    FILE* archivo;
    eServicio* tarea;
    int i;
    archivo = fopen(path,"w");
    if(archivo!=NULL)
    {
        fprintf(archivo,"nombrecliente,apellidoCliente,dniCliente,codigoArticulo,costo,estado,NRO_SERVICIO\n");
        for(i=0;i<servicios->len(servicios);i++)
        {
            tarea = (eServicio*)servicios->get(servicios,i);
            if(tarea!=NULL)
            {
                fprintf(archivo,"%s,%s,%d,%s,%f,%d,%d\n",tarea->nombre,tarea->apellido,tarea->dni,tarea->codigo,tarea->costo,tarea->estado,tarea->nroServicio);
            }

        }
    }
    fclose(archivo);


}

//------------------------------------------------------------------------------//

void bajaLogicaServicio(ArrayList* servicios, char* path)
{
    eServicio* tarea;
    int aux;
    float aux2;
    int i;
    int flag=0;

    printf("\nIngrese el nro de servicio: ");
    scanf("%d",&aux);

    for(i=0;i<servicios->len(servicios);i++)
    {
        tarea = (eServicio*)servicios->get(servicios,i);
        if(tarea!=NULL && tarea->nroServicio == aux)
        {
            printf("\nIngrese el costo de reparacion: ");
            scanf("%f",&aux2);

            setCosto(tarea,aux2);
            setEstado(tarea,0);
           // servicios->add(servicios,tarea);
            escrituraTexto(servicios,path);
            flag=1;
            break;

        }
    }

    if(flag)
    {
        printf("\nEl servicio se dio de baja exitosamente\n");
    }
    else
    {
        printf("\nEl servicio no se encontro\n");
    }


}

//------------------------------------------------------------------------------//
