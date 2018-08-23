using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrestamosPersonales
{
    public class PrestamoPesos : Prestamo
    {
        private float _porcentajeInteres;
//-----------------------------------------------------//
  
        public float Interes
        {
            get { return this.CalcularInteres(); }
        }

 //----------------------------------------------//

        private float CalcularInteres()
        {
            float rtn;
            rtn = base.monto * this._porcentajeInteres;
            return rtn; 
        }

        public override void ExtenderPlazo(DateTime nuevoVencimiento)
        {
            
            TimeSpan dias = nuevoVencimiento - base.vencimiento;
            int cant = dias.Days;
            float interes = cant * 0.25f;
            this._porcentajeInteres += interes;
            base.vencimiento = nuevoVencimiento;
        }
        

        public override string Mostrar()
        {
            StringBuilder muestra = new StringBuilder();
            muestra.Append(base.Mostrar());
            muestra.Append("PorcentajeDeIntereses: ");
            muestra.Append(this._porcentajeInteres);
            muestra.Append("\nTotalDelPrestamo: ");
            muestra.Append(this.Interes);
            muestra.Append("\n");
            return muestra.ToString();

        }

        public PrestamoPesos(float monto, DateTime vencimiento, float interes) 
            : base(monto , vencimiento)
        {
            this._porcentajeInteres = interes;
        }

        public PrestamoPesos(Prestamo prestamo, float porcentajeInteres)
            : this(prestamo.Monto, prestamo.Vencimiento, porcentajeInteres)
        {
        }



    }
}
