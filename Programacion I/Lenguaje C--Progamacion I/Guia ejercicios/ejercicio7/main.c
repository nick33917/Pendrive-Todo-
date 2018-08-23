#include <stdio.h>
#include <stdlib.h>
#define PI 3.141592
/*⦁	7-Diseñar un programa que calcule la longitud de la circunferencia y el área del círculo de radio dado*/
int main()
{
    float radio;
    float long_circ;
    float area_circ;

    printf("Ingresar el radio de un circulo: ");
    scanf("%f",&radio);
    long_circ= (2*radio*PI);
    area_circ=(PI*radio*radio);
    printf("La longitud de la circunsferencia es: %f\n",long_circ);
    printf("El area de la circunsferencia es: %f",area_circ);

    return 0;
}
