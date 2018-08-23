#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTPROG 10
#define CANTCAT 3

typedef struct{
    int id;
    char nombre[50];
    int categoria;
    int proyecto;
    int estado;                         // Hacer todas estas funciones:
    int sueldo;                       //Mostrar todos los programadores semisenior -- LISTO
    int cantHoras;                    //Mostrar el monto total de sueldos a pagar para los programadores junior -- LISTO
}eProgramador;                        //La/s categoria/s que tengan menos programadores/ hacerlo pensando en 50 categorias.

typedef struct{
    int id;
    char desc[50];
    int valorPorHora;
}eCategoria;

//Prototipos
void inicializarVector(eProgramador equipo[], int cant);
void cargarCategoria(eCategoria listaCat[], int cant);
int fEspacioLibre(eProgramador equipo[], int cant);
void ingresarProgramador(eProgramador equipo[], int cant);
void imprimirProgramadores(eProgramador equipo[], eCategoria listaCat[], int cantProg, int cantCat);
void imprimirSemi(eProgramador equipo[], eCategoria listaCat[], int cantProg, int cantCat);
void cantProgramadores(eProgramador equipo[], eCategoria listaCat[], int cantProg);

int main()
{
    char opcion = 's';
    //Creo la variable equipo utilizando la estructura del programador
    eProgramador equipo[CANTPROG];
    //Creo la variable listaCat utiliziando la estructura de la categoria
    eCategoria listaCat[CANTCAT];
    //Cargo las categorias (Junior, S.Senior, Senior)
    cargarCategoria(listaCat,CANTCAT);
    //Inicializo todos los estados en 0 (Inicializo el vector).
    inicializarVector(equipo,CANTPROG);

    //

    int op;
    while (opcion == 's')
    {
        printf("1 - Ingrese un programador\n");
        printf("2 - Imprimir programadores\n");
        printf("3 - Imprimir SemiSeniors\n");
        printf("4 - Imprimir Sueldos de los Junior\n");
        printf("5 - Imprimir menor cantidad de programadores\n");
        printf("6 - Salir\n");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                system("cls");
                ingresarProgramador(equipo,CANTPROG);
                break;
            case 2:
                system("cls");
                imprimirProgramadores(equipo,listaCat,CANTPROG,CANTCAT);
                break;
            case 3:
                system("cls");
                imprimirSemi(equipo,listaCat,CANTPROG,CANTCAT);
                break;
            case 4:
                system("cls");
                imprimirJunior(equipo,listaCat,CANTPROG,CANTCAT);
                break;
            case 5:
                system("cls");
                cantProgramadores(equipo,listaCat,CANTPROG);
                break;
            case 6:
                opcion = 'n';
                break;
        }
    }

    return 0;
}

