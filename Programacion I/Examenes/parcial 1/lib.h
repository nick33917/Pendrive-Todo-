#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    int idCategoria;
    int estado;
} eProgramador;

typedef struct
{
    int idCategoria;
    char descripcion[50];
    int pagoHora;
} eCategoria;

typedef struct
{
    int idProyecto;
    char nombre[50];
} eProyecto;

typedef struct
{
    int idProgramador;
    int idProyecto;
    int horasDeTrabajo;
} eProgramadorProyecto;
/** \brief Muestra un menu y pide una opcion.
 * \param Pide el mensaje que va a ser mostrado.
 * \return Retorna la opcion
 */
int menu(char mensaje[]);
/** \brief Da de alta a un programador
 * \param Pide la estructura programadores
 * \param Pide el tamaño de la estructura
 * \return Retorna 0 si hubo un error o 1 si esta todo bien
 *
 */
int alta(eProgramador programadores[],int tam);
/** \brief Busca una posicion libre en la estructura programadores
 * \param Pide la estructura programadores
 * \param Pide el tamaño de la estructura
 * \return Retorna la posicion libre o -1 si no encontro un lugar libre
 */
int posicionLibre(eProgramador programadores[],int tam);
/** \brief Verifica que el id no este repetido
 * \param Pide la estructura programadores
 * \param Pide el tamaño de la estructura
 * \param Pide el id que va a ser verificado
 * \return Retorna 0 si encontro el id repetido o 1 si esta todo bien
 */
int verificarId(eProgramador programadores[],int tam,int id);
/** \brief Pre carga datos a las estructuras
 * \param Pide la estructura programador
 * \param Pide la estructura proyectos
 * \param Pide la estructura categorias
 * \param Pide la estructura programador proyectos
 */
void hardCodear(eProgramador programadores[],eProyecto proyectos[],eCategoria categorias[],eProgramadorProyecto programadorproyectos[]);
/** \brief Modifica una de las tantas opciones de un programador
 * \param Pide la estructura programadores
 * \param Pide la estructura programador proyectos
 * \param Pide la estructura proyectos
 * \param Pide el tamaño de la estructura programadores
 * \param Pide el tamaño de la estructura programadores proyectos
 * \param Pide el tamaño de la estructura proyectos
 * \return Retorna 1 si esta todo bien y si hubo un error retorna 0
 */
int modificar(eProgramador programadores[],eProgramadorProyecto programadorproyecto[],eProyecto proyectos[],int tam,int tamPP,int tamp);
/** \brief Inicializa los estados de programadores en 0
 * \param Pide la estructura programador
 * \param Pide el tamaño de la estructura
 */
void inicializarEstados(eProgramador programadores[],int tam);
/** \brief Da de baja a un programador
 * \param Pide la estructura programador
 * \param Pide la estructura programador proyecto
 * \param Pide el tamaño de la estructura programador
 * \param Pide el tamaño de la estructura programador proyecto
 * \return Retorna 1 si esta todo bien o 0 si hubo un error
 *
 */
int baja(eProgramador programadores[],eProgramadorProyecto programadoresproyectos[],int tam,int tamPP);
/** \brief Asigna un programador a un proyecto
 * \param Pide la estructura programadores
 * \param Pide la estructura proyectos
 * \param Pide la estructura programadores proyectos
 * \param Pide el tamaño de la estructura programador
 * \param Pide el tamaño de la estructura proyectos
 * \param Pide el tamaño de la estructura programador proyecto
 * \return Retorna 1 si esta todo bien o 0 si hubo un error
 */
int asignarProgramador(eProgramador programadores[],eProyecto proyectos[],eProgramadorProyecto pp[],int tam,int tamp,int tampp);
/** \brief Inicializa en -1 la estructura programador proyectos
 * \param Pide la estructura programador proyectos
 * \param Pide el tamaño de la estructura programador proyectos
 */
