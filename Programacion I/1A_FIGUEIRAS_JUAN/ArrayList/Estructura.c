#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Estructura.h"

eDestinatario* new_destinatario()
{
    eDestinatario* returnAux;

    returnAux = (eDestinatario*)malloc(sizeof(eDestinatario));

    if(returnAux != NULL)
    {
        strcpy(returnAux->nombre, "");
        strcpy(returnAux->email, "");
    }

    return returnAux;
}

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

            int r1,r2;

            r1 = destinatario_setNombre(destinatario,auxNombre);
            r2 = destinatario_setEmail(destinatario,auxEmail);

            //strcpy(destinatario->nombre, auxNombre);
            //strcpy(destinatario->email, auxEmail);

            if(destinatario != NULL && r1 == 0 && r2 == 0)
            {
                lista->add(lista,destinatario);
            }

        }

        returnAux = 0;
    }

    return returnAux;
}
int listaDefinitiva(ArrayList* listaBlanca, ArrayList* listaNegra, ArrayList* listaFinal)
{
    int returnAux = -1;

    eDestinatario* aux1;
    eDestinatario* aux2;

    int i,j,bandera = 1;

    if(listaBlanca != NULL && listaNegra != NULL && listaFinal != NULL)
    {
        for(i = 0; i<listaBlanca->size; i++)
        {
            aux1 = (eDestinatario*)listaBlanca->get(listaBlanca, i);

            for(j = 0; j<listaNegra->size; j++)
            {
                aux2 = (eDestinatario*)listaNegra->get(listaNegra, j);

                bandera = 1;

                if(strcmp(aux1->email,aux2->email) == 0)
                {
                    bandera = 0; //El email está en la lista negra.
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
                aux1 = (eDestinatario*)listaFinal->get(listaFinal, i);
                aux2 = (eDestinatario*)listaFinal->get(listaFinal, j);

                bandera = 1;

                if(strcmp(aux1->email,aux2->email) == 0)
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
        destinatario = (eDestinatario*)lista->get(lista, i);

        printf("%s       %s\n",destinatario->nombre, destinatario->email);
    }

}

int destinatario_setNombre(eDestinatario* destinatario, char* nombre)
{
    if(destinatario != NULL)
    {
        strcpy(destinatario->nombre,nombre);
        return 0;
    }
    return -1;

}

char* destinatario_getNombre(eDestinatario* destinatario)
{
    char* nombre = NULL;

    if(destinatario != NULL)
    {
        strcpy(nombre,destinatario->nombre);
    }

    return nombre;

}

int destinatario_setEmail(eDestinatario* destinatario, char* email)
{
    if(destinatario != NULL)
    {
        strcpy(destinatario->email,email);
        return 0;
    }
    return -1;

}

char* destinatario_getEmail(eDestinatario* destinatario)
{
    char* email = NULL;

    if(destinatario != NULL)
    {
        strcpy(email,destinatario->email);
    }

    return email;

}
