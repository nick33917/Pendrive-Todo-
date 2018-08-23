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
            Auto coche2 = new Auto(3, "yop125", 3, EMarcas.Iveco);
            Auto coche3 = new Auto(5, "lop789", 2, EMarcas.Ford);
            lav = lav + coche1;
            lav = lav + coche2;
            lav = lav + coche3;
            foreach(Vehiculo vec in lav.GetVehiculos)
            {
                if (vec is Auto)
                {
                    Console.WriteLine("{0}\n",((Auto)vec).MostrarAuto());
                }
                else if (vec is Moto)
                {
                    Console.WriteLine("{0}\n", ((Moto)vec).MostrarMoto());

                }
                else if (vec is Camion)
                {
                    Console.WriteLine("{0}\n", ((Camion)vec).MostarCamion());
                }
                
            }
            Console.WriteLine("-------------------------------------------\n\n\n \t\tOrdenamiento de instancia por Marca \n -----------------------------");

            lav.GetVehiculos.Sort(lav.OrdenarVehiculosPorMarca);
            foreach (Vehiculo vec in lav.GetVehiculos)
            {
                if (vec is Auto)
                {
                    Console.WriteLine("{0}\n", ((Auto)vec).MostrarAuto());
                }
                else if (vec is Moto)
                {
                    Console.WriteLine("{0}\n", ((Moto)vec).MostrarMoto());

                }
                else if (vec is Camion)
                {
                    Console.WriteLine("{0}\n", ((Camion)vec).MostarCamion());
                }

            }

            Console.WriteLine("-------------------------------------------\n\n\n \t\tOrdenamiento Estatico por patente \n -----------------------------");

            lav.GetVehiculos.Sort(Lavadero.OrdenarVehiculosPorPatente);
            foreach (Vehiculo vec in lav.GetVehiculos)
            {
                if (vec is Auto)
                {
                    Console.WriteLine("{0}\n", ((Auto)vec).MostrarAuto());
                }
                else if (vec is Moto)
                {
                    Console.WriteLine("{0}\n", ((Moto)vec).MostrarMoto());

                }
                else if (vec is Camion)
                {
                    Console.WriteLine("{0}\n", ((Camion)vec).MostarCamion());
                }

            }
            
            Console.ReadLine();
        }
    }
}
