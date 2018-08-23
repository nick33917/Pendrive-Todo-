﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Entidades;
using System.Data;
using System.Data.SqlClient;
namespace Programm
{
    public delegate string ListadoDB (ISerializable obj);

    public class Program
    {
        private static bool Deserializar(ISerializable obj)
        {
           return obj.DeserealizarXml();

        }

        private string ObtenerPrecioDB(ISerializable obj)
        {
            string cadena = ""; 
            
            try
            {
                SqlConnection baseDeDato = new SqlConnection(Properties.Settings.Default.conexion);
                baseDeDato.Open();
                SqlCommand comando = new SqlCommand("SELECT * FROM [Precios].[dbo].[PreciosFruta] ", baseDeDato);
                SqlDataReader lectura = comando.ExecuteReader();
                while (lectura.Read())
                {
                    cadena += int.Parse(lectura[0].ToString() + lectura[1].ToString() + int.Parse(lectura[2].ToString()) + "\n");
                }
                lectura.Close();
                baseDeDato.Close();
            }
            catch (Exception e)
            {

               
            }
            return cadena;
        }

        private static bool Serializar(ISerializable obj)
        {
            return obj.SerializarXml();
        }

        static void Main(string[] args)
        {
            Cajon<Fruta> cajon = new Cajon<Fruta>(3, 15.36f);
            Cajon<Platano> cajonplatanos = new Cajon<Platano>(4, 13.5f);
            Manzana m1 = new Manzana(15.0f, ConsoleColor.Red, "Moño Azul");
            Manzana m2 = new Manzana(22.06f, ConsoleColor.Magenta, "Parajes pampeanos");
            Manzana m3 = new Manzana(5.5f, ConsoleColor.DarkYellow, "El abuelo");
            Platano p1 = new Platano(4.8f, ConsoleColor.Yellow, "Ecuador");
            Platano p2 = new Platano(21.7f, ConsoleColor.DarkYellow, "Colombia");
            Platano p3 = new Platano(16.99f, ConsoleColor.Yellow, "Brasil");

            try
            {
                cajon += m1;
                cajon += m2;
                cajon += p1;
                cajon += p2;
                cajon += m3;
            }
            catch (Exception exc)
            {
                Console.WriteLine(exc.Message);
            }

            Console.WriteLine(cajon);
	    //EVENTOS
            Console.WriteLine(cajon.PrecioTotal);

            try
            {
                cajonplatanos += p1;
                cajonplatanos += p2;
                cajonplatanos += p3;
            }
            catch (Exception e)
            {
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine(e.Message.ToString());
                Console.ForegroundColor = ConsoleColor.Green;
            }

            //SERIALIZAR CAJON        
            cajon.RutaArchivo = "cajon.xml";

            if (Program.Serializar(cajon))
                Console.WriteLine("Serializado correctamente.");
            else
                Console.WriteLine("Error al serializar.");

            //SERIALIZAR MANZANA            
            m2.RutaArchivo = "manzana.xml";

            if (Program.Serializar(m2))
            {
                Console.WriteLine("Manzana serializada correctamente.");
            }
            else
            {
                Console.WriteLine("Error al serializar Manzana.");
            }

            //DESERIALIZAR CAJON
            if (Program.Deserializar(cajon))
                Console.WriteLine(" > Cajon deserializado correctamente.");
            else
                Console.WriteLine(" > Error al deserializar Cajon.");

            //DESERIALIZAR MANZANA
            if (Program.Deserializar(m2))
                Console.WriteLine(" > manzana deserializada correctamente.");
            else
                Console.WriteLine(" > Error al deserializar manzana.");

            //BASE DE DATOS
            Program prog = new Program();
            ListadoDB dele = new ListadoDB(prog.ObtenerPrecioDB);

            Console.WriteLine(dele.Invoke(cajon));

            Console.ReadLine();
        }
      }
}

