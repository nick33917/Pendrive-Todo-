#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mostrarPersona(ePersona);
//estructura //
typedef struct
{
    int dni;
    char nombre[40];
    float peso;
}ePersona;

int main()
{
    /* """1ra manera"""" ---- ePersona unaPersona={30000,"juan",85};
    printf("%d---%s---%f",unaPersona.dni,unaPersona.nombre,unaPersona.peso);*/


   /* """2da manera""" --- ePersona unaPersona;
    unaPersona.dni=20000;
    strcpy(unaPersona.nombre,"juan");
    unaPersona.peso=85;

    printf("%d---%s---%f",unaPersona.dni,unaPersona.nombre,unaPersona.peso);*/


    ePersona unaPersona;
    ePersona otraPersona;
    printf("Ingrese el dni: ");
    scanf("%d",&unaPersona.dni);

    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(unaPersona.nombre);

    printf("Ingrese el peso: ");
    scanf("%f",&unaPersona.peso);

    //va a mostrar lo mismo en la otraPersona, se guardan los "datos" de unaPers a otraPers//
    otraPersona=unaPersona;

    /* printf("%d---%s---%f",unaPersona.dni,unaPersona.nombre,unaPersona.peso);
    printf("\n-------------------------------------------------\n");
    printf("%d---%s---%f",otraPersona.dni,otraPersona.nombre,otraPersona.peso);*/

    //muestro con una biblioteca//
    mostrarPersona(unaPersona);
    printf("\n------------\n");
    mostrarPersona(otraPersona);

    return 0;
}


void mostrarPersona(ePersona personita)
{
    printf("%d---%s---%f",personita.dni,personita.nombre,personita.peso);

}
