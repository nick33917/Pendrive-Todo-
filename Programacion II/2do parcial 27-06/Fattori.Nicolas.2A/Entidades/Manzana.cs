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
    public class Manzana : Fruta , ISerializable
    {
        public string distribuidora;
        private string _archivo;

        public string Tipo { get { return "Manzana"; } }

        public override bool TieneCarozo
        {
            get { return true; }
        }

        public Manzana(float peso, ConsoleColor color, string distribu)
            : base(peso, color)
        {
            this.distribuidora = distribu;
        }

        protected override string FrutaToString()
        {
            string cadena = base.FrutaToString();
            cadena += this.distribuidora;
            return cadena;
        }

        public override string ToString()
        {
            return this.FrutaToString();
        }


        public string RutaArchivo
        {
            get
            {
                return this._archivo;
            }
            set
            {
                this._archivo = "EventoPrecio.txt";
            }
        }

        public bool DeserealizarXml()
        {
            bool rtn = true;
            try
            {
                XmlTextReader texto = new XmlTextReader(this.RutaArchivo);
                XmlSerializer serializar = new XmlSerializer(typeof(Manzana));
                serializar.Deserialize(texto);
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
                XmlSerializer serializar = new XmlSerializer(typeof(Manzana));
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
