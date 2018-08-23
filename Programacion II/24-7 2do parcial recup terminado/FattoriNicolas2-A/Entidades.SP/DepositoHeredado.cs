using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml.Serialization;
using System.Xml;

namespace Entidades.SP
{
    public class DepositoHeredado : Deposito , ISerializar, IDeserializar
    {
        public DepositoHeredado()
            : base()
        {
        }


        public bool Xml(string path)
        {
            bool rtn = true;
            try
            {
                XmlTextWriter escritor = new XmlTextWriter(path, Encoding.UTF8);
                XmlSerializer serial = new XmlSerializer(typeof(DepositoHeredado));
                serial.Serialize(escritor, this);
                escritor.Close();

            }
            catch
            {
                rtn = false;
            }

            return rtn;
        }

        bool IDeserializar.Xml(string path, out DepositoHeredado dep)
        {

            bool rtn = true;
            dep = new DepositoHeredado();
            try
            {
                XmlTextReader lector = new XmlTextReader(path);
                XmlSerializer serial = new XmlSerializer(typeof(DepositoHeredado));
                dep = (DepositoHeredado)serial.Deserialize(lector);
                lector.Close();
            }
            catch
            {
                rtn = false;
            }
            return rtn;
        }
    }
}
