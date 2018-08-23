using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades_Clase29_05
{
    [Serializable] public class Alumno : Persona
    {
        public int legajo;

        public Alumno(string nombre, string apellido,int dni, int legajo)
            : base(nombre, apellido, dni)
        {
            this.legajo = legajo;
        }
        public Alumno() 
            : base("","",0)
        {
            this.legajo = 0;
        }
        public override string ToString()
        {
            string s = base.ToString() + this.legajo;
            return s;
        }

    }
}
