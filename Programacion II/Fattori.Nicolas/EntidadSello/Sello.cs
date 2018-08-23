using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EntidadSello
{
    public class Sello
    {
        public static string mensaje;

        public static ConsoleColor color;

        public static void Imprimir() //muestra por pantalla el mensaje
        {
            string mensajeListo;
         //   mensaje = Sello.ArmarFormatoMensaje();
            if (Sello.TryParse(mensaje, out mensajeListo) == true)
            {
                Console.ForegroundColor = Sello.color;
                Console.WriteLine("{0}", mensajeListo);


            }
            else
            {
                Console.WriteLine("No pudo imprimirse");
            }
           // Console.WriteLine("{0}", Sello.mensaje);
            Console.ForegroundColor = ConsoleColor.Gray;
  
        }

        public static void Borrar() //limpia pantalla
        {
            Console.Clear();
        }

        private static string ArmarFormatoMensaje()
        {
            string cad="" ;
            int i;
            int letras = Sello.mensaje.Length;

            for (i = 0; i < (letras + 2); i++)
            {
                cad += "*";
            }

            cad += "\n*";
            cad += mensaje;
            cad += "*\n";

            for (i = 0; i < (letras + 2); i++)
            {
                cad += "*";
            }

            return cad;
        }

        public static bool TryParse(string mensaje, out string salida)
        {
            bool estaOk=false;
            if (mensaje != "")
            {
                estaOk = true;
                salida = Sello.ArmarFormatoMensaje();

            }
            else
            {
                salida = "";
            }
            return estaOk;
        }
    }
}
