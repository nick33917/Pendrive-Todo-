#include "lib.h"

//inicializa estados en cero
void inicializarEstados(programador programador[], int longitud)
{
	int i;
	for (i = 0; i<longitud; i++)
	{
		programador[i].estado = 0;
		programador[i].numProyectos = 0;
	}
}

//carga categorias en un vector
void cargarCategorias(categorias categorias[])
{
	int idCategoria[3] = { 1, 2, 3 };
	int pagoXHora[5] = { 250, 500, 1000 };
	char descripcion[3][30] = { "Junior", "SemiSenior", "Senior" };

	int i;
	for (i = 0; i < 3; i++)
	{
		categorias[i].idCategoria = idCategoria[i];
		categorias[i].pagoXHora = pagoXHora[i];
		strcpy(categorias[i].descripcion, descripcion[i]);
	}
}

//carga proyectos en un vector
void cargarProyectos(proyectos proyectos[])
{
	int idProyecto[7] = { 1, 2, 3, 4, 5, 6, 7 };
	char nombre[7][30] = { "Base de datos", "Maquetacion", "Servidor", "Debug", "Android", "Deploys", "Arduino" };

	int i;
	int j;

	for (i = 0; i < 7; i++)
	{
		proyectos[i].idProyecto = idProyecto[i];
		strcpy(proyectos[i].nombre, nombre[i]);

		//	Initializamos el numero de asignados
		for (j = 0; j < 3; j++)
		{
			proyectos[i].numAsignados[j] = 0;
		}
	}
}

//Validacion de unicamente caracteres enteroericos.
int validarNumero(char entero[])
{
	int i;
	for (i = 0; i<strlen(entero); i++)
	{
		if (!(isdigit(entero[i])))
		{
			printf("Debe ingresar solo numeros enteros.\n");
			return 0;
		}
	}

	return 1;
}

//Validacion de unicamente caracteres alfabéticos.
int validarCadena(char caracter[])
{
	int i;

	for (i = 0; i<strlen(caracter); i++)
	{
		if (isdigit(caracter[i]) || ispunct(caracter[i]))
		{
			printf("Debe ingresar solo caracteres alfabeticos.\n");
			return 0;
		}
	}

	return 1;
}


//Agrega personas al vector siempre y cuando el 'estado' de la fila sea 0.
int agregarNuevoProgramador(programador programador[], int longitud, int lastId)
{
	int i;
	char auxHoras[20];
	char auxnombre[51];
	char auxapellido[51];
	int auxInt;
	int flag = 0;

	for (i = 0; i<longitud; i++)
	{
		if (programador[i].estado == 0)
		{
			do
			{
				printf("\nIngrese nombre: ");
				fflush(stdin);
				gets(auxnombre);

			} while (validarCadena(auxnombre) == 0);

			do
			{
				printf("Ingrese apellido: ");
				fflush(stdin);
				gets(auxapellido);

			} while (validarCadena(auxapellido) == 0);

			printf("Categorias:\n 1- Junior\n 2- SemiSenior\n 3- Senior\n");
			printf("Ingrese la categoria: ");
			fflush(stdin);
			scanf("%d", &auxInt);

			do
			{
				printf("Cantidad de horas: ");
				fflush(stdin);
				scanf("%s", &auxHoras);
			} while (validarNumero(auxHoras) == 0);

			programador[i].idCategoria = auxInt;
			programador[i].horas = atoi(auxHoras);
			strcpy(programador[i].nombre, auxnombre);
			strcpy(programador[i].apellido, auxapellido);
			programador[i].estado = 1;
			programador[i].id = lastId;

			flag = 1;
			printf("%s registrado con exito.\n", programador[i].nombre);
			system("pause");
			break;
		}

	}

	if (!flag)
	{
		printf("ERROR: no hay espacio suficiente.");
	}

	return flag;
}


//modificar el programador por id
void modificarProgramador(programador programador[], int longitud)
{
	int i;
	char auxHoras[20];
	int auxInt;
	int flag = 0;
	int id;

	printf("Ingrese el ID del programador a modificar: ");
	scanf("%d", &id);

	for (i = 0; i<longitud; i++)
	{
		if (programador[i].id == id)
		{
			printf("Editando al programador: %s, %s", programador[i].apellido, programador[i].nombre);

			printf("\nCategorias:\n 1- Junior\n 2- SemiSenior\n 3- Senior\n");
			printf("Ingrese la categoria: ");
			fflush(stdin);
			scanf("%d", &auxInt);

			printf("Cantidad de horas: ");
			fflush(stdin);
			scanf("%s", &auxHoras);

			programador[i].idCategoria = auxInt;
			programador[i].horas = atoi(auxHoras);

			flag = 1;
			printf("%s, %s modificado con exito.\n", programador[i].apellido, programador[i].nombre);
			system("pause");
			break;
		}

	}

	if (!flag)
	{
		printf("ERROR: no hay espacio suficiente.\n");
	}
}

