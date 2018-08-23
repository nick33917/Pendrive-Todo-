using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace clase_2
{
    class Sello
    {
        public static string mensaje;

        public static void Imprimir() //muestra por pantalla el mensaje
        {
            Console.WriteLine("{0}",Sello.mensaje);
        }

        public static void Borrar() //limpia pantalla
        {
            Console.Clear();
        }
    }

}
