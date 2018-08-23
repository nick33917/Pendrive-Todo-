#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia,mes,anio;

}eFecha;
//estructura //
typedef struct
{
    int dni;
    char nombre[40];
    float peso;
    eFecha fNac;
}ePersona;

void mostrarPersona(ePersona);

int main()
{
    ePersona listaPersonas[3];
    ePersona aux;
    int i;
    int j;

    for(i=0;i<3;i++)
    {
        printf("Ingrese el dni de la persona %d: ",i+1);
        scanf("%d",&listaPersonas[i].dni);

        printf("Ingrese el nombre de la persona %d: ",i+1);
        fflush(stdin);
        gets(listaPersonas[i].nombre);

        printf("Ingrese el peso de la persona %d: ",i+1);
        scanf("%f",&listaPersonas[i].peso);

        printf("Ingrese el dia de la Fecha de Nacimiento de la persona %d: ",i+1);
        scanf("%d",&listaPersonas[i].fNac.dia);
        printf("Ingrese el mes de la Fecha de Nacimiento de la persona %d: ",i+1);
        scanf("%d",&listaPersonas[i].fNac.mes);
        printf("Ingrese el anio de la Fecha de  Nacimiento de la persona %d: ",i+1);
        scanf("%d",&listaPersonas[i].fNac.anio);

        printf("\n-----------\n");
    }
    printf("DOCUMENTO\tNOMBRE\tPESO\tDIA\tMES\tANIO \n\n");

    for(i=0;i<3;i++)
    {
        mostrarPersona(listaPersonas[i]);
        printf("\n-----\n");
    }


    for(i=0;i<3-1;i++)
    {
        for(j=i+1;j<3;j++)
        {   //ordeno primero por nombre//
            if(strcmp(listaPersonas[i].nombre,listaPersonas[j].nombre)>0)
            {
                aux=listaPersonas[i];
                listaPersonas[i]=listaPersonas[j];
                listaPersonas[j]=aux;
            }
            //si el nombre es el mismo//
            if(strcmp(listaPersonas[i].nombre,listaPersonas[j].nombre)==0)
            {   //se ordena por dni//
                if(listaPersonas[i].dni>listaPersonas[j].dni)
                {
                    aux=listaPersonas[i];
                    listaPersonas[i]=listaPersonas[j];
                    listaPersonas[j]=aux;

                }

            }
        }
    }

   /* ePersona otraPersona;
    epersona listaPersona[3];
    printf("Ingrese el dni: ");
    scanf("%d",&unaPersona.dni);

    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(unaPersona.nombre);

    printf("Ingrese el peso: ");
    scanf("%f",&unaPersona.peso);

    otraPersona=unaPersona;




    mostrarPersona(unaPersona);
    printf("\n------------\n");
    mostrarPersona(otraPersona);                */

    return 0;
}


void mostrarPersona(ePersona personita)
{
    printf("%d\t %s\t %0.2f\t %02d\t %02d\t %d",personita.dni,personita.nombre,personita.peso,personita.fNac.dia,personita.fNac.mes,personita.fNac.anio);

}


