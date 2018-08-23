using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EntidadesClase22
{
    //DELEGADOS 
    public delegate void DelegadoSueldoCero();
    public delegate void DelegadoLimiteSueldo(double sueldo, Empleado e1);
    public delegate void DelegadoLimiteSueldoMejorado(Empleado sender, EmpleadoEventArgs e);

    public class Empleado
    {
        public string _nombre;
        public string _apellido;
        public int _dni;
        private double _sueldo;

        public double Sueldo
        {
            get
            {
                return this._sueldo;
            }
            set
            {
                if (value < 0)
                    throw new SueldoNegativoException();
                else if (value == 0)
                    this.SueldoCero();
                else if (value > 20000 && value < 30000)
                    this.SueldoMaximoMejorado(this, new EmpleadoEventArgs());
                else if (value > 10000)
                    this.SueldoMaximo(value, this);

                else
                    this._sueldo = value;
            }

        }//si es menor a 0, mando la excepcion SueldoNegativoException

        public Empleado(string nombre, string apellido, int dni)
        {
            this._apellido = apellido;
            this._dni = dni;
            this._nombre = nombre;
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendFormat("Nombre: {0} -- ", this._nombre);
            sb.AppendFormat("Apellido: {0} -- ", this._apellido);
            sb.AppendFormat("DNI: {0} -- ", this._dni);
            sb.AppendFormat("Sueldo: {0}", this.Sueldo);

            return sb.ToString();
        }

        //EVENTOS
        public event DelegadoSueldoCero SueldoCero;
        public event DelegadoLimiteSueldo SueldoMaximo;
        public event DelegadoLimiteSueldoMejorado SueldoMaximoMejorado;


        //MANEJADORES DE EVENTOS
        public void ManejadorEvento()
        {
            Console.WriteLine("Cuidado, el sueldo es 0");
        }

        public void ManejadorSueldoMaximo(double sueldo, Empleado e)
        {
            Console.WriteLine("El empleado {0} {1} esta recibiendo una suma excesiva de ${2}", e._nombre, e._apellido, sueldo);
        }

        public void ManejadorSueldoMaximoMejorado(Empleado sender, EmpleadoEventArgs e)
        {
            Console.WriteLine("El empleado {0} {1} esta recibiendo una suma de entre $20000 y $30000", sender._nombre, sender._apellido);
        }
    }
}
