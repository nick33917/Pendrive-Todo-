#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3
/* CARGAR 3 ESTRUCTURAS CON LOS SIGUIENTES CAMPOS (NOMBRE,APELLIDO,DNI,TELEFONO),MOSTRAR CADA PERSONA CON SUS CAMPOS,
MOSTRAR LA PERSONA POR ORDEN ALFABETICO*/
typedef struct
{
    char nombre[20];
    char apellido[20];
    int dni;
    int telefono;

}ePersona ;

void cargarPersonas(ePersona*,int );
void mostrarPersonas(ePersona*,int);
void ordenarPersonas(ePersona *,int);

int main()
{
    ePersona gente[TAM];
    ePersona *ptrGente;

    ptrGente=gente;
    cargarPersonas(ptrGente,TAM);
    ordenarPersonas(ptrGente,TAM);
    mostrarPersonas(ptrGente,TAM);




    return 0;
}


void cargarPersonas(ePersona* personas,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("Ingrese un nombre:");
        fflush(stdin);
        gets((personas+i)->nombre);

        printf("Ingrese un apellido:");
        fflush(stdin);
        gets((personas+i)->apellido);

        printf("Ingrese un dni:");
        scanf("%d",&(personas +i)->dni);

        printf("Ingrese un telefono:");
        scanf("%d",&(personas +i)->telefono);


    }



}

void ordenarPersonas(ePersona * personas,int tam)
{
    int i;
    int j;
    ePersona aux;
    for(i=0;i<tam-1;i++)
    {
        for(j=1;j<tam;j++)
        {
            if(strcmp((personas+i)->nombre,(personas+j)->nombre)>0)
            {
                  aux = *(personas + i);
                 *(personas + i) = *(personas + j);
                 *(personas + j) = aux;




            }
        }
    }
}


void mostrarPersonas(ePersona* personas,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%6s    %6s    %d    %d \n",(personas+i)->nombre,(personas+i)->apellido,(personas+i)->dni,(personas+i)->telefono);
    }
}
