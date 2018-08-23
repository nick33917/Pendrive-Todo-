#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


void mostrarPeliculas(EMovie peliculas)
{
    FILE* archivo;
    int cant;
    archivo = fopen(ARCH,"rb");
    if(archivo== NULL)
    {
        printf("\nNo hay nada para leer en el archivo");
        exit(1);
    }
    rewind(archivo);
    while(!feof(archivo))
    {
        cant=fread(&peliculas,sizeof(EMovie),1,archivo);
        if(cant!=1)
        {
            if(feof(archivo))
            {
                break;
            }

            else
            {
                printf("todabia no se termino de leer el archivo");
            }

        }
        if(peliculas.estado==1)
        {
            printf("Titulo: %6s\n   Genero:%6s\n    Duracion:%d\n   Descripcion:%6s\n   Puntaje:%d\n   Link Imagen:%6s\n \n",peliculas.titulo,peliculas.genero,peliculas.duracion,peliculas.descripcion,peliculas.puntaje,peliculas.linkImagen);
        }
    }
    fclose(archivo);
}


int altaPelicula(EMovie peli)
{
    int flag=0;
    FILE* archivo;


    archivo = fopen(ARCH,"rb+");

    if(archivo== NULL)
    {
        archivo = fopen(ARCH,"wb+");

        if(archivo== NULL)
        {
            printf("El archivo no pudo ser abierto");
            return flag;
            exit(1);

        }
    }

    printf("Ingrese el titulo de la pelicula: ");
    fflush(stdin);
    gets(peli.titulo);

    printf("Ingrese el genero de la pelicula: ");
    fflush(stdin);
    gets(peli.genero);

    printf("Ingrese la duracion de la pelicula: ");
    scanf("%d",&peli.duracion);

    printf("Ingrese la descripcion de la pelicula: ");
    fflush(stdin);
    gets(peli.descripcion);

    printf("Ingrese el puntaje de la pelicula: ");
    scanf("%d",&peli.puntaje);

    printf("Ingrese el link de la imagen: ");
    fflush(stdin);
    gets(peli.linkImagen);

    peli.estado=1;

    fseek(archivo,0L,SEEK_END);
    fflush(stdin);
    fwrite(&peli,sizeof(EMovie),1,archivo);
    rewind(archivo);
    fclose(archivo);
    flag=1;
    return flag;


}

int bajaPelicula(EMovie peli)
{
    int resultado=0;
    int flag=0;
    char letra;
    char auxPeli[30];
    int baja;
    FILE* archivo;

    printf("Ingrese el titulo de la pelicula que quiere dar de baja: ");
    fflush(stdin);
    gets(auxPeli);

    archivo = fopen(ARCH,"rb+");
    if(archivo== NULL)
    {
        printf("El archivo no pudo ser abierto");
        exit(1);
    }
    while(!feof(archivo))
    {
        baja=fread(&peli,sizeof(EMovie),1,archivo);
        if(baja)
        {
            if((strcmp(peli.titulo,auxPeli)==0) && peli.estado==1)
            {
                printf("Esta seguro que quiere dar de baja la Pelicula: %s? S/N: ",peli.titulo);
                scanf("%c",&letra);
                if(letra=='s')
                {
                    peli.estado=0;
                    flag=1;
                    break;
                }
                else
                {
                    break;
                }
            }
        }
    }
    if(flag)
    {
        fseek(archivo,(long)(-1)*sizeof(EMovie),SEEK_CUR);
        fflush(stdin);
        fwrite(&peli,sizeof(EMovie),1,archivo);
        resultado=1;

    }
    rewind(archivo);
    fclose(archivo);
    return resultado;

}

int modificarPelicula(EMovie peli)
{

    int resultado=0;
    int opcion;
    int modificar;
    char salir='s';
    int flag=0;
    FILE* archivo;
    char auxPeli[30];


    printf("Ingrese el titulo de la pelicula que quiere modificar: ");
    fflush(stdin);
    gets(auxPeli);

    archivo = fopen(ARCH,"rb+");
    if(archivo== NULL)
    {
        printf("\nEl archivo no pudo ser abierto");
        exit(1);
    }

    while(!feof(archivo))
    {
        modificar=fread(&peli,sizeof(EMovie),1,archivo);
        if(modificar)
        {
            if((strcmp(peli.titulo,auxPeli)==0) && peli.estado==1)
            {
                while(salir=='s')
                {

                    printf("\n\n--------------MODIFICACION DE PELICULA--------------\n\n");
                    printf("1- Modificar Titulo\n");
                    printf("2- Modificar Genero\n");
                    printf("3- Modificar Duracion\n");
                    printf("4- Modificar Descripcion\n");
                    printf("5- Modificar Puntaje\n");
                    printf("6- Modificar Link de Imagen\n");
                    printf("7- Terminar modificacion de la pelicula\n");
                    printf("\nIngrese la opcion: ");
                    scanf("%d",&opcion);
                    switch(opcion)
                    {
                    case 1:
                        system("cls");
                        printf("Ingrese el nuevo titulo de la pelicula: ");
                        fflush(stdin);
                        gets(peli.titulo);
                        break;
                    case 2:
                        system("cls");
                        printf("Ingrese el nuevo genero de la pelicula: ");
                        fflush(stdin);
                        gets(peli.genero);
                        break;
                    case 3:
                        system("cls");
                        printf("Ingrese la nueva duracion de la pelicula: ");
                        scanf("%d",&peli.duracion);
                        break;
                    case 4:
                        system("cls");
                        printf("Ingrese la nueva descripcion de la pelicula: ");
                        fflush(stdin);
                        gets(peli.descripcion);
                        break;
                    case 5:
                        system("cls");
                        printf("Ingrese el nuevo puntaje de la pelicula: ");
                        scanf("%d",&peli.puntaje);
                        break;
                    case 6:
                        system("cls");
                        printf("Ingrese el link de la nueva imagen: ");
                        fflush(stdin);
                        gets(peli.linkImagen);
                        break;
                    case 7:
                        salir='n';
                        break;
                    default:
                        system("cls");
                        printf("Opcion incorrecta, Ingrese una opcion correcta !!!\n");
                        break;
                    }

                }

                flag=1;
                break;

            }
        }
    }
    if(flag)
    {
        fseek(archivo,(long)(-1)*sizeof(EMovie),SEEK_CUR);
        fflush(stdin);
        fwrite(&peli,sizeof(EMovie),1,archivo);
        resultado=1;

    }
    rewind(archivo);
    fclose(archivo);
    return resultado;

}



void generarHtml(EMovie peli, char nombreArch[])
{
    FILE* archivo;
    int lectura;
    archivo=fopen(nombreArch,"rb");
    if(archivo==NULL)
    {
        printf("El archivo no pudo ser abierto.\n");
    }

    while(!feof(archivo))
    {
        lectura=fread(&peli,sizeof(EMovie),1,archivo);
        if(lectura)
        {

        }

    }

}
