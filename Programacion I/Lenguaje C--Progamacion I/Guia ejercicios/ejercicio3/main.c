#include <stdio.h>
#include <stdlib.h>
/*⦁	Escribir  un programa que realice las siguientes acciones
⦁	Limpie la pantalla
⦁	Asigne a 2 variables numero1 y numero2 valores distintos de cero
⦁	Efectúe el producto de dichas variables
⦁	Muestre el resultado pos pantalla
⦁	Obtenga el cuadrado de numero1 y lo muestre par pantalla*/
int main()
{
    system("cls");

    int num1;
    int num2;
    int producto;
    int cuadrado;

    printf("Ingrese el primer numero: ");
    scanf("%d",&num1);
    while(num1==0)
    {
        printf("Ingrese el primer numero, diferente a 0 : ");
        scanf("%d",&num1);
    }

    printf("Ingrese el segundo numero: ");
    scanf("%d",&num2);
    while(num2==0)
    {
        printf("Ingrese el segundo numero , diferente a 0 : ");
        scanf("%d",&num2);
    }
    producto = num1*num2 ;
    printf("El resultado del producto es : %d\n",producto);
    cuadrado=num1*num1 ;
    printf("El cuadrado del numero1 es : %d",cuadrado);



    return 0;
}
