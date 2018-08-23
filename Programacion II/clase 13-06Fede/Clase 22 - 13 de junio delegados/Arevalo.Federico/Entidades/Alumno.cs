using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Alumno
    {
        private string _apellido;
        private string _dni;
        private string _fotoAlumno;
        private string _nombre;

        public string Apellido { get { return this._apellido; } set { this._apellido = value; } }
        public string DNI { get { return this._dni; } set { this._dni = value; } }
        public string Nombre { get { return this._nombre; } set { this._nombre = value; } }
        public string FotoAlumno { get { return this._fotoAlumno; } set { this._fotoAlumno = value; } }

        public Alumno(string apellido, string nombre, string dni, string ruta)
        {
            this._apellido = apellido;
            this._nombre = nombre;
            this._dni = dni;
            this._fotoAlumno = ruta;
        }
    }
}
