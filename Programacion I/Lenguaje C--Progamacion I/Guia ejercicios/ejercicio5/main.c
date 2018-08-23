#include <stdio.h>
#include <stdlib.h>
/*⦁	5-Escribir el programa necesario para calcular y mostrar el cuadrado de un número.
 El número debe ser mayor que cero, en caso de error que aparezca el mensaje "ERROR, el número debe ser mayor que cero" */

int main()
{
    int num;
    int cuadrado;
    printf("Ingrese un numero: ");
    scanf("%d",&num);

    while(num<=0)
    {
        printf("ERROR , el numero debe ser mayor a cero \n");
        printf("Ingrese un numero mayor a cero: ");
        scanf("%d",&num);
    }
    cuadrado=num*num ;
    printf("El cuadrado del numero ingresado es: %d",cuadrado);



    return 0;
}
