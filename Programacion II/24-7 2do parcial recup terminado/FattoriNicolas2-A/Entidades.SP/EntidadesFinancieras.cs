using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades.SP
{
    public delegate void DelegadoElementosPares(Object sender, EventArgs e);

    public class EntidadesFinancieras<T>
    {
        private List<T> _elementos;
        private int _cantidad;
        public event DelegadoElementosPares ElementosParesEvent;

        public EntidadesFinancieras()
        {
            this._elementos = new List<T>();
        }

        public EntidadesFinancieras(int cant)
            : this()
        {
           this._cantidad = cant;
        }

        public void Add(T obj)
        {
            if (this._cantidad > this._elementos.Count)
            {
                this._elementos.Add(obj);
                if ((this._elementos.Count % 2) == 0)
                {
                    this.ElementosParesEvent(this, EventArgs.Empty);
                }
            }
        }

        public override string ToString()
        {
            string cadena = "";
            int cont=0;
            foreach (T obj in this._elementos)
            {
                cont++;
                if ((cont % 2) == 0)
                {
                    cadena += obj.ToString() + "\n";
                }
            }
            return cadena;
        }

        
    }
}
