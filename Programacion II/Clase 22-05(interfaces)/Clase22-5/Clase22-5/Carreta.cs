using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Clase22_5
{
    public class Carreta: Vehiculo , IARBA
    {
        public Carreta(double precio)
            : base(precio)
        {
        }

        public override double Precio
        {
            get { return base._precio; }
        }



        double IARBA.CalcularImpuesto()
        {
            double rtn = base._precio * 0.18;
            return rtn;
        }
    }
}
