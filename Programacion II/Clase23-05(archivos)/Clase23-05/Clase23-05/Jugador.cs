using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Clase23_05
{
    public class Jugador
    {
        protected string _nombre;
        protected string _apellido;
        protected EPuesto _puesto;


        public string Nombre { get { return this._nombre; } }
        public string Apellido { get { return this._apellido; } }
        public EPuesto Puesto { get { return this._puesto; } }



        public Jugador(string nombre, string apellido, EPuesto puesto)
        {
            this._nombre = nombre;
            this._apellido = apellido;
            this._puesto = puesto;
        }



        public override string ToString()
        {
            string s = this._nombre + "-" + this._apellido + "-" + this._puesto ;
            return s;
        }

        public static bool TraerUno(string path, Jugador jugBuscado, out Jugador jug1)
        {
            string cadena = "";
            bool rtn = false;
            jug1 = null;
            bool flag = AdministradorDeArchivos.Leer(path,out cadena);
            string[] linea = cadena.Split('\n');
            if (flag)
            {
                foreach (string i in linea)
                {
                    string[] cadObj = i.Split('-');
                    if ((jugBuscado._nombre == cadObj[0])&& (jugBuscado._apellido == cadObj[1]) && (jugBuscado._puesto.ToString() == cadObj[2].Trim()))
                    {
                        jug1 = new Jugador(cadObj[0], cadObj[1], ((EPuesto)Enum.Parse(typeof(EPuesto), cadObj[2])));
                        rtn = true;
                        break;

                    }
                }
            }
            

            return rtn;
        }
    }
}
