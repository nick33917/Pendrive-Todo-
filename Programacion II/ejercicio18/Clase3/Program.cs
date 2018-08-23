using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Geometría;

namespace PruebaGeometrica
{
    class Ejercicio18
    {
        static void Main(string[] args)
        {
            float area;
            float perimetro;
            Punto vertice1 = new Punto(2,2);
            Punto vertice3 = new Punto(3, 5);
            Rectangulo rect = new Rectangulo(vertice1, vertice3);
            area = rect.GetArea();
            perimetro = rect.GetPerimetro();

            Console.Write("Perimetro:{0} , Area:{1}", perimetro, area);
            Console.ReadLine();

        }
    }


}
