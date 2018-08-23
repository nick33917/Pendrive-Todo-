#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAX 20
#define CantPer 4
#define CantAuto 4
int main()
{
    int opcion;
    char seguir='s';
    eDuenio personas[]={{1,"pedro","piserchia","lynch 209",151548,1},{2,"arnaldo","florentino","mitre 504",161710,1},{3,"romualdo","perez","salta 201",131917,1},{4,"pepe","tontolino","magan 400",333698,1}};
    eEstacionamiento automovil[]={{"AOY405",1,1,15,21,1},{"FLH401",2,2,14,20,1},{"LEK236",3,3,16,22,1},{"HGI801",4,4,10,18,1}};
    //para usar la funcion 7,8 y 9 hay que poner los estados en0, es decir que ya se retiraron del estacionamiento//


    /*
    estadosEn0(personas,CantPer);
    estadosAutoen0(automovil,CantAuto);

    cargarEstacionamiento(automovil,3);
    cargarPersonas(personas,CantPer);
    */

    while(seguir=='s')
    {
        printf("\t\t\t-------------ESTACIONAMIENTO-------------\n\n");
        printf("1-Alta del duenio.\n");
        printf("2-Modificacion del duenio.\n");
        printf("3-Ingreso del automovil.\n");
        printf("4-Egreso del automovil.\n");
        printf("5-Listado de autos estacionados con datos de los dueños.\n");
        printf("6-Propietarios de autos Audi.\n");
        printf("7-Recaudacion total por marca.\n");
        printf("8-Recaudacion total del estacionamiento.\n");
        printf("9-Salir.\n\n");
        printf("\nIngrese la opcion: ");
        scanf("%d",&opcion);


        switch(opcion)
        {
        case 1:
            system("cls");
            altaPersona(personas,CantPer,MAX);
            system("pause");
            break;
        case 2:
            system("cls");
            modificarDuenio(personas,CantPer);
            system("pause");
            break;
        case 3:
            system("cls");
            altaEstacionamiento(automovil,CantAuto,MAX);
            system("pause");
            break;
        case 4:
            system("cls");
            egresoAutomovil(personas,CantPer,automovil,CantAuto);
            system("pause");
            break;
        case 5:
            system("cls");
            printf("PATENTE------MARCA----HORA ENTRADA---IDDUEÑO---ESTADO-------NOMBRE------APELLIDO-------DIRECCION----NUM TARJ\n\n");
            ordenamiento(automovil,CantAuto);
            mostrarListadoDeAutos(automovil,personas,CantPer,CantAuto);
            system("pause");
            break;

        case 6:
            system("cls");
            propietariosAudi(automovil,CantAuto,personas,CantPer);
            system("pause");
            break;
        case 7:
            system("cls");
            recaudacionPorMarca(automovil,CantAuto);
            system("pause");
            break;
        case 8:
            system("cls");
            recaudacionTotalEstacionamiento(automovil,CantAuto);
            system("pause");
            break;
        case 9:
            seguir='n';
            break;


        default:
            printf("Reingrese la opcion !!!\n");
            break;

        }
        system("cls");
    }

    return 0;
}
