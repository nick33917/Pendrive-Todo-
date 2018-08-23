using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.IO;
using System.Data;
using System.Data.SqlClient;
namespace Entidades
{
  
    public class Paquete : IMostrar<Paquete>
    {
        public enum EEstado
        {
            Ingresado,
            EnViaje,
            Entregado
        }

        #region atributos
        private string _direccionEntrega;
        private EEstado _estado;
        private string _trackingID;
        public event DelegadoEstado InformaEstado;
        public delegate void DelegadoEstado(object sender, EventArgs e);

        #endregion

        #region Propiedades
        public string DireccionEntrega 
        {
            get
            {
                return this._direccionEntrega;
            }
            set
            {
                this._direccionEntrega = value;
            }
        }

        public EEstado Estado 
        { 
            get
            {
                return this._estado;
            }
            set
            {
                this._estado = value;
            }
        }

        public string TrackingID 
        {
            get
            {
                return this._trackingID;
            }
            set
            {
                this._trackingID = value;
            }
        }
        #endregion

        #region Metodos
        public Paquete(string direccionEntrega, string tackingID)
        {
            this._direccionEntrega = direccionEntrega;
            this._trackingID = tackingID;
        }

        public string MostrarDatos(IMostrar<Paquete> elemento)
        {
            Paquete p = (Paquete)elemento;
            return string.Format("{0} para {1}", p.TrackingID, p.DireccionEntrega);
        }

        public override string ToString()
        {
            return this.MostrarDatos(this);
        }

        public static bool operator ==(Paquete p1, Paquete p2)
        {
            bool rtn=false;
            int num = string.Compare(p1._trackingID,p2._trackingID);
            if (num==0)
            {
                rtn=true;
            }
            return rtn;
        }

        public static bool operator !=(Paquete p1, Paquete p2)
        {
            return !(p1 == p2);
        }

        public void MockCicloDeVida()
        {
            do
            {

                Thread.Sleep(10000);
                this._estado += 1;
                EventArgs e = new EventArgs();
                this.InformaEstado(this, e);

            }
            while (this._estado != EEstado.Entregado);

            try
            {
                PaqueteDAO.Insertar(this);
            }
            catch(SqlException e)
            {
               
            }
            


          

        }

        #endregion




        
    }
}
