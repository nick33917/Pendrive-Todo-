using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades16_05
{
    public class Deposito <T>
    {
        private int _capacidadMaxima;
        private List<T> _lista;

        public Deposito(int capacidad)
        {
            this._lista = new List<T>();
            this._capacidadMaxima = capacidad;
        }

        public bool Agregar(T a)
        {
            bool rtn = this + a;
            return rtn;
        }

        private int GetIndice(T a)
        {
            int rtn = -1;

            foreach (T obj in this._lista)
            {
                if (obj.Equals(a))
                {
                    rtn = this._lista.IndexOf(a);
                    break;
                }
            }
            return rtn;
        }

        public static bool operator +(Deposito<T>d, T a)
        {
            bool rtn = false;

            if (d._lista.Count < d._capacidadMaxima)
            {
                d._lista.Add(a);
                rtn = true;
            }
            return rtn;
        }

        public static bool operator -(Deposito<T> d, T a)
        {
            bool rtn = false;
            int indice = d.GetIndice(a);
            if (indice != -1)
            {
                d._lista.Remove(a);
                rtn = true;
            }
            return rtn;
        }

        public bool Remover(T a)
        {
            bool rtn = this - a;
            return rtn;

        }

        public override string ToString()
        {
            string cadena = "CapacidadMaxima:" + this._capacidadMaxima +"\n";
            foreach (T a in this._lista)
            {
                cadena += a;              
            }
            return cadena;
        }

    }
}
