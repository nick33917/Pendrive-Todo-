using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Entidades_Clase7;
namespace Prueba
{
    class Program
    {
        static void Main(string[] args)
        {
            bool validar;
            Equipo banfield = new Equipo(4, "Banfield");
            Jugador j1 = new Jugador("nicolas", 10, 10, 38839471);
            Jugador j2 = new Jugador("lucas", 9, 9, 38839471);
            Jugador j3 = new Jugador("peditro", 8, 6, 15987462);
            List<Jugador> lista = banfield.GetJugadores();

            validar = banfield + j1;

            if (validar)
            {
                foreach (Jugador buffer in lista)
                {
                    Console.WriteLine(buffer.MostrarDatos());

                }

            }

           

            Console.ReadLine();
        }
    }
}
