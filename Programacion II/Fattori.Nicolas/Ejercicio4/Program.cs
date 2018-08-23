using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio4
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title="Ejercicio  4";
            int i;
            int j;
            int suma;
            int contador=0;

            for (i = 10000; i>1; i--)
            {
                suma = 0;
                for (j =1; j<i; j++)
                {
                    if (i % j == 0 && j!=i)
                    {
                        suma = suma + j;
                        
                     }

                }

                if(suma==i)
                {
                    Console.WriteLine("{0}", i);
                    contador++;
                    if (contador == 4)
                    {
                        break;
                    }
                    
                }
            }
            Console.ReadLine();
        }
    }
}
