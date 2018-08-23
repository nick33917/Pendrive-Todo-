using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Entidades;
namespace Test
{
    class Program
    {
        static void Main(string[] args)
        {
            Numero n1 = new Numero(5);
            string cadena= "52";
            bool flag = Numero.Parse(cadena,out n1);

            if (flag)
            {
                Console.WriteLine("Perfecto");

            }
            else
            {
                Console.WriteLine("MAL");

            }
            Console.ReadLine();
           
            
        }
    }
}
