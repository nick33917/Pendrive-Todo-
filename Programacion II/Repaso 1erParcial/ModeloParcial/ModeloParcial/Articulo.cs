using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ModeloParcial
{
    public class Articulo
    {
        #region Atributos

        private int _codigo;
        private string _nombre;
        private float _precioCosto;
        private float _precioVenta;
        private int _stock;

        #endregion

        #region Propiedades

        public virtual string NombreYCodigo
        {
            get { return this._nombre + this._codigo; }
        }

        public virtual float PrecioCosto
        {
            set
            { 
                this._precioCosto=value;
                //0.3f me lo toma como un flotante
                this._precioVenta = this._precioCosto + (this._precioCosto * 0.3f);
            }
        }

        public float PrecioVenta
        {
            get { return this._precioVenta; }
        }

        public int Stock
        {
            set { this._stock = value; }
        }

        #endregion

        #region Constructor

        public Articulo(int codigo, string nombre, float precioCosto, int cantidad)
        {
            this._codigo = codigo;
            this._nombre = nombre;
            this.PrecioCosto = precioCosto;
            this._stock = cantidad;
        }

        #endregion

        public bool HayStock(int cantidad)
        {
            bool rtn = false;
            if (this._stock >= cantidad)
            {
                rtn = true;
            }
            return rtn;
        }

        public static bool operator ==(Articulo articuloUno, Articulo articuloDos)
        {
            bool rtn = false;
            if (articuloUno.NombreYCodigo == articuloDos.NombreYCodigo)
            {
                rtn = true;
            }
            return rtn;
        }

        public static bool operator !=(Articulo articuloUno, Articulo articuloDos)
        {
            return !(articuloUno == articuloDos);
        }

        public static int operator +(Articulo articuloUno, Articulo articuloDos)
        {
            int suma = articuloUno._stock + articuloDos._stock;
            return suma;
        }

        public static int operator -(Articulo articuloUno, int cantidad)
        {
            int resta = articuloUno._stock - cantidad;
            return resta;
        }

    }
}
