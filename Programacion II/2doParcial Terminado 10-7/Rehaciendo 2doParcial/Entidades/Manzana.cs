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
    
    public class Manzana : Fruta , ISerializable
    {
        public string distribuidora;

        public override bool TieneCarozo
        {
            get { return true; }
        }

        public string Tipo 
        {
            get { return "Manzana"; } 
        }
        //constructor por defecto para serializar
        public Manzana()
            :base(0,ConsoleColor.Red)
        {
            this.distribuidora = "Sin nombre";
        }

        public Manzana(float peso, ConsoleColor color, string distrib)
            : base(peso, color)
        {
            this.distribuidora = distrib;
        }

        protected override string FrutaToString()
        {
            string cadena = "Tipo:" + this.Tipo + base.FrutaToString() + " --- Distribuidora:" + this.distribuidora;
            return cadena;
        }

        public override string ToString()
        {
            return this.FrutaToString();
        }

        public string RutaArchivo { get; set; }
        

        public bool Deserealizar()
        {
            bool rtn = true;

            try
            {
                XmlTextReader lector = new XmlTextReader(this.RutaArchivo);
                XmlSerializer serial = new XmlSerializer(typeof(Manzana));
                Manzana man = (Manzana)serial.Deserialize(lector);
                this._color = man._color;
                this._peso = man._peso;
                this.distribuidora = man.distribuidora;
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
                XmlSerializer serial = new XmlSerializer(typeof(Manzana));
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
