using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
namespace Entidades
{
    [XmlInclude(typeof(Manzana))][XmlInclude(typeof(Platano))][Serializable]
    public abstract class Fruta
    {
        protected ConsoleColor _color;
        protected float _peso;

        public abstract bool TieneCarozo { get;}

        public Fruta(float peso, ConsoleColor color)
        {
            this._peso = peso;
            this._color = color;
        }

        protected virtual string FrutaToString()
        {
            string cadena = "\nColorFruta:" + this._color + " --- PesoFruta:" + this._peso + " --- TieneCarozo:"+ this.TieneCarozo;
            return cadena;
        }
    }
}
