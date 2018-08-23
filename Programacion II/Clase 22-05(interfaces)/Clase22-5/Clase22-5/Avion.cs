using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Clase22_5
{
    public class Avion : Vehiculo , IAFIP , IARBA
    {
        protected double _velocidadMaxima;

        public Avion(double precio, double velMax)
            : base(precio)
        {
            this._velocidadMaxima = velMax;
        }

        public override double Precio
        {
            get { return base._precio; }
        }



        double IAFIP.CalcularImpuesto()
        {
            double rtn = base._precio * 0.33;
            return rtn;
        }

        double IARBA.CalcularImpuesto()
        {
            double rtn = base._precio * 0.27;
            return rtn;
        }
    }
}
