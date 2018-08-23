using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Runtime;
namespace Entidades
{
    public class Correo : IMostrar<List<Paquete>> 
    {
        private List<Thread> _mockPaquetes;
        private List<Paquete> _paquetes;

        public List<Paquete> Paquetes
        {
            get
            {
                return this._paquetes;
            }
            set
            {
                this._paquetes = value;
            }
        }

        public Correo()
        {
            this._mockPaquetes = new List<Thread>();
            this._paquetes = new List<Paquete>();
        }

        public void FinEntregas()
        {
            foreach (Thread hilo in this._mockPaquetes)
            {
                if (hilo.IsAlive)
                {
                    hilo.Abort();
                }
            }
        }


        string IMostrar<List<Paquete>>.MostrarDatos(IMostrar<List<Paquete>> elemento)
        {
            string rtn = "";
            List<Paquete> listaPaq = ((Correo)elemento)._paquetes;
            foreach(Paquete p in listaPaq)
            {
                rtn += string.Format("{0} para {1} ({2})\n", p.TrackingID, p.DireccionEntrega, p.Estado.ToString());
            }
            return rtn;
        }

        public static Correo operator +(Correo c, Paquete p)
        {
            bool rtn = false;
            foreach (Paquete paq in c._paquetes)
            {
                 if (paq == p)
                 {
                      rtn = true;
                      throw new TrackingIdRepetidoException("El trackingID :"+ p.TrackingID + "ya se encuentra en la Lista");
                 }
            }
            if (!rtn)
            {
                c._paquetes.Add(p);
                Thread hiloMock = new Thread(p.MockCicloDeVida);
                c._mockPaquetes.Add(hiloMock);
                hiloMock.Start();
            }

            return c;
        }

       
    }
}
