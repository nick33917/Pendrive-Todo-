#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	int idCategoria;
	int horas;
	int estado;
	int numProyectos;
	int idProyectosAsignados[1000];
	int idProyectosHoras[1000];
} programador;

typedef struct
{
	int idCategoria;
	char descripcion[200];
	int pagoXHora;
} categorias;

typedef struct
{
	int idProyecto;
	char nombre[50];
	int numAsignados[3];
} proyectos;

/**
 * Agrega un programador al array.
 * @param lista el array programador se pasa como parametro
 * @param tamaño del array pasado como parametro
 * @param id del ultimo ingresado en forma de autoincrementar
 * @return 1 si tuvo exito o 0 si falló
 */
int agregarNuevoProgramador(programador programador[], int longitud, int lastId);


/**
 * Modifica un programador del array.
 * @param lista el array programador se pasa como parametro
 * @param tamaño del array pasado como parametro
 * @return 1 si tuvo exito o 0 si falló
 */
void modificarProgramador(programador programador[], int longitud);


/**
 * Elimina (cambia estado a 0) de un programador al array.
 * @param lista el array programador se pasa como parametro
 * @param lista el array proyectos se pasa como parametro
 * @param tamaño del array pasado como parametro
 * @return 1 si tuvo exito o 0 si falló
 */
void eliminarProgramador(programador programador[], proyectos proyectos[], int longitud);

/**
 * Carga categorias al array categorias
 * @param Carga categorias al array categorias
 * @return 1 si tuvo exito o 0 si falló
 */
void cargarCategorias(categorias categorias[]);

/**
 * Carga proyectos al array proyectos
 * @param Carga proyectos al array proyectos
 * @return 1 si tuvo exito o 0 si falló
 */
void cargarProyectos(proyectos proyectos[]);

/**
 * Valida que el valor ingresado sea un entero
 * @param pasa el entero como parametro
 * @return 1 si tuvo exito o 0 si falló
 */
int validarNumero(char entero[]);

/**
 * Valida que el valor ingresado sean caracteres
 * @param pasa el caracter como parametro
 * @return 1 si tuvo exito o 0 si falló
 */
int validarCadena(char caracter[]);

/**
 * Asigna proyectos al array de programadores dentro de sus variables
 * @param lista el array programador se pasa como parametro
 * @param tamaño del array pasado como parametro
 * @param lista el array proyectos se pasa como parametro
 * @return 1 si tuvo exito o 0 si falló
 */
void asignarProgramadorAProyecto(programador programador[], int longitud, proyectos proyectos[]);

/**
 * Inicializa los estados de todo el array en 0 para no ser mostrador/cargados y obtener basura
 * @param lista el array programador se pasa como parametro
 * @param tamaño del array pasado como parametro
 * @return 1 si tuvo exito o 0 si falló
 */
void inicializarEstados(programador programador[], int longitud);

/**
 * Lista los programadores con su categoria y proyectos
 * @param lista el array programador se pasa como parametro
 * @param tamaño del array pasado como parametro
 * @param lista el array categorias se pasa como parametro
 * @param lista el array proyectos se pasa como parametro
 * @return 1 si tuvo exito o 0 si falló
 */
void listarProgramadores(programador programador[], int longitud, categorias categorias[], proyectos proyectos[]);

/**
 * Lista los proyectos con sus respectivos contadores de categorias que lo integran
 * @param lista el array proyectos se pasa como parametro
 * @return 1 si tuvo exito o 0 si falló
 */
void listarProyectos(proyectos proyectos[]);

/**
 * Lista proyectos del programador indicado por ID
 * @param lista el array programador se pasa como parametro
 * @param tamaño del array pasado como parametro
 * @param lista el array proyectos se pasa como parametro
 * @return 1 si tuvo exito o 0 si falló
 */
void listarProgramadorByID(programador programador[], int longitud, proyectos proyectos[]);

/**
 * Muestra el proyecto más demandado (con más integrantes)
 * @param lista el array proyectos se pasa como parametro
 * @return 1 si tuvo exito o 0 si falló
 */
void proyectoDemandante(proyectos proyectos[]);

/**
 * Ordena los programadores dentro del array
 * @param lista el array programador se pasa como parametro
 * @param tamaño del array pasado como parametro
 * @return 1 si tuvo exito o 0 si falló
 */
void ordenarProgramadores(programador sProgrammer[], int longitud);

#endif // LIB_H_INCLUDED
