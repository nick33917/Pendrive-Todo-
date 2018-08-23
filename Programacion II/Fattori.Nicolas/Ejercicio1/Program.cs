using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio1
{
    class Program
    {
        static void Main(string[] args)
        {
            float maximo = 0;
            float minimo=0;
            float suma=0;
            float promedio;
            int contador=0;
            int i;

            for (i = 0; i < 5; i++)
            {
                Console.Write("Ingrese el numero");
                float numero = float.Parse((Console.ReadLine()));
                contador++;
                suma = (numero + suma);
                if (i== 0)
                {
                    minimo = numero;
                    maximo = numero;
               

                }
                else
                {

                    if (numero >= maximo)
                    {
                        maximo = numero;
                    }
                    else
                    {
                        minimo = numero;
                    }
                }
            }

            promedio= (suma/contador) ;

            Console.Write("Valor maximo:{0:#,###.00} ,Valor Minimo:{1:#,###.00} ,Promedio:{2:#,###.00} ", maximo, minimo, promedio);
            Console.ReadLine();

        }
    }
}
