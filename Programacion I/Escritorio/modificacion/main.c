#include <stdio.h>
#include <stdlib.h>

typedef struct
{

    char nombre[MAX];
    int edad;
    int estado;
    int dni;

} EPersona;
int main()
{

    return 0;
}

void bajaPersona(EPersona lista[],int tam)
{
    char buffer[20];
    int dni;
    int i;
    char modificar='n';
    printf("Ingrese el dni de la persona que quiere modificar: ");
    scanf("%d",&dni);
    i=buscarPorDni(lista, dni, tam);
    if(i!=-1)
    {
        printf("\tLos datos de la persona son: \nDNI----------NOMBRE--------EDAD\n");
        printf("%d     %s        %d\n",lista[i].dni,lista[i].nombre,lista[i].edad);
        printf("Desea modificar los datos de esta persona? s/n: ");
        fflush(stdin);
        scanf("%c",&modificar);
        if(modificar=='s')
        {
            printf("\nIngrese el Nuevo nombre: ");
            fflush(stdin);
            gets(buffer);
            while(validarNombre(buffer,maximo)==0)
            {
                printf("\nReingre el nombre: ");
                fflush(stdin);
                gets(buffer);
            }
            strcpy(lista[i].nombre,buffer);


        }
        else
        {
            printf("\nLos datos de la persona no fueron modificados.\n");

        }

    }
    else
    {
        printf("\nEl documento no se encontro en el sistema\n");

    }


}

int buscarPorDni(EPersona lista[], int docum, int tam)
{
    int indice=-1,i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].dni==docum && lista[i].estado ==1)
        {
            indice=i;
            break;
        }

    }

    return indice;

}

