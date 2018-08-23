using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.IO;


namespace Entidades
{
    public delegate void CajonDelegado(object sender, EventArgs ea);

    [Serializable]
    public class Cajon<T> : ISerializable
    {
        private int _capacidad;
        private float _precioUnitario;
        private List<T> _frutas;
        public event CajonDelegado EventoPrecio;

        public List<T> Frutas
        {
            get 
            { 
                return this._frutas; 
            }
        }

        public float PrecioTotal
        {
            get
            {
                if (this._precioUnitario * this._frutas.Count > 25)
                    this.EventoPrecio(this, EventArgs.Empty);

                return this._frutas.Count * this._precioUnitario;
            }
        }

        public string RutaArchivo 
        {
            get;
            set; 
        }

        public Cajon()
        {
            this._capacidad = 0;
            this._precioUnitario = 0;
            this._frutas = new List<T>();

            this.EventoPrecio += new CajonDelegado(ManejadorEventoTest);
        }

        public Cajon(int capacidad, float precio): this(capacidad)
        {
            this._precioUnitario = precio;
        }

        public Cajon(int capacidad): this()
        {
            this._capacidad = capacidad;
        }

        public bool Deserializar()
        {
            bool retornador = true;

            try
            {
                XmlSerializer ser = new XmlSerializer(this.GetType());

                StreamReader leo = new StreamReader(this.RutaArchivo);

                Console.WriteLine(((Cajon<T>)ser.Deserialize(leo)).ToString());

                leo.Close();
            }
            catch (Exception e)
            {
                retornador = false;
            }

            return retornador;
        }

        public bool SerializarXML()
        {
            bool retornador = true;

            try
            {
                this.RutaArchivo = "Cajon.xml";

                XmlSerializer ser = new XmlSerializer(this.GetType());

                StreamWriter escribo = new StreamWriter(this.RutaArchivo, false);

                ser.Serialize(escribo, this);

                escribo.Close();
            }
            catch (Exception e)
            {
                retornador = false;
            }

            return retornador;
        }

        public static Cajon<T> operator +(Cajon<T> c, T f)
        {
            if (c._frutas.Count + 1 <= c._capacidad)
            {
                c._frutas.Add(f);
                return c;
            }
            else
            {
                throw new CajonLlenoException("¡El cajón se encuentra lleno!");
            }
        }

        public static void ManejadorEventoTest(object obj, EventArgs ee)
        {
            try
            {
                StreamWriter escribo = new StreamWriter("Precios.txt", true);

                escribo.WriteLine("Precio del cajón: " + ((Cajon<Fruta>)obj).PrecioTotal.ToString() +  " -- " + DateTime.Now.ToString());

                escribo.Close();
            }
            catch (Exception e)
            {

            }
        }

        public override string ToString()
        {
            string str = "Cajon -- Capacidad: " + this._capacidad + " -- precio unitario: " + this._precioUnitario + "-- precio total: " + this.PrecioTotal;

            foreach (T f in this._frutas)
            {
                str += f.ToString();
            }

            return str;
        }
    }
}
