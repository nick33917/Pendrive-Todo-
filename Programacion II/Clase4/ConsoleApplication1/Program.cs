using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using ClassLibrary1;
namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            //constructor por default
            Console.WriteLine("Por defecto");
            Cosa valores = new Cosa();
            Console.WriteLine("{0} ",valores.Mostrar());

            Console.WriteLine("\n");

            DateTime fecha = new DateTime(1995, 03, 03);
            Console.WriteLine("Valores predeterminados por el usuario");
            Cosa valores1 = new Cosa(5,"Locura",fecha);
            Console.WriteLine("{0} ", valores1.Mostrar());

            Console.WriteLine("\n");

            valores.EstablecerValor(3);
            valores.EstablecerValor("Nicolas");
            valores.EstablecerValor(DateTime.Now);

            Console.WriteLine("{0}", valores.Mostrar());
            Console.ReadLine();

            
        }
    }
}
