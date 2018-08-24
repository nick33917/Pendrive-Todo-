#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"
#include "funciones.h"


ePersona* persona_new(void)
{
    ePersona* returnAux;
    returnAux = (ePersona*)malloc(sizeof(ePersona));
    if(returnAux !=NULL)
    {
       strcpy(returnAux->nombre, "");
       strcpy(returnAux->mail, "");

    }
    return returnAux;

}
int parserPersona(FILE* pFile , ArrayList* thisPersona)
{
    char auxNombre[20];
    char auxMail[51];
    ePersona* nuevaPersona;

    if(pFile == NULL || thisPersona == NULL)
    {
        return -1;
    }

   // fscanf(pFile, "%[^,],%[^,],%[^,],%s\n", auxInt, auxNombre, auxApellido, auxEmpty);

    while(!feof(pFile))
    {
        // fscanf(pFile, "%[^,],%[^,],%[^,],%s\n", auxInt, auxNombre, auxApellido, auxEmpty);

         fscanf(pFile,"%[^,],%s\n",auxNombre,auxMail);
         nuevaPersona = persona_new();
         if(nuevaPersona !=NULL)
         {
            strcpy(nuevaPersona->nombre, auxNombre);
            strcpy(nuevaPersona->mail, auxMail);

         }

           thisPersona->add(thisPersona,nuevaPersona);
           // al_add(pArrayListEmployee, nuevoEmpleado);

    }
    fclose(pFile);
    return 0;
}

int compararMail(void* mail1,void* mail2)
{
    int aux=0;
    if(strcmp(((ePersona*)mail1)->mail,((ePersona*)mail2)->mail)==0)
    {
        aux=1;
    }
    return aux;
}

void depurar(ArrayList* lista, ArrayList* listaNegra,ArrayList* depurada)
{
    int i;
    int j;
    int aux;
    int flag;
    void* mail1;
    void* mail2;
    if(lista!=NULL && listaNegra!=NULL && depurada!=NULL)
    {
        for(i=0;i<lista->size;i++)
        {
            mail1=lista->get(lista,i);

            for(j=0;j<listaNegra->size;j++)
            {
                mail2=listaNegra->get(listaNegra,j);
                aux=compararMail(mail1,mail2);
                flag=1;
                if(aux)
                {
                   flag=0;
                   break;
                }
            }

            if(flag)
            {
                depurada->add(depurada,mail1);
            }
        }
    }

}

int ordenamiento(void* pElement,void* pElement2)
{
    int aux;
    if(strcmp(((ePersona*)pElement)->nombre,((ePersona*)pElement2)->nombre) > 0)
    {
        aux=1;
    }
    else if(strcmp(((ePersona*)pElement)->nombre ,((ePersona*)pElement2)->nombre) < 0)
    {
        aux=-1;
    }
    return aux;

}


void print_Lista(ArrayList* lista)
{
    int i;
    ePersona* personas;
    for(i=0;i<lista->size;i++)
    {
        personas=(ePersona*)lista->get(lista,i);
        printf("%s   %s \n",personas->nombre,personas->mail);

    }

}

