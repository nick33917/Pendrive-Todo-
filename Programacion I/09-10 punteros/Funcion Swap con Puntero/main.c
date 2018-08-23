#include <stdio.h>
#include <stdlib.h>
void swap(int* ,int*);

int main()
{
    int x=5;
    int y=8;
    printf("Antes del swap\n\n");
    printf("X=%d\n",x);
    printf("Y=%d\n\n",y);

    swap(&x,&y);


    printf("Despues del Swap y en el main\n\n");
    printf("X=%d\n",x);
    printf("Y=%d\n",y);


    return 0;
}

void swap(int* x ,int* y)
{
    int aux;
    aux=*x;
    *x=*y;
    *y=aux;
    printf("Dentro de la funcion Swap\n\n");
    printf("X=%d\n",*x);
    printf("Y=%d\n\n",*y);

}