//eliminar vector siempre y cuando el 'estado' de la fila sea 0.
void eliminarProgramador(programador programador[], proyectos proyectos[], int longitud)
{
	int i;
	int flag = 0;
	int id;
	int j;

	printf("ID del programador a eliminar: ");
	scanf("%d", &id);

	for (i = 0; i<longitud; i++)
	{
		if (programador[i].id == id)
		{
			programador[i].estado = 0;

			//	Descontamos el total de proyectos
			if (programador[i].numProyectos > 0)
			{
				for (j = 0; j < programador[i].numProyectos; j++)
				{
					proyectos[programador[i].idProyectosAsignados[j]].numAsignados[programador[i].idCategoria - 1]--;
				}
			}

			flag = 1;
			printf("%s, %s eliminado con exito.\n", programador[i].apellido, programador[i].nombre);
			system("pause");
			break;
		}

	}

	if (!flag)
	{
		printf("ERROR: no hay espacio suficiente.\n");
	}
}

//??
void asignarProgramadorAProyecto(programador programador[], int longitud, proyectos proyectos[])
{
	int id;
	int opc;
	int Horas;

	printf("Ingrese el ID del usuario al que desea asignar un proyecto: ");
	scanf("%d", &id);

	for (int i = 0; i < longitud; i++)
	{
		if (programador[i].id == id && programador[i].estado == 1)
		{

            for (int p = 0; p < 7; p++)
            {
                printf("%d - %s\n", proyectos[p].idProyecto, proyectos[p].nombre);
            }

			printf("Ingrese el ID del proyecto a asignar al programador %s %s: ", programador[i].apellido, programador[i].nombre);
			scanf("%d", &opc);
            opc--;
			programador[i].idProyectosAsignados[programador[i].numProyectos] = opc;

			printf("Ingrese la cantidad de horas: ");
			scanf("%d", &Horas);

			programador[i].idProyectosHoras[programador[i].numProyectos] = Horas;
			programador[i].numProyectos++;

			//	Agregamos un nuevo asignado al proyecto
			proyectos[opc].numAsignados[programador[i].idCategoria - 1]++;

			printf("Proyecto %d asignado con el ID: %d\n", opc, programador[i].numProyectos - 1);
			system("pause");
		}
	}
}

//listar programadores
void listarProgramadores(programador programador[], int longitud, categorias categorias[], proyectos proyectos[])
{
	int i;
	int j;

	for (i = 0; i < longitud; i++)
	{
		if (programador[i].estado == 1)
		{
			ordenarProgramadores(programador, longitud);

			printf("Programador: %d - %s %s - %s\n", programador[i].id, programador[i].apellido, programador[i].nombre, categorias[programador[i].idCategoria - 1].descripcion);

			if (programador[i].numProyectos > 0)
			{
				printf("Proyectos: \n");

				//	Listado de proyectos
				for (j = 0; j < programador[i].numProyectos; j++)
				{
					printf("%s - Cobro total: $%d\n", proyectos[programador[i].idProyectosAsignados[j]].nombre, (programador[i].idProyectosHoras[j] * categorias[programador[i].idCategoria - 1].pagoXHora));
				}
			}
			else
			{
				printf("No posee proyectos. \n");
			}
		}
	}
	system("pause");
}

void listarProyectos(proyectos proyectos[])
{
	int i;

	for (i = 0; i < 7; i++)
	{
		printf("Proyecto: %d - %s\n", proyectos[i].idProyecto, proyectos[i].nombre);
		printf("Juniors: %d\n", proyectos[i].numAsignados[0]);
		printf("SemiSenior: %d\n", proyectos[i].numAsignados[1]);
		printf("Senior: %d\n\n", proyectos[i].numAsignados[2]);
	}
	system("pause");
}

void listarProgramadorByID(programador programador[], int longitud, proyectos proyectos[])
{
	int ID;
	int i;
	int j;

	//	Listamos los programadores
	for (i = 0; i < longitud; i++)
	{
		if (programador[i].estado == 1)
		{
			printf("Programador %s %s - ID: %d\n", programador[i].apellido, programador[i].nombre, programador[i].id);
		}
	}

	printf("Ingrese el ID del programador: ");
	scanf("%d", &ID);

	for (i = 0; i < longitud; i++)
	{
		if (programador[i].id == ID && programador[i].estado == 1)
		{
			if (programador[i].numProyectos > 0)
			{
				printf("Proyectos: \n");

				for (j = 0; j < programador[i].numProyectos; j++)
				{
					printf(" -%s\n", proyectos[programador[i].idProyectosAsignados[j]].nombre);
				}
			}
			else
			{
				printf("No posee proyectos. \n");
			}
			system("pause");
		}
	}
}

void proyectoDemandante(proyectos proyectos[])
{
	int i;
	int j;
	int tmpInt = 0;
	int maxProyect = 0;
	int IDProyect;

	for (i = 0; i < 7; i++)
	{
		tmpInt = 0;
		for (j = 0; j < 3; j++)
		{
			tmpInt += proyectos[i].numAsignados[j];
		}

		if (tmpInt > maxProyect)
		{
			IDProyect = i;
			maxProyect = tmpInt;
		}

	}

	printf("Proyecto mas demandado: %s (%d asignados) \n", proyectos[IDProyect].nombre, maxProyect);
	system("pause");
}

void ordenarProgramadores(programador sProgrammer[], int longitud)
{
	int i;
	int j;
	programador aux;

	for (i = 0; i < longitud - 1; i++)
	{
		for (j = i; j < longitud; j++)
		{
			if (sProgrammer[i].estado == 1 && sProgrammer[j].estado == 1)
			{
				if (sProgrammer[i].id >= sProgrammer[j].id)
				{
					aux = sProgrammer[i];
					sProgrammer[i] = sProgrammer[j];
					sProgrammer[j] = aux;
				}
			}
		}
	}
}
