#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

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
}eProgramador;

typedef struct
{
	int idCategoria;
	char descripcion[200];
	int pagoPorHora;
}eCategoria;

typedef struct
{
    int idProyecto;
	char nombre[50];
	int numAsignados[3];
}eProyecto;

/** \brief Limpia pantalla.
 */
void fLimpiar();

void fInicializarEstados(eProgramador prog[], int tam);
void fCargarCategorias(eCategoria cate[], int tam);
void fCargarProyectos(eProyecto proyec[]);


#endif // FUNCIONES_H_INCLUDED
