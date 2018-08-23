using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Calculadora
    {
        /// <summary>
        /// Valida el operador para saber que cuenta realizar.
        /// </summary>
        /// <param name="operador"></param>
        /// <returns></returns>
        private static string ValidarOperador(string operador)
        {
            string rtn;
            switch (operador)
            {
                case "-":
                    rtn="-";
                    break;

                case "*":
                    rtn= "*";
                    break;

                case "/":
                    rtn = "/";
                    break;
                default :
                    rtn = "+";
                    break;
            }
            return rtn;
        }


        /// <summary>
        /// Realiza la operacion  que queramos entre 2 numeros y devuelve el resultado.
        /// </summary>
        /// <param name="num1">1er numero</param>
        /// <param name="num2">2do numero</param>
        /// <param name="operador">operador para realizar la cuenta</param>
        /// <returns></returns>
        public double Operar(Numero num1,Numero num2,string operador)
        {
            double resultado;
            string s = ValidarOperador(operador);
            switch (s)
            {
                case "-":
                    resultado = num1 - num2;
                    break;

                case "*":
                    resultado = num1 * num2;
                    break;

                case "/":
                    resultado = num1 / num2;
                    break;
                default:
                    resultado = num1 + num2;
                    break;
            }
            return resultado;
            

        }
    }
}
