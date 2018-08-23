using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Entidades;

namespace CentralitaHerencia
{
    class Program
    {
        static void Main(string[] args)
        {
            Centralita empresa = new Centralita("Telefonica");
            Local llam1 = new Local("Argentina",30,"Brasil",2);
            Provincial llam2 = new Provincial("España",Franja.Franja_1,21,"Italia");
            Local llam3 = new Local("Paraguay", 45, "Peru", 2);
            Provincial llam4 = new Provincial(Franja.Franja_3, llam2);

            empresa.Llamadas.Add(llam1);
            empresa.Llamadas.Add(llam2);
            empresa.Llamadas.Add(llam3);
            empresa.Llamadas.Add(llam4);

            empresa.Mostrar();
            Console.ReadLine();
            
        }
    }
}
