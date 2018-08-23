#include <stdio.h>
#include <stdlib.h>
/*⦁	10-Escribir en C un programa que muestre los números impares entre 0 y 100 y que imprima cuantos      impares hay*/
int main()
{
   printf("Los numeros impares del 0 al 100 son:\n");

   int num_impar;
   float resto;
   int cont_impar=0;
   for(num_impar=0;num_impar<100;num_impar++)
   {
       resto=num_impar%2;
       if(resto!=0)
       {
           printf("%d\n",num_impar);
           cont_impar++;
       }
   }
   printf("La cantidad de numeros impares es: %d",cont_impar);

    return 0;
}
