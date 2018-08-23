using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SqlClient;
namespace Entidades30_5
{
    public class Persona
    {
        private string _nombre;
        private string _apellido;
        private int _edad;
        private int _id;

        public string Nombre { get { return this._nombre; }  set {this._nombre=value;}}
        public string AApellido { get {return this._apellido;}  set {this._apellido=value;}}
        public int Edad { get {return this._edad;}  set {this._edad=value;}}
        public int Id { get {return this._id;}}


        public Persona(string nombre, string apellido, int edad)
        {
            this._nombre = nombre;
            this._apellido = apellido;
            this._edad = edad;
        }

        public Persona(int id, string nombre, string apellido, int edad) 
            : this(nombre,apellido,edad)

        {
            this._id = id;
        }

        public static List<Persona> TraerTodos()
        {
            List<Persona> per = new List<Persona>();
            //el namespace properties se crea cuando guardo la value en setting//
            SqlConnection baseDeDato = new SqlConnection(Properties.Settings.Default.conexion);
            //abre la conexion//
            baseDeDato.Open();
            //configo para poder pasarle comandos a la base de datos//
            SqlCommand comando = new SqlCommand("SELECT [id],[nombre],[apellido],[edad] FROM [Padron].[dbo].[Personas]", baseDeDato);
            //el sqldatareader no se puede instanciar , siempre le pasa el valor el execute reader//
            //es un objeto de solo lectura y de avance , es decir cada vez que lee algo lo elimina y pasa al siguiente//
            SqlDataReader lectura = comando.ExecuteReader();
            while (lectura.Read())
            {
               // lectura[0].ToString();//me traeria solo el nombre. siempre devuelve un obj porque puede ser cualq tipo de dato//
               // lectura["id"];//otra manera de devolver un valor//
                per.Add(new Persona(int.Parse(lectura[0].ToString()), lectura[1].ToString(),lectura[2].ToString(),int.Parse(lectura[3].ToString())));
            }

            lectura.Close();
            baseDeDato.Close();
           
            return per;
        }

        public override string ToString()
        {

            return this._id + "--" + this._nombre + "--" + this._apellido + "--" + this._edad + "\n"; 
        }


        public bool agregar()
        {
            bool flag = true;
            try
            {
                SqlConnection baseDeDato = new SqlConnection(Properties.Settings.Default.conexion);
                //abre la conexion//
                baseDeDato.Open();
                //es insdistinto mayuscula o minuscula//
                //si pongo personas solo en el nombre de la tabla lo toma igual//
                SqlCommand comando = new SqlCommand("INSERT INTO [Padron].[dbo].[Personas] (nombre,apellido,edad) VALUES ('" + this._nombre + "' ,'" + this._apellido + "','" + this._edad + "')", baseDeDato);
                int num = comando.ExecuteNonQuery();
                baseDeDato.Close();
            }
            catch
            {
                flag = false;
            }
            return flag;
        }

        public static bool Borrar(Persona per)
        {
            bool flag = true;
            int num;
            try
            {
                SqlConnection baseDeDato = new SqlConnection(Properties.Settings.Default.conexion);
                //abre la conexion//
                baseDeDato.Open();
                SqlCommand comando = new SqlCommand("DELETE from Personas WHERE id = " + per.Id , baseDeDato);
               
                num = comando.ExecuteNonQuery();
                baseDeDato.Close();
            }
            catch
            {
                flag = false;
            }

            return flag;
        }

        public bool Modificar()
        {
            bool flag = true;
            int num;
            try
            {
                SqlConnection baseDeDato = new SqlConnection(Properties.Settings.Default.conexion);
                //abre la conexion//
                baseDeDato.Open();
                SqlCommand comando = new SqlCommand("UPDATE Personas SET Nombre ='" + this._nombre +"' , Apellido ='" + this._apellido + "' , Edad= " + this._edad + " WHERE id = "+ this.Id, baseDeDato);
                num = comando.ExecuteNonQuery();
                baseDeDato.Close();
            }
            catch
            {
                flag = false;

            }
            return flag;
        }

        public static Persona TraerTodos(int id)
        {
            Persona per;
            try
            {
                SqlConnection baseDeDato = new SqlConnection(Properties.Settings.Default.conexion);
                //abre la conexion//
                baseDeDato.Open();
                // el * es lo mismo que pones id , nombre, apellido , edad//
                SqlCommand comando = new SqlCommand("SELECT * FROM Personas WHERE id= " + id, baseDeDato);
                SqlDataReader lectura = comando.ExecuteReader();
                lectura.Read();
                per = new Persona(id, lectura[1].ToString(), lectura[2].ToString(), int.Parse(lectura[3].ToString()));
                lectura.Close();
                baseDeDato.Close();
            }
            catch(Exception e)
            {
               
                per = null;
                
            }
            return per;
        }

        public static DataTable TraerTodosTabla()
        {
            
            DataTable data = new DataTable("Personas"); 
            //el namespace properties se crea cuando guardo la value en setting//
            SqlConnection baseDeDato = new SqlConnection(Properties.Settings.Default.conexion);
            //abre la conexion//
            baseDeDato.Open();
            //configo para poder pasarle comandos a la base de datos//
            SqlCommand comando = new SqlCommand("SELECT [id],[nombre],[apellido],[edad] FROM [Padron].[dbo].[Personas]", baseDeDato);
            //el sqldatareader no se puede instanciar , siempre le pasa el valor el execute reader//
            //es un objeto de solo lectura y de avance , es decir cada vez que lee algo lo elimina y pasa al siguiente//
            SqlDataReader lectura = comando.ExecuteReader();
            //lee todo el reader y crea um data row con los datos
            data.Load(lectura);
            lectura.Close();
            baseDeDato.Close();
           
            return data;
        }
    }
}
