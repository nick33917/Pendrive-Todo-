#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define MAX 50
typedef struct {

    char nombre[MAX];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[],int tamb);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int docum , int tam);
void estadosEn0(EPersona personas[],int tam);
void ordenarNombre(EPersona lista[],int tam);
void altaPersona(EPersona lista[],int tam,int maximo);
int validarNombre(char aux[],int tam);
int validarDni(int aux);
int validarEdad(int anios);
void bajaPersona(EPersona lista[],int tam);
void mostrarPersonas(EPersona lista[],int tam);
void mostrarPersona(EPersona unaPersona);


#endif // FUNCIONES_H_INCLUDED
