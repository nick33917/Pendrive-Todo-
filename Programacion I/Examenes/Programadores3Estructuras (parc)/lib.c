#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lib.h"

void fLimpiar()
{
    system("cls"); //Limpio pantalla
}
void fInicializarEstados(eProgramador prog[], int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		prog[i].estado=0;
		prog[i].numProyectos=0;
	}
}
void fCargarCategorias(eCategoria cate[], int tam)
{
    int idCategoria[3] = {1,2,3};
	int pagoPorHora[5] = {250,500,1000};
	char descripcion[3][30] = {"Junior","SemiSenior","Senior"};

	int i;
	for (i=0;i<tam;i++)
	{
		cate[i].idCategoria = idCategoria[i];
		cate[i].pagoPorHora = pagoPorHora[i];
		strcpy(cate[i].descripcion, descripcion[i]);
	}
}
void fCargarProyectos(eProyecto proyec[])
{
    int idProyecto[7] = {1,2,3,4,5,6,7};
	char nombre[7][30] = {"Base de datos","Maquetacion","Servidor","Debug","Android","Deploys","Arduino"};

	int i;
	int j;

	for (i=0;i<7;i++)
	{
		proyec[i].idProyecto = idProyecto[i];
		strcpy(proyec[i].nombre, nombre[i]);

		//	Initializamos el numero de asignados
		for (j=0;j<3;j++)
		{
			proyec[i].numAsignados[j] = 0;
		}
	}
}
