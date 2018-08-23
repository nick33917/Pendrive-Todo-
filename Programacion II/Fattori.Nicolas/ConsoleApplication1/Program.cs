using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            float numero;
            float cuadrado;
            float cubo;

            Console.WriteLine("Ingrese un numero: ");
            float aux = float.Parse(Console.ReadLine());
            while (aux < 0)
            {
                Console.WriteLine("Reingrese el numero: ");
                aux = float.Parse(Console.ReadLine());
            }

            numero = aux;

            cuadrado = (float)Math.Pow(numero,2);
            cubo = (float)Math.Pow(numero,3);

            Console.WriteLine("Cuadrado:{0:#,###.00} , cubo:{1:#,###.00} ", cuadrado, cubo);
            Console.ReadLine();

        }
    }
}
