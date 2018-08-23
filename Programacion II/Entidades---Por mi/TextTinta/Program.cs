using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Entidades;

namespace TextTinta
{
    class Program
    {
        static void Main(string[] args)
        {
            //compruebo la sobrecarga de constructores y la muestro//
            Tinta obj1= new Tinta();
            Tinta obj2 = new Tinta(ETipoTinta.conBrillito);
            Tinta obj3 = new Tinta(ConsoleColor.Blue, ETipoTinta.china);

            string mostrar1 = Tinta.Mostrar(obj1);
            string mostrar2 = Tinta.Mostrar(obj2);
            string mostrar3 = Tinta.Mostrar(obj3);

            Console.WriteLine("***Por defecto***\n{0} \n\n ***Con 1 parametro***\n{1} \n\n ***Con 2 parametros***\n{2} \n\n", mostrar1, mostrar2, mostrar3);

            // compruebo la sobrecarga de operadores de comparacion y muestro el resueltado//
            if (obj1 == obj2)
            {
                Console.WriteLine("-----Son el mismo tipo de tinta-----");
            }
            else
            {
                Console.WriteLine("-----Son distinto tipo de tinta-----");

            }
            
            
            
            Console.ReadLine();
               
        }
    }
}
