using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Clase22_5
{
    public class Deportivo : Auto , IAFIP , IARBA
    {
        protected int _caballosFuerza;

        public Deportivo(double precio, string patente, int hp)
            : base(precio, patente)
        {
            this._caballosFuerza = hp;
        }

        double IAFIP.CalcularImpuesto()
        {
            double rtn = base._precio * 0.28;
            return rtn;
        }

        double IARBA.CalcularImpuesto()
        {
            double rtn = base._precio * 0.23;
            return rtn;
        }
    }
}
