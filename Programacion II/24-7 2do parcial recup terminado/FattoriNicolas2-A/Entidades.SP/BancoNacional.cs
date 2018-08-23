using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades.SP
{
    public class BancoNacional : Banco
    {
        public string pais;

        public BancoNacional(string nombre, string pais)
            : base(nombre)
        {
            this.pais = pais;
        }

        public override string Mostrar()
        {
            return this.nombre;
        }

        public override string Mostrar(Banco b)
        {
            string cadena="" ;
            if (b is BancoMunicipal)
            {
                cadena +=  ((BancoMunicipal)b).pais + "---" + ((BancoMunicipal)b).provincia + "---" + ((BancoMunicipal)b).municipio;
            }
            else if (b is BancoProvincial)
            {
                cadena += ((BancoProvincial)b).pais + "---" + ((BancoProvincial)b).provincia;
            }
            else if (b is BancoNacional)
            {
                cadena +=  this.pais;
            }
            
            return cadena;
        }

        public override string ToString()
        {
            return this.Mostrar(this);
        }
    }
}
