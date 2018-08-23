using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrestamosPersonales
{
    public class PrestamoDolar : Prestamo
    {
        private PeriodicidadDePagos _periodicidad;
//---------------------------------------------------------------------//
        public float Interes
        {
            get { return CalcularInteres(); }
        }

        public PeriodicidadDePagos Periodicidad
        {
            get { return this._periodicidad; }
        }
//-----------------------------------------------------------------------//
        private float CalcularInteres()
        {
            float resultado = 0;
            switch (this._periodicidad)
            {
                case PeriodicidadDePagos.Mensual:
                    resultado = base.monto * 0.25f;
                    break;
                case PeriodicidadDePagos.Bimestral:
                    resultado = base.monto * 035f;
                    break;
                case PeriodicidadDePagos.Trimestral:
                    resultado = base.monto * 0.40f;
                    break;
                
            }
            return resultado;

        }

        public override void ExtenderPlazo(DateTime nuevoVencimiento)
        {
            TimeSpan dias = nuevoVencimiento - base.vencimiento;
            int cant = dias.Days;
            float interes = cant * 2.5f;
            base.monto += interes;
            base.vencimiento = nuevoVencimiento;
        }

        public override string Mostrar()
        {
            StringBuilder muestra = new StringBuilder();
            muestra.Append(base.Mostrar());
            muestra.Append("Periodicidad: ");
            muestra.Append(this._periodicidad);
            muestra.Append("\nTotalDelPrestamo: ");
            muestra.Append(this.Interes);
            muestra.Append("\n");
            return muestra.ToString();
        }

        public PrestamoDolar (float monto, DateTime vencimiento, PeriodicidadDePagos periodicidad) 
            : base(monto,vencimiento)
        {
            this._periodicidad = periodicidad;
            
        }

        public PrestamoDolar(Prestamo prestamo, PeriodicidadDePagos periodicidad) 
            : this(prestamo.Monto,prestamo.Vencimiento,periodicidad)
        {

        }
    }
}
