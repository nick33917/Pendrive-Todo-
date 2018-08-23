#include <stdio.h>
#include <stdlib.h>
//⦁	Ingresar 5 números y calcular su media//
int main()
{
    int num;
    int i;
    int suma=0 ;
    float promedio;
    for(i=0;i<5;i++)
    {
        printf("Ingresar un numero: ");
        scanf("%d",&num);
        suma=suma+num ;
    }
    promedio=(float)suma/i ;
    printf("El promedio de los numeros ingresados es: %f" ,promedio);

    return 0;
}
