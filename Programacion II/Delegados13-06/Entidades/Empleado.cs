using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    //Los delegados van en el namespace no dentro de la clase.

    //Con un delegado puedo definir un evento
    public delegate void DelegadoSueldoCero();
    public delegate void DelegadoDeLimiteSueldo(double sueldo, Empleado e);
    public delegate void DelegadoDeLimiteSueldoMejorado(Empleado sender, EmpleadoEventArgs e);

    public class Empleado
    {
        public string nombre;
        public string apellido;
        public int dni;
        private double _sueldo;
        //Se define como cualquier atributo
        public event DelegadoSueldoCero SueldoCero; //Evento
        public event DelegadoDeLimiteSueldo SueldoMaximo; //Evento
        public event DelegadoDeLimiteSueldoMejorado SueldoMaximoMejorado; //Evento


        public double Sueldo 
        { 
            get 
            { 
                return this._sueldo;
            } 
            set 
            {
                if (value > 20000 && value < 30000)
                {
                    EmpleadoEventArgs e = new EmpleadoEventArgs();
                    e.Sueldo = value;
                    this.SueldoMaximoMejorado(this, e);
                }
                else if (value > 10000)
                {
                    this.SueldoMaximo(value, this);
                }
                else if (value == 0)
                {
                    this.SueldoCero();
                }
                else if (value < 0)
                {
                    throw new SueldoNegativoException("Error el sueldo es negativo!");
                }
                else
                {
                    this._sueldo = value;
                }
            } 
        }

        public Empleado(string nombre, string apellido, int dni)
        {
            this.nombre = nombre;
            this.apellido = apellido;
            this.dni = dni;
        }

        public override string ToString()
        {
            return "Nombre: " + this.nombre + " Apellido: " + this.apellido + " Dni: " + this.dni + " Sueldo: " + this._sueldo;
        }

        public void ManejadorEvento()
        {
            Console.WriteLine("Metodo Manejador: Error, el sueldo es 0!");
        }

        public void ManejadorSueldoMaximo(double sueldo, Empleado e)
        {
            Console.WriteLine("Error! \nEl empleado: " + e.ToString() + "\nQuiere ganar: " + sueldo);
        }

        public void ManejadorSueldoMaximoMejorado(Empleado sender, EmpleadoEventArgs e)
        {
            Console.WriteLine("Error! \nEl empleado: " + sender.ToString() + "\nQuiere ganar: " + e.Sueldo);
        }

    }
}
