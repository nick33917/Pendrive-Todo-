#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Parser.h"
#include "Estructura.h"


//Puede ser lista banca o lista negra
int parserGenerico(FILE* pFile, ArrayList* lista, char* path)
{
    int returnAux = -1;

    char auxNombre[200];
    char auxEmail[200];

    eDestinatario* destinatario;

    if(pFile != NULL && lista != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%s\n", auxNombre, auxEmail);

            //printf("NOMBRE: %s -- EMAIL: %s\n",auxNombre, auxEmail);

            destinatario = new_destinatario();

            if(destinatario != NULL)
            {
                strcpy(destinatario->nombre, auxNombre);
                strcpy(destinatario->email, auxEmail);
            }

            lista->add(lista,destinatario);
        }

        returnAux = 0;
    }

    return returnAux;
}

int listaDefinitiva(ArrayList* listaBlanca, ArrayList* listaNegra, ArrayList* listaFinal, ArrayList* listaFinalFinal)
{
    int returnAux = -1;

    eDestinatario* aux1;
    eDestinatario* aux2;

    eDestinatario* aux3;
    eDestinatario* aux4;

    int i,j,bandera = 1;

    if(listaBlanca != NULL && listaNegra != NULL && listaFinal != NULL)
    {
        for(i = 0; i<listaBlanca->size; i++)
        {
            aux1 = (eDestinatario*)listaBlanca->get(listaBlanca, i); //Agarro el elemento de la lista blanca y lo parseo

            for(j = 0; j<listaNegra->size; j++)
            {
                aux2 = (eDestinatario*)listaNegra->get(listaNegra, j); //Agarro el elemento de la lista negra y lo parseo

                bandera = 1;

                if(strcmp(aux1->email,aux2->email) == 0)
                {
                    bandera = 0; //El email est� en la lista negra.
                    break;
                }

            }
            if(bandera == 1)
            {
                listaFinal->add(listaFinal,aux1);
            }

        }
        //Segunda depuracion
        for(i = 0; i<listaFinal->size-1; i++)
        {
            for(j = i+1; j<listaFinal->size; j++)
            {
                aux3 = (eDestinatario*)listaFinal->get(listaFinal, i); //Agarro un elemento de la listaFinal
                aux4 = (eDestinatario*)listaFinal->get(listaFinal, j); //Agarro un elemento de la listaFinal

                bandera = 1;

                if(strcmp(aux3->email,aux4->email) == 0)
                {
                    bandera = 0; //El email esta repetido.
                    break;
                }

            }
            if(bandera == 0)
            {
                listaFinal->remove(listaFinal,j);
            }

        }

        returnAux = 0;
    }

    return returnAux;

}
void ordenar(ArrayList* lista)
{
    lista->sort(lista, strcmp, 1);
}
void imprimir(ArrayList* lista)
{
    eDestinatario* destinatario;

    int i;

    for(i = 0; i<lista->size ; i++)
    {
        destinatario = (eDestinatario*)lista->get(lista, i); //AGARRO EL ELEMENTO DE LA LISTA Y LO PARSEO

        printf("%s       %s\n",destinatario->nombre, destinatario->email);
    }

}
