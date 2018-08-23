#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define TAM 2

typedef struct{
    int id;
    char nombre[20];
    char categoria;
    int proyecto;
    int estado;
}
eProgramador;

void mostrarProgramador(eProgramador unProgramador);
void mostrarProgramadores(eProgramador lista[],int tam);
void inicializarVector(eProgramador lista[],int tam);
void altaProgramador(eProgramador lista[],int tam);
int buscarLibre(eProgramador lista[],int tam);
int buscarProgramador(int id, eProgramador lista[],int tam);
int validarCadena(char buffer[],int tamanio);
int validarCategoria(char buffer[]);

//a = Senior
//b = SemiSenior
//c = Junior

int menu();

int main()
{
    eProgramador equipo[50];
    int salir = 1;

    inicializarVector(equipo,TAM);
    do{
        switch(menu()){

    case 1:
        system("cls");
        altaProgramador(equipo,TAM);
        system("pause");

        break;

    case 2:
         system("cls");
        printf("Opcion2");
        getch();


        break;
    case 3:
         system("cls");
        printf("Opcion3");
        getch();

        break;

    case 4:
         system("cls");
         mostrarProgramadores(equipo,TAM);
         system("pause");
         break;



    case 5:
        salir = 0;
        break;

        }

    }while(salir);
    return 0;
}


    int menu(){
        int opcion;
        system("cls");
        printf("\n***Programadores***\n\n\n");
        printf("1- Alta Programador\n");
        printf("2- Modificacion Programador\n");
        printf("3- Baja Programador\n");
        printf("4- Listado Programadores\n");
        printf("5- Salir\n");
        printf("\n\nIngrese opcion: ");
        scanf("%d", &opcion);

        return opcion;

    }

// muestra 1 programador solo//
    void mostrarProgramador(eProgramador unProgramador)
    {
        char cat[11];
        if(unProgramador.categoria== 'a')
        {
            strcpy(cat,"Senior");
        }
        else if(unProgramador.categoria=='b')
        {
            strcpy(cat,"SemiSenior");
        }
        else
        {
            strcpy(cat,"Junior");
        }

        printf("%3d %10s %11s   %5d\n",unProgramador.id,unProgramador.nombre,cat,unProgramador.proyecto);
    }

//muestra los programadores y verifica si no hay ninguno cargado salta un error//
    void mostrarProgramadores(eProgramador lista[],int tam)
    {
        int flag=0;
        for(int i=0;i<tam;i++)
        {
            if(lista[i].estado==1)
            {
                mostrarProgramador(lista[i]);
                flag=1;
            }
        }

        if(flag!=1)
        {
            printf("No hay programadores para mostrar");
        }

    }


//inicializa todo los estados en 0//
    void inicializarVector(eProgramador lista[],int tam)
    {
        for(int i=0;i<tam;i++)
        {
            lista[i].estado=0;
        }
    }

    void altaProgramador(eProgramador lista[],int tam)
    {
        eProgramador nuevoProgramador;
        int lugar;
        int esta;
        int id;
        char buffer[2000];
        lugar=buscarLibre(lista,tam);

        if(lugar == -1)
        {
            printf("No hay mas lugar en el sistema !!!\n");
        }
        else
        {
            printf("Ingrese el Id: ");
            scanf("%d",&id);
            esta=buscarProgramador(id,lista,tam);
            if(esta!=-1)
            {
                printf("El Id ya se encuentra registrado !!!");
            }
            else
            {
                nuevoProgramador.id=id;

                printf("Ingrese el Nombre: ");
                fflush(stdin);
                gets(buffer);
                while(validarCadena(buffer,19)==0)
                {
                    printf("Reingrese el nombre: ");
                    fflush(stdin);
                    gets(buffer);
                }
                strcpy(nuevoProgramador.nombre,buffer);


                printf("Ingrese categoria: ");
                fflush(stdin);
               /* gets(buffer);
                while(validarCategoria(buffer)==0)
                {
                    printf("Reingrese la categoria: ");
                    fflush(stdin);
                    gets(buffer);
                }
                scanf("%c",&nuevoProgramador.categoria); */

                printf("Ingrese el proyecto: ");
                scanf("%d",&nuevoProgramador.proyecto);

                nuevoProgramador.estado=1;

                lista[lugar]=nuevoProgramador;

            }



        }











    }


    int buscarLibre(eProgramador lista[],int tam)
    {
        int indice=-1;
        for(int i=0;i<tam;i++)
        {
            if(lista[i].estado==0)
            {
                indice=i;
                break;
            }
        }
        return indice;

    }

    int buscarProgramador(int id, eProgramador lista[],int tam)
    {
        int indice=-1;
        for(int i=0;i<tam;i++)
        {
            if(lista[i].id==id && lista[i].estado==1)
            {
                indice=i;
                break;
            }

        }
        return indice;

    }

    int validarCadena(char buffer[],int tamanio)
    {
        int flag=0;
        if(strlen(buffer)<tamanio)
        {
            flag=1;
        }
        return flag;
    }

    int validarCategoria(char buffer[])
    {
        int flag=0;
        if(buffer=='a' && buffer=='b' && buffer=='c')
        {
            flag=1;
        }
        return flag;
    }





