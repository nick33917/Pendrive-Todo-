using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Clase9Herencia
{
    public class Lavadero
    {
        private List<Vehiculo> _vehiculos;
        private float _precioAuto;
        private float _precioCamion;
        private float _precioMoto;

        public Lavadero(float precioAuto, float precioCamion, float PrecioMoto)
            : this()
        {
            this._precioAuto = precioAuto;
            this._precioCamion = precioCamion;
            this._precioMoto = PrecioMoto;

        }
        private Lavadero()
        {
            this._vehiculos = new List<Vehiculo>();
        }

        public string GetLavadero
        {
            get
            {
                string s = "PrecioAuto:" + this._precioAuto + "---" + "PrecioCamion:" + this._precioCamion + "---" + "PrecioMoto:" + this._precioMoto + "\n\n";
                foreach (Vehiculo v in this._vehiculos)
                {
                    s += v.ToString() + "\n" +v.Acelerar() + "\n";
                    
                }
                return s;
            }
        }

        public List<Vehiculo> GetVehiculos
        {
            get { return this._vehiculos; }
        }

        public double MostrarTotalFacturado()
        {
            return this.MostrarTotalFacturado(EVehiculos.Auto) + this.MostrarTotalFacturado(EVehiculos.Camion) + this.MostrarTotalFacturado(EVehiculos.Moto);


        }
        public double MostrarTotalFacturado(EVehiculos vehiculos)
        {
            double facturado = 0;
            int contAuto = 0;
            int contMoto = 0;
            int contCamion = 0;
            foreach (Vehiculo v in this._vehiculos)
            {
                if (v is Auto)
                {
                    contAuto++;
                }
                else if (v is Moto)
                {
                    contMoto++;

                }
                else if (v is Camion)
                {
                    contCamion++;

                }

            }

            switch (vehiculos)
            {
                case EVehiculos.Camion:
                    facturado = this._precioCamion * contCamion;
                    break;

                case EVehiculos.Auto:
                    facturado = this._precioAuto * contAuto;
                    break;

                case EVehiculos.Moto:
                    facturado = this._precioMoto * contMoto;
                    break;


            }

            return facturado;
        }

        public static bool operator ==(Lavadero objLavadero, Vehiculo objVehiculo)
        {
            bool rtn = false;
            foreach (Vehiculo v in objLavadero._vehiculos)
            {
                if (v == objVehiculo)
                {
                    rtn = true;
                    break;
                }
            }
            return rtn;
        }
        public static bool operator !=(Lavadero objLavadero, Vehiculo objVehiculo)
        {
            return !(objLavadero == objVehiculo);
        }

        public static Lavadero operator +(Lavadero objLavadero, Vehiculo objVehiculo)
        {
            if (objLavadero != objVehiculo)
            {
                objLavadero._vehiculos.Add(objVehiculo);
            }
            return objLavadero;

        }

        public static Lavadero operator -(Lavadero objLavadero, Vehiculo objVehiculo)
        {
            if (objLavadero == objVehiculo)
            {
                objLavadero._vehiculos.Remove(objVehiculo);
            }
            return objLavadero;
        }
        //para accederlo es lavadero.ordenarVehiculosPorPatente();
        public static int OrdenarVehiculosPorPatente(Vehiculo obj1, Vehiculo obj2)
        {
            int rtn = string.Compare(obj1.Patente, obj2.Patente);
            return rtn;
        }
        /*para accederlo es:
        lavadero lava =new lavadero();
         lava.OrdenarVehiculosPorMarca();
         */
        public  int OrdenarVehiculosPorMarca(Vehiculo obj1, Vehiculo obj2)
        {
            int rtn = string.Compare(obj1.Marca.ToString(), obj2.Marca.ToString());
            return rtn;

        }

      
    }
}
