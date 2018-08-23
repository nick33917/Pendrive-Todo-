using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio6
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "Ejercicio 6";
            int i;
            int año;
 
            Console.Write("Ingrese el año: ");
            if(Int32.TryParse(Console.ReadLine(),out año) == true)
            {
                if ((año % 4) == 0 || (año % 100 == 0 && año % 400 == 0))
                {
                    Console.WriteLine("El año ingresado es Bisiesto");
                }
                else
                {
                    
                     Console.WriteLine("El año ingresado NO es Bisiesto");
                    
                }
            }
            Console.ReadLine();

        }
    }
}
