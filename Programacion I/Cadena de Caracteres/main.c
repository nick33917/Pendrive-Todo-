#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char nombre[20];
    char apellido[20];
    char apellidoNombre[400];
    char buffer[2000];

    printf("ingresar el nombre: ");
    gets(buffer);

    while (strlen(buffer)>19)
    {
        printf("Reingresar el nombre: ");
        gets(buffer);
    }

    strcpy(nombre,buffer);


    printf("ingresar el apellido: ");
    gets(buffer);

    while (strlen(buffer)>19)
    {
        printf("Reingresar el apellido: ");
        gets(buffer);
    }

    strcpy(apellido,buffer);


    strcat(apellidoNombre,nombre);
    strcat(apellidoNombre,apellido);
    printf("el nombrey apellido es:%s" ,apellidoNombre);

    /*strcat(nombre,", ");
    strcat(nombre,apellido);
    printf("El Apellido y Nombre es: %s",nombre);*/










    return 0;
}
