using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades16_05
{
    public class DepositoDeCocinas
    {
        private int _capacidadMaxima;
        private List<Cocina> _lista;

        public DepositoDeCocinas(int capacidad)
        {
            this._lista = new List<Cocina>();
            this._capacidadMaxima = capacidad;
        }

        public bool Agregar(Cocina a)
        {
            bool rtn = this + a;
            return rtn;
        }

        private int GetIndice(Cocina a)
        {
            int rtn = -1;

            foreach (Cocina cocinas in this._lista)
            {
                if (cocinas == a)
                {
                    rtn = this._lista.IndexOf(a);
                    break;
                }
            }
            return rtn;
        }

        public static bool operator +(DepositoDeCocinas d, Cocina a)
        {
            bool rtn = false;

            if (d._lista.Count < d._capacidadMaxima)
            {
                d._lista.Add(a);
                rtn = true;
            }
            return rtn;
        }

        public static bool operator -(DepositoDeCocinas d, Cocina a)
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

        public bool Remover(Cocina a)
        {
            bool rtn = this - a;
            return rtn;

        }

        public override string ToString()
        {
            string cadena = "CapacidadMaxima:" + this._capacidadMaxima + "\nListado de Cocinas: \n";
            foreach (Cocina a in this._lista)
            {
                cadena += a;              
            }
            return cadena;
        }
    }
}
