using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Ejercicio47;

namespace PruebaEjercicio
{
    class Program
    {
        static void Main(string[] args)
        {
            Contabilidad<Factura, Recibo> empresa = new Contabilidad<Factura, Recibo>() ;
            

            Recibo rec1 = new Recibo(1);
            Recibo rec2 = new Recibo(2);
            Recibo rec3 = new Recibo(3);

            Factura fac1 = new Factura(1);
            Factura fac2 = new Factura(2);
            Factura fac3 = new Factura(3);

            empresa += fac1;
            empresa += fac2;
            empresa += fac3;

            empresa += rec1;
            empresa += rec2;
            empresa += rec3;

            

        }
    }
}
