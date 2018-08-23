using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Libro
    {
        protected Autor _autor;
        protected int _cantidadDePaginas;
        protected Random _generadorDePaginas;
        protected float _precio;
        protected string _titulo;

        public int CantidadDePaginas
        {
            get 
            {
                if (this._cantidadDePaginas == 0)
                {
                    this._cantidadDePaginas = this._generadorDePaginas.Next(10, 580);
                }

                return this._cantidadDePaginas;
            }
        }

        private Libro() 
        {
            this._precio = 0;
            this._titulo = "";
            
            
        }

        public Libro(float precio, string titulo, string nombre, string apellido)
            :this()

        {

            
            
            

        }

        public Libro(string titulo, Autor autor, float precio)
        {
            this._autor = autor;
            this._titulo = titulo;
            this._precio = precio;
            this._cantidadDePaginas = 0;

        }

        private static string Mostrar(Libro I)
        {
            return (string)I;
            
        }

        public static bool operator ==(Libro a, Libro b)
        {
            bool rtn = false;
            if ((a._titulo == b._titulo) && (a._autor == b._autor))
            {
                rtn = true;
            }
            return rtn;
        }

        public static bool operator !=(Libro a, Libro b)
        {
            return !(a == b);
        }

        public static explicit operator string(Libro I)
        {
            return "Autor: " + I._autor + "\nCantidadDePaginas: " + I._cantidadDePaginas + "\nPrecio: " + I._precio + "\nTitulo: " + I._titulo + "\n";
        }
    }
}
