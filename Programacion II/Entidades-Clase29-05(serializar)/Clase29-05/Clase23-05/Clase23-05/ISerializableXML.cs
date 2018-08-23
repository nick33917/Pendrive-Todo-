using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Clase23_05
{
    public interface ISerializableXML
    {
        void Serializar();
        Jugador Deserializar();
    }
}
