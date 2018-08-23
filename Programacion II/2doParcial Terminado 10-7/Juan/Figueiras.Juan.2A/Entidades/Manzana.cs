using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.IO;

namespace Entidades
{
    [Serializable]
    public class Manzana : Fruta, ISerializable
    {
        public string distribuidora;

        public override bool TieneCarozo
        {
            get 
            { 
                return true; 
            }
        }

        public string Tipo
        {
            get 
            { 
                return "Manzana"; 
            }
        }

        public string RutaArchivo 
        { 
            get; 
            set; 
        }

        protected override string FrutaToString()
        {
            return base.FrutaToString() + " -- Tipo :" + this.Tipo + " -- distribuidora :" + this.distribuidora;
        }

        public Manzana(): base(123, ConsoleColor.DarkRed)
        {
            this.distribuidora = "Sin distribuidora";
        }

        public Manzana(float peso, ConsoleColor color, string distribuidora): base(peso, color)
        {
            this.distribuidora = distribuidora;
        }

        public override string ToString()
        {
            return this.FrutaToString();
        }

        public bool SerializarXML()
        {
            bool retornador = true;

            try
            {
                this.RutaArchivo = "Manzana.xml";

                XmlSerializer ser = new XmlSerializer(this.GetType());

                //StreamWriter archivo = new StreamWriter(path, flag);

                StreamWriter escribo = new StreamWriter(this.RutaArchivo, false);

                ser.Serialize(escribo, this);

                escribo.Close();
            }
            catch (Exception e)
            {
                return false;
            }

            return retornador;
        }

        public bool Deserializar()
        {
            bool retornador = true;

            try
            {
                XmlSerializer ser = new XmlSerializer(this.GetType());

                StreamReader leo = new StreamReader(this.RutaArchivo);

                Console.WriteLine((ser.Deserialize(leo)).ToString());

                leo.Close();
            }
            catch (Exception e)
            {
                retornador = false;
            }

            return retornador;
        }
    }
}
