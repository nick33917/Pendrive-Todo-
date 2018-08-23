using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Clase9Herencia
{
    public class Vehiculo
    {
        protected string _patente;
        protected byte _cantRuedas;
        protected EMarcas _marca;
    

    public string Patente 
    {
        get{return this._patente;}
        
    }

    public EMarcas Marca
    {
        get{return this._marca;}
    }



    protected string Mostrar()
    {
        return "Patente:" + this._patente + "\n" + "CantRuedas:" + this._cantRuedas + "\n" + "Marca:" + this._marca + "\n";

    }

    public Vehiculo(string patente, byte cantRuedas, EMarcas marca)
    {
        this._patente = patente;
        this._cantRuedas = cantRuedas;
        this._marca = marca;
    }

    public static bool operator ==(Vehiculo vehiculo1, Vehiculo vehiculo2)
    {
        bool rtn = false;
        if (vehiculo1._patente == vehiculo2._patente && vehiculo1._marca == vehiculo2._marca)
        {
            rtn = true;
        }
        return rtn;

    }
    public static bool operator !=(Vehiculo vehiculo1, Vehiculo vehiculo2)
    {
        return !(vehiculo1 == vehiculo2);
    }


    }
}
