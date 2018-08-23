#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarCadena(char cad[],int tam);
void mostrarNombre(char[]);
void mostrarNombres(char[][20],int fila);
void ordenarNombre(char cad[][20],int tam);
int main()
{
   char nombre[5][20];
   char auxCad[100];
   int i;
   for(i=0;i<5;i++)
   {
        printf("Ingrese un nombre: ");
        gets(auxCad);

        while(!validarCadena(auxCad,19))//como me devuelvo 0 o 1 directamente valido y no igualo a ==0 o ==1 //
        {
        printf("\nNombre muy largo.Reingrese el nombre: ");
        gets(auxCad);
        }

        strcpy(nombre[i],auxCad);

   }
    mostrarNombres(nombre,5);

    ordenarNombre(nombre,5);
    printf("\n\n");

    mostrarNombres(nombre,5);




    return 0;
}



int validarCadena(char cad[],int tam)
{
    int flag=0;
    if(strlen(cad)<tam)
    {
        flag=1;

    }

   return flag;

}

void mostrarNombres(char cad[][20],int tam)
{

    for(int i=0;i<tam;i++)
   {
      mostrarNombre(cad[i]);
   }
}

void mostrarNombre(char nombre[])
{
    printf("el nombre es: %s\n",nombre);
}

void ordenarNombre(char cad[][20],int tam)
{

    char aux[20];
    for(int i=0;i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(stricmp(cad[i],cad[j])>0)
            {
                strcpy(aux,cad[j]);
                strcpy(cad[j],cad[i]);
                strcpy(cad[i],aux);

            }
        }

    }


}
