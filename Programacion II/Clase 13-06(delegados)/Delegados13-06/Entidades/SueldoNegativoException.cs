using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class SueldoNegativoException : Exception
    {
        public SueldoNegativoException(string mensaje)
            : base(mensaje)
        {
        }
    }
}
