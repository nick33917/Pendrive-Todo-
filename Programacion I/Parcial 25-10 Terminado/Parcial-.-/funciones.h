#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

typedef struct
{
    int idDuenio;
    char nombre[20];
    char apellido[20];
    char direccion[20];
    long int numTarjCred;
    int estado;
}eDuenio;


typedef struct
{
    char patente[20];
    int marca;
    int idDuenio;
    int horaEntrada;
    int horaSalida;
    int estado;
}eEstacionamiento;



/** \brief inicia todos los estados de la estructura en 0.
 *
 * \param el array de la estrucutura.
 * \param tamaño del array de la estructura.
 * \return void.
 *
 */
void estadosEn0(eDuenio [],int);


/** \brief Obtiene el indice que coincide con el id pasado por parametro.
 *
 * @param el array se pasa como parametro.
 * @param el id a ser buscado en el array.
 * @param tamaño del array de la estructura.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro id y si no lo encuentra devuelve -1.
 *
 */
int buscarPorId(eDuenio [], int, int);


/** \brief Obtiene el primer indice libre del array.
 *
 * @param el array se pasa como parametro.
 * @param tamaño del array de la estructura.
 * @return el primer indice disponible y si devuelve -1 no hay mas lugar.
 *
 */
int obtenerEspacioLibre(eDuenio [],int);


/** \brief Ingreso de un cliente en el sistema.
 *
 * \param el array se pasa como parametro.
 * \param tamaño del array de la estructura.
 * \param cantidad maxima de letras que puede tener un nombre.
 * \return void.
 *
 */
void altaPersona(eDuenio[],int,int);


/** \brief valida si el numero ingresado no contiene  letras.
 *
 * \param cadena de char donde se guarda el numero
 * \return devuelve distinto de 0 si contiene letras.
 *
 */
int validarNumero(char []);


/** \brief valida la cantidad maxima de caracteres que se puede ingresar.
 *
 * \param array donde se guarda el nombre ingresado.
 * \param cantidad maxima de caracteres para ingresar el nombre.
 * \return devuelve 0 si cumple con la condicion y devuelve 1 si no cumple .
 *
 */
int validarNombre(char [],int );


/** \brief inicia todos los estados de la estructura en 0.
 *
 * \param el array de la estrucutura.
 * \param tamaño del array de la estructura.
 * \return void.
 *
 */
void estadosAutoen0(eEstacionamiento[],int);


/** \brief
 *
 * \param el array de la estrucutura.
 * \param la patente a buscar.
 * \param tamaño del array de la estructura.
 * \return devuelve el indice de donde se encuentra y si devuelve -1 no la encontro.
 *
 */
int buscarPatente(eEstacionamiento[], char[], int );



/** \brief Obtiene el primer indice libre del array.
 *
 * @param el array se pasa como parametro.
 * @param tamaño del array de la estructura.
 * @return el primer indice disponible y si devuelve -1 no hay mas lugar.
 *
 */
int obtenerEstacionamientoLibre(eEstacionamiento [],int );



/** \brief Ingreso de un automovil al estacionamiento.
 *
 * \param el array se pasa como parametro.
 * \param tamaño del array de la estructura.
 * \param cantidad maxima de letras que puede tener un nombre.
 * \return void.
 *
 */
void altaEstacionamiento(eEstacionamiento[],int,int);


/** \brief ordena por horario de entrada y si hay 2 iguales , por order alfabetico de las patentes.
 *
 * \param el array de la estrucutura.
 * \param tamaño del array de la estructura.
 * \return void.
 *
 */
void ordenamiento(eEstacionamiento [],int);



/** \brief Muestra cada auto que esta en el estacionamiento , con los datos del duenio.
 *
 * \param el array de una estrucutura.
 * \param el array de otra estrucutura.
 * \param tamaño del array de la 2da estructura.
 * \param tamaño del array de la 1ra estructura.
 * \return void.
 *
 */
void mostrarListadoDeAutos(eEstacionamiento[],eDuenio[],int ,int);


/** \brief modifica el numero de tarjeta de un cliente.
 *
 * \param el array de una estrucutura.
 * \param tamaño del array de la estructura
 * \return void.
 *
 */
void modificarDuenio(eDuenio[],int);


/** \brief Imprime un ticket cuando el automovil sale del estacionmiento con los datos de lo que gasto.
 *
 * \param el array de una estrucutura.
 * \param tamaño del array de la 1ra estructura.
 * \param el array de otra estrucutura.
 * \param tamaño del array de la 2da estructura.
 * \return void.
 *
 */
void egresoAutomovil(eDuenio[],int ,eEstacionamiento [],int );



/** \brief Muestra los datos de las personas que ingresaron un automovil marca Audi.
 *
 * \param el array de una estrucutura.
 * \param tamaño del array de la 1ra estructura.
 * \param el array de otra estrucutura.
 * \param tamaño del array de la 2da estructura.
 * \return void.
 *
 */
void propietariosAudi(eEstacionamiento[],int ,eDuenio [],int );


/** \brief Calcula y muestra la recaudacion de cada marca ingresada en el estacionamiento.
 *
 * \param el array de una estrucutura.
 * \param tamaño del array de la estructura.
 * \return void.
 *
 */
void recaudacionPorMarca(eEstacionamiento[],int);


/** \brief Calcula la ganancia total del estacionamiento y la muestra.
 *
 * \param el array de una estrucutura.
 * \param tamaño del array de la estructura.
 * \return void.
 *
 */
void recaudacionTotalEstacionamiento(eEstacionamiento[],int);

