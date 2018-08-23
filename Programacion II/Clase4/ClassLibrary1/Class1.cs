using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassLibrary1
{
    public class Cosa
    {
        public int entero;
        public string cadena;
        public DateTime fecha;


        //firma del metodo

        /// <summary>
        /// Establece un valor para un atributo de la clase
        /// </summary>
        /// <param name="num">Parametro que inicializa el atributo entero en la clase</param>
        public void EstablecerValor(int num)
        {
            this.entero = num;
        }
        //firma del metodo , sobrecarga 1

        /// <summary>
        /// Establece un valor para un atributo de la clase
        /// </summary>
        /// <param name="cad">Parametro que inicializa el atributo cadena en la clase</param>
        public void EstablecerValor(string cad)
        {
            this.cadena = cad;
        }

        //firma del metodo ,sobrecarga 2

        /// <summary>
        /// Establece un valor para un atributo de la clase
        /// </summary>
        /// <param name="fecha">Parametro que inicializa el atributo fecha en la clase</param>
        public void EstablecerValor(DateTime fecha)
        {
            this.fecha = fecha;
        }
        /// <summary>
        /// retorno un string concatenando todos los datos
        /// </summary>
        /// <returns></returns>
        public string Mostrar()
        {
            string retorno = ""+ this.entero + "\n" + this.cadena + "\n" + this.fecha;
             return retorno;


        }

        //constructor
        public Cosa()
        {
            this.entero = 10;
            this.cadena = "Sin valor";
            this.fecha = DateTime.Now;

        }

        //constructor parametrizado sobrecarga1
        public Cosa(int num, string cad, DateTime fecha)
        {
            this.entero = num;
            this.cadena = cad;
            this.fecha = fecha;
        }

        //constructor parametrizado sobrecarga2
        public Cosa(int numero, string cadena)
        {
            this.entero = numero;
            this.cadena = cadena;
            this.fecha = DateTime.Now;
        }

        //constructor parametrizado sobrecarga3
        public Cosa(int numero)
        {
            this.entero = numero;
            this.cadena = "Sin valor";
            this.fecha = DateTime.Now;
        }


       
    }
}
