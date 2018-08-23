#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int pedirNumero(int num,int vec[],int tam);
int main()
{
    int legajo[]={128,356,198,215,320};
    int num;
    int indice;


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
