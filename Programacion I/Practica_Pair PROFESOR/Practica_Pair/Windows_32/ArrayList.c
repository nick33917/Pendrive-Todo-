#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"

ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux=NULL;
    void** auxpElements;
    this = (ArrayList*)malloc(sizeof(ArrayList));
    if(this !=NULL)
    {
        auxpElements=(void**)malloc(sizeof(void*)*INITIAL_VALUE);
    }
    if(auxpElements !=NULL)
    {
        this->size=0;
        this->pElements=auxpElements;
        this->reservedSize=INITIAL_VALUE;
        this->add=al_add;
        this->len=al_len;
        this->set=al_set;
        this->remove=al_remove;
        this->clear=al_clear;
        this->clone=al_clone;
        this->get=al_get;
        this->contains=al_contains;
        this->push=al_push;
        this->indexOf=al_indexOf;
        this->isEmpty=al_isEmpty;
        this->pop=al_pop;
        this->subList=al_subList;
        this->containsAll=al_contains;
        this->deleteArrayList=al_deleteArrayList;
        this->sort=al_sort;

        returnAux=this;
    }
    else
    {
        free(this);
    }
    return returnAux;

}

//*---------------------------------------------------------------------------------*//

int al_add(ArrayList* this,void* pElement)
{
    int returnAux=-1;

    if(this !=NULL && pElement !=NULL)
    {
        if(!(resizeUp(this)))
        {
            this->pElements[this->size]=pElement;
            this->size++;
            returnAux = 0;

        }

    }

    return returnAux;

}

//*----------------------------------------------------------------------------*//

int resizeUp(ArrayList* pList)
{
    int returnAux=-1;
    void** aux;
    if(pList !=NULL )
    {
        if(pList->size == pList->reservedSize)
        {
            aux=(void**)realloc(pList->pElements,sizeof(void*)*(pList->reservedSize+INCREMENT));
            if(aux!=NULL)
            {
                pList->pElements=aux;
                pList->reservedSize = pList ->reservedSize + INCREMENT;
            }
        }
        returnAux=0;
    }
    return returnAux;
}

//*----------------------------------------------------------------------------*//

int resizeDown(ArrayList* this)
{
    int returnAux=-1;
    if(this!=NULL )
    {
        if((this->reservedSize - this->size) >INCREMENT)
        {
            this->pElements=(void*)realloc(this->pElements,sizeof(void)*(this->reservedSize-INCREMENT));
            this->reservedSize = this->reservedSize - INCREMENT;
        }
        returnAux=0;
    }
    return returnAux;
}

//*-------------------------------------------------------------------------------*//

int contract(ArrayList* this,int index)
{
    int returnAux=-1;
    int i;
    if(this!=NULL)
    {
        for(i=index;i<this->size;i++)
        {
           this->pElements[i]= this->pElements[i+1];

        }
        this->size--;
        returnAux=0;

    }
    return returnAux;

}

//*------------------------------------------------------------------------*//
int expand(ArrayList* this,int index)
{
    int returnAux=-1;
    int i;
    if(this!=NULL)
    {

        if(!resizeUp(this))
        {
            for(i=this->size;i>index;i--)
            {
                this->pElements[i]=this->pElements[i-1];
            }
            returnAux=0;
        }
        this->size ++;
    }
    return returnAux;
}

//*--------------------------------------------------------------------------*//




