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


void estadosEn0(eDuenio [],int);
int buscarPorId(eDuenio [], int, int);
int obtenerEspacioLibre(eDuenio [],int);
void altaPersona(eDuenio[],int,int);
int validarNumero(char []);
int validarNombre(char [],int );

void estadosAutoen0(eEstacionamiento[],int);
int buscarLugar(eEstacionamiento[], char[], int );
int obtenerEstacionamientoLibre(eEstacionamiento [],int );
void altaEstacionamiento(eEstacionamiento[],int,int);



void ordenamiento(eEstacionamiento [],int);
void mostrarListadoDeAutos(eEstacionamiento[],eDuenio[],int ,int);
void modificarDuenio(eDuenio[],int);
void egresoAutomovil(eDuenio[],int ,eEstacionamiento [],int );
void propietariosAudi(eEstacionamiento[],int ,eDuenio [],int );
void recaudacionPorMarca(eEstacionamiento[],int);
void recaudacionTotalEstacionamiento(eEstacionamiento[],int);

