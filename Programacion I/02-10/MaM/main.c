#include <stdio.h>
#include <stdlib.h>
#define CANTALUM 10
#define CANTMAT 5
#define CANTINSCRIP 20

typedef struct{
    int legajo;
    char nombre[20];
}eAlumno;

typedef struct{
    int id;
    char descripcion[20];
}eMateria;

typedef struct{
    int legajo;
    int idMateria;
}eInscripcion;


void mostrarAlumnoConMaterias(eAlumno [],eMateria [],eInscripcion [],int ,int ,int);
void mostrarMateriaConCantDeInscriptos(eMateria [],int,eInscripcion [],int);


int main()
{
    eAlumno Alumnos[]={{1, "Jose"}, {3, "Alberto"}, {4, "Juan"}, {7, "Luis"}, {10, "Ana"}, {9, "Silvia"}, {8, "Maria"}, {15, "Sofia"}, {18, "Martin"}, {11, "Dalia"}};
    eMateria Materias[]={{1, "Progamacion"}, {2, "Matematicas"},{3, "Quimica"}, {4, "Fisica"}, {5, "Electronica"}};
    eInscripcion Inscripciones[]={{1,2}, {1,3}, {3,2}, {4,4}, {3,5}, {3,1}, {4,1}, {1,1}, {8,1}, {9,3}, {10,2}, {10,5}, {10, 3}, {8, 1}, {1,2}};

    mostrarAlumnoConMaterias(Alumnos,Materias,Inscripciones,CANTALUM,CANTMAT,CANTINSCRIP);
    printf("\n\n--------------------\n\n");
    mostrarMateriaConCantDeInscriptos(Materias,CANTMAT,Inscripciones,CANTINSCRIP);



    return 0;
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





