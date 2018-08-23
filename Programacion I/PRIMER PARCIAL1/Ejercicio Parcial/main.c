#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTCLIENTE 5
#define CANTALQ 15
#define CANTEQUIPO 3
#define CANTSITUAC 2


//EQUIPOS//
#define AMOLADORA 1
#define MEZCLADORA 2
#define TALADRO 3

//ESTADOS//
#define ALQUILADO 1
#define FINALIZADO 2

typedef struct
{
    int id;
    char descrip[20];
} eSituacion;

typedef struct
{
    int id;
    char descrip[20];
} eEquipo;


typedef struct
{
    int id;
    int dni;
    char nombre[20];
    char apellido[20];
    int estado;
} eCliente;

typedef struct
{
    int idCliente;
    int idEquipo;
    int idSituacion;
    float tiempoEstimado;
    float tiempoReal;
    int operador;
    int estado;
} eAlquiler;



void cargarClientes(eCliente[],int);

void cargarSituaciones(eSituacion[],int );

void cargarEquipo(eEquipo[],int );

void mostrarClientesConAlquileres(eCliente [],int,eEquipo [],int,eAlquiler [],int );

void cargarAlquileres(eAlquiler [],int);

void promedioTiempoReal(eEquipo[],int,eAlquiler[],int,eSituacion[],int);

void mostrarEquiposMasAlquilados(eEquipo[],int,eAlquiler [],int);

int maximoDeEquipos(eAlquiler [],int,eEquipo[],int );

int cantidadDeEquipos(int,eAlquiler[],int );

void mostrarClientesConMasAlquileres(eCliente[],int,eAlquiler[],int );

int maximoDeClientes(eAlquiler [],int,eCliente [],int );

int cantidadDeClientes(int,eAlquiler [],int );



int main()
{
    int opcion;
    char seguir='s';
    printf("1-nuevo alquiler\n");
    printf("2-fin de alquiler\n");
    printf("3-informar\n");
    printf("4-\n");
    printf("5-\n\n");

    printf("Ingrese la opcion: \n");
    scanf("%d",&opcion);

    eCliente personas[CANTCLIENTE];
    eEquipo herramientas[CANTEQUIPO];
    eAlquiler alquileres[CANTALQ];
    eSituacion estados[CANTSITUAC];

    cargarClientes(personas,CANTCLIENTE);
    cargarSituaciones(estados,CANTSITUAC);
    cargarAlquileres(alquileres,CANTALQ);
    cargarEquipo(herramientas,CANTEQUIPO);


    while(seguir=='s')
    {

        switch(opcion)
        {
        case 1:
            system("cls");
            mostrarClientesConAlquileres(personas,CANTCLIENTE,herramientas,CANTEQUIPO,alquileres,CANTALQ);
            system("pause");
            break;

        case 2:
            system("cls");
            promedioTiempoReal(herramientas,CANTEQUIPO,alquileres,CANTALQ,estados,CANTSITUAC);
            system("pause");

            break;

        case 3:

            system("cls");
            mostrarEquiposMasAlquilados(herramientas,CANTEQUIPO,alquileres,CANTALQ);
            break;

        case 4:
            system("cls");
            mostrarClientesConMasAlquileres(personas,CANTCLIENTE,alquileres,CANTALQ);
            system("pause");
            break;
        case 5:
            system("cls");
            mostrarClientesConMasAlquileres(personas,CANTCLIENTE,alquileres,CANTALQ);
            system("pause");
            break;
        case 6:
            seguir='n';
            break;

        }
    }

    return 0;
}


void cargarClientes(eCliente personas[],int CantCliente)
{
    int id[]= {1,2,3,4,5};
    int dni[]= {1111,2222,3333,4444,5555};
    char nombre[][20]= {"juan","roberto","pedro","nicolas","facundo"};
    char apellido[][20]= {"figueiras","petinato","alfonso","fattori","arana"};
    int estado[]= {1,1,1,1,1};
    int i;
    for(i=0; i<CantCliente; i++)
    {
        personas[i].id=id[i];
        personas[i].dni=dni[i];
        strcpy(personas[i].nombre,nombre[i]);
        strcpy(personas[i].apellido,apellido[i]);
        personas[i].estado=estado[i];

    }

}


void cargarSituaciones(eSituacion estados[],int cantEst)
{
    int id[]= {1,2};
    char descrip[][15]= {"Alquilado","Finalizado"};
    int i;
    for(i=0; i<cantEst; i++)
    {
        estados[i].id=id[i];
        strcpy(estados[i].descrip,descrip[i]);
    }

}


void cargarEquipo(eEquipo herramientas[],int cantEquip)
{
    int id[]= {1,2,3};
    char descrip[][20]= {"Amoladora","Mezcladora","Taladro"};
    int i;

    for(i=0; i<cantEquip; i++)
    {
        herramientas[i].id=id[i];
        strcpy(herramientas[i].descrip,descrip[i]);
    }

}

