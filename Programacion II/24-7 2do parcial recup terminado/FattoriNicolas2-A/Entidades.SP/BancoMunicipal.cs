using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades.SP
{
    public class BancoMunicipal : BancoProvincial
    {
        public string municipio;

        public BancoMunicipal(BancoProvincial bp, string municipio)
            : base(new BancoNacional(bp.nombre, bp.pais), bp.provincia)
        {
            this.municipio = municipio;
        }

        public override string ToString()
        {
            return base.Mostrar(this);
        }
    }
}
