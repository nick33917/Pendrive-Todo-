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
    [Serializable]
    [XmlInclude(typeof(Manzana))]
    public abstract class Fruta
    {
        protected ConsoleColor _color;
        protected float _peso;

        public abstract bool TieneCarozo { get; }

        public Fruta(float peso, ConsoleColor color)
        {
            this._peso = peso;
            this._color = color;
        }

        protected virtual string FrutaToString()
        {
            string cadena = this._peso.ToString();
            cadena += this._color.ToString();
            return cadena;
        }
            

    }
}
