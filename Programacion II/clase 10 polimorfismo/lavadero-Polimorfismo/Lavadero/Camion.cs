using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Clase9Herencia
{
    public class Camion : Vehiculo
    {
        protected float _tara;

        protected override string Mostrar()
        {
            return base.Mostrar() + "Peso:" + this._tara;
        }

        public Camion(float tara, string patente, byte cantRuedas, EMarcas marca)
            : base(patente, cantRuedas, marca)
        {
            this._tara = tara;
        }

        public override string ToString()
        {
            return this.Mostrar();
        }

        public override bool Equals(object obj)
        {
            bool rtn = false;
            if (obj is Camion && (Camion)obj == this)
            {
                rtn = true;
            }
            return rtn;
        }

        public override string Acelerar()
        {
            return "El Camion esta acelerando\n";
        }
    }
}
