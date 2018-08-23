using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio3
{
    class Program
    {
        static void Main(string[] args)
        {
            int j;
            
            Console.WriteLine("Ingrese un numero: ");
            int numero = Int32.Parse(Console.ReadLine());
            for(int i=2; i<numero ;i++)
            {
                int contador = 0;

                for (j=1; j<numero; j++)
                {
                    if (i % j == 0)
                    {
                        contador++;

                    }

                }

                if (contador == 2)
                {
                    Console.WriteLine("{0}", i);

                }

            }
            Console.ReadLine();



        }
    }
}
