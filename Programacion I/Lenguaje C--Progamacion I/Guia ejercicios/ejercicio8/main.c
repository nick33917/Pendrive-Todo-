#include <stdio.h>
#include <stdlib.h>
/*⦁	8-Diseñar un programa que calcule la superficie de un triángulo a partir del ingreso de su base y altura y muestre el resultado.*/
int main()
{
    int base;
    int altura;
    float superficie;

    printf("Ingrese la base de un triangulo: ");
    scanf("%d",&base);
    printf("Ingrese la altura de un triangulo: ");
    scanf("%d",&altura);
    superficie=((float)base*altura)/2;
    printf("La superficie del triangulo es: %f",superficie);

    return 0;
}
