#include <stdio.h>
#include <stdlib.h>
void mostrarAlum(int legajo[],int nota1[],int nota2)
int main()
{
    int legajo[]={128,356,198,215,320};
    int nota1 []={2,2,2,7,10};
    int nota2 []={7,2,8,6,9};
    float promedio[MAX];
    int num;
    int indice;
    return 0;
}


for(i=0;i<5;i++)
    {
        promedio[i]=(float)(nota1[i]+nota2[i])/2;
    }

    printf("\n LEGAJO   NOTA1   NOTA2   PROMEDIO\n");
    printf("\n ---------------------------------\n\n");
    for(i=0;i<5;i++)
    {
        printf("   %4d   %4d   %4d   %4.2f\n",legajo[i],nota1[i],nota2[i],promedio[i]);
    }
    printf("\n---------------------------------\n");

