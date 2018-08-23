#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char modelo[20];
    int nucleos;
}eProcesador;

typedef struct
{
    char marca[20];
    eProcesador procesador;
    int ram;
    float precio;
}eNotebook;

void mostrarNotebook(eNotebook);
void inicializarNotebook(eNotebook* );
void cargarNotebook(eNotebook*);


int main()
{
    eNotebook maquina1;
    inicializarNotebook(&maquina1);
    mostrarNotebook(maquina1);
    cargarNotebook(&maquina1);
    mostrarNotebook(maquina1);


    return 0;
}

void mostrarNotebook(eNotebook note)
{
    printf("Marca:%6s\n ----Procesador----\n Modelo:%6s\n Nucleo:%d\n Ram:%d\n Precio:%.2f\n",note.marca,note.procesador.modelo,note.procesador.nucleos,note.ram,note.precio);
}

void inicializarNotebook(eNotebook* x)
{
    strcpy(x->marca," ");
    strcpy(x->procesador.modelo," ");
    x->procesador.nucleos=0;
    x->ram=0;
    x->precio=0;

}

void cargarNotebook(eNotebook* x)
{
    fflush(stdin);
    printf("Ingrese la marca:");
    gets(x->marca);

    printf("\nIngrese el modelo del Procesador: ");
    gets(x->procesador.modelo);

    printf("\nIngrese la cantidad de nucleos del procesador: ");
    scanf("%d",&x->procesador.nucleos);

    printf("\nIngrese la Ram: ");
    scanf("%d",&x->ram);

    printf("\nIngrese el precio: ");
    scanf("%f",&x->precio);


}
