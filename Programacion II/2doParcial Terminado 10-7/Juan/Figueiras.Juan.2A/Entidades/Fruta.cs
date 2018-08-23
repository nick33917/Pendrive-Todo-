using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.IO;

namespace Entidades
{
    [XmlInclude(typeof(Manzana))][XmlInclude(typeof(Platano))][Serializable]
    public abstract class Fruta
    {
        protected ConsoleColor _color;
        protected float _peso;

        //Abstracta para hacer el override en las clases hijas.
        public abstract bool TieneCarozo 
        { 
            get;
        }

        public Fruta(float peso, ConsoleColor color)
        {
            this._color = color;
            this._peso = peso;
        }

        protected virtual string FrutaToString()
        {
            return " -- Color :" + this._color + " -- peso :" + this._peso + " -- tiene carozo :" + this.TieneCarozo;
        }
    }
}
