using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Autor
    {
        private string _apellido;
        private string _nombre;

        public Autor(string nombre,string apellido)
        {
            this._nombre = nombre;
            this._apellido = apellido;
        }

        public static bool operator ==(Autor a, Autor b)
        {
            bool rtn = false;
            if ((a._apellido == b._apellido) && (a._nombre == b._nombre))
            {
                rtn = true;
            }
            return rtn;

        }

        public static bool operator !=(Autor a, Autor b)
        {
            return !(a==b);

        }

        public static implicit operator string(Autor a)
        {
            return "Nombre: " + a._nombre + "\nApellido: " + a._apellido;
        }

    }
}
