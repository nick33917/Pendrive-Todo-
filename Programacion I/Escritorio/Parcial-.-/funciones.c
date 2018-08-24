#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


void estadosEn0(eDuenio personas[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        personas[i].estado=0;
    }
}


int obtenerEspacioLibre(eDuenio lista[],int tam)
{
    int indice=-1, i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;

}

int buscarPorId(eDuenio lista[], int id, int tam)
{
    int indice=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].idDuenio==id && lista[i].estado ==1)
        {
            indice=i;
            break;
        }

    }
    return indice;
}

void altaPersona(eDuenio lista[],int tam,int maximo)
{
    eDuenio nuevaPersona;
    int espacio;
    int esta;
    int id;
    char buffer[2000];
    espacio=obtenerEspacioLibre(lista,tam);
    if(espacio==-1)
    {
        printf("No hay mas lugar para cargar Personas !!! \n");

    }
    else
    {
        printf("Ingrese el id del dueño: ");
        fflush(stdin);
        gets(buffer);

        while(validarNumero(buffer)!=0)
        {
            printf("\nReingrese el id: ");
            fflush(stdin);
            gets(buffer);
        }
        id=atoi(buffer);
        nuevaPersona.idDuenio=id;
        esta=buscarPorId(lista,id,tam);
        if(esta!=-1)
        {
            printf("\nEl id: %d  ya fue ingresado !!!",id);


        }
        else
        {


            printf("\nIngrese el nombre: ");
            fflush(stdin);
            gets(buffer);
            while(validarNombre(buffer,maximo)==0)
            {
                printf("\nReingre el nombre: ");
                fflush(stdin);
                gets(buffer);
            }
            strcpy(nuevaPersona.nombre,buffer);

            printf("\nIngrese el apellido: ");
            fflush(stdin);
            gets(buffer);
            while(validarNombre(buffer,maximo)==0)
            {
                printf("\nReingre el apellido: ");
                fflush(stdin);
                gets(buffer);
            }
            strcpy(nuevaPersona.apellido,buffer);

            printf("\nIngrese la direccion: ");
            fflush(stdin);
            gets(nuevaPersona.direccion);

            printf("\nIngrese el nº de la tarjeta de credito: ");
            scanf("%li",&nuevaPersona.numTarjCred);

            nuevaPersona.estado=1;
            lista[espacio]=nuevaPersona;


        }

    }


    printf("\n");

}

int validarNumero(char num[])
{
    int flag=0;
    int i;
    int cant;
    cant=strlen(num);

    for(i=0; i<cant; i++)
    {
        if(isdigit(num[i])==0)
        {
            flag=1;
            break;

        }
    }
    return flag;
}


int validarNombre(char aux[],int maximo)
{
    int flag=0;
    if(strlen(aux)<maximo-1)
    {
        flag=1;
    }
    return flag;
}



void estadosAutoen0(eEstacionamiento automovil[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        automovil[i].estado=0;
    }
}

int obtenerEstacionamientoLibre(eEstacionamiento lista[],int tam)
{
    int indice=-1, i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;

}

int buscarLugar(eEstacionamiento lista[], char patente[], int tam)
{
    int indice=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if((strcmp(lista[i].patente,patente)==0) && lista[i].estado ==1)
        {
            indice=i;
            break;
        }

    }
    return indice;
}


void altaEstacionamiento(eEstacionamiento lista[],int tam,int maximo)
{
    eEstacionamiento nuevoauto;
    int espacio;
    int esta;
    int id;
    char buffer[2000];
    int opcion;
    int aux;
    espacio=obtenerEstacionamientoLibre(lista,tam);
    if(espacio==-1)
    {
        printf("No hay mas lugar en el estacionamiento !!! \n");

    }
    else
    {
        printf("Ingrese la patente: ");
        fflush(stdin);
        gets(nuevoauto.patente);
        esta=buscarLugar(lista,nuevoauto.patente,tam);
        if(esta!=-1)
        {
            printf("\nLa patente: %s  ya fue ingresada !!!",nuevoauto.patente);


        }
        else
        {

            printf("\n\n\talpha_romeo 1\n \tferrari 2\n \taudi 3\n \totro 4\n\n");
            printf("\nIngrese la marca: ");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case ALPHA_ROMEO:
                nuevoauto.marca=ALPHA_ROMEO;
                break;
            case FERRARI:
                nuevoauto.marca=FERRARI;
                break;
            case AUDI:
                nuevoauto.marca=AUDI;
                break;
            case OTRO:
                nuevoauto.marca=OTRO;
                break;
            }
            nuevoauto.marca=opcion;
            printf("\nIngrese el id del dueño: ");
            fflush(stdin);
            gets(buffer);

            while(validarNumero(buffer)!=0)
            {
                printf("\nReingrese el id: ");
                fflush(stdin);
                gets(buffer);
            }
            id=atoi(buffer);
            nuevoauto.idDuenio=id;

            printf("\nIngrese la hora de entrada: ");
            scanf("%d",&aux);
            while(aux<0 || aux>24)
            {
                printf("\nReingrese la hora de entrada: \n");
                scanf("%d",&aux);
            }
            nuevoauto.horaEntrada=aux;
            nuevoauto.horaSalida=0;

            nuevoauto.estado=1;
            lista[espacio]=nuevoauto;


        }

    }


    printf("\n");

}

