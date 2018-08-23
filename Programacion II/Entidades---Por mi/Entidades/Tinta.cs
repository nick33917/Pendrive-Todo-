using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Tinta
    {
        ConsoleColor color;
        ETipoTinta tipoTinta;
       
        public Tinta(ConsoleColor color, ETipoTinta tipoTinta)
        {
            this.color = color;
            this.tipoTinta = tipoTinta;
        }

        public Tinta() :this(ConsoleColor.Black, ETipoTinta.comun)
        {

        }

        public Tinta(ETipoTinta tipoTinta) :this ()
        {
            this.tipoTinta = tipoTinta;

        }

        private string Mostrar()
        {
            return "El color es: " + this.color + "\nEl tipo de tinta es: " + this.tipoTinta; 
        }

        public static string Mostrar(Tinta tipo)
        {
            string s = tipo.Mostrar();
            return s;

        }

        public static bool operator ==(Tinta tinta1, Tinta tinta2)
        {
            bool rtn=false;
            if (tinta1.color == tinta2.color && tinta1.tipoTinta == tinta2.tipoTinta)
            {
                rtn = true;
            }
            return rtn;

        }

        public static bool operator !=(Tinta tinta1, Tinta tinta2)
        {
            return !(tinta1 == tinta2);

        }
    }

    
}
