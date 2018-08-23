#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarCadena(char cad[],int tam);
int main()
{
   char nombre[20];
   char auxCad[100];
   printf("Ingrese un nombre: ");
   gets(auxCad);
  /* while(strlen(auxCad)>19)
   {
       printf("Reingrese el nombre: ");
       gets(auxCad);
   }
   strcpy(nombre,auxCad);*/
   while(!validarCadena(auxCad,19))//como me devuelvo 0 o 1 directamente valido y no igualo a ==0 o ==1 //
    {
        printf("\nNombre muy largo.Reingrese el nombre: ");
        gets(auxCad);
    }
    strcpy(nombre,auxCad);
    printf("\nEl nombre ingresado es: %s\n",nombre);


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

