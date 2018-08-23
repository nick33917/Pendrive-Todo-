using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio47
{
    public class Contabilidad<T,U> where T : Documento where U: Documento, new()
    {
        private List<T> _egresos;
        private List<U> _ingresos;

        
        public static Contabilidad<T, U> operator +(Contabilidad<T, U> c, T egreso)
        {
            c._egresos.Add(egreso);
            return c;
        }

        public static Contabilidad<T, U> operator +(Contabilidad<T, U> c, U ingreso)
        {
            c._ingresos.Add(ingreso);
            return c;
        }

        
    }
}
