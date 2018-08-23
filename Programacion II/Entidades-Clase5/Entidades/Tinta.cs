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

        public Tinta(ConsoleColor color,ETipoTinta tipo)
        {
            this.color = color;
            this.tipoTinta = tipo;
        }

        public Tinta(): this(ConsoleColor.Black, ETipoTinta.comun)
        {
        }

        public Tinta(ETipoTinta tipo): this()
        {
            this.tipoTinta = tipo;
        }


        private string Mostrar()
        {
             return "tipo de color:" + this.color + "-" +"tipo de tinta:"+ this.tipoTinta;
            
        }

        public static string Mostrar(Tinta tipo)
        {

            return tipo.Mostrar();
        }

        public static bool operator ==(Tinta tinta1, Tinta tinta2)
        {
            bool rtn=false;

            if (tinta1.color == tinta2.color && tinta1.tipoTinta == tinta2.tipoTinta)
            {
                rtn = true;
            }
            return rtn;
          // return tinta1.color == tinta2.color && tinta1.tipoTinta == tinta2.tipoTinta;       
        }

        public static bool operator !=(Tinta tinta1, Tinta tinta2)
        {
            return !(tinta1 == tinta2);
            
        }



    }
}
