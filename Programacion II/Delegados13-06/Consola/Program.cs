using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Entidades;

namespace Consola
{
    class Program
    {
        static void Main(string[] args)
        {
            Empleado e1 = new Empleado("Juan", "Figueiras", 411701);

            e1.SueldoCero += new DelegadoSueldoCero(e1.ManejadorEvento);
            e1.SueldoMaximo += new DelegadoDeLimiteSueldo(e1.ManejadorSueldoMaximo);
            e1.SueldoMaximoMejorado += new DelegadoDeLimiteSueldoMejorado(e1.ManejadorSueldoMaximoMejorado);

            try
            {
                e1.Sueldo = 20999;
            }
            catch(SueldoNegativoException e)
            {
                Console.WriteLine(e.Message);
            }


            Console.ReadKey();
        }
    }
}
