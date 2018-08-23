using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades_Clase29_05
{
    public class Profesor : Persona
    {
        public string titulo;

        public Profesor(string nombre, string apellido,int dni, string titulo)
            : base(nombre, apellido, dni)
        {
            this.titulo = titulo;
        }
        public Profesor() 
            : base("","",0)
        {
            this.titulo = "";
        }
        public override string ToString()
        {
            string s = base.ToString() + this.titulo;
            return s;
        }
    }
}
