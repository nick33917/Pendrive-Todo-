using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Numero
    {
        protected int _numero;

        public int LecturaNumero
        {
            get { return this._numero; }
        }


        public Numero(int num)
        {
            this._numero = num;
        }


        public static int operator +(Numero n1, Numero n2)
        {
            return (n1._numero + n2._numero);
        }

        public static int operator -(Numero n1, Numero n2)
        {
            return (n1._numero - n2._numero);
        }

        public static double operator /(Numero n1, Numero n2)
        {
            return (n1._numero / n2._numero);
        }

        public static int operator *(Numero n1, Numero n2)
        {
            return (n1._numero * n2._numero);
        }

        public static bool Parse(string cadena, out Numero n1)
        {
            //el objeto tiene que estar inicializado porque sino el compilador no lo toma//
            n1 = null;
            int num=0;
            bool flag=true;
            try
            {
                num = int.Parse(cadena);
            }
            catch(Exception e)
            {
                flag=false;
            }

            if(flag)
            {
               n1= new Numero(num);
            }

            return flag;
        }




    }
}
