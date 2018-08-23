
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void estadosEn0(EPersona personas[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        personas[i].estado=0;
    }
}




int buscarPorDni(EPersona lista[], int docum, int tam)
{
    int indice=-1,i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].dni==docum && lista[i].estado ==1)
        {
            indice=i;
            break;
        }

    }

    return indice;

}




void ordenarNombre(EPersona lista[],int tam)
{
    int i;
    int j;
    EPersona auxEPersona;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre) >0 )
            {
                auxEPersona = lista[j];
                lista[j] = lista[i];
                lista[i] = auxEPersona;
            }

            if(strcmp(lista[i].nombre, lista[j].nombre) ==0 )
            {
                if(lista[i].dni>lista[j].dni)
                {
                    auxEPersona = lista[j];
                    lista[j] = lista[i];
                    lista[i] = auxEPersona;

                }
            }
        }

    }

}



void mostrarPersona(EPersona unaPersona)
{

    printf("%d     %s\t      %d  \n",unaPersona.dni,unaPersona.nombre,unaPersona.edad);
    printf("\n--------------------------------------------------\n");

}




void mostrarPersonas(EPersona lista[],int tam)
{
    int flag=-1, i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            mostrarPersona(lista[i]);
            flag=1;
        }

    }
    if(flag==-1)
    {
        printf("No hay ninguna persona cargada para mostrar\n");
    }


}




int obtenerEspacioLibre(EPersona lista[],int tam)
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




void altaPersona(EPersona lista[],int tam,int maximo)
{
    EPersona nuevaPersona;
    int espacio;
    int esta;
    int edad;
    int dni;
    char buffer[2000];
    espacio=obtenerEspacioLibre(lista,tam);
    if(espacio==-1)
    {
        printf("No hay mas lugar para cargar Personas !!! \n");

    }
    else
    {
        printf("Ingrese el dni: ");
        fflush(stdin);
        gets(buffer);

        while(validarNumero(buffer)!=0)
        {
            printf("\nReingrese el dni: ");
            fflush(stdin);
            gets(buffer);
        }
        dni=atoi(buffer);
        nuevaPersona.dni=dni;
        esta=buscarPorDni(lista,dni,tam);
        if(esta!=-1)
        {
            printf("\nEl dni: %d  ya fue ingresado !!!",dni);


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

            printf("\nIngrese la edad: ");
            fflush(stdin);
            gets(buffer);
            while(validarNumero(buffer)!=0 || strlen(buffer)<0 || strlen(buffer)>3)
            {
                printf("\nReingrese la Edad: ");
                fflush(stdin);
                gets(buffer);

            }
            edad=atoi(buffer);
            nuevaPersona.edad=edad;

            nuevaPersona.estado=1;
            lista[espacio]=nuevaPersona;


        }

    }


    printf("\n");

}




void bajaPersona(EPersona lista[],int tam)
{
    int dni;
    int i;
    char eliminar='n';
    printf("Ingrese el dni de la persona a buscar: ");
    scanf("%d",&dni);
    i=buscarPorDni(lista, dni, tam);
    if(i!=-1)
    {
        printf("\tLos datos de la persona son: \nDNI----------NOMBRE--------EDAD\n");
        printf("%d     %s        %d\n",lista[i].dni,lista[i].nombre,lista[i].edad);
        printf("Desea dar de baja del sistema a esta persona? s/n: ");
        fflush(stdin);
        scanf("%c",&eliminar);
        if(eliminar=='s')
        {
            printf("\nLa persona fue dada de baja\n");
            lista[i].estado=0;

        }
        else
        {
            printf("\nLa persona no fue dada de baja\n");

        }

    }
    else
    {
        printf("\nEl documento no se encontro en el sistema\n");

    }


}


