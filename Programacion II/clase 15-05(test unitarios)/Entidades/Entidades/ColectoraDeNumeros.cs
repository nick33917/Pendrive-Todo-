using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class ColectoraDeNumeros
    {
        protected List<Numero> _numeros;

        public ETipoNumero  Tipo { get; set; }

        private ColectoraDeNumeros()
        {
            this._numeros = new List<Numero>();
        }
        public ColectoraDeNumeros(ETipoNumero tipo) 
            : this()
        {
            this.Tipo = tipo;
        }

        public static bool operator ==(ColectoraDeNumeros colec, Numero num)
        {
            bool flag = false;
            
            foreach (Numero n in colec._numeros)
            {
                if (n.LecturaNumero == num.LecturaNumero)
                {
                    flag = true;
                    break;
                }
            }
            return flag;

        }

        public static bool operator !=(ColectoraDeNumeros colec, Numero num)
        {
            return !(colec == num);
        }


        public static ColectoraDeNumeros operator +(ColectoraDeNumeros colec, Numero num)
        {
            if (Verificadora.VerificarNumero(colec.Tipo, num))
            {
                colec._numeros.Add(num);
            }
            else
            {
                throw new Exception("No se pudo agregar a la coleccion porque no es del mismo tipo \n");
            }

            return colec;

        }
        public static ColectoraDeNumeros operator -(ColectoraDeNumeros colec, Numero num)
        {
            if (colec == num)
            {
                colec._numeros.Remove(num);
            }

            else
            {
                throw new Exception("El numero que se quiere remover no se encuentra en la coleccion\n" + colec.ToString());
            }
            return colec;
        }


        public override string ToString()
        {
            string cadena = "Tipo:" + this.Tipo + "\n";
            foreach (Numero n in this._numeros)
            {
                cadena += "\nNumero:" + n.LecturaNumero;
            }

            return cadena;
        }




    }
}
