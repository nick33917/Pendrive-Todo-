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

        public override bool TieneCarozo
        {
            get { return false; }
        }

        public string Tipo
        {
            get { return "Platano"; }
        }

        public Platano()
            : base(0, ConsoleColor.Yellow)
        {
            this.paisOrigen = "Sin pais";
        }
        public Platano(float peso, ConsoleColor color, string pais)
            : base(peso, color)
        {
            this.paisOrigen = pais;
        }
        
        protected override string FrutaToString()
        {
            string cadena = base.FrutaToString() + " ---PaisOrigen:" + this.paisOrigen + " --- Tipo:" + this.Tipo;
            return cadena;
        }

        public override string ToString()
        {
            return this.FrutaToString();
        }

    }

}