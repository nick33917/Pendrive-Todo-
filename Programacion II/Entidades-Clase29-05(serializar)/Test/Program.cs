using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Entidades_Clase29_05;
using System.IO;
using System.Xml;
using System.Xml.Serialization;
namespace Test
{
    public class Program
    {
        public static bool GuardarXml(string str, Alumno alum)
        {
            bool rtn = true;
            try
            {
                XmlTextWriter texto = new XmlTextWriter(str, Encoding.UTF8);
                XmlSerializer serializar = new XmlSerializer(typeof(Alumno));
                serializar.Serialize(texto, alum);
                texto.Close();
            }
            catch
            {
                rtn = false;

            }
            return rtn;

         }

        public static bool LeerXml(string str, out Alumno alum)
        {
            bool rtn = true;
            alum = null;
            try
            {
                XmlTextReader texto = new XmlTextReader(str);
                //serializa solo un unico tipo de dato//
                XmlSerializer serializar = new XmlSerializer(typeof(Alumno));
                alum = (Alumno)serializar.Deserialize(texto);
                texto.Close();
                
            }
            catch
            {
                rtn = false;
            }
            return rtn;

        }
        static void Main(string[] args)
        {
            Aula aula1 = new Aula(3);
            Alumno alum1 = new Alumno("nicolas", "fattori", 38839471, 1);
            Alumno alum2 = new Alumno("jose", "sand", 20954997, 2);
            Profesor prof1 = new Profesor("hola", "holas", 123456, "profesor");
            aula1.Lista.Add(alum1);
            aula1.Lista.Add(alum2);
            aula1.Lista.Add(prof1);
            Console.WriteLine(aula1);
/*
            if (Program.GuardarXml("aula.xml", alum1))
            {
                Console.WriteLine("Guardado");
            }
            else
            {
                Console.WriteLine("No lo guardo");

            }
            Console.ReadLine();
            Alumno buffer = new Alumno();
            if (Program.LeerXml("aula.xml",out buffer))
            {
                Console.WriteLine(buffer);
            }
 
            else
            {
                Console.WriteLine("No lo pudo leer");

            }

            Console.ReadLine();

*/
  /*          Xml<Alumno> var = new Xml<Alumno>();
            if (var.GuardarXml("aula.xml", alum2))
            {
                Console.WriteLine("Guardado");
            }
            else
            {
                Console.WriteLine("No lo guardo");

            }
            Console.ReadLine();
*/
/*            List<Alumno> alumnos = new List<Alumno>();
            alumnos.Add(alum1);
            alumnos.Add(alum2);

            Xml<List<Alumno>> vars = new Xml<List<Alumno>>();
            if (vars.GuardarXml("aula.xml",alumnos))
            {
                Console.WriteLine("Guardado");
            }
            else
            {
                Console.WriteLine("No lo guardo");

            }
            Console.ReadLine();
  */
/*
            List<Persona> personas = new List<Persona>();
            personas.Add(alum1);
            personas.Add(alum2);
            personas.Add(prof1);
            Xml<List<Persona>> listas = new Xml<List<Persona>>();
            if (listas.GuardarXml("aula.xml",personas))
            {
                Console.WriteLine("Guardado");
            }
            else
            {
                Console.WriteLine("No lo guardo");

            }
            Console.ReadLine();
*/

            Xml<Aula> xmlAula = new Xml<Aula>();
            if (xmlAula.GuardarXml("aula.xml", aula1))
            {
                Console.WriteLine("Guardado");
            }
            else
            {
                Console.WriteLine("No lo guardo");

            }
            Console.ReadLine();



        }
    }
}
