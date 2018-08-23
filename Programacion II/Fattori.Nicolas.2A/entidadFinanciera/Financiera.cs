using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



namespace entidadFinanciera
{
    using PrestamosPersonales;

    public class Financiera
    {
        private List<Prestamo> _listaDePrestamos;
        private string _razonSocial;
        //---------------------------------------------//

        public float InteresesEnDolar
        {
            get
            {
                float acum = 0;
                foreach (Prestamo prest in this._listaDePrestamos)
                {
                    if (prest is PrestamoDolar)
                    {
                        acum += prest.Monto;
                    }
                }
                return acum;
            }
        }

        public float InteresesEnPesos
        {
            get
            {
                float acum = 0;
                foreach (Prestamo prest in this._listaDePrestamos)
                {
                    if (prest is PrestamoPesos)
                    {
                        acum += prest.Monto;
                    }
                }
                return acum;
            }
        }

        public float InteresesTotales
        {
            get
            {
                float acumPesos = 0;
                float acumDolar = 0;
                float rtn;
                foreach (Prestamo prest in this._listaDePrestamos)
                {
                    if (prest is PrestamoPesos)
                    {
                        acumPesos += prest.Monto;
                    }
                    else if (prest is PrestamoDolar)
                    {
                        acumDolar += prest.Monto;
                    }

                }
                rtn = acumPesos + (acumDolar * 21);
                return rtn;
            }
        }

        public List<Prestamo> ListaDePrestamos
        {
            
            get 
            {
                List<Prestamo> Lista = new List<Prestamo>();
                return Lista ; 
            }
        }

        public string RazonSocial
        {
            get { return this._razonSocial; }
        }

        //-------------------------------------------------------------------//

        private float CalcularInteresGanado(TipoDePrestamo tipoPrestamo)
        {
            float rtn = 0;
            if (tipoPrestamo == TipoDePrestamo.Pesos)
            {
                rtn = this.InteresesEnPesos;
            }
            else if (tipoPrestamo == TipoDePrestamo.Dolares)
            {
                rtn = this.InteresesEnDolar;
            }
            else if (tipoPrestamo == TipoDePrestamo.Todos)
            {
                rtn = this.InteresesTotales;
            }

            return rtn;
        }

        public static explicit operator string(Financiera financiera)
        {
            StringBuilder muestra = new StringBuilder();
            muestra.Append("RazonSocial: ");
            muestra.Append(financiera._razonSocial);
            muestra.Append("\nInteresesTotalesGanados: ");
            muestra.Append(financiera.InteresesTotales);
            muestra.Append("\nInteresesPorPrestamosEnPesos: ");
            muestra.Append(financiera.InteresesEnPesos);
            muestra.Append("\nInteresesPorPrestamosEnDolares: ");
            muestra.Append(financiera.InteresesEnDolar);

            financiera._listaDePrestamos.Sort(Prestamo.OrdenarPorFecha);
            foreach (Prestamo prest in financiera._listaDePrestamos)
            {
                if(prest is PrestamoPesos)
                {
                    muestra.Append("\n\t------------PrestamosEnPesos------------\n");
                    muestra.Append(((PrestamoPesos)prest).Mostrar());
                }
                else if(prest is PrestamoDolar)
                {
                    muestra.Append("\n\t------------PrestamosEnDolar------------\n");
                    muestra.Append(((PrestamoDolar)prest).Mostrar());
                }
            }
            return muestra.ToString();
        }
         
        

        private Financiera()
        {
            this._listaDePrestamos = new List<Prestamo>();
        }

        public Financiera(string razonSocial) : this()
        {
            this._razonSocial = razonSocial;
        }

        public static string Mostrar(Financiera financiera)
        {
            return (string)financiera;
        }

        public static bool operator !=(Financiera financiera, Prestamo prestamo)
        {
            return true;
        }

        public static bool operator ==(Financiera financiera, Prestamo prestamo)
        {
            return true;
        }

        public static Financiera operator +(Financiera financiera, Prestamo prestamoNuevo)
        {
            financiera._listaDePrestamos.Add(prestamoNuevo);
            return financiera;
        }

        public void OrdenarPrestamos()
        {
            this._listaDePrestamos.Sort(Prestamo.OrdenarPorFecha);

        }



    }
}
