using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;

namespace Entidades.SP
{
    public static class ClaseExtensora
    {
        public static string MostrarBD(this Producto p)
        {
            string cadena = "";
            try
            {
                SqlConnection conexion = new SqlConnection(Properties.Settings.Default.conexion);
                SqlCommand comando = new SqlCommand();
                conexion.Open();
                comando.Connection = conexion;
                comando.CommandText = "SELECT * FROM [productosDB].[dbo].[productos]";
                SqlDataReader lectura = comando.ExecuteReader();
                while (lectura.Read())
                {
                    cadena +="Nombre: " + lectura[0].ToString() + " ----Stock: " + lectura[1].ToString() + "\n";
                }
                conexion.Close();
                lectura.Close();
            }
            catch (Exception e)
            {

                throw e;
            }
            return cadena;
        }
        
    }
}
