using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml;
using System.Xml.Serialization;
namespace Entidades_Clase29_05
{
    public class Xml<T>
    {
        public bool GuardarXml(string str, T tipo)
        {
            bool rtn = true;
            try
            {
                XmlTextWriter texto = new XmlTextWriter(str, Encoding.UTF8);
                XmlSerializer serializar = new XmlSerializer(typeof(T));
                serializar.Serialize(texto, tipo);
                texto.Close();
            }
            catch
            {
                rtn = false;

            }
            return rtn;

        }


        public bool LeerXml(string str, out T tipo)
        {
            bool rtn = true;
            tipo = default(T);
            try
            {
                XmlTextReader texto = new XmlTextReader(str);
                //serializa solo un unico tipo de dato//
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


    }
}
