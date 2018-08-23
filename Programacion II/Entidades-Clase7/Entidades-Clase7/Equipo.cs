using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades_Clase7
{
    public class Equipo
    {
        private short cantidadDeJugadores;
        private List<Jugador> jugadores;
        private string nombre;

        public Equipo(short cantidad, string nombre) :this()
        {
            this.cantidadDeJugadores = cantidad;
            this.nombre = nombre;
        }
        private Equipo()
        {
            this.jugadores = new List<Jugador>();
            this.cantidadDeJugadores = 5;
        }

        public static bool operator +(Equipo e,Jugador j)
        {
            bool rtn=false;
            bool validar=false;
            foreach (Jugador jug in e.jugadores)
            {
                validar = (jug == j);
                if (validar)
                {
                    break;
                }

            }

            if (validar == false)
            {
                if (e.cantidadDeJugadores > e.jugadores.Count)
                {
                    e.jugadores.Add(j);
                    rtn = true;

                }
            }

            return rtn;
        }

        public List<Jugador> GetJugadores()
        {
            return this.jugadores;
        }
    }
}
