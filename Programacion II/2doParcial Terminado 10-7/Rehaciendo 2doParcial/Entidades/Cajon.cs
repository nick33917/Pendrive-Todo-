using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml;
using System.Xml.Serialization;
namespace Entidades
{
    public delegate void DelegadoPrecioTotal(object sender , EventArgs ea);

    [Serializable]
    public class Cajon<T> : ISerializable
    {
        private int _capacidad;
        private List<T> _frutas;
        private float _precioUnitario;
        public event DelegadoPrecioTotal EventoPrecio;

        public List<T> Frutas 
        {
            get { return this._frutas; } 
        }

        public float PrecioTotal
        {
            get
            {
                float total = this._precioUnitario * this._frutas.Count;
                if (total> 25)
                {
                    this.EventoPrecio(this, EventArgs.Empty);

                }
                return total;

            }
        }

       
        public void ManejadorPrecioTotal(object obj, EventArgs e)
        {
            try
            {
                StreamWriter escritura = new StreamWriter("PrecioTotal.txt", true);
                escritura.WriteLine("Hora:" + DateTime.Now + "----- PrecioTotal:" + ((Cajon<T>)obj).PrecioTotal.ToString());
                escritura.Close();
            }
            catch(Exception)
            {
            }
        }

        public Cajon()
        {
            this._frutas = new List<T>();
            this.EventoPrecio += new DelegadoPrecioTotal(this.ManejadorPrecioTotal);
        }

        public Cajon(int capacidad):this()
        {
            this._capacidad = capacidad;
        }

        public Cajon(int capacidad,float precio):this(capacidad)
        {
            this._precioUnitario = precio;
        }

        public override string ToString()
        {
            string cadena = "Capacidad:" + this._capacidad + "--- CantidadTotalDeFrutas:" + this._frutas.Count + "PrecioTotal:" + this.PrecioTotal;
            foreach(T frut in this._frutas)
            {
                cadena += "\n" + frut.ToString() + "\n";
            }
            return cadena;
        }

        public static Cajon<T> operator +(Cajon<T> c, T f)
        {
            if (c._frutas.Count < c._capacidad)
            {
                c._frutas.Add(f);
            }
            else
            {
                throw new CajonLlenoException("El cajon esta lleno");
            }
            return c;
                
         }



        public string RutaArchivo { get; set; }


        public bool Deserealizar()
        {
            bool rtn = true;

            try
            {
                XmlTextReader lector = new XmlTextReader(this.RutaArchivo);
                XmlSerializer serial = new XmlSerializer(typeof(Cajon<T>));
                Cajon<T> caj = (Cajon<T>)serial.Deserialize(lector);
                this.RutaArchivo = caj.RutaArchivo;
                this._frutas = caj._frutas;
                lector.Close();
            }
            catch
            {
                rtn = false;
            }
            return rtn;
        }

        public bool SerializarXML()
        {
            bool rtn = true;
            try
            {
                XmlTextWriter escritor = new XmlTextWriter(this.RutaArchivo, Encoding.UTF8);
                XmlSerializer serial = new XmlSerializer(typeof(Cajon<T>));
                serial.Serialize(escritor, this);
                escritor.Close();

            }
            catch
            {
                rtn = false;
            }

            return rtn;
        }

     
    }
}
