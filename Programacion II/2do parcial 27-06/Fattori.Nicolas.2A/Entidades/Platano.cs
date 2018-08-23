using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Platano : Fruta
    {
        public string paisOrigen;

        public string Tipo { get { return "Platano"; } }

        public override bool TieneCarozo
        {
            get { return false; }
        }

        public Platano(float peso, ConsoleColor color, string pais) 
            : base(peso,color)
        {
            this.paisOrigen = pais;
        }

        protected override string FrutaToString()
        {
            string cadena =  base.FrutaToString();
            cadena += paisOrigen;
            return cadena;
        }

        public override string ToString()
        {
            return this.FrutaToString();
        }
            
    }
}
