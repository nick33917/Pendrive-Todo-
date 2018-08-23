using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Clase9Herencia
{
    public class Auto : Vehiculo
    {
        protected int _cantAsientos;

        protected override string Mostrar()
        {
            return base.Mostrar() + "CantAsientos:" + this._cantAsientos;
        }

        public Auto(int cantAsientos, string patente, byte cantRuedas, EMarcas marca)
            : base(patente,cantRuedas,marca)
        {
            this._cantAsientos = cantAsientos;

        }

        public override string ToString()
        {
            return this.Mostrar();
        }

        public override bool Equals(object obj)
        {
            bool rtn = false;
            if (obj is Auto && (Auto)obj == this)
            {
                rtn = true;
            }
            return rtn;
        }

        public override string Acelerar()
        {
            return "El auto esta acelerando\n";
        }

    }
}
