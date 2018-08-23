using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades16_05
{
    public class Auto
    {
        private string _color;
        private string _marca;

        public string Color
        {
            get { return this._color; }
        }

        public string Marca
        {
            get { return this._marca; }
        }

        public Auto(string color, string marca)
        {
            this._color = color;
            this._marca = marca;
        }

        public static bool operator ==(Auto a, Auto b)
        {
            bool rtn = false;
            if (a._color == b._color && a._marca == b._marca)
            {
                rtn = true;
            }

            return rtn;
        }

        public static bool operator !=(Auto a, Auto b)
        {
            return !(a == b);
        }

        public override bool Equals(object obj)
        {
            bool rtn = false;

            if (obj is Auto && (this == ((Auto)obj)))
            {
                rtn = true;
            }
            return rtn;
        }

        public override string ToString()
        {
            return "Marca:" + this._marca + " --- Color:" + this._color + "\n";
        }

    }
}
