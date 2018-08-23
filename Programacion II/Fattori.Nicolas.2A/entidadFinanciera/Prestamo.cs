using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrestamosPersonales
{
    public enum PeriodicidadDePagos
    {
        Mensual,
        Bimestral,
        Trimestral
        
    }

    public enum TipoDePrestamo
    {
        Pesos,
        Dolares,
        Todos
    }

    public abstract class Prestamo
    {
        protected float monto;
        protected DateTime vencimiento;
//-----------------------------------------------------------------------//

        public float Monto
        {
            get { return this.monto; }
        }

        public DateTime Vencimiento 
        { 
            get
            {
                return this.vencimiento;
            }
            set
            {
                if (value < DateTime.Now)
                {
                    this.vencimiento = DateTime.Now;
                }
            }
        }
//----------------------------------------------------------------------//
        public abstract void ExtenderPlazo(DateTime nuevoVencimiento);
        
        
        public Prestamo(float monto, DateTime vencimiento)
        {
            this.monto = monto;
            this.Vencimiento = vencimiento;
        }

        public static int OrdenarPorFecha(Prestamo p1, Prestamo p2)
        {
            int rtn = -1;
            if (p1.vencimiento == p2.vencimiento)
            {
                rtn = 0;
            }
            else if (p1.vencimiento > p2.vencimiento)
            {
                rtn = 1;
            }
            return rtn;
        }

        public virtual string Mostrar()
        {
            return "Monto:" + this.monto + "\nVencimiento:" + this.vencimiento + "\n";
        }


    }
}
