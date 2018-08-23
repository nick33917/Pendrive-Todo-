#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "lib.c"

#define SIZEPROGRAMADOR 50
#define SIZEPROYECTOS 1000
#define SIZECATEGORIAS 3

int main()
{
	int opc;
	int lastId = 0;
	int id;

	programador programador[SIZEPROGRAMADOR];
	proyectos proyectos[SIZEPROYECTOS];
	categorias categorias[SIZECATEGORIAS];

	inicializarEstados(programador, SIZEPROGRAMADOR);
	cargarCategorias(categorias);
	cargarProyectos(proyectos);

	do
	{
		system("cls");
		printf("--Gestion de programadores--\n1-ALTA DE PROGRAMADOR\n2-MODIFICAR DATOS DEL PROGRAMADOR\n3-BAJA DEL PROGRAMADOR\n4-ASIGNAR PROGRAMADOR A PROYECTO\n5-LISTADO DE PROGRAMADORES\n6-LISTADO DE TODOS LOS PROYECTOS\n7-LISTAR PROYECTOS DE PROGRAMADOR\n8-PROYECTO DEMANDANTE\n9-SALIR\nOpcion: ");
		scanf("%i", &opc);

		switch (opc)
		{
			case 1:
				if (agregarNuevoProgramador(programador, SIZEPROGRAMADOR, lastId))
				{
					lastId++;
				}
				break;

			case 2:
				modificarProgramador(programador, SIZEPROGRAMADOR);
				break;

			case 3:
				eliminarProgramador(programador, proyectos, SIZEPROGRAMADOR);
				break;

			case 4:
				asignarProgramadorAProyecto(programador, SIZEPROGRAMADOR, proyectos);
				break;

			case 5:
				listarProgramadores(programador, SIZEPROGRAMADOR, categorias, proyectos);
				break;

			case 6:
				listarProyectos(proyectos);
				break;

			case 7:
				listarProgramadorByID(programador, SIZEPROGRAMADOR, proyectos);
				break;

			case 8:
				proyectoDemandante(proyectos);
				break;

			case 9:
				break;
		}

	} while (opc != 9);


	return 0;
}
