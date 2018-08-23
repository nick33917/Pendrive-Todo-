using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Entidades.Alumnos;
using Entidades.Externa;
using Entidades.Externa.Sellada;
using System.IO;
using System.Data;
using System.Data.SqlClient;
//metodos de extension o de agregado//
namespace clase19_06
{
    public static class Extensora
    {
        public static string ObtenerInfo(this Persona p)
        {
            return p.ToString();
        }

        public static string ObtenerInfoDll(this PersonaExternaSellada p)
        {
            return p.Nombre + p.Apellido + p.Edad + p.Sexo;
        }

        public static bool EscribirEnArchivo(this PersonaExternaSellada p, string path)
        {
            bool rtn = true;
            try
            {
                StreamWriter archivo = new StreamWriter(path,true);
                archivo.WriteLine(p.ObtenerInfoDll());
                archivo.Close();

            }
            catch
            {
                rtn = false;
            }
            return rtn;

        }

        public static bool EsNulo(this object obj)
        {
            bool rtn= false;
            if (obj == null)
            {
                rtn = true;
            }
            return rtn;
        }

        public static int CantidadCaracteres(this string str)
        {
            return str.Length;
        }

        public static bool AgregarEnBaseDeDatos(this PersonaExternaSellada p)
        {
            bool flag = true;
            try
            {
                SqlConnection baseDeDato = new SqlConnection(Properties.Settings.Default.connection);
                //abre la conexion//
                baseDeDato.Open();
                //es insdistinto mayuscula o minuscula//
                //si pongo personas solo en el nombre de la tabla lo toma igual//
                SqlCommand comando = new SqlCommand("INSERT INTO [Personas.bd].[dbo].[Table_1] (nombre,apellido,edad,sexo) VALUES ('" + p.Nombre + "' ,'" + p.Apellido + "'," + p.Edad + "," + (int)p.Sexo + ")", baseDeDato);
                int num = comando.ExecuteNonQuery();
                baseDeDato.Close();
            }
            catch
            {
                flag = false;
            }
            return flag;
        }

        public static List<PersonaExternaSellada> TraerTodos(this PersonaExternaSellada p)
        {
            List<PersonaExternaSellada> listPer = new List<PersonaExternaSellada>();
            try
            {
                
                SqlConnection baseDeDato = new SqlConnection(Properties.Settings.Default.connection);
                //abre la conexion//
                baseDeDato.Open();
                // el * es lo mismo que pones id , nombre, apellido , edad//
                SqlCommand comando = new SqlCommand("SELECT * FROM [Personas.bd].[dbo].[Table_1] ", baseDeDato);
                SqlDataReader lectura = comando.ExecuteReader();
                while (lectura.Read())
                {
                    listPer.Add(new PersonaExternaSellada(lectura[1].ToString(), lectura[2].ToString(), int.Parse(lectura[3].ToString()),(Entidades.Externa.Sellada.ESexo)lectura[4]) );
                    
                }
                lectura.Close();
                baseDeDato.Close();
            }
            catch (Exception e)
            {

               listPer = null;

            }
            return listPer;
        }
    }
}
