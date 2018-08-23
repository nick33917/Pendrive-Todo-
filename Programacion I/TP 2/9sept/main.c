#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define TAM 5
int main()
{
    int codigo[TAM]={0};
    int i;
    char descrip[TAM][50];
    float precio[TAM];
    int stock[TAM];
    char si='s';
    int menu;
    int flag=0;
    char aux[100];
    int j;
    int auxint;
    while(si=='s')
    {

        printf("\nMENU:\n");
        if(flag==1)
        {
        printf("1-Alta producto.\n2-Mostrar producto.\n3-Ordenar por descripcion.\n4-Salir.\n");
        }
        else
        {
        printf("1-Alta producto.\n4-Salir.\n");
        }
        scanf("%d",&menu);
        switch(menu)
        {

        case 1:

            for(i=0;i<TAM;i++)
            {

            if(codigo[i]==0)
            {
            system("cls");
            printf("ingrese el codigo del producto:\n");
            scanf("%d",&codigo[i]);

            printf("ingrese el nombre del producto:\n");
            fflush(stdin);
            gets(descrip[i]);

            printf("ingrese el precio del producto:\n");
            scanf("%f",&precio[i]);

            printf("ingrese el stock del producto:\n");
            scanf("%d",&stock[i]);
            flag=1;
            system("cls");
            break;
            }
            }
            break;

        case 2:
            system("cls");

            for(i=0;i<TAM;i++)
            {
                if(codigo[i]!=0)
                {
                printf("-----------------\n");
                printf("Codigo: %d\n",codigo[i]);
                printf("Nombre: %s\n",descrip[i]);
                printf("Precio: %.2f\n",precio[i]);
                printf("Stock:  %d\n", stock[i]);
                printf("-----------------\n");
                }
            }
            system("pause");
            break;
        case 3:
            for(i=0;i<TAM-1;i++)
            {
                for(j=i+1;j<TAM;j++)

                if (strcmp(descrip[i],descrip[j])>0)
                {
                    strcpy(aux,descrip[i]);
                    strcpy(descrip[i],descrip[j]);
                    strcpy(descrip[j],aux);

                    auxint=precio[i];
                    precio[i]=precio[j];
                    precio[j]=auxint;

                    auxint=codigo[i];
                    codigo[i]=codigo[j];
                    codigo[j]=auxint;

                    auxint=stock[i];
                    stock[i]=stock[j];
                    stock[j]=auxint;
                }
                i++;
            }
            break;
        case 4:
            si='n';
            break;
        }
    }
    return 0;
}
