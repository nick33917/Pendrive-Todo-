using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace Clase23_05
{
    public static class AdministradorDeArchivos
    {
        public static bool Escribir(string path, string cosa ,bool flag)
        {
            bool rtn = true;
            try
            {
                StreamWriter archivo = new StreamWriter(path, flag);
                archivo.WriteLine(cosa);
                archivo.Close();
                
            }
            catch
            {
                rtn = false;
            }
            return rtn;
        }
        public static bool Leer(string path , out string cosa)
        {
            bool rtn = true;
            cosa = "";
            try
            {
                StreamReader archivo = new StreamReader(path);
                cosa = archivo.ReadToEnd();
                archivo.Close();

            }
            catch
            {
                rtn = false;
            }
            return rtn;
        }
        
    }
}
