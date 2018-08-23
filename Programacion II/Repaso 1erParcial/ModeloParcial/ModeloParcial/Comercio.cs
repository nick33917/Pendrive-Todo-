using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ModeloParcial
{
    public class Comercio
    {
        private string _dueño;
        private List<Articulo> _misArticulos;
        private List<Venta> _misVentas;

        public Comercio(string dueño)
        {
            this._dueño = dueño;
            this._misArticulos = new List<Articulo>();
            this._misVentas = new List<Venta>();
        }

        public void ComprarArticulo(Articulo articuloComprado)
        {
            bool flag = false;
            foreach (Articulo art in this._misArticulos)
            {
                if (art == articuloComprado)
                {
                    art.Stock = art + articuloComprado;
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                this._misArticulos.Add(articuloComprado);
            }
        }

        public void VenderArticulo(Articulo articuloSolicitado, int cantidad)
        {
            bool flag = false;
            foreach (Articulo art in this._misArticulos)
            {
                if (art == articuloSolicitado)
                {
                    flag=true;
                    if (art.HayStock(cantidad))
                    {
                        art.Stock = art - cantidad;
                        Venta obj = new Venta(articuloSolicitado, cantidad);
                        this._misVentas.Add(obj);
                        break;
                    }
                    else
                    {
                        Console.WriteLine("No hay stock\n{0}", articuloSolicitado.NombreYCodigo);
                        break;
                    }
                }

            }
            if (!flag)
            {
                Console.WriteLine("No Existe en la lista de articulos\n{0}",articuloSolicitado.NombreYCodigo);
            }


        }

        public static void MostrarArticulos(Comercio comercioAMostrar)
        {
            foreach (Articulo art in comercioAMostrar._misArticulos)
            {
                Console.WriteLine("Nombre y codigo del articulo:{0}" , art.NombreYCodigo); 
            }
        }

        public static void MostrarGanancia(Comercio comercioParaResumen)
        {
            float acum = 0;
            foreach (Venta vent in comercioParaResumen._misVentas)
            {
                acum += vent.RetornarGanancia();
            }

            Console.WriteLine("Ganancia:{0}", acum);
        }
    }
}
