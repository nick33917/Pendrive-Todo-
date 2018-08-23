using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.IO;

namespace Entidades
{
    //Para que sea una excepcion debo heredarla de la clase exception
    public class CajonLlenoException : Exception
    {
        public CajonLlenoException(string mensaje): base(mensaje){}
    }
}
