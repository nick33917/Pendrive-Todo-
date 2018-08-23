using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
    public class Centralita
    {
        #region Atributos

        private List<Llamada> _listaDeLlamadas;
        protected string _razonSocial;

        #endregion

        #region Constructores

        public Centralita(string nombreEmpresa)
        {
            this._razonSocial = nombreEmpresa;
            this._listaDeLlamadas = new List<Llamada>();
        }
        public Centralita()
            : this("")
        {
        }

        #endregion


        #region Propiedades

        public float GananciaTotal
        {
            get { return this.CalcularGanancia(TipoLlamada.Todas); }
        }

        public float GananciaPorLocal
        {
            get { return this.CalcularGanancia(TipoLlamada.Local); }
        }

        public float GananciaPorProvincial
        {
            get { return this.CalcularGanancia(TipoLlamada.Provincial); }
        }

        public List<Llamada> Llamadas
        {
            get { return this._listaDeLlamadas; }
        }

        #endregion

        #region Metodos

        private float CalcularGanancia(TipoLlamada tipo)
        {
            float acumLocal = 0;
            float acumProvincial = 0;
            float ganancia = 0;
            foreach (Llamada llam in this._listaDeLlamadas)
            {
                if (llam is Local)
                {
                    acumLocal += ((Local)llam).CostoLlamada;
                }
                else if (llam is Provincial)
                {
                    acumProvincial += ((Provincial)llam).CostoLlamada;
                }
            }

            switch (tipo)
            {
                case TipoLlamada.Local:
                    ganancia = acumLocal;
                    break;
                case TipoLlamada.Provincial:
                    ganancia = acumProvincial;
                    break;
                case TipoLlamada.Todas:
                    ganancia = acumLocal + acumProvincial;
                    break;
                default:
                    break;
            }

            return ganancia;

        }

        public void Mostrar()
        {
            Console.WriteLine("\t\tNombre empresa:" + this._razonSocial + "\nGananciaTotal:" + this.CalcularGanancia(TipoLlamada.Todas) + "\nGananciaPorLocales:" + this.CalcularGanancia(TipoLlamada.Local) + "\nGananciaPorProvinciales:" + this.CalcularGanancia(TipoLlamada.Provincial) + "\n\n\t\tDetalle de llamadas:");
            foreach (Llamada llam in this._listaDeLlamadas)
            {
                llam.Mostrar();
                Console.WriteLine("\n");
            }

        }

        #endregion
    }
}
