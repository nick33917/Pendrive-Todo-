using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Clase22_5
{
    public class Familiar : Auto
    {
        protected int _cantAcientos;

        public Familiar(double precio, string patente, int cantidadAsientos) 
            : base(precio,patente)
        {
            this._cantAcientos = cantidadAsientos;
        }
    }
}
