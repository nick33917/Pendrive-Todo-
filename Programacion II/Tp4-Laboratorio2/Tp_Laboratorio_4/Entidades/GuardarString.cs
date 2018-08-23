using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Entidades
{
    public static class GuardarString
    {
        public static bool Guardar(this string texto, string archivo)
        {
            bool rtn = true;
            try
            {
                string path = Environment.GetFolderPath(System.Environment.SpecialFolder.DesktopDirectory);
                StreamWriter txt = new StreamWriter(path + "//" + archivo , true);
                txt.WriteLine(texto + "\n");
                txt.Close();

            }
            catch
            {
                rtn = false;
            }
            return rtn;

        }
            
    }
}
