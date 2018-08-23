using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Interfaces;
using System.IO;
namespace Entidades
{
    public delegate void DelegadoHilos(string msj);

    public class LosHilos: IRespuesta<int>
    {
        private int _id;
        private List<InfoHilo> _misHilos;
        public event DelegadoHilos AvisoFin;
        public string Bitacora
        {
            get
            {
                string cosa = "";
                string path = Environment.GetFolderPath(System.Environment.SpecialFolder.DesktopDirectory);
                StreamReader archivo = new StreamReader(path + "// Bitacora.txt");
                cosa += archivo.ReadToEnd() + "\n";
                archivo.Close();
                return cosa;
            }
            set
            {
                string path = Environment.GetFolderPath(System.Environment.SpecialFolder.DesktopDirectory);
                StreamWriter archivo = new StreamWriter(path + "// Bitacora.txt", true);
                archivo.WriteLine(value);
                archivo.Close();

            }
        }

        public LosHilos()
        {
            this._misHilos = new List<InfoHilo>();
            this._id = 0;
        }

        private static LosHilos AgregarHilo(LosHilos hilos)
        {
            hilos._id++;
            InfoHilo infoNuevo = new InfoHilo(hilos._id, ((IRespuesta<int>)hilos));
            hilos._misHilos.Add(infoNuevo);
            return hilos;
        }


        public void RespuestaHilo(int id)
        {
            string cadena = string.Format("Termino el hilo: {0}", id);
            this.Bitacora = cadena;
            this.AvisoFin(cadena);
        }

        public static LosHilos operator +(LosHilos hilos, int cantidad)
        {
            if (cantidad < 1)
            {
                throw new CantidadInvalidaException();
            }
            else if (cantidad > 0)
            {
                while (cantidad > 0)
                {
                    LosHilos.AgregarHilo(hilos);
                    cantidad--;
                }
            }
            return hilos;
        }
    }
}
