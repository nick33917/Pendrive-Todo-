using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Entidades.Alumnos;
using Entidades.Externa;
using Entidades.Externa.Sellada;
namespace clase19_06
{
   
    class Program
    {
        static void Main(string[] args)
        {
            //Persona per = new Persona("nicolas", "fattori", 23,Entidades.Externa.ESexo.Masculino);
            //Console.WriteLine(per.ObtenerInfo());
            bool flag;
            PersonaExternaSellada perSellada = new PersonaExternaSellada("jose", "argento", 55, Entidades.Externa.Sellada.ESexo.Indefinido);


            //flag = perSellada.EscribirEnArchivo("PersonaExternaSellada.txt");
            //if (flag)
            //{
            //    Console.WriteLine("Se agrego correctamente");
            //}
            //else
            //{
            //    Console.WriteLine("no se guardo");

            //}

            //muestra los datos de la persona sellada
            //Console.WriteLine(perSellada.ObtenerInfoDll());


            //perSellada = null;
            //if (perSellada == null)
            //{
            //    Console.WriteLine("es Nulo");
            //}


            //string cadena = "Hola";
            //int cant = cadena.CantidadCaracteres();
            //Console.WriteLine(cant.ToString());
            
            //flag =perSellada.AgregarEnBaseDeDatos();
            //if (flag)
            //{
            //    Console.WriteLine("se agrego bien");
            //}

            List<PersonaExternaSellada> lista = new List<PersonaExternaSellada>();
            lista = perSellada.TraerTodos();
            foreach (PersonaExternaSellada p in lista)
            {
                Console.WriteLine(p.ObtenerInfoDll());
            }
            
            Console.ReadLine();

        }
    }
}
