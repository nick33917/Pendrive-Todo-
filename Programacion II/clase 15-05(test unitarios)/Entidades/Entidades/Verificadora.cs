using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public static  class Verificadora
    {
        public static bool VerificarNumero(ETipoNumero tipo, Numero num)
        {
            bool flag = false;
            switch (tipo)
            {
                case ETipoNumero.Par:
                    if (num.LecturaNumero % 2 == 0)
                    {
                        flag = true;
                    }
                    break;
                case ETipoNumero.Impar:
                    if (!(num.LecturaNumero % 2 == 0))
                    {
                        flag = true;
                    }

                    break;
                case ETipoNumero.Positivo:
                    if (num.LecturaNumero > 0)
                    {
                        flag = true;
                    }
                    break;
                case ETipoNumero.Negativo:
                    if (num.LecturaNumero < 0)
                    {
                        flag = true;
                    }
                    break;
                case ETipoNumero.Cero:
                    if (num.LecturaNumero == 0)
                    {
                        flag = true;
                    }
                    break;
                default:
                    break;

            }

            return flag;
        }
    }
}
