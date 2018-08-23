using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Clase9Herencia;

namespace PruebaEjercicio
{
    class Program
    {
        static void Main(string[] args)
        {
            Lavadero lav = new Lavadero(100, 150, 50);
            Auto coche1 = new Auto(4, "htp123", 4, EMarcas.Honda);
            Auto coche2 = new Auto(3, "htp123", 3, EMarcas.Honda);
            Auto coche3 = new Auto(5, "lop789", 2, EMarcas.Ford);
            Camion cam1 = new Camion(1500, "pepe10", 10, EMarcas.Scania);
            Moto mot1 = new Moto(1200, "lok125", 2, EMarcas.Zanella);
            lav = lav + coche1;
            lav = lav + coche2;
            lav = lav + coche3;
            lav = lav + cam1;
            lav = lav + mot1;
           /* foreach(Vehiculo vec in lav.GetVehiculos)
            {
                Console.WriteLine(vec + "\n");
        
            }*/
            string s = lav.GetLavadero;
            Console.WriteLine(s + "\n");
            Console.WriteLine("-------------------------------------------\n\n\n \t\tOrdenamiento de instancia por Marca \n ------------------------------------");

            lav.GetVehiculos.Sort(lav.OrdenarVehiculosPorMarca);
            s = lav.GetLavadero;
            Console.WriteLine(s + "\n");
          /*  foreach (Vehiculo vec in lav.GetVehiculos)
            {
                //va directo al toString , y es lo mismo ve.toString()//
                Console.WriteLine(vec + "\n");

            }
            */
            Console.WriteLine("-------------------------------------------\n\n\n \t\tOrdenamiento Estatico por patente \n --------------------------------------");

            lav.GetVehiculos.Sort(Lavadero.OrdenarVehiculosPorPatente);
           /*
            foreach (Vehiculo vec in lav.GetLavadero)
            {
                Console.WriteLine(vec + "\n");
            }
            */
            s = lav.GetLavadero;
            Console.WriteLine(s + "\n");


            if (coche1.Equals(coche2))
            {
                Console.WriteLine("son iguales");
            }
            else
            {
                Console.WriteLine("son diferentes");

            }
            Console.ReadLine();
        }
    }
}
