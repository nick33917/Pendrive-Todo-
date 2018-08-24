#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"
#include "funciones.h"

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

eVenta*  new_venta()
{
    eVenta* pedido;
    pedido= (eVenta*)malloc(sizeof(eVenta));
    if(pedido!=NULL)
    {
        pedido->idVenta = 0;
        pedido->idCliente = 0;
        pedido->codigoProd = 0;
        pedido->cantidad = 0;
        pedido->precioUnit = 0;

    }
    return pedido;
}

//------------------------------------------------------------------------------//

void lecturaClientes(ArrayList* clientes , char* path)
{
    char id[200],nombre[200], apellido[200], dni[200];
    int flag=0;
    FILE* archivo;
    eCliente* persona;

    archivo = fopen(path,"r");
    if(archivo!=NULL && path!=NULL)
    {
        // pongo esta linea para que no me muestre la 1er linea del archivo //
        fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,dni);
        flag=1;

        while(!feof(archivo))
        {
            fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,dni);
            persona = new_cliente();
            if(persona!=NULL)
            {

                persona->idEmpleado = atoi(id);
                persona->dni = atoi(dni);
                strcpy(persona->nombre,nombre);
                strcpy(persona->apellido,apellido);


            }

            clientes->add(clientes,persona);
        }

    }

    if(flag)
    {
        printf("\nEl archivo se leyo correctamente\n");
    }

    fclose(archivo);


}

//------------------------------------------------------------------------------//

void lecturaVentas(ArrayList* ventas, char* path)
{
    char idVenta[200], idCliente[200], codigoProd[200], cantidad[200], precioUnit[200];
    int flag=0;
    FILE* archivo;
    eVenta* pedido;

    archivo = fopen(path,"r");
    if(archivo!=NULL && path!=NULL)
    {
        // pongo esta linea para que no me muestre la 1er linea del archivo //
        fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVenta,idCliente,codigoProd,cantidad,precioUnit);
        flag=1;

        while(!feof(archivo))
        {
            fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVenta,idCliente,codigoProd,cantidad,precioUnit);
            pedido = new_venta();
            if(pedido!=NULL)
            {
                pedido->idVenta = atoi(idVenta);
                pedido->idCliente = atoi(idCliente);
                pedido->codigoProd = atoi(codigoProd);
                pedido->cantidad = atoi(cantidad);
                pedido->precioUnit = atof(precioUnit);
            }

            ventas->add(ventas,pedido);
        }

    }

    if(flag)
    {
        printf("\nEl archivo se leyo correctamente\n");
    }

    fclose(archivo);


}

//------------------------------------------------------------------------------//

void escrituraClientes(ArrayList* clientes, char* path)
{
    FILE* archivo;
    eCliente* persona;
    int i;

    archivo = fopen(path,"w");
    if(archivo!=NULL)
    {
        fprintf(archivo,"IdCliente,Nombre,Apellido,Dni\n");
        for(i=0;i<clientes->len(clientes);i++)
        {
            persona = (eCliente*)clientes->get(clientes,i);
            if(persona!=NULL)
            {
                fprintf(archivo,"%d,%s,%s,%d\n",persona->idEmpleado,persona->nombre,persona->apellido,persona->dni);
            }

        }
    }
    fclose(archivo);


}

//------------------------------------------------------------------------------//

void escrituraVentas(ArrayList* ventas, char* path)
{
    FILE* archivo;
    eVenta* pedido;
    int i;

    archivo = fopen(path,"w");
    if(archivo!=NULL)
    {
        fprintf(archivo,"IdVenta,IdCliente,CodigoProd,Cantidad,PrecioUnit\n");
        for(i=0;i<ventas->len(ventas);i++)
        {
            pedido = (eVenta*)ventas->get(ventas,i);
            if(pedido!=NULL)
            {
                fprintf(archivo,"%d,%d,%d,%d,%f\n",pedido->idVenta,pedido->idCliente,pedido->codigoProd,pedido->cantidad,pedido->precioUnit);
            }

        }
    }
    fclose(archivo);


}

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

        escrituraClientes(cliente,path);

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

            escrituraClientes(cliente,path);
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
            escrituraClientes(cliente,path);
            flag=1;

        }
    }

    if(!flag)
    {
        printf("\nEl id no se encontro!!!\n");
    }
    else
    {
        printf("\nEl cliente se borro exitosamente!! \n");
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
void ordenaYmuestra(ArrayList* cliente)
{
    if(cliente!=NULL)
    {
        cliente->sort(cliente,compararApellido,1);
        mostrarClientes(cliente);

    }

}
//------------------------------------------------------------------------------//
