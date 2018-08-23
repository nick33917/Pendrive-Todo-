using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.IO;
namespace Entidades
{
    public delegate void CorrenCallback(int avance , Corredor corred);
    public class Persona : Corredor
    {
        private string _nombre;
        public event CorrenCallback Corriendo;

        public override void Correr()
        {
            while (true)
            {

                int valor = Corredor._avance.Next(1, base.VelocidadMaxima);
                if (valor < 10)
                {
                    Thread.Sleep(300);
                    this.Corriendo(valor,this);
                }
                else
                {
                    break;
                }

            }
        }

        public override void Guardar(string path)
        {
            try
            {
                StreamWriter escritura = new StreamWriter(path, true);
                escritura.WriteLine(this.ToString());
                escritura.Close();
            }
            catch(Exception e )
            {
                throw new NoSeGuardoException(e);
            }

        }

        public override string ToString()
        {
            string cadena = this._nombre + " en carril " + base._carrilElegido + " a una velocidad maxima de " + base.VelocidadMaxima + "\n";
            return cadena;
        }

        public Persona(string nombre, short velocidadMax, Carril carril)
            : base(velocidadMax, carril)
        {
            this._nombre = nombre;
        }

        






    }
}
