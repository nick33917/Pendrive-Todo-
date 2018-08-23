using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Clase9Herencia
{
    public class Moto : Vehiculo
    {
        protected float _cilindrada;

        public string MostrarMoto()
        {
            return base.Mostrar() + "Cilindrada:" + this._cilindrada;
        }

        public Moto(float cilindrada, string patente, byte cantRuedas, EMarcas marca)
            : base(patente, cantRuedas, marca)
        {
            this._cilindrada = cilindrada;
        }
    }
}
