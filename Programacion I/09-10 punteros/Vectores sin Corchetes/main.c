#include <stdio.h>
#include <stdlib.h>
#define TAM 5
void mostrarVector(int*,int);

int main()
{
    int vec[TAM];
    int i;

    //se puede hacer una funcion para ingresar los numeros//
    for(i=0; i<TAM; i++)
    {
        printf("Ingrese el numero:");
        scanf("%d",(vec + i));
    }
    printf("\n\n");

    mostrarVector(vec,TAM);

    return 0;
}



void mostrarVector(int* x,int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%d // ",*(x+i));
    }
}