void inicializarPp(eProgramadorProyecto pp[],int tampp);
/** \brief Inicializa en -1 la estructura proyectos
 * \param Pide la estructura proyectos
 * \param Pide el tamaño de la estructura proyectos
 */
void inicializarProyectos(eProyecto proyectos[],int tampy);
/** \brief Hace una lista de todos los programadores
 * \param Pide la estructura programadores
 * \param Pide la estructura categoria
 * \param Pide la estructura programadores proyectos
 * \param Pide la estructura programador proyecto
 * \param Pide el tamaño de la estructura programador
 * \param Pide el tamaño de la estructura proyectos
 * \param Pide el tamaño de la estructura programador proyecto
 * \return Retorna 1 si esta todo bien o 0 si hubo un error
 */
int listadoProgramadores(eProgramador programadores[],eCategoria categorias[],eProyecto proyectos[],eProgramadorProyecto pp[],int tam,int tamp,int tampp);
/** \brief Hace una lista de todos los proyectos
 * \param Pide la estructura programadores
 * \param Pide la estructura proyectos
 * \param Pide la estructura programadores proyectos
 * \param Pide el tamaño de la estructura programador
 * \param Pide el tamaño de la estructura proyectos
 * \param Pide el tamaño de la estructura programador proyecto
 * \return Retorna 1 si esta todo bien o 0 si hubo un error
 */
int listadoProyectos(eProgramador programadores[],eProyecto proyectos[],eProgramadorProyecto pp[],int tam,int tamp,int tampp);
/** \brief Hace una lista de los proyectos de un programador
 * \param Pide la estructura programadores
 * \param Pide la estructura proyectos
 * \param Pide la estructura programadores proyectos
 * \param Pide el tamaño de la estructura programador
 * \param Pide el tamaño de la estructura proyectos
 * \param Pide el tamaño de la estructura programador proyecto
 * \return Retorna 1 si esta todo bien o 0 si hubo un error
 */
int listarProyectosProgramador(eProgramador programadores[],eProyecto proyectos[],eProgramadorProyecto pp[],int tam,int tamp,int tampp);
/** \brief Muestra el proyecto con mas programadores
  * \param Pide la estructura programadores
 * \param Pide la estructura proyectos
 * \param Pide la estructura programadores proyectos
 * \param Pide el tamaño de la estructura programador
 * \param Pide el tamaño de la estructura proyectos
 * \param Pide el tamaño de la estructura programador proyecto
 * \return Retorna 1 si esta todo bien o 0 si hubo un error
 */
int proyectoDemandante(eProgramador programadores[],eProyecto proyectos[],eProgramadorProyecto pp[],int tam,int tamp,int tampp);
/** \brief Muestra un mensaje y pide al usuario ingresar un string
 * \param  Pide el mensaje a ser mostrado
 * \param  Pide la cadena en la que el usuario va a escribir
 */
void getString(char mensaje[],char input[]);
/** \brief Pide un string y valida que contenga solo numeros
 * \param  Pide la cadena que va a ser validada
 * \return Retorna 0 si la cadena tiene letras, sino retorna 1
 */
int getStringLetras(char mensaje[],char input[]);
/** \brief Pide un string y valida que contenga solo letras
 * \param  Pide la cadena que va a ser validada
 * \return Retorna 0 si la cadena tiene numero, sino retorna 1
 */
int esSoloLetras(char str[]);
/** \brief Muestra un mensaje, pide al usuario un string y despues valida que solo contenga numeros
 * \param  Pide el mensaje a ser mostrado
 * \param  Pide la cadena en la que el usuario va a escribir
 * \return Retorna 1 si esta todo validado, sino retorna 0
 */
int getStringNumeros(char mensaje[],char input[]);
/** \brief Pide un string y valida que contenga solo numeros
 * \param  Pide la cadena que va a ser validada
 * \return Retorna 0 si la cadena tiene letras, sino retorna 1
 */
int esNumerico(char str[]);

