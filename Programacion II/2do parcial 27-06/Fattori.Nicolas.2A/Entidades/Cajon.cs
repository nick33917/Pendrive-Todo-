using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml.Serialization;
using System.Xml;
namespace Entidades
{
    public delegate void CajonDelegado(string path , float precioCajon);
    public class Cajon<T> : ISerializable
    {
        private int _capacidad;
        private List<T> _frutas;
        private float _precioUnitario;
        private string _archivo;

        public event CajonDelegado EventoPrecio;


        public List<T> Frutas { get { return this._frutas;} }

        public float PrecioTotal
        {
            get
            {
                int cant = this._frutas.Count;
                float rtn = (cant * this._precioUnitario);
                if (rtn > 25)
                {

                    this.RutaArchivo = "EventoPrecio.txt";
                    this.EventoPrecio +=(Manejador);
                }
                return rtn;
            }
        }
        public string RutaArchivo
        {
            get
            {
                return this._archivo;
            }
            set
            {
                this._archivo = value;
            }
        }

        public void Manejador(string path ,float precio)
        {
            this.RutaArchivo = path;
            this._precioUnitario = precio;
        }

        public Cajon()
        {
            this._frutas = new List<T>();
        }
        public Cajon(int capacidad)
            :this()
        {
            this._capacidad = capacidad;
        }
        public Cajon(int capacidad, float precio)
            :this(capacidad)
        {
            this._precioUnitario = precio;
        }

        public static Cajon<T> operator +(Cajon<T> c, T f)
        {
            if (c._frutas.Count < c._capacidad)
            {
                c._frutas.Add(f);
            }
            else
            {
                throw new CajonLlenoException("Cajon LLeno"); 
            }

            return c;
        }

        public override string ToString()
        {
            string cadena = "";
            cadena += this._capacidad + this.PrecioTotal;
            foreach (T f in this._frutas)
            {
                cadena += "\n" + f.ToString();

            }
            return cadena;
        }

        
        public bool DeserealizarXml()
        {
            bool rtn = true;
            T tipo = default(T);
            try
            {
                XmlTextReader texto = new XmlTextReader(this.RutaArchivo);
                XmlSerializer serializar = new XmlSerializer(typeof(T));
                tipo = (T)serializar.Deserialize(texto);
                texto.Close();

            }
            catch
            {
                rtn = false;
            }
            return rtn;
        }

        public bool SerializarXml()
        {
            bool rtn = true;
            try
            {
                XmlTextWriter texto = new XmlTextWriter(this.RutaArchivo, Encoding.UTF8);
                XmlSerializer serializar = new XmlSerializer(typeof(T));
                serializar.Serialize(texto, this);
                texto.Close();
            }
            catch
            {
                rtn = false;

            }
            return rtn;
        }
    }
}
