using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public abstract class Llamada
    {
        #region Atributos

        protected float _duracion;
        protected string _nroDestino;
        protected string _nroOrigen;

        #endregion

        #region Propiedades

        public float Duracion
        {
            get { return this._duracion; }
        }

        public string NroDestino 
        {
            get { return this._nroDestino; }
        }

        public string NroOrigen
        {
            get { return this._nroOrigen; }
        }

       public abstract float CostoLlamada
       { 
           get; 
       }
        
        #endregion

        #region Constructor

        public Llamada(string origen, string destino, float duracion)
        {
            this._nroOrigen = origen;
            this._nroDestino = destino;
            this._duracion = duracion;
        }

        #endregion

        #region Metodos

        public static int OrdenarPorDuracion(Llamada uno, Llamada dos)
        {
            int rtn = -1;
            if (uno._duracion == dos._duracion)
            {
                rtn = 0;
            }
            else if (uno._duracion > dos._duracion)
            {
                rtn = 1;
            }
            return rtn;
        }

        protected virtual string Mostrar()
        {
            StringBuilder mostrar = new StringBuilder("Origen:" + this._nroOrigen + "\nDestino:" + this._nroDestino + "\nDuracion:" + this._duracion);
            return Convert.ToString(mostrar);
        }

        public static bool operator ==(Llamada uno, Llamada dos)
        {
            bool rtn = false;
            if (uno.Equals(dos) && uno._nroDestino==dos._nroDestino && uno._nroOrigen == dos._nroOrigen)
            {
                rtn = true;
            }
            return rtn;
        }

        public static bool operator !=(Llamada uno, Llamada dos)
        {
            return !(uno == dos);
        }


        #endregion

     }
}
