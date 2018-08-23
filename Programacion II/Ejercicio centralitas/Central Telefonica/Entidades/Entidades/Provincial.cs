using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Provincial : Llamada
    {
        #region Atributos

        protected Franja _franjaHoraria;

        #endregion

        #region Propiedades

        public float CostoLlamada
        {
            get {return this.CalcularCosto();}
        }
        #endregion

        #region Constructores
        public Provincial(Franja miFranja, Llamada unaLlamada)
            : base(unaLlamada.NroOrigen, unaLlamada.NroDestino, unaLlamada.Duracion)
        {
            this._franjaHoraria = miFranja;
        }

        public Provincial(string origen, Franja miFranja, float duracion, string destino)
            : base(origen, destino, duracion)
        {
            this._franjaHoraria = miFranja;
        }

        #endregion

        #region Metodos

        private float CalcularCosto()
        {
            float costo=0;
            if (this._franjaHoraria == Franja.Franja_1)
            {
                costo = base._duracion * ((float)0.99);
            }
            else if (this._franjaHoraria == Franja.Franja_2)
            {
                costo = base._duracion * ((float)1.25);
            }
            else if (this._franjaHoraria == Franja.Franja_3)
            {
                costo = base._duracion * ((float)0.66);
            }
            return costo;
        }

        public void Mostrar()
        {
            base.Mostrar();
            StringBuilder mostra = new StringBuilder("Franja horario:" + this._franjaHoraria+ "\nCostoLlamada:" + this.CostoLlamada);
            Console.WriteLine(mostra);
        }
        #endregion

    }
}
