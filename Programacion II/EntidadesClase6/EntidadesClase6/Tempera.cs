using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EntidadesClase6
{
    public class Tempera
    {
        private ConsoleColor color;
        private string marca;
        private int cantidad;

        public Tempera(ConsoleColor color, string marca, int cantidad)
        {
            this.color = color;
            this.marca = marca;
            this.cantidad = cantidad;
        }

        private string Mostrar()
        {
            return this.color + " - " + this.marca + " - " + this.cantidad ;
        }

        public static string Mostrar(Tempera objTempera)
        {
            string s = objTempera.Mostrar();
            return s;
        }

        public static bool operator ==(Tempera objTempera1, Tempera objTempera2)
        {
            bool rtn = false;
            if (objTempera1.color == objTempera2.color && objTempera1.marca == objTempera2.marca)
            {
                rtn = true;
            }
            return rtn;
        }

        public static bool operator !=(Tempera objTempera1, Tempera objTempera2)
        {
            return !(objTempera1 == objTempera2);
        }

        public static implicit operator int(Tempera objTempera)
        {
            return objTempera.cantidad;
        }

        public static explicit operator string(Tempera objTempera)
        {
            return objTempera.Mostrar();

        }

        public static Tempera operator +(Tempera objTempera, int cant)
        {
            objTempera.cantidad +=cant;
            return objTempera;
        }

        public static Tempera operator +(Tempera objTempera1, Tempera objTempera2)
        {

            if (objTempera1 == objTempera2)
            {
                 objTempera1 += objTempera2.cantidad;
            }
            return objTempera1;
        }


    }
}