void cargarAlquileres(eAlquiler alquileres[],int cantAlq)
{
    int idCliente[]= {1,1,2,3,3,3,3,3,5};
    int idEquipo[]= {1,2,1,2,2,3,2,3,3};
    int idSituacion[]= {1,1,1,1,1,1,1,1,1};
    float tiempoEstimado[]= {10.2,15.3,15.3,16,18,19,25,48,23};
    float tiempoReal[]= {12,56,8,9,45,48,15,16,12};
    int operador[]= {10,11,12,13,14,15,16,17,18};
    int estado[]= {1,1,1,1,1,1,1,1,1};
    int i;

    for(i=0; i<cantAlq; i++)
    {
        alquileres[i].idCliente=idCliente[i];
        alquileres[i].idEquipo=idEquipo[i];
        alquileres[i].idSituacion=idSituacion[i];
        alquileres[i].tiempoEstimado=tiempoEstimado[i];
        alquileres[i].tiempoReal=tiempoReal[i];
        alquileres[i].operador=operador[i];
        alquileres[i].estado=estado[i];

    }
}


void mostrarClientesConAlquileres(eCliente personas[],int cantCliente,eEquipo herramientas[],int cantEquipo,eAlquiler alquileres[],int cantAlq)
{
    //personas//
    int i;
    //alquileres//
    int j;
    //herramientas//
    int k;

    printf("ID  NOMBRE\t APELLIDO\t DNI\n\n");
    for(i=0; i<cantCliente; i++)
    {
        if(personas[i].estado!=0)
        {
            printf("%d   %6s   %7s    %5d\n\n",personas[i].id,personas[i].nombre,personas[i].apellido,personas[i].dni);
            printf("Alquilo:\n");
            for(j=0; j<cantAlq; j++)
            {
                if(personas[i].id==alquileres[j].idCliente)
                {
                    for(k=0; k<cantEquipo; k++)
                    {
                        if(alquileres[j].idEquipo==herramientas[k].id)
                        {
                            printf("\t%s\n",herramientas[k].descrip);
                            break;

                        }


                    }


                }

            }
        }
        printf("\n**********************************\n\n");
    }


}


void promedioTiempoReal(eEquipo herramientas[],int cantEquip,eAlquiler alquileres[],int cantAlq,eSituacion situaciones[],int cantSituac)
{
    int i;
    int j;
    int k;
    float acum=0;
    int cont=0;
    float prom;
    //recorro las herramientas//
    for(i=0; i<cantEquip; i++)
    {

        for(j=0; j<cantAlq; j++)
        {
            if(herramientas[i].id==alquileres[j].idEquipo && alquileres[j].estado==1)
            {
                for(k=0; k<cantSituac; k++)
                {
                    if(alquileres[j].idSituacion==situaciones[k].id)
                    {
                        printf("%.2f\n",alquileres[j].tiempoReal);
                        acum=alquileres[j].tiempoReal+acum;
                        cont++;
                        break;

                    }
                }
            }

        }

    }
    prom=acum/cont;
    printf("El promedio es:%.3f",prom);
}

int cantidadDeEquipos(int herramienta,eAlquiler alquileres[],int cantAlq)
{
    int cantidad=0;
    int i;

    for(i=0; i<cantAlq; i++)
    {
        if(alquileres[i].idEquipo==herramienta && alquileres[i].estado==1)
        {
            cantidad++;
        }
    }
    return cantidad;
}

int maximoDeEquipos(eAlquiler alquileres[],int cantAlq,eEquipo herramientas[],int cantEquipo)
{
    int maximo;
    int i;
    int flag=0;
    int cantidad;

    for(i=0; i<cantEquipo; i++)
    {
        cantidad=cantidadDeEquipos(herramientas[i].id,alquileres,cantAlq);
        if( cantidad>maximo ||flag==0)
        {
            maximo=cantidad;
            flag= 1;
        }

    }
    return maximo;

}

void mostrarEquiposMasAlquilados(eEquipo herramientas[],int cantEquipo,eAlquiler alquileres[],int cantAlq)
{
    int i;
    int maximo;

    maximo=maximoDeEquipos(alquileres,cantAlq,herramientas,cantEquipo);

    for(i=0; i<cantEquipo; i++)
    {
        if(maximo == cantidadDeEquipos(herramientas[i].id,alquileres,cantAlq))
        {
            printf("%s %d alquileres\n",herramientas[i].descrip,maximo);
        }
    }

}


int cantidadDeClientes(int cliente,eAlquiler alquileres[],int cantAlq)
{
    int cantidad=0;
    int i;

    for(i=0; i<cantAlq; i++)
    {
        if(alquileres[i].idCliente==cliente && alquileres[i].estado==1)
        {
            cantidad++;
        }
    }
    return cantidad;
}

int maximoDeClientes(eAlquiler alquileres[],int cantAlq,eCliente personas[],int cantCliente)
{
    int maximo;
    int i;
    int flag=0;
    int cantidad;

    for(i=0; i<cantCliente; i++)
    {
        cantidad=cantidadDeClientes(personas[i].id,alquileres,cantAlq);
        if( cantidad>maximo ||flag==0)
        {
            maximo=cantidad;
            flag= 1;
        }

    }
    return maximo;

}

void mostrarClientesConMasAlquileres(eCliente personas[],int cantCliente,eAlquiler alquileres[],int cantAlq)
{
    int i;
    int maximo;

    maximo=maximoDeClientes(alquileres,cantAlq,personas,cantCliente);
    for(i=0; i<cantCliente; i++)
    {
        if(maximo == cantidadDeClientes(personas[i].id,alquileres,cantAlq))
        {
            printf("%6s\t %6s\n",personas[i].nombre,personas[i].apellido);



        }


    }



}






