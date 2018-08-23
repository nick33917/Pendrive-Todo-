using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Novela : Libro
    {
        public EGenero genero;
        public Novela(string titulo, float precio, Autor autor, EGenero genero)
            : base(titulo, autor, precio)
        {
            this.genero = genero;
        }

        public static implicit operator double(Novela n)
        {
            return n._precio;

        }

        public static bool operator ==(Novela a, Novela b)
        {
            bool rtn = false;
            if (((Libro)a == (Libro)b ) && (a.genero == b.genero))
            {
                rtn = true;
            }
            return rtn;

        }
        public static bool operator !=(Novela a, Novela b)
        {
            return !(a == b);

        }

        public string Mostrar()
        {
            return (string)this + "\nGenero: " + this.genero + "\n";
        }


       
    }
}
