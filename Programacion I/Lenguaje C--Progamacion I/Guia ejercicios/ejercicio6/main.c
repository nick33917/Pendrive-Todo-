#include <stdio.h>
#include <stdlib.h>
/*⦁	6-De 10 números ingresadas indicar cuantos son mayores a cero y cuantos son menores a cero*/
int main()
{
    int num;
    int i;
    int positivos=0;
    int negativos=0;

    for(i=0;i<10;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&num);

        if(num>0)
        {
            positivos++;
        }
        else if(num<0)
        {
            negativos++;
        }
    }
    printf("Has ingresado %d numeros positivos y %d numeros negativos",positivos,negativos);
    return 0;
}
