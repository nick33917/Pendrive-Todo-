using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Clase22_5
{
    public class Comercial : Avion ,IARBA
    {
        protected int _capacidadPasajeros;

        public Comercial(double precio, double velocidad, int pasajeros)
            : base(precio, velocidad)
        {
            this._capacidadPasajeros = pasajeros;
        }


        //double IARBA.CalcularImpuesto()
        //{
        //    double rtn = base._precio * 0.25;
        //    return rtn;
        //}
    }
}
