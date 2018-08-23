#include <stdio.h>
#include <stdlib.h>
//Leer 10 elementos de un vector de enteros y mostrar su contenido
int main()
{
    int vec[10]={2,3,6,9,8,2,7,1,15,32};
    int i;
    for(i=0;i<10;i++)
    {
        printf("%d ",vec[i]);

    }

    return 0;
}
