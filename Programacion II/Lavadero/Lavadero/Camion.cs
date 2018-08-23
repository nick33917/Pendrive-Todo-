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

        public string MostarCamion()
        {
            return base.Mostrar() + "Peso:" + this._tara;
        }

        public Camion(float tara, string patente, byte cantRuedas, EMarcas marca)
            : base(patente, cantRuedas, marca)
        {
            this._tara = tara;
        }


    }
}
