#include <stdio.h>
#include <stdlib.h>

void funcionX(int* x);

int main()
{
    int x = 5;

    printf("La variable x vale %d\n", x);
    fflush(stdin);
    getch();

     printf("La direccion de memoria de la variable x es %p\n", &x);
    fflush(stdin);
    getch();

    funcionX(&x);

    printf("La variable x despues de llamar a funcionX vale %d\n", x);
    fflush(stdin);
    getch();
    return 0;
}


void funcionX(int* x)
{
    printf("La variable x cuando llega a la funcionX vale %d\n", *x);
    fflush(stdin);
    getch();

    *x = 10;

    printf("La variable x ahora dentro de la funcionX vale %d\n", *x);
    fflush(stdin);
    getch();
}
