using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EntidadesClase6
{
    public class Paleta
    {
        private Tempera[] colores;
        private int cantMaxColores;


        private Paleta(int num)
        {
            this.cantMaxColores = num;
            this.colores = new Tempera[num];
        }

        private Paleta() : this(5)
        {
        }

        // en el main se usaria paleta obj = 8;//
        public static implicit operator Paleta(int num)
        {
            Paleta obj = new Paleta(num);
            return obj;
        }

        private string Mostrar()
        {
            string s="Cantidad maxima de colores: "+ this.cantMaxColores + "\n";
            for (int i = 0; i < this.cantMaxColores; i++)
            {
                if (this.colores.GetValue(i) != null)
                {
                    s += Tempera.Mostrar(colores[i]) + "\n";
                }
            }
            return s;

        }

        public static explicit operator string(Paleta objPaleta)
        {
            return objPaleta.Mostrar();
        }

        public static bool operator ==(Paleta paleta, Tempera tempera)
        {
            bool rtn = false;
            for (int i = 0; i < paleta.cantMaxColores; i++)
            {
                if (paleta.colores.GetValue(i) != null)
                {
                    if (paleta.colores[i] == tempera)
                    {
                        rtn = true;
                        break;

                    }
                }
            }
            return rtn;
        }

        public static bool operator !=(Paleta paleta, Tempera tempera)
        {
            return !(paleta == tempera);
        }


        public static Paleta operator +(Paleta paleta, Tempera tempera)
        {
            int indice = 0;
            if (paleta == tempera)
            {
                indice = paleta.ObtenerIndice(tempera);
                paleta.colores[indice] += tempera;
            }
            return paleta;

        }

        private int ObtenerIndice()
        {
            int rtn = -1;
            for (int i = 0; i < this.cantMaxColores; i++)
            {
                if (this.colores.GetValue(i) == null)
                {
                    rtn = i;
                    
                }

            }
            return rtn;
            
        }
        private int ObtenerIndice(Tempera tempera)
        {
            int rtn = -1;
            for (int i = 0; i < this.cantMaxColores; i++)
            {
                if (tempera == this.colores[i])
                {
                    rtn = i;
                    break;
                }
            }
            return rtn;
        }


        public static Paleta operator -(Paleta paleta, Tempera tempera)
        {
            int indice = -1;
            if (paleta == tempera)
            {
                indice = paleta.ObtenerIndice(tempera);
                if (indice > 0)
                {
                    paleta.colores[indice] += -(tempera);

                    if (paleta.colores[indice] <= 0)
                    {
                        paleta.colores[indice] = null;

                    }
                }

            }
            return paleta;
        }


    }
}
