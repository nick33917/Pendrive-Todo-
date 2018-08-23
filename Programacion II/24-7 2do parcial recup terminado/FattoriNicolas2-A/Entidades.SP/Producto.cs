using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades.SP
{
    public class Producto
    {
        public string nombre;
        public int stock;

        public Producto(string nombre, int stock)
        {
            this.nombre = nombre;
            this.stock = stock;
        }
        public Producto()
        {
            this.nombre = "sin nombre";
            this.stock = 0;
        }
    }
}
