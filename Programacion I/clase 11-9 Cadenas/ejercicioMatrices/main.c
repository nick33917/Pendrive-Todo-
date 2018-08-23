#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarCadena(char cad[],int tam);
void mostrarNombre(char[]);
void mostrarNombres(char[][20],int fila);
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

   for(i=0;i<5;i++)
   {
      printf("\nEl nombre ingresado es: %s\n",nombre[i]);
   }


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

void mostrarNombres(char[][20],int tam)
{

    for(int i=0;i<tam;i++)
   {
      printf("\nEl nombre ingresado es: %s\n",nombre[i]);
   }
}

void mostrarNombre(char[])
{
    printf("el nombre es: %s",nombre[i]);
}

