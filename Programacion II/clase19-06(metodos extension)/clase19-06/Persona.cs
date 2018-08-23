using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Entidades.Externa;

namespace Entidades.Alumnos
{
    public class Persona : PersonaExterna
    {
        protected string _nombre;
        protected string _apellido;
        protected int _edad;
        protected ESexo _sexo;

        public Persona(string nombre, string apellido, int edad,Entidades.Externa.ESexo sexo) 
            : base(nombre,apellido,edad,sexo)

        {
            this._nombre = nombre;
            this._apellido = apellido;
            this._edad = edad;
            this._sexo = (ESexo)sexo;
        }

        public string Nombre { get { return this._nombre; } }
        public string Apellido { get { return this._apellido; } }
        public int Edad { get { return this._edad; } }
        public ESexo Sexo { get { return this._sexo; } }

        public override string ToString()
        {
            return this._nombre + this._apellido + this._edad + this._sexo;
        }
    }
}