void ordenamiento(eEstacionamiento automoviles[],int cantAlq)
{
    int i;
    int j;
    eEstacionamiento aux;

        for(i=0; i<cantAlq-1; i++)
        {
            for(j=i+1; j<cantAlq; j++)
            {
                if(automoviles[i].horaEntrada > automoviles[j].horaEntrada )
                {
                    aux= automoviles[i];
                    automoviles[i] = automoviles[j];
                    automoviles[j] = aux;
                }
                else if(automoviles[i].horaEntrada == automoviles[j].horaEntrada)
                {
                    if(strcmpi(automoviles[i].patente, automoviles[j].patente) >0)
                    {
                        aux = automoviles[i];
                        automoviles[i] = automoviles[j];
                        automoviles[j] = aux;
                    }
                }
            }
        }

    }





void mostrarListadoDeAutos(eEstacionamiento autos[],eDuenio pers[],int tamDue,int tamAut)
{
    int i;
    int j;
    for(i=0; i<tamAut; i++)
    {
        for(j=0; j<tamDue; j++)
        {
            if(autos[i].idDuenio==pers[j].idDuenio  && autos[i].estado==1)
            {

                if(autos[i].marca==1)
                {
                    printf("%6s    ALPHA_ROMEO       %d         %d         %d      %10s     %10s    %12s     %li\n",autos[i].patente,autos[i].horaEntrada,autos[i].idDuenio,autos[i].estado,pers[j].nombre,pers[j].apellido,pers[j].direccion,pers[j].numTarjCred);

                }
                else if(autos[i].marca==2)
                {
                    printf("%6s        FERRARI       %d         %d         %d      %10s     %10s    %12s     %li\n",autos[i].patente,autos[i].horaEntrada,autos[i].idDuenio,autos[i].estado,pers[j].nombre,pers[j].apellido,pers[j].direccion,pers[j].numTarjCred);


                }
                else if(autos[i].marca==3)
                {
                    printf("%6s           AUDI       %d         %d         %d      %10s     %10s    %12s     %li\n",autos[i].patente,autos[i].horaEntrada,autos[i].idDuenio,autos[i].estado,pers[j].nombre,pers[j].apellido,pers[j].direccion,pers[j].numTarjCred);


                }
                else
                {
                    printf("%6s           OTRO       %d         %d        %d       %10s      %10s    %12s     %li\n",autos[i].patente,autos[i].horaEntrada,autos[i].idDuenio,autos[i].estado,pers[j].nombre,pers[j].apellido,pers[j].direccion,pers[j].numTarjCred);


                }
                break;

            }

        }
    }


}

void modificarDuenio(eDuenio pers[],int tam)
{
    int id;
    int i;
    int flag=0;
    printf("Ingrese el id de la persona: ");
    scanf("%d",&id);
    for(i=0; i<tam; i++)
    {
        if(id==pers[i].idDuenio)
        {
            printf("Ingrese el nuevo numero de tarjeta: ");
            scanf("%li",&pers[i].numTarjCred);
            flag=1;
            break;
        }

    }
    if(!flag)
    {
        printf("Id incorrecto!!!\n");
    }
}

