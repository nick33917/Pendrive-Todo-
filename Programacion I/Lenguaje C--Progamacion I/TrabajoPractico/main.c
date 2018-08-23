#include <stdio.h>
#include <stdlib.h>

int suma(int num1,int num2);
int resta(int num1,int num2);
float divisionConValidacion(int num1,int num2);
int multiplicacion(int num1,int num2);
int main()
{
    int numero1;
    int numero2;
    int resSuma;
    int resResta;
    float resDivision;
    int resMultiplicacion;
    char seguir='s';
    int opcion=0;


    while(seguir=='s')
    {

        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        scanf("%d",&opcion);


        switch(opcion)
        {
            case 1:
                printf("Ingresar el 1er operando: ");
                scanf("%d",&numero1);
                break;
            case 2:
                printf("Ingresar el 2edo operando: ");
                scanf("%d",&numero2);
                break;
            case 3:
                resSuma=suma(numero1,numero2);
                printf("El resultado de la suma es: %d",&resSuma);
                break;
            case 4:
                resResta=resta(numero1,numero2);
                printf("El resultado de la resta es: %d",&resResta);
                break;
            case 5:
                resDivision=divisionConValidacion(numero1,numero2);
                printf("El resultado de la division es: %f",resDivision);
                break;
            case 6:
                resMultiplicacion=multiplicacion(numero1,numero2);
                printf("El resultado de la multiplicacion es: %d",&resMultiplicacion);
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                seguir = 'n';
                break;
        }



    }
    return 0;

}
int suma(int num1,int num2)
{
    int resultado;
    resultado=num1 + num2;
    return resultado;

}
int resta(int num1,int num2)
{
    int resultado;
    resultado=num1 - num2;
    return resultado;
}
float divisionConValidacion(int num1,int num2)
{
    float resultado;
    while(num2==0)
    {
        printf("No se puede dividir por 0 !!!Ingrese otro numero diferente a 0: ");
        scanf("%d",&num2);
    }
    resultado=(float)num1/num2 ;
    return resultado;
}
int multiplicacion(int num1,int num2)
{
    int resultado;
    resultado=num1 * num2;
    return resultado;
}
