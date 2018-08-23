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
            Tinta objTinta1 = new Tinta();
            Tinta objTinta2 = new Tinta(ETipoTinta.conBrillito);
            Tinta objTinta3 = new Tinta(ConsoleColor.Blue,ETipoTinta.china);
            
            string obj1 = Tinta.Mostrar(objTinta1);
            string obj2 = Tinta.Mostrar(objTinta2);
            string obj3 = Tinta.Mostrar(objTinta3);
            Console.Write("Sin parametros :\n{0}\nCon un parametro:\n{1}\nCon dos parametros:\n{2}",obj1,obj2,obj3);
            

            if (objTinta1 == objTinta2)
            {
                Console.WriteLine("\n\nnSon iguales !!!");

            }
            else
            {
                Console.WriteLine("\n\nSon Distintos !!!");
            }
            Console.ReadLine();

            Pluma objPluma = new Pluma("Faber Castell",objTinta1,10);
            string mostrarPluma = objPluma;
            Console.WriteLine("{0}",mostrarPluma);
            Console.ReadLine();
            //-----------------------------------agrego 1 a la tinta//
            //objpluma = objpluma+ objtinta;
            objPluma += objTinta1;
            string mostrarPluma2 = objPluma;
            Console.WriteLine("{0}", mostrarPluma2);
            Console.ReadLine();

        }
    }
}