void egresoAutomovil(eDuenio persona[],int tamPer,eEstacionamiento autos[],int tamAut)
{
    int i;
    int j;
    int id;
    int auxNum;
    int flag=0;
    int marca;
    char nombre[20];
    char apellido[20];
    int horasEstacionado=0;
    int valor;
    char auxPatente[8];
    int salida=0;

    printf("Ingrese la patente del automovil que desea retirar: ");
    fflush(stdin);
    gets(auxPatente);

    printf("\nIngrese el horario de salida: ");
    scanf("%d",&auxNum);
    while(auxNum<0 ||auxNum>24)
    {
        printf("\nReingrese el horario de salida: ");
        scanf("%d",&auxNum);

    }
    salida=auxNum;


    for(i=0; i<tamAut; i++)
    {

        if(strcmpi(auxPatente,autos[i].patente)==0 && autos[i].estado==1)
        {
            id=autos[i].idDuenio;
            if(autos[i].horaEntrada < salida)
            {
                autos[i].horaSalida=salida;
                horasEstacionado = (autos[i].horaSalida - autos[i].horaEntrada);
                flag=1;
                autos[i].estado=0;

            }

            if(autos[i].marca==1)
            {
                valor=150*horasEstacionado;
                marca=1;
                break;
            }
            else if(autos[i].marca==2)
            {
                valor=175*horasEstacionado;
                marca=2;
                break;
            }
            else if(autos[i].marca==3)
            {
                valor=200*horasEstacionado;
                marca=3;
                break;
            }
            else
            {
                valor=250*horasEstacionado;
                break;
            }


        }
    }

    if(flag==0)
    {
        printf("Supero la estadia permitida o la patente no se encuentra en el sistema !!!\n");
    }

    if(flag)
    {
        for(j=0; j<tamPer; j++)
        {

            if(id==persona[j].idDuenio)
            {
                strcpy(nombre,persona[j].nombre);
                strcpy(apellido,persona[j].apellido);
                break;
            }
        }
        printf("NOMBRE---APELLIDO---PATENTE---MARCA---VALOR ESTADIA\n\n");
        if(marca==1)
        {
            printf("%10s    %12s    %6s    ALPHA_ROMEO    %d\n",nombre,apellido,auxPatente,valor);


        }
        else if(marca==2)
        {
            printf("%10s    %12s    %6s        FERRARI    %d",nombre,apellido,auxPatente,valor);

        }
        else if(marca==3)
        {
            printf("%10s    %12s    %6s           AUDI    %d",nombre,apellido,auxPatente,valor);

        }
        else
        {
            printf("%10s    %12s    %6s           OTRO    %d",nombre,apellido,auxPatente,valor);


        }

    }


}



void propietariosAudi(eEstacionamiento autos[],int tambAut,eDuenio persona[],int tambPer)
{
    int i;
    int j;
    int id;
    printf("NOMBRE------APELLIDO-----DIRECCION----NUM TARJ\n\n");
    for(i=0; i<tambAut; i++)
    {
        if(autos[i].marca==3)
        {
            id=autos[i].idDuenio;
            for(j=0; j<tambPer; j++)
            {
                if(id==persona[i].idDuenio)
                {
                    printf("%8s     %8s    %8s       %li\n",persona[i].nombre,persona[i].apellido,persona[i].direccion,persona[i].numTarjCred);
                    break;
                }
            }

        }
    }
}


void recaudacionPorMarca(eEstacionamiento autos[],int tam)
{
    int resultado;
    int i;
    int acumRomeo=0;
    int acumFerrari=0;
    int acumAudi=0;
    int acumOtro=0;

    for(i=0; i<tam; i++)
    {

        if(autos[i].marca==1 && autos[i].estado==0)
        {
            resultado=(autos[i].horaSalida - autos[i].horaEntrada)*150;
            acumRomeo = acumRomeo + resultado;

        }

        else if(autos[i].marca==2 && autos[i].estado==0)
        {
            resultado=(autos[i].horaSalida - autos[i].horaEntrada)*175;
            acumFerrari=acumFerrari+resultado;
        }
        else if(autos[i].marca==3 && autos[i].estado==0)
        {
            resultado=(autos[i].horaSalida - autos[i].horaEntrada)*200;
            acumAudi=acumAudi+resultado;
        }
        else if(autos[i].marca==4 && autos[i].estado==0)
        {
            resultado=(autos[i].horaSalida - autos[i].horaEntrada)*250;
            acumOtro=acumOtro+resultado;
        }

    }

    printf("ALPHA_ROMEO---FERRARI-----AUDI-----OTRO\n\n");
    printf("%6d\t      %d\t %d\t    %d\n",acumRomeo,acumFerrari,acumAudi,acumOtro);

}


void recaudacionTotalEstacionamiento(eEstacionamiento autos[],int tam)
{
    int resultado;
    int i;
    int acum=0;

    for(i=0; i<tam; i++)
    {

        if(autos[i].marca==1 && autos[i].estado==0)
        {
            resultado=(autos[i].horaSalida - autos[i].horaEntrada)*150;
            acum = acum + resultado;

        }

        else if(autos[i].marca==2 && autos[i].estado==0)
        {
            resultado=(autos[i].horaSalida - autos[i].horaEntrada)*175;
            acum=acum+resultado;
        }
        else if(autos[i].marca==3 && autos[i].estado==0)
        {
            resultado=(autos[i].horaSalida - autos[i].horaEntrada)*200;
            acum=acum+resultado;
        }
        else if(autos[i].marca==4 && autos[i].estado==0)
        {
            resultado=(autos[i].horaSalida - autos[i].horaEntrada)*250;
            acum=acum+resultado;
        }

    }

    printf("Recaudacion total del estacionamiento: %d",acum);
    printf("\n");


}





