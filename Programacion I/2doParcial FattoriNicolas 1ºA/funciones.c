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
int parserPersona(FILE* pFile, ArrayList* thisPersona)
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
            set_name(nuevaPersona,auxNombre);
            set_mail(nuevaPersona,auxMail);

        }

        thisPersona->add(thisPersona,nuevaPersona);
        // al_add(pArrayListEmployee, nuevoEmpleado);

    }
    fclose(pFile);
    return 0;
}



int parserBlackList(FILE* black_list,ArrayList* listaNegra,ArrayList* lista)
{
    int returnAux=-1;
    char auxNombre[20];
    char auxMail[51];
    int i;
    int index;
    int flag=1;
    ePersona* aux;
    ePersona* nuevaPersona;
    if(lista == NULL || listaNegra == NULL || black_list==NULL)
    {
        return returnAux;
    }
    while(!feof(black_list))
    {

        fscanf(black_list,"%[^,],%s\n",auxNombre,auxMail);
        /*
        nuevaPersona = persona_new();
        if(nuevaPersona !=NULL)
        {
            set_name(nuevaPersona,auxNombre);
            set_mail(nuevaPersona,auxMail);

        }*/
        for(i=0;i<lista->len(lista);i++)
        {
            aux = get_mail(lista,i);
            if((strcmp(aux->mail,auxMail)) == 0)
            {
                flag=0;
                index=i;
                break;
            }
        }

        if(!flag)
        {
             listaNegra->add(listaNegra,lista->get(lista,index));

        }
        else
        {
            nuevaPersona = persona_new();
            if(nuevaPersona !=NULL)
            {
                set_name(nuevaPersona,auxNombre);
                set_mail(nuevaPersona,auxMail);

            }
            listaNegra->add(listaNegra,nuevaPersona);

         }

    }
    return returnAux;

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

int depurar(ArrayList* lista, ArrayList* listaNegra,ArrayList* depurada)
{
    int returnAux=-1;
    int i;
    int j;
    void* aux;
    void* aux2;
    int flag;

    if(lista!=NULL && listaNegra!=NULL && depurada!=NULL)
    {
        for (i=0; i<lista->len(lista); i++)
        {
            flag = listaNegra->contains(listaNegra,lista->get(lista, i));
            if (!flag)
            {
                depurada->add(depurada,lista->get(lista, i));

            }
        }

        for(i=0;i<depurada->len(depurada)-1;i++)
        {
            aux =  depurada->get(depurada,i);
            for(j=i+1;j<depurada->len(depurada);j++)
            {
                aux2 = depurada->get(depurada,j);
                if(aux == aux2)
                {
                    depurada->remove(depurada,i);
                }
            }

        }
        returnAux=1;
    }

    return returnAux;
}
/*
        for(i=0; i<lista->len(lista)-1; i++)
        {
            mail1=lista->get(lista,i);

            for(j=0; j<listaNegra->len(listaNegra); j++)
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




        for(i=0; i<depurada->len(depurada)-1; i++)
        {
            mail3=depurada->get(depurada,i);
            for(j=i+1; j<depurada->len(depurada); j++)
            {
                mail4=depurada->get(depurada,j);
                aux2= compararMail(mail3,mail4);
                if(aux2)
                {
                    depurada->remove(depurada,i);
                }

            }
        }

        returnAux=1;
    }

    return returnAux;
    */





void mostrarLista(ArrayList* lista)
{
    int i;
    ePersona* personas;
    printf("NOMBRE ------ MAIL\n\n");
    for(i=0; i<lista->len(lista); i++)
    {
        personas=(ePersona*)lista->get(lista,i);
        printf("%s   %s \n",personas->nombre,personas->mail);
    }
    printf("\n\n");

}

void set_name(ePersona* persona, char* nombre)
{
    strcpy(persona->nombre,nombre);
}

void set_mail(ePersona* persona, char* mail)
{
    strcpy(persona->mail,mail);
}

ePersona* get_name(ePersona* persona,int index)
{
    ePersona* aux;
    if(persona!=NULL)
    {
        aux = persona->nombre[index];

    }
    return aux;

}

ePersona* get_mail(ArrayList* this,int index)
{
    ePersona* aux;
    if(this!=NULL)
    {
        aux =((ePersona*)this->get(this,index));

    }
    return aux;

}
