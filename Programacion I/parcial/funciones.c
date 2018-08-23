#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void inicializarEn0(eProg_proy relacion[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        relacion[i].estado=0;
    }
}


void inicializarVector(eProgramador lista[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado=0;
    }
}

void ingresarUsuarios(eProgramador lista[],int tam)
{
    int id[]= {1,2,3};
    char nombre[][20]= {"Juan","David","Cristian"};
    char cat[][20]= {"Senior","Senior","Junior"};
    int i;

    for(i=0; i<tam; i++)
    {
        lista[i].id=id[i];
        strcpy(lista[i].cat,cat[i]);
        strcpy(lista[i].nombre,nombre[i]);
        lista[i].sueldo=0;
        lista[i].estado=1;

    }


}

void cargarProg_proy(eProg_proy relacion[],int tam)
{
    int i;
    int idProgramador[]= {1,1,2,2,2,2,3,3,3};
    int idProyecto[]= {11,12,10,11,12,13,11,12,13};
    int hsPorProyecto[]= {8,7,4,10,15,8,4,5,6,12};


    for(i=0; i<tam; i++)
    {
        relacion[i].idprog=idProgramador[i];
        relacion[i].idproy=idProyecto[i];
        relacion[i].hstrabaj=hsPorProyecto[i];
        relacion[i].estado= 1;

    }

}


void cargarProyecto(eProyecto proy[],int tam)
{
    int idproy[]= {10,11,12,13};
    char descrip[][20]= {"SS.GESTION","AFIP","ARBA","WEB SERVICE"};
    int i;

    for(i=0; i<tam; i++)
    {
        proy[i].idproy=idproy[i];
        strcpy(proy[i].descrip,descrip[i]);

    }

}





void mostrarProg_Proy(eProgramador lista[],eProyecto proy[],eProg_proy relacion[],int cantProg,int cantProy,int cantProgProy)
{
    int i;
    int j;
    int k;
    //recorre los programadores//
    for(i=0; i<cantProg; i++)
    {
        printf("%d    %s\n\n",lista[i].id,lista[i].nombre);

        //recorre la relacion prog-proy//
        for(j=0; j<cantProgProy; j++)
        {
            if(lista[i].id==relacion[j].idprog)
            {
                //recorre la cant de proyectos//
                for(k=0; k<cantProy; k++)
                {
                    if(relacion[j].idproy==proy[k].idproy)
                    {
                        printf("Trabaja en Proyecto:  %s",proy[k].descrip);
                        break;

                    }

                }
                printf("\n");

            }

        }


        printf("\n\n");
    }
}


void mostrarCadaProyecto(eProgramador lista[],eProyecto proy[],eProg_proy relacion[],int cantProg,int cantProy,int cantProgProy)
{
    int i;
    int j;
    int k;

    //recorro cada proyecto//
    for(i=0; i<cantProy; i++)
    {
        printf("Las personas que trabajan en el proyecto: %s\n\n",proy[i].descrip);
        //recorro la relacion prog-proy//
        for(j=0; j<cantProgProy; j++)
        {
            if(proy[i].idproy==relacion[j].idproy)
            {
                //recorro todos los programadores//
                for(k=0; k<cantProg; k++)
                {
                    if(relacion[j].idprog==lista[k].id)
                    {
                        printf("%d   %s\n",lista[k].id,lista[k].nombre);
                        break;
                    }

                }
            }

        }
        printf("\n\n");
    }

}


void cargarCat(eCategoria cat[], int tam)
{
    int id[]= {70,75,80};
    char descrip[][30]= {"Junior","S.senior","Senior"};
    int valor[]= {50,75,100};
    int i;
    for(i=0; i<tam; i++)
    {
        cat[i].id=id[i];
        strcpy(cat[i].descrip,descrip[i]);
        cat[i].valorHs=valor[i];
    }
}


void saladrioProg(eProgramador lista[],eProg_proy relacion[],eCategoria categoria[],int cantProg,int cantProgProy,int cantcat)
{
    int i;
    int j;
    int k;
    int acum=0;

    //recorro programadores//
    for(i=0; i<cantProg; i++)
    {
        //recorro la relacion prog-proy//
        for(j=0; j<cantProgProy; j++)
        {

            if(lista[i].id==relacion[j].idprog)
            {
                for(k=0; k<cantcat; k++)
                {
                    if(strcmpi(lista[i].cat,categoria[k].descrip)==0)
                    {
                        acum=(categoria[k].valorHs * relacion[j].hstrabaj) + acum;
                        lista[i].sueldo=acum;
                        break;

                    }

                }


            }


        }
        printf("ID: %6d\t    NOMBRE: %10s\t  CATEGORIA:%8s\t SUELDO: $%6d \n\n",lista[i].id,lista[i].nombre,lista[i].cat,lista[i].sueldo);
        acum=0;
    }

}

void proyectoConMasProg(eProgramador lista[],eProyecto proy[],eProg_proy relacion[],int cantProg,int cantProy,int cantProgProy)
{
    int i;
    int j;
    int k;
    int cont[4]={};
    int maximo=0;
    int indice;

    //recorro todos los proyectos//
    for(i=0;i<cantProy;i++)
    {
        for(j=0;j<cantProgProy;j++)
        {
            if(proy[i].idproy==relacion[j].idproy)
            {
                for(k=0;k<cantProg;k++)
                {
                    if(relacion[j].idprog==lista[k].id)
                    {
                        cont[i] ++;
                    }
                }

            }
        }
    }

    for(i=0;i<cantProy;i++)
    {
        if(maximo==0 || cont[i]>maximo)
        {
            maximo=cont[i];

            indice=i;
        }

    }

    printf("El proyecto que mas Programadores tiene es: %s ",proy[indice].descrip);


}



