#include <stdio.h>
#include <stdlib.h>
//⦁	Escribir el programa necesario para calcular la suma de dos números. Mostrar el resultado//
int main()
{
    int num1;
    int num2;
    int suma;
    printf("Ingrese un numero: ");
    scanf("%d",&num1);
    printf("Ingrese un numero: ");
    scanf("%d",&num2);
    suma=num1 + num2 ;
    printf("La suma de los numeros es: %d",suma);

    return 0;
}
