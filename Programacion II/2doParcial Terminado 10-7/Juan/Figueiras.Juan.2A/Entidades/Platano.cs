using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    [Serializable]
    public class Platano : Fruta
    {
        public string paisOrigen;

        public override bool TieneCarozo
        {
            get 
            { 
                return false; 
            }
        }

        public string Tipo
        {
            get 
            { 
                return "Platano"; 
            }
        }

        protected override string FrutaToString()
        {
            return base.FrutaToString() + "-- Tipo :" + this.Tipo + " -- país de origen :" + this.paisOrigen;
        }

        public Platano(float peso, ConsoleColor color, string pais): base(peso, color)
        {
            this.paisOrigen = pais;
        }

        public Platano(): base(123, ConsoleColor.DarkYellow)
        {
            this.paisOrigen = "Sin país de origen";
        }

        public override string ToString()
        {
            //return base.FrutaToString() + "-- Tipo :" + this.Tipo + " -- país de origen :" + this.paisOrigen;
            return this.FrutaToString();
        }
    }
}
