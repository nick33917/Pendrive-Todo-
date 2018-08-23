#include <stdio.h>
#include <stdlib.h>
int pedirNumero();
int suma(int n1,int n2);
int resta(int n1,int n2);
float division(float n1,float n2);
int multiplicacion(int num1,int num2);
int main()
{
    int num1;
    int num2;
    float rta;


    num1=pedirNumero();
    num2=pedirNumero();

    rta=suma(num1,num2);
    printf("la suma es: %.0f\n",rta);

    rta=resta(num1,num2);
    printf("La resta es: %.0f\n",rta);

    rta=division(num1,num2);
    printf("La divison es: %.3f\n",rta);

    rta=multiplicacion(num1,num2);
    printf("La multiplicacion es: %.0f",rta);


    return 0;
}
int pedirNumero()
{
    int num;
    printf("Ingrese un numero: ");
    scanf("%d",&num);
    return num;
}
int suma(int n1,int n2)
{
    int resp;
    resp=n1 + n2 ;
    return resp;
}
int resta(int n1,int n2)
{
    int resp;
    resp=n1-n2;
    return resp;
}
float division(float n1,float n2)
{
    float resp;
    resp=n1/n2;
    return resp;
}
int multiplicacion(int num1,int num2)
{
    int resp;
    resp=num1*num2;
    return resp;
}

