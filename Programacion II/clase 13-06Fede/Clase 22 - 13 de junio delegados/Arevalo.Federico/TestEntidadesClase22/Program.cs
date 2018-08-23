using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using EntidadesClase22;

namespace TestEntidadesClase22
{
    class Program
    {
        static void Main(string[] args)
        {
            Empleado e1 = new Empleado("Federico", "Arevalo", 123);

            //Console.WriteLine(e1.ToString());

            //Console.ReadLine();

            e1.SueldoCero += new DelegadoSueldoCero(new DelegadoSueldoCero(e1.ManejadorEvento));
            e1.SueldoMaximo += new DelegadoLimiteSueldo(new DelegadoLimiteSueldo(e1.ManejadorSueldoMaximo));
            e1.SueldoMaximoMejorado += new DelegadoLimiteSueldoMejorado(new DelegadoLimiteSueldoMejorado(e1.ManejadorSueldoMaximoMejorado));
            //e1.SueldoMaximoMejorado += 

            try
            {
                Console.WriteLine("Ingresa el sueldo");
                e1.Sueldo = double.Parse(Console.ReadLine());  
            }
            catch (SueldoNegativoException e)
            {
                Console.WriteLine("El sueldo es menor a 0");
            }                 

            Console.WriteLine(e1.ToString());

            Console.ReadLine();
        }
    }
}
