using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades_Clase7
{
    public class Jugador
    {
        private long dni;
        private string nombre;
        private int partidosJugados;
        private float promedioGoles;
        private int totalGoles;

        public float GetPromedioGoles()
        {
            
            float rtn= this.totalGoles / this.partidosJugados;
            this.promedioGoles = rtn;
            return this.promedioGoles;
        }
         

        public Jugador(string nombre, int totalGoles, int totalPartidos,long dni) :this(nombre,dni) 
        {
            this.totalGoles = totalGoles;
            this.partidosJugados = totalPartidos;
            this.promedioGoles = GetPromedioGoles();
            
        }

        private Jugador()
        {
            this.nombre = "Sin nombre";
            this.dni = 1;
            this.partidosJugados = 0;
            this.promedioGoles = 0;
            this.totalGoles = 0;

        }

        public Jugador(string nombre,long dni) : this()
        {
            this.nombre = nombre;
            this.dni = dni;

        }

        public string Nombre
        {
            get { return this.nombre; }
            set { this.nombre = value; }
        }

        public long Dni
        {
            get { return this.dni; }
           
        }

        public int PartidosJugador
        {
            get { return this.partidosJugados; }
            set { this.partidosJugados = value; }
        }

        public int TotalGoles
        {
            get { return this.totalGoles; }
            set { this.totalGoles = value; }
        }

        public string MostrarDatos()
        {
            return this.dni + "-" + this.nombre + "-" + this.partidosJugados+ "-" + this.promedioGoles + "-" + this.totalGoles + "\n";

        }

        public static bool operator ==(Jugador j1, Jugador j2)
        {
            bool flag = false;
            if (j1.dni == j2.dni)
            {
                flag = true;

            }
            return flag;
                
        }

        public static bool operator !=(Jugador j1, Jugador j2)
        {
            return !(j1 == j2);
        }


    }
}
