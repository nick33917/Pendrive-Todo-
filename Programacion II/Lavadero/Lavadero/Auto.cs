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

        public string MostrarAuto()
        {
            return base.Mostrar() + "CantAsientos:" + this._cantAsientos;
        }

        public Auto(int cantAsientos, string patente, byte cantRuedas, EMarcas marca)
            : base(patente,cantRuedas,marca)
        {
            this._cantAsientos = cantAsientos;

        }
    }
}
