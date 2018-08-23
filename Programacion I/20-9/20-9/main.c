#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define TAM 2
#define MAX 3
typedef struct
{
    int id;
    char descrip[20];
    float valorHs;
} eCategoria;

typedef struct
{
    int id;
    char nombre[20];
    int categoria;
    int proyecto;
    int estado;
    int sueldo;
    int cantHs;
}eProgramador;

void cargarCat(eCategoria cat[], int tam);
void ingresarUsuarios(eProgramador lista[],int tam);

void inicializarVector(eProgramador lista[],int tam);
void altaProgramador(eProgramador lista[],int tam);
int buscarLibre(eProgramador lista[],int tam);
int buscarProgramador(int id, eProgramador lista[],int tam);
int validarCadena(char buffer[],int tamanio);
int validarCategoria(char buffer[]);
void mostrarCategoria(eCategoria cat[],int tam);
void mostrarProgramadores(eProgramador lista[],int tam);
void mostrarProgramadoresCateg(eProgramador lista[],eCategoria cat[],int tam);

//a = Senior
//b = SemiSenior
//c = Junior

int menu();

int main()
{
    eProgramador equipo[MAX];
    eCategoria categoria[MAX];
    int salir = 1;

    inicializarVector(equipo,TAM);
    do
    {
        switch(menu())
        {

        case 1:
            system("cls");
            cargarCat(categoria,MAX);
            ingresarUsuarios(equipo,MAX);
            mostrarCategoria(categoria,MAX);
            printf("------------------------------------------------------------\n\n");
            // mostrarProgramadores(equipo,MAX);
            printf("ID-----NOMBRE----CATEGORIA--PROYECTO---CANT HORAS\n\n");
            mostrarProgramadoresCateg(equipo,categoria,MAX);
            system("pause");

            break;

        case 2:
            system("cls");

            getch();


            break;
        case 3:
            system("cls");

            getch();

            break;

        case 4:
            system("cls");


            break;



        case 5:
            salir = 0;
            break;

        }

    }
    while(salir);
    return 0;
}


int menu()
{
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







//inicializa todo los estados en 0//
void inicializarVector(eProgramador lista[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        lista[i].estado=0;
    }
}



void ingresarUsuarios(eProgramador lista[],int tam)
{
    int id[]= {1,2,3};
    char nombre[][20]= {"Juan","Luis","Jose"};
    int categoria[]= {70,70,80};
    int proyecto[]= {1,2,4};
    int sueldo[]= {500,1000,1000};
    int cantHs[]= {10,20,10};
    int i;

    for(i=0; i<tam; i++)
    {
        lista[i].id=id[i];
        strcpy(lista[i].nombre,nombre[i]);
        lista[i].categoria=categoria[i];
        lista[i].proyecto=proyecto[i];
        lista[i].sueldo=sueldo[i];
        lista[i].cantHs=cantHs[i];

    }


}


void cargarCat(eCategoria cat[], int tam)
{
    int id[]= {70,75,80};
    char descrip[][30]= {"Junior","S.senior","Senior"};
    float valor[]= {50,75,100};
    int i;
    for(i=0; i<tam; i++)
    {
        cat[i].id=id[i];
        strcpy(cat[i].descrip,descrip[i]);
        cat[i].valorHs=valor[i];
    }
}


void mostrarCategoria(eCategoria cat[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%d    %s    %f\n",cat[i].id,cat[i].descrip,cat[i].valorHs);
    }
}

void mostrarProgramadores(eProgramador lista[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%d\t\t %s\t\t %d\t\t %d\t\t %d\n",lista[i].id,lista[i].nombre,lista[i].categoria,lista[i].proyecto,lista[i].cantHs);

    }

}

void mostrarProgramadoresCateg(eProgramador lista[],eCategoria cat[],int tam)
{
    int i;


    for(i=0;i<tam;i++)
    {

        if(lista[i].categoria==cat[i].id)
        {
            printf("%d    %s    %s    %d    %d\n",lista[i].id,lista[i].nombre,cat[i].descrip,lista[i].proyecto,lista[i].cantHs);
        }


    }
}