void ModificarPersona(EPersona lista[],int tam,int maximo)
{
    char buffer[2000];
    int dni;
    int i;
    char modificar='n';
    printf("Ingrese el dni de la persona que quiere modificar: ");
    scanf("%d",&dni);
    i=buscarPorDni(lista, dni, tam);
    if(i!=-1)
    {
        printf("\tLos datos de la persona son: \nDNI----------NOMBRE--------EDAD\n");
        printf("%d     %s        %d\n",lista[i].dni,lista[i].nombre,lista[i].edad);
        printf("Desea modificar los datos de esta persona? s/n: ");
        fflush(stdin);
        scanf("%c",&modificar);
        if(modificar=='s')
        {
            printf("\nIngrese el Nuevo nombre: ");
            fflush(stdin);
            gets(buffer);
            while(validarNombre(buffer,maximo)==0)
            {
                printf("\nReingre el nombre: ");
                fflush(stdin);
                gets(buffer);
            }
            strcpy(lista[i].nombre,buffer);


        }
        else
        {
            printf("\nLos datos de la persona no fueron modificados.\n");

        }

    }
    else
    {
        printf("\nEl documento no se encontro en el sistema\n");

    }


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




//---------------------------**************************************************---------------------------------------------


void cargarClientes(eCliente personas[],int CantCliente)
{
    int id[]= {1,2,3,4,5};
    int dni[]= {1111,2222,3333,4444,5555};
    char nombre[][20]= {"juan","roberto","pedro","nicolas","facundo"};
    char apellido[][20]= {"figueiras","petinato","alfonso","fattori","arana"};
    int estado[]= {1,1,1,1,1};
    int i;
    for(i=0; i<CantCliente; i++)
    {
        personas[i].id=id[i];
        personas[i].dni=dni[i];
        strcpy(personas[i].nombre,nombre[i]);
        strcpy(personas[i].apellido,apellido[i]);
        personas[i].estado=estado[i];

    }

}


void cargarSituaciones(eSituacion estados[],int cantEst)
{
    int id[]= {1,2};
    char descrip[][15]= {"Alquilado","Finalizado"};
    int i;
    for(i=0; i<cantEst; i++)
    {
        estados[i].id=id[i];
        strcpy(estados[i].descrip,descrip[i]);
    }

}


void cargarEquipo(eEquipo herramientas[],int cantEquip)
{
    int id[]= {1,2,3};
    char descrip[][20]= {"Amoladora","Mezcladora","Taladro"};
    int i;

    for(i=0; i<cantEquip; i++)
    {
        herramientas[i].id=id[i];
        strcpy(herramientas[i].descrip,descrip[i]);
    }

}


void cargarAlquileres(eAlquiler alquileres[],int cantAlq)
{
    int idCliente[]= {1,1,2,3,3,3,3,3,5};
    int idEquipo[]= {1,2,1,2,2,3,2,3,3};
    int idSituacion[]= {1,1,1,1,1,1,1,1,1};
    float tiempoEstimado[]= {10.2,15.3,15.3,16,18,19,25,48,23};
    float tiempoReal[]= {12,56,8,9,45,48,15,16,12};
    int operador[]= {10,11,12,13,14,15,16,17,18};
    int estado[]= {1,1,1,1,1,1,1,1,1};
    int i;

     for(i=0;i<cantAlq;i++)
     {
         alquileres[i].idCliente=idCliente[i];
         alquileres[i].idEquipo=idEquipo[i];
         alquileres[i].idSituacion=idSituacion[i];
         alquileres[i].tiempoEstimado=tiempoEstimado[i];
         alquileres[i].tiempoReal=tiempoReal[i];
         alquileres[i].operador=operador[i];
         alquileres[i].estado=estado[i];

     }
}


void mostrarClientesConAlquileres(eCliente personas[],int cantCliente,eEquipo herramientas[],int cantEquipo,eAlquiler alquileres[],int cantAlq)
{
    //personas//
    int i;
    //alquileres//
    int j;
    //herramientas//
    int k;

    printf("ID  NOMBRE\t APELLIDO\t DNI\n\n");
    for(i=0; i<cantCliente; i++)
    {
        if(personas[i].estado!=0)
        {
            printf("%d   %6s   %7s    %5d\n\n",personas[i].id,personas[i].nombre,personas[i].apellido,personas[i].dni);
            printf("Alquilo:\n");
            for(j=0; j<cantAlq; j++)
            {
                if(personas[i].id==alquileres[j].idCliente)
                {
                    for(k=0; k<cantEquipo; k++)
                    {
                        if(alquileres[j].idEquipo==herramientas[k].id)
                        {
                            printf("\t%s\n",herramientas[k].descrip);
                            break;

                        }


                    }


                }

            }
        }
        printf("\n**********************************\n\n");
    }


}


void promedioTiempoReal(eEquipo herramientas[],int cantEquip,eAlquiler alquileres[],int cantAlq,eSituacion situaciones[],int cantSituac)
{
    int i;
    int j;
    int k;
    float acum=0;
    int cont=0;
    float prom;
    //recorro las herramientas//
    for(i=0;i<cantEquip;i++)
    {

        for(j=0;j<cantAlq;j++)
        {
            if(herramientas[i].id==alquileres[j].idEquipo && alquileres[j].estado==1)
            {
                for(k=0;k<cantSituac;k++)
                {
                    if(alquileres[j].idSituacion==situaciones[k].id)
                    {
                        printf("%.2f\n",alquileres[j].tiempoReal);
                        acum=alquileres[j].tiempoReal+acum;
                        cont++;
                        break;

                    }
                }
            }

        }

    }
    prom=acum/cont;
    printf("El promedio es:%.3f",prom);
}

int cantidadDeEquipos(int herramienta,eAlquiler alquileres[],int cantAlq)
{
    int cantidad=0;
    int i;

    for(i=0;i<cantAlq;i++)
    {
        if(alquileres[i].idEquipo==herramienta && alquileres[i].estado==1)
        {
            cantidad++;
        }
    }
    return cantidad;
}

int maximoDeEquipos(eAlquiler alquileres[],int cantAlq,eEquipo herramientas[],int cantEquipo)
{
    int maximo;
    int i;
    int flag=0;
    int cantidad;

    for(i=0;i<cantEquipo;i++)
    {
        cantidad=cantidadDeEquipos(herramientas[i].id,alquileres,cantAlq);
        if( cantidad>maximo ||flag==0)
        {
            maximo=cantidad;
            flag= 1;
        }

    }
    return maximo;

}

void mostrarEquiposMasAlquilados(eEquipo herramientas[],int cantEquipo,eAlquiler alquileres[],int cantAlq)
{
    int i;
    int maximo;

    maximo=maximoDeEquipos(alquileres,cantAlq,herramientas,cantEquipo);

    for(i=0;i<cantEquipo;i++)
    {
        if(maximo == cantidadDeEquipos(herramientas[i].id,alquileres,cantAlq))
        {
            printf("%s %d alquileres\n",herramientas[i].descrip,maximo);
        }
    }

}


int cantidadDeClientes(int cliente,eAlquiler alquileres[],int cantAlq)
{
    int cantidad=0;
    int i;

    for(i=0;i<cantAlq;i++)
    {
        if(alquileres[i].idCliente==cliente && alquileres[i].estado==1)
        {
            cantidad++;
        }
    }
    return cantidad;
}

int maximoDeClientes(eAlquiler alquileres[],int cantAlq,eCliente personas[],int cantCliente)
{
    int maximo;
    int i;
    int flag=0;
    int cantidad;

    for(i=0;i<cantCliente;i++)
    {
        cantidad=cantidadDeClientes(personas[i].id,alquileres,cantAlq);
        if( cantidad>maximo ||flag==0)
        {
            maximo=cantidad;
            flag= 1;
        }

    }
    return maximo;

}

void mostrarClientesConMasAlquileres(eCliente personas[],int cantCliente,eAlquiler alquileres[],int cantAlq)
{
    int i;
    int maximo;

    maximo=maximoDeClientes(alquileres,cantAlq,personas,cantCliente);
    for(i=0;i<cantCliente;i++)
    {
        if(maximo == cantidadDeClientes(personas[i].id,alquileres,cantAlq))
        {
            printf("%6s\t %6s\n",personas[i].nombre,personas[i].apellido);



        }


    }



}

void mostrarAlumnoConMaterias(eAlumno alumnos[],eMateria materias[],eInscripcion inscripcion[],int cantAlum,int cantMat,int CantInscrip)
{
  int i;
  int j;
  int k;
//recorre alumnos//
  for(i=0;i<cantAlum;i++)
  {
      printf("El alumno %6s con Legajo %d ,Esta Inscripto a las siguientes Materias:\n",alumnos[i].nombre,alumnos[i].legajo);
      //recorre inscripciones//
      for(j=0;j<CantInscrip;j++)
      {
          if(alumnos[i].legajo==inscripcion[j].legajo)
          {
              //recorre materias//
              for(k=0;k<cantMat;k++)
              {
                  if(inscripcion[j].idMateria==materias[k].id)
                  {
                      printf("%6s\n",materias[k].descripcion);
                        break;

                  }

              }
          }
      }
      printf("\n*************************************************************-\n\n\n");

  }

}


  void mostrarMateriaConCantDeInscriptos(eMateria mat[],int cantMat,eInscripcion inscrip[],int cantIncrip)
  {
      int i;
      int j;
      int cont=0;

      //recorro las materias//
      for(i=0;i<cantMat;i++)
      {
          for(j=0;j<cantIncrip;j++)
          {
              if(mat[i].id==inscrip[j].idMateria)
              {
                  cont ++;

              }

          }

          printf("%6s :%d\n\n",mat[i].descripcion,cont);
          cont=0;
      }

  }
