using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Geometría
{
    class Rectangulo
    {
       private Punto vertice1;
       private Punto vertice2;
       private Punto vertice3;
       private Punto vertice4;
       private float area;
       private float perimetro;

       public Rectangulo(Punto vertice1, Punto vertice3)
       {
           this.vertice1 = vertice1;
           this.vertice3 = vertice3;
           this.vertice2 = new Punto(this.vertice1.GetX(), this.vertice3.GetY());
           this.vertice4 = new Punto(this.vertice3.GetX(), this.vertice1.GetY());

       }


        public float Area()
        { 
            int basee;
            int altura;
            float area;

            basee = (this.vertice4.GetX()) - (this.vertice1.GetX()) ;
            basee = Math.Abs(basee);

            altura = (this.vertice2.GetY()) - (this.vertice1.GetY());
            altura = Math.Abs(altura);

            area = basee * altura;
            this.area = area;
            return area;
        
        }

        public float Perimetro()
        {
            int basee;
            int altura;
            float perim;

            basee = (this.vertice4.GetX()) - (this.vertice1.GetX());
            basee = Math.Abs(basee);

            altura = (this.vertice2.GetY()) - (this.vertice1.GetY());
            altura = Math.Abs(altura);

            perim = (basee + altura) * 2;
            this.perimetro = perim;

            return perim;
        }

        public float GetArea()
        {
            float area = this.Area();
            return area;

        }

        public float GetPerimetro()
        {
            float perim = this.Perimetro();
            return perim;
        }

        


                    
    }
}
