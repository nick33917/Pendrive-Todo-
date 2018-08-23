using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades_Clase29_05
{
   public class Aula
    {
       private int _numero;
       private List<Persona> _lista;

       public List<Persona> Lista { get { return this._lista; } }
       public int Numero { get { return this._numero; } set {this._numero=value;} }

       public Aula()
       {
           this._lista = new List<Persona>(); 
       }

       public Aula(int numero)
           : this()
       {
           this._numero = numero;
       }

       public override string ToString()
       {
           string s="";
           foreach (Persona per in this._lista)
           {
               if (per is Alumno)
               {
                   s += ((Alumno)per).ToString();
                   s += "\n";
                }
               else if (per is Profesor)
               {
                   s += ((Profesor)per).ToString();
                   s+="\n" ;
               }
           }
           return s;
       }
    }
}
