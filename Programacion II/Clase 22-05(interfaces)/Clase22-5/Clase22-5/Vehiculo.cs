using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Clase22_5
{
    public abstract class Vehiculo
    {
        protected double _precio;

        public abstract double Precio { get; }

        public void MostrarPrecio()
        {
            Console.WriteLine("Precio:{0}", this._precio);
        }

        public Vehiculo(double precio)
        {
            this._precio = precio;
        }
    }
}
