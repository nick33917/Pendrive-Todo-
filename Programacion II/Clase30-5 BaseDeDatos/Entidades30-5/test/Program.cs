using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Entidades30_5;
using System.Data;
namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
          //  Persona pers = new Persona(5,"Nicolas", "Fattori", 23);

            //bool flag = pers.agregar();
            //if (flag)
            //{
            //    Console.WriteLine("Se agrego correctamente\n");
            //}
            //else
            //{
            //    Console.WriteLine("No se agrego\n");

            //}

            //foreach (Persona per in Persona.TraerTodos())
            //{
            //    Console.WriteLine(per.ToString());
            //}

            //if (Persona.Borrar(pers))
            //{
            //    Console.WriteLine("Se borro\n");
            //}
            //else
            //{
            //    Console.WriteLine("No se borro\n");
            //}

            //if (pers.Modificar())
            //{
            //    Console.WriteLine("Se Modifico\n");
            //}

            //else
            //{
            //    Console.WriteLine("No se Modifico\n");

            //}
            //Persona pers = new Persona(0,"","",0);
            //pers =  Persona.TraerTodos(3);


            Persona.TraerTodosTabla();
            foreach (DataRow row in Persona.TraerTodosTabla().Rows)
            {
                //muestro el nombre de toda mi base de datos es decir mi 2da columna//
                Console.WriteLine(row[1].ToString());
            }
             Console.ReadLine();



        }
    }
}
