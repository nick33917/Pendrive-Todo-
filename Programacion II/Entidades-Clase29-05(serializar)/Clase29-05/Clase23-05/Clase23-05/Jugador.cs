using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//serializacion texto
using System.IO;
//serializacion binario
using System.Runtime.Serialization.Formatters.Binary;
//clase para standarizacion xml
using System.Xml;
using System.Xml.Serialization;
namespace Clase23_05
{
    //ahi que agreegar el seriable para poder hacer una clase seriable//
    [Serializable] public class Jugador : ISerializableBinario , ISerializableXML
    {
        protected string _nombre;
        public string _apellido;
        protected EPuesto _puesto;


        public string Nombre { get { return this._nombre; } set { this._nombre = value; } }
        public string Apellido { get { return this._apellido;}}
        public EPuesto Puesto { get { return this._puesto; } set { this._puesto = value; } }



        public Jugador(string nombre, string apellido, EPuesto puesto)
        {
            this._nombre = nombre;
            this._apellido = apellido;
            this._puesto = puesto;
        }

        public Jugador()
        {
            this._nombre = "";
            this._apellido = "";
            this._puesto = EPuesto.Arquero;

        }


        public override string ToString()
        {
            string s = this._nombre + "-" + this._apellido + "-" + this._puesto ;
            return s;
        }

        public static bool TraerUno(string path, Jugador jugBuscado, out Jugador jug1)
        {
            string cadena = "";
            bool rtn = false;
            jug1 = null;
            bool flag = AdministradorDeArchivos.Leer(path,out cadena);
            string[] linea = cadena.Split('\n');
            if (flag)
            {
                foreach (string i in linea)
                {
                    string[] cadObj = i.Split('-');
                    if ((jugBuscado._nombre == cadObj[0])&& (jugBuscado._apellido == cadObj[1]) && (jugBuscado._puesto.ToString() == cadObj[2].Trim()))
                    {
                        jug1 = new Jugador(cadObj[0], cadObj[1], ((EPuesto)Enum.Parse(typeof(EPuesto), cadObj[2])));
                        rtn = true;
                        break;

                    }
                }
            }
            

            return rtn;
        }

        void ISerializableBinario.Serializar()
        {
            BinaryFormatter binario = new BinaryFormatter();
            FileStream manipular = new FileStream("jugadores.dat",FileMode.Create);
            binario.Serialize(manipular, this);
            manipular.Close();
        }

        Jugador ISerializableBinario.Deserializar()
        {
            //formatea a binario//
            BinaryFormatter binario = new BinaryFormatter();
            FileStream manipular = new FileStream("jugadores.dat", FileMode.Open);
            Jugador jug = ((Jugador)binario.Deserialize(manipular));
            manipular.Close();
            return jug;
        }

        void ISerializableXML.Serializar()
        {
            XmlTextWriter texto = new XmlTextWriter("jugadores.xml", Encoding.UTF8);
            XmlSerializer serializar = new XmlSerializer(typeof(Jugador));
            serializar.Serialize(texto, this);
            texto.Close();
        }

        Jugador ISerializableXML.Deserializar()
        {
            XmlTextReader texto = new XmlTextReader("jugadores.xml");
            XmlSerializer serializar = new XmlSerializer(typeof(Jugador));
            Jugador j = ((Jugador)serializar.Deserialize(texto));
            texto.Close();

            return j;
        }
    }
}
