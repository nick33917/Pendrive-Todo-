#include <stdio.h>
#include <stdlib.h>
/*⦁	11-Hacer el programa que imprima los números pares entre el 1 y el 100*/
int main()
{
    int num_par;
    float resto;
    printf("Los numeros impares son: \n");
    for(num_par=1;num_par<=100;num_par++)
    {
        resto=num_par%2;
        if(resto==0)
        {
            printf("%d\n",num_par);
        }

    }

    return 0;
}
