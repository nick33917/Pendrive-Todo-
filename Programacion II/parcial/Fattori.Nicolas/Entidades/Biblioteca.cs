using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Biblioteca
    {
        private int _capacidad;
        private List<Libro> _libros;

        public double PrecioDeManuales
        {
            get 
            {
                double rtn = this.ObtenerPrecio(ELibro.Manual);
                return rtn;
            }
        }

        public double PrecioDeNovelas
        {
            get
            {
                double rtn = this.ObtenerPrecio(ELibro.Novela);
                return rtn;
            }
        }

        public double PrecioTotal
        {
            get
            {
                double rtn = this.ObtenerPrecio(ELibro.Ambos);
                return rtn;
            }
        }




        private Biblioteca()
        {
            this._libros = new List<Libro>();
        }

        private Biblioteca(int capacidad)
            :this()
        {
            this._capacidad = capacidad;
        }

        public static implicit operator Biblioteca(int capacidad)
        {
            Biblioteca nueva = new Biblioteca();
            nueva._capacidad = capacidad;
            return nueva;

        }

        public static string Mostrar(Biblioteca e)
        {
            string muestra="";
            foreach(Libro lib in e._libros)
            {
                muestra += " CapacidadDeBiblioteca:" + e._capacidad;
                if (lib is Manual)
                {
                    muestra += ((Manual)lib).Mostrar();
                }
                else if (lib is Novela)
                {
                    muestra += ((Novela)lib).Mostrar();
                }

            }

            return muestra;
        }

        public static bool operator ==(Biblioteca e, Libro I)
        {
            bool rtn = false;
            foreach (Libro lib in e._libros)
            {
                if (lib == I)
                {
                    rtn = true;
                }
            }
            return rtn;

        }
        public static bool operator !=(Biblioteca e, Libro I)
        {
            return !(e==I);

        }
        public static Biblioteca operator +(Biblioteca e, Libro I)
        {
            int cont = 0;
            foreach (Libro lib in e._libros)
            {
                cont ++;
            }
            if ((e._capacidad > cont) && (e != I))
            {
                e._libros.Add(I);

            }
            else
            {
                Console.WriteLine("No hay Mas Lugar en la biblioteca\n");
            }
            return e;

        }

        private double ObtenerPrecio(ELibro tipoLibro)
        {
            double precio = 0;
            switch (tipoLibro)
            {
                case ELibro.Manual:
                    foreach(Libro lib in this._libros)
                    {
                        if (lib is Manual)
                        {
                            precio += ((Manual)lib) ;
                        }
                       
                    }
                   break;
                case ELibro.Novela:
                   foreach (Libro lib in this._libros)
                   {
                       if (lib is Novela)
                       {
                           precio += ((Novela)lib);
                       }

                   }
                    break;
                case ELibro.Ambos:
                    foreach (Libro lib in this._libros)
                    {
                        if (lib is Novela && lib is Manual)
                        {
                            precio += ((Novela)lib);
                        }

                    }
                    break;

              }
            return precio;
        }

    }
}
