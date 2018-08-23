using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades16_05
{
    public class Cocina
    {
        private int _codigo;
        private bool _esIndustrial;
        private double _precio;

        public int Codigo { get { return this._codigo; } }
        public bool EIndustrial { get { return this._esIndustrial; } }
        public double Precio { get { return this._precio; } }

        public Cocina(int codigo, double precio, bool esIndustrial)
        {
            this._codigo = codigo;
            this._precio = precio;
            this._esIndustrial = esIndustrial;
        }

        public static bool operator ==(Cocina a, Cocina b)
        {
            bool rtn = false;
            if (a._codigo == b._codigo)
            {
                rtn = true;
            }
            return rtn;
        }

        public static bool operator !=(Cocina a, Cocina b)
        {
            return !(a == b);
        }

        public override bool Equals(object obj)
        {
            bool rtn=false;
            if(obj is Cocina && (((Cocina)obj) == this))
            {
                rtn=true;
            }
            return rtn;
        }

        public override string ToString()
        {
            return "Codigo:" + this._codigo + "--- Precio:" + this._precio + "---EsIndustrial? :" + this._esIndustrial + "\n"; 
        }

    }
}
