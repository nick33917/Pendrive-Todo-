#include <stdio.h>
#include <stdlib.h>
/*⦁	9-Escribir un programa que realice lea por teclado 20 caracteres. Luego de la lectura indicar cuantas "a" se ingresaron,
 cuantas "e, i, o, u" */
int main()
{
    char palabra;
    int cont_palabra;
    int a=0;
    int e=0;
    int i=0;
    int o=0;
    int u=0;

    for(cont_palabra=0;cont_palabra<20;cont_palabra++)
    {
        printf("Ingrese una palabra: ");
        scanf("%c",&palabra);

    }


    return 0;
}
