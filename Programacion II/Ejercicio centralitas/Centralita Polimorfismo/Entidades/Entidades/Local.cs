using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Local : Llamada
    {
        #region Atributos
        protected float _costo;
        #endregion

        #region Propiedades

        public override float CostoLlamada 
        {
            get { return this.CalcularCosto(); }
        }
        #endregion

        #region Constructores

        public Local(Llamada unaLlamada,float costo) 
            : base(unaLlamada.NroOrigen,unaLlamada.NroDestino,unaLlamada.Duracion)
        {
            this._costo = costo;
        }

        public Local(string origen, float duracion, string destino, float costo)
            : base(origen, destino, duracion) 
        {
            this._costo = costo;
        }
        #endregion

        #region Metodos

        private float CalcularCosto()
        {
            float costo;
            costo = base._duracion * this._costo;
            return costo;
        }

        protected override string Mostrar()
        {
            string rtn = base.Mostrar() + "Costo llamada:" + this.CostoLlamada;
            return  rtn;
        }

        public override bool Equals(object obj)
        {
            bool rtn = false;
            if (obj is Local)
            {
                rtn = true;
            }
            return rtn;
        }

        public override string ToString()
        {
            return this.Mostrar();
        }
        #endregion
    }
}
