#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    int comp=-2;
    if(pEmployeeA !=NULL && pEmployeeB !=NULL)
    {
        Employee* empA=(Employee*)pEmployeeA;
        Employee* empB=(Employee*)pEmployeeB;
        comp = strcmp(empA->name,empB->name);

    }
    return comp;

}


void employee_print(Employee* this)
{
    if(this != NULL){
        printf("%d %s %s \n", this->id, this->name, this->lastName);
    }
}


Employee* employee_new(void)
{
    Employee* returnAux;
    returnAux = (Employee*)malloc(sizeof(Employee));
    if(returnAux !=NULL){
       returnAux->id = 0;
       strcpy(returnAux->name, "");
       strcpy(returnAux->lastName, "");
       returnAux->isEmpty = 1;
    }
    return returnAux;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{
    int flag =-1;
    if(this != NULL)
    {
        if(id>0 || id<10000)
        {
            this->id=id;
            flag=0;

        }

    }

    return flag;

}

int employee_getId(Employee* this)
{
    int id=-1;
    if(this !=NULL)
    {
        id = this->id;
    }

    return id;

}


