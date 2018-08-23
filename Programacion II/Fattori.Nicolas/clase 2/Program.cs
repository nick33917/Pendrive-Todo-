using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace clase_2
{
    class Program
    {
        static void Main(string[] args)
        {
            // usando classLibrary //
            EntidadSello.Sello.mensaje = "Hola perro"; // nameSpace.clase
            EntidadSello.Sello.color = ConsoleColor.Yellow; // cambia color de la letra
            EntidadSello.Sello.Imprimir();
            Console.WriteLine("Presione una tecla para salir");
            Console.ReadLine();
            EntidadSello.Sello.Borrar();


       /*   c
            Sello.mensaje = "Hola mundo";
            Sello.Imprimir();
            Console.ReadLine();
            Sello.Borrar();
         */
        }
    }
}
