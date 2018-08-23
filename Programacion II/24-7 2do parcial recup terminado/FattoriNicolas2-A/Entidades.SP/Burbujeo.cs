using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace Entidades.SP
{
    public class Burbujeo
    {
        public void MetodoInstacia()
        {
            throw new MiException("MetodoInstancia(Clase Burbujeo)");
        }

        public static void MetodoClase()
        {
            try
            {
                Burbujeo b = new Burbujeo();
                b.MetodoInstacia();
            }
            catch (MiException e)
            {
                Burbujeo.EscribirArchivo("burbujeo.txt",e.Message);
                throw new MiException("MetodoClase(Clase Burbujeo)");
            }
            
            
        }

        public static bool EscribirArchivo(string path, string lugar)
        {
            bool flag = true;
            try
            {
                StreamWriter escritura = new StreamWriter(path, true);
                escritura.WriteLine("Hora:" + DateTime.Now + "----- LugarPorElQuePaso:" + lugar);
                escritura.Close();
            }
            catch (Exception)
            {
                flag = false;
            }
            return flag;
        }

        public static string LeerArchivo(string path)
        {
            string cosa = "";
            try
            {
                StreamReader archivo = new StreamReader(path);
                cosa = archivo.ReadToEnd();
                archivo.Close();

            }
            catch(Exception)
            {
                
            }
            return cosa;
        }
    }
}
