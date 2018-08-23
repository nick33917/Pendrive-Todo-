using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace Entidades.SP
{
    public class MiException : Exception
    {
        public MiException(string msj)
            :base(msj)
        {
        }
    }
}