void cargarCategoria(eCategoria listaCat[], int cant)
{
    //Declaro un vector por cada componente

    int id[]= {70,75,80};
    char desc[][30]= {"Junior","Semi-Senior","Senior"};
    float valorPorHora[]= {50,75,100};
    int i;
    for(i=0; i<cant; i++)
    {
        listaCat[i].id=id[i]; //Copio la posicion 0 del vec id, a la posicion 0 del vec id en la estructura.
        strcpy(listaCat[i].desc,desc[i]);
        listaCat[i].valorPorHora=valorPorHora[i];
    }
}
void inicializarVector(eProgramador equipo[], int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        equipo[i].estado=0;
    }
}
int fEspacioLibre(eProgramador equipo[], int cant)
{
    int resultado = -1;
    int i;
    for (i = 0; i < cant; i++)
    {
        if (equipo[i].estado == 0)
        {
            resultado = i;
            break;
        }
    }
    return resultado;
}
void ingresarProgramador(eProgramador equipo[], int cant)
{
    int indice;
    indice = fEspacioLibre(equipo,cant);
    printf("Indice: %d\n",indice);

    if(indice!=-1)
    {
        printf("Ingrese ID del programador: ");
        scanf("%d",&equipo[indice].id);

        printf("Ingrese Nombre del programador: ");
        scanf("%s",equipo[indice].nombre);

        printf("Ingrese la categoria (70-Junior 75-SemiSenior 80-Senior): ");
        scanf("%d",&equipo[indice].categoria);

        printf("Ingrese la cantidad de horas trabajadas: ");
        scanf("%d",&equipo[indice].cantHoras);

        equipo[indice].estado=1;
    }
    else
    {
        printf("No hay mas espacio!\n");
    }
}
void imprimirProgramadores(eProgramador equipo[], eCategoria listaCat[], int cantProg, int cantCat)
{
    int i,j;
    for(i=0;i<cantProg;i++)
    {
        if(equipo[i].estado!=0)
        {
            for(j=0;j<cantCat;j++)
            {
                if(equipo[i].categoria==listaCat[j].id)
                {
                    equipo[i].sueldo=equipo[i].cantHoras * listaCat[j].valorPorHora;
                    printf("\n%s\t%s\t\t%d\n",equipo[i].nombre,listaCat[j].desc,equipo[i].sueldo);
                }
            }
        }
    }
    printf("\n--------------------------------");
    printf("\n\nNombre\tCategoria\tSueldo\n\n");
}
void imprimirSemi(eProgramador equipo[], eCategoria listaCat[], int cantProg, int cantCat)
{
    int i,j;
    for(i=0;i<cantProg;i++)
    {
        if(equipo[i].estado!=0)
        {
            for(j=0;j<cantCat;j++)
            {
                if(equipo[i].categoria==75)
                {
                    equipo[i].sueldo=equipo[i].cantHoras * listaCat[1].valorPorHora;
                    printf("\n%s\t%s\t\t%d\n",equipo[i].nombre,listaCat[1].desc,equipo[i].sueldo);
                    break;
                }
            }
        }
    }
    printf("\n--------------------------------");
    printf("\n\nNombre\tCategoria\tSueldo\n\n");
}
void imprimirJunior(eProgramador equipo[], eCategoria listaCat[], int cantProg, int cantCat)
{
    int i,j;
    for(i=0;i<cantProg;i++)
    {
        if(equipo[i].estado!=0)
        {
            for(j=0;j<cantCat;j++)
            {
                if(equipo[i].categoria==70)
                {
                    equipo[i].sueldo=equipo[i].cantHoras * listaCat[0].valorPorHora;
                    printf("\n%s\t%s\t\t%d\n",equipo[i].nombre,listaCat[0].desc,equipo[i].sueldo);
                    break;
                }
            }
        }
    }
    printf("\n--------------------------------");
    printf("\n\nNombre\tCategoria\tSueldo\n\n");
}
void cantProgramadores(eProgramador equipo[], eCategoria listaCat[], int cantProg)
{
    int i, min;
    int contjunior=0, contsemi=0, contsenior=0;
    char desc[3][30]= {"Junior","Semi-Senior","Senior"};
    for(i=0;i<cantProg;i++)
    {
        if(equipo[i].estado!=0)
        {
            if(equipo[i].categoria==70)
            {
                contjunior++;
            }
            if(equipo[i].categoria==75)
            {
                contsemi++;
            }
            if(equipo[i].categoria==80)
            {
                contsenior++;
            }
        }
    }

    if(contjunior<contsemi && contjunior<contsenior)
    {
       min=contjunior;
       printf("Cantidad menor de programadores: %d , categoria: %s\n", min, desc[0]);
    }
    else if(contsemi<contjunior && contsemi<contsenior)
    {
        min=contsemi;
        printf("Cantidad menor de programadores: %d , categoria: %s\n", min, desc[1]);
    }
    else
    {
        min=contsenior;
        printf("Cantidad menor de programadores: %d , categoria: %s\n", min, desc[2]);
    }


}
