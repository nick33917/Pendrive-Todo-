using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Data;
namespace Entidades
{
    public static class PaqueteDAO
    {
        private static SqlCommand _comando;
        private static SqlConnection _conexion;

        static PaqueteDAO()
        {
           _conexion = new SqlConnection(Properties.Settings.Default.conexion);
        }

        public static bool Insertar(Paquete p)
        {
            bool rtn=true;
            try
            {
                _conexion.Open();
                _comando = new SqlCommand("INSERT INTO [correo-sp-2017].[dbo].[Paquetes] (DireccionEntrega,TrackingID,Alumno) VALUES ('" + p.DireccionEntrega + "' ,'" + p.TrackingID + "','Nicolas Fattori')", PaqueteDAO._conexion);
                _comando.ExecuteNonQuery();
            }
            catch(Exception e)
            {
                rtn = false;
                throw e;
            }
            finally
            {
                _conexion.Close();
                
            }
            return rtn;
        }
    }
}
