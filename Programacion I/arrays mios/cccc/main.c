#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int pedirNumero(int num,int vec[],int tam);
int main()
{
    int legajo[]={128,356,198,215,320};
    int nota1 []={2,2,2,7,10};
    int nota2 []={7,2,8,6,9};
    float promedio[MAX];
    int num;
    int indice;
    int i;

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

    printf("ingrese el numero del vector a buscar: ");
    scanf("%d",&num);
    indice=pedirNumero(num,legajo,MAX);
    if(indice==-1)
    {
        printf("El numero %d no se encontro en el array",num);
    }
    else
    {
        printf("El numero: %d se encuentra en el indice: %d",num,indice);

    }


    return 0;
}


int pedirNumero(int num,int vec[],int tam)
{

    int indice= -1;
    int i;
    for(i=0;i<tam;i++)
    {

        if(vec[i]==num)
        {
            indice=i;
            break;
        }


    }
     return indice;
}
