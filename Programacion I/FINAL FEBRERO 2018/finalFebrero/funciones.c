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
        pedido->idCliente = 0;
        strcpy(pedido->codigoProd," ");
        pedido->cantidad = 0;
        pedido->precioUnit = 0;
        strcpy(pedido->fechaVenta," ");
    }
    return pedido;
}

//------------------------------------------------------------------------------//

void lecturaClientes(ArrayList* clientes, char* path)
{
    char id[200],nombre[200], apellido[200], dni[200];
    int flag=0;
    int flag2=0;
    FILE* archivo;
    eCliente* persona;
    eCliente* auxPer;
    int i;

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

                for(i=0; i<clientes->len(clientes); i++)
                {
                    auxPer=(eCliente*)clientes->get(clientes,i);
                    if(persona->dni == auxPer->dni)
                    {
                        flag2=1;
                        break;

                    }


                }
                if(!flag2)
                {
                    clientes->add(clientes,persona);

                }


            }


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

    archivo=fopen(path,"r+");
    if(archivo !=NULL)
    {


        archivo = fopen(path,"w+");
        if(archivo!=NULL)
        {
            fprintf(archivo,"IdCliente,Nombre,Apellido,Dni\n");
            for(i=0; i<clientes->len(clientes); i++)
            {
                persona = (eCliente*)clientes->get(clientes,i);
                if(persona!=NULL)
                {
                    fprintf(archivo,"%d,%s,%s,%d\n",persona->idEmpleado,persona->nombre,persona->apellido,persona->dni);
                }

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

void altaVenta(ArrayList* ventas)
{
    eVenta* pedido;
    pedido=new_venta();

    int aux;
    float aux2;
    char buffer [200];

    printf("\nIngrese el id del cliente: ");
    scanf("%d",&aux);
    setIdCliente(pedido,aux);

    printf("\nIngrese el Codigo del producto: ");
    fflush(stdin);
    gets(buffer);
    setCodigo(pedido,buffer);

    printf("\nIngrese el costo unitario: ");
    scanf("%f",&aux2);
    setPrecio(pedido,aux2);

    printf("\nIngrese la cantidad: ");
    scanf("%d",&aux);
    setCantidad(pedido,aux);

    printf("\nIngrese la fecha: ");
    fflush(stdin);
    gets(buffer);
    setFecha(pedido,buffer);


    ventas->add(ventas,pedido);





}

//------------------------------------------------------------------------------//

void setIdCliente(eVenta* pedido, int aux)
{
    pedido->idCliente=aux;
}
//------------------------------------------------------------------------------//

void setPrecio(eVenta* pedido, float aux)
{
    pedido->precioUnit=aux;
}

//------------------------------------------------------------------------------//

void setCantidad (eVenta* pedido, int aux)
{
    pedido->cantidad=aux;
}

//------------------------------------------------------------------------------//

void setCodigo(eVenta* pedido, char* codigo)
{
    if(codigo!=NULL)
    {
        strcpy(pedido->codigoProd,codigo);
    }

}

//------------------------------------------------------------------------------//

void setFecha(eVenta* pedido, char* fecha)
{
    if(fecha!=NULL)
    {
        strcpy(pedido->fechaVenta,fecha);
    }

}

//------------------------------------------------------------------------------//

void mostrarVentas(ArrayList* ventas)
{
    eVenta* pedido;
    int i;
    if(ventas!=NULL)
    {
        for(i=0; i<ventas->len(ventas); i++)
        {
            pedido=(eVenta*)ventas->get(ventas,i);
            printf("%d   %s   %f    %d    %s\n",pedido->idCliente,pedido->codigoProd,pedido->precioUnit,pedido->cantidad,pedido->fechaVenta);

        }
    }

}

//------------------------------------------------------------------------------//

void generarCsvVentas(ArrayList* ventas,ArrayList* clientes)
{


    FILE* archivo;
    eVenta* pedido;
    eCliente* persona;
    int i;
    int j;
    float aux;

    archivo = fopen("informe_venta.csv","w");
    if(archivo!=NULL)
    {
        char buffer [200];
        printf("Ingrese el codigo del producto: ");
        fflush(stdin);
        gets(buffer);
        fprintf(archivo,"nombreCliente,apellidoCliente,dniCliente,FechaVenta,ImporteVenta\n");
        for(i=0;i<ventas->len(ventas);i++)
        {
            pedido=(eVenta*)ventas->get(ventas,i);
            if(strcmp(pedido->codigoProd,buffer)==0)
            {
                for(j=0;j<clientes->len(clientes);j++)
                {
                    persona=(eCliente*)clientes->get(clientes,j);
                    if(pedido->idCliente==persona->idEmpleado)
                    {

                        aux = (pedido->cantidad * pedido->precioUnit);
                        fprintf(archivo,"%s,%s,%d,%s,%f\n",persona->nombre,persona->apellido,persona->dni,pedido->fechaVenta,aux);
                        break;
                    }
                }

            }
        }

    }

    fclose(archivo);


}

//------------------------------------------------------------------------------//

void generarCsvVentasdeFecha(ArrayList* ventas,ArrayList* clientes)
{


    FILE* archivo;
    eVenta* pedido;
    eCliente* persona;
    int i;
    int j;
    float aux;

    archivo = fopen("informe_VentasFecha.csv","w");
    if(archivo!=NULL)
    {
        char buffer [200];
        printf("Ingrese una fecha: ");
        fflush(stdin);
        gets(buffer);
        fprintf(archivo,"nombreCliente,apellidoCliente,dniCliente,CodigoArticulo,ImporteVenta\n");
        for(i=0;i<ventas->len(ventas);i++)
        {
            pedido=(eVenta*)ventas->get(ventas,i);
            if(strcmp(pedido->fechaVenta,buffer)==0)
            {
                for(j=0;j<clientes->len(clientes);j++)
                {
                    persona=(eCliente*)clientes->get(clientes,j);
                    if(pedido->idCliente==persona->idEmpleado)
                    {

                        aux = (pedido->cantidad * pedido->precioUnit);
                        fprintf(archivo,"%s,%s,%d,%s,%f\n",persona->nombre,persona->apellido,persona->dni,pedido->codigoProd,aux);
                        break;
                    }
                }

            }
        }

    }

    fclose(archivo);


}
//------------------------------------------------------------------------------//
