using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades16_05
{
    public class DepositoDeAutos
    {
        private int _capacidadMaxima;
        private List<Auto> _lista;

        public DepositoDeAutos(int capacidad)
        {
            this._lista = new List<Auto>();
            this._capacidadMaxima = capacidad;
        }

        public bool Agregar(Auto a)
        {
            bool rtn = this + a;
            return rtn;
        }

        private int GetIndice(Auto a)
        {
            int rtn = -1;

            foreach (Auto autos in this._lista)
            {
                if (autos == a)
                {
                    rtn = this._lista.IndexOf(a);
                    break;
                }
            }
            return rtn;
        }

        public static bool operator +(DepositoDeAutos d, Auto a)
        {
            bool rtn = false;

            if (d._lista.Count < d._capacidadMaxima)
            {
                d._lista.Add(a);
                rtn = true;
            }
            return rtn;
        }

        public static bool operator -(DepositoDeAutos d, Auto a)
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

        public bool Remover(Auto a)
        {
            bool rtn = this - a;
            return rtn;

        }

        public override string ToString()
        {
            string cadena = "CapacidadMaxima:" + this._capacidadMaxima + "\nListado de Autos: \n";
            foreach (Auto a in this._lista)
            {
                cadena += a.ToString();              
            }
            return cadena;
        }


    }
}
