using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Numero
    {
        private double numero;

        /// <summary>
        /// Valida si es un numero , devuelve 0 si no es un numero o el numero en un double.
        /// </summary>
        /// <param name="srtNumero">el numero en formato de string</param>
        /// <returns></returns>
        private double ValidarNumero(string srtNumero)
        {
            
            double num=0;
            bool flag;
            flag= double.TryParse(srtNumero,out num);
            return num;
        }

        public string SetNumero 
        { 
             set {this.numero = this.ValidarNumero(value);}
        }

        /// <summary>
        /// Convierte un numero binario a decimal , lo devuelve en un string.
        /// </summary>
        /// <param name="binario">el numero que voy a convertir</param>
        /// <returns></returns>
        public static string BinarioDecimal(string binario)
        {
           string numDecimal = Convert.ToInt64(binario,2).ToString();
           return numDecimal;

        }

        /// <summary>
        /// Convierte un numero decimal a binario , lo devuelve en un double.
        /// </summary>
        /// <param name="numero">el numero que voy a convertir</param>
        /// <returns></returns>
        public static string DecimalBinario(double numero)
        {
            string numBinario = Convert.ToString((long)numero,2);
            return numBinario;
        }
       /// <summary>
       /// Constructor por defecto.
       /// </summary>
        public Numero () : this(0)
        {
        }

        /// <summary>
        /// Constructor parametrizado.
        /// </summary>
        /// <param name="numero"></param>
        public Numero(double numero)
        {
            this.numero = numero;
        }

        /// <summary>
        /// Constructor parametrizado.
        /// </summary>
        /// <param name="strNumero"></param>
        public Numero(string strNumero)
        {
            this.SetNumero = strNumero;
           
        }

        /// <summary>
        /// Resta 2 objetos de tipo Numero.
        /// </summary>
        /// <param name="n1">1er numero</param>
        /// <param name="n2">2do numero</param>
        /// <returns></returns>
        public static double operator -(Numero n1, Numero n2)
        {
            double rtn;
            rtn = n1.numero - n2.numero;
            return rtn;
        }

        /// <summary>
        /// Suma 2 objetos de tipo Numero.
        /// </summary>
        /// <param name="n1">1er numero</param>
        /// <param name="n2">2do numero</param>
        /// <returns></returns>
        public static double operator +(Numero n1, Numero n2)
        {
            double rtn;
            rtn = n1.numero + n2.numero;
            return rtn;
        }

        /// <summary>
        /// Multiplica 2 objetos de tipo Numero.
        /// </summary>
        /// <param name="n1">1er numero</param>
        /// <param name="n2">2do numero</param>
        /// <returns></returns>
        public static double operator *(Numero n1, Numero n2)
        {
            double rtn;
            rtn = n1.numero * n2.numero;
            return rtn;
        }


        /// <summary>
        /// Divide 2 objetos de tipo Numero y si el 2do es 0, devuelve 0.
        /// </summary>
        /// <param name="n1">1er numero</param>
        /// <param name="n2">2do numero</param>
        /// <returns></returns>
        public static double operator /(Numero n1, Numero n2)
        {
            double rtn=0;
            if (n2.numero != 0)
            {
                rtn = n1.numero / n2.numero;
            } 
            return rtn;
            
        }

        



    }
}
