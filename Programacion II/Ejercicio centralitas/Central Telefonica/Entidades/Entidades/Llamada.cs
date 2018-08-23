using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Llamada
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

        public void Mostrar()
        {
            StringBuilder mostrar = new StringBuilder("Origen:" + this._nroOrigen + "\nDestino:" + this._nroDestino + "\nDuracion:" + this._duracion);
            Console.WriteLine(mostrar);
        }

        #endregion

     }
}
