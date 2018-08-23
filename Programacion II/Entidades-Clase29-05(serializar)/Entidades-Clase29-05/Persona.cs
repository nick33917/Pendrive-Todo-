using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml;
using System.Xml.Serialization;
namespace Entidades_Clase29_05
{
    [Serializable] [XmlInclude(typeof(Alumno))] [XmlInclude(typeof(Profesor))] public abstract class Persona
    
    {
        protected string _nombre;
        protected string _apellido;
        protected int _dni;

        public string Nombre { get { return this._nombre; } set { this._nombre = value; } }
        public string Apellido { get { return this._apellido;} set {this._apellido=value ;} }
        public int Dni { get { return this._dni; } set { this._dni = value; } }
        public Persona(string nombre, string apellido, int dni)
        {
            this._apellido = apellido;
            this._nombre = nombre;
            this._dni = dni;
        }
        public Persona() : this("","",0)
        {
        }

        public override string ToString()
        {
            string s = this._nombre +"--" + this._apellido + "--" + this._dni +"--";
            return s;

        }

    }
}
