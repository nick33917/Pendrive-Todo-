using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
namespace Entidades.SP
{
    [XmlInclude(typeof(DepositoHeredado))]
    [XmlInclude(typeof(Deposito))]
    public class Deposito
    {
        public Producto[] productos;
      //  private int cantidad;

        public Deposito() : this(3)
        {
        }

        public Deposito(int cant)
        {
            this.productos = new Producto[cant];
           // this.cantidad = cant;
        }



        

        public static Producto[] operator +(Deposito d1, Deposito d2)
        {
            Producto[] array = new Producto[d1.productos.Length + d2.productos.Length];
            d1.productos.CopyTo(array, 0);
            d2.productos.CopyTo(array, d1.productos.Length);

            for (int i = 0; i < d1.productos.Length; i++)
            {
                array[i] = d1.productos[i];
            }
            for (int i = d1.productos.Length; i < d2.productos.Length + d1.productos.Length; i++)
            {
                array[i] = d2.productos[i - d1.productos.Length];
            }

            for (int i = 0; i < array.Length - 1; i++)
            {
                for (int j = i + 1; j < array.Length; j++)
                {
                    if (array[i] != null && array[j] != null)
                    {
                        if (array[i] == array[j])
                        {
                            array[i].stock += array[j].stock;
                            array[j] = null;
                        }
                    }
                }
            }

            return array;

            // int cantidad = d1.cantidad + d2.cantidad;
           //int stock, count=0;
           //bool flag = false;
           //Producto p;
           //Producto[] aux = new Producto[cantidad];
           //for (int i = 0; i < d1.cantidad; i++){
           //    stock = d1.productos[i].stock;
           //    for (int j = 0; j < d2.cantidad; j++) {
           //        if (d1.productos[i].nombre == d2.productos[j].nombre) { //sobrecarge igualdad en Producto
           //            stock += d2.productos[j].stock;
           //        }
           //    }
           //    p = new Producto(d1.productos[i].nombre, stock);
           //    aux[count] = p;
           //    count++;
           //}
           //for (int i = 0; i < d2.cantidad; i++)
           //{
           //    for (int j = 0; j < d1.cantidad; j++)
           //    {
           //        if (d2.productos[i].nombre == d1.productos[j].nombre)
           //        { //sobrecarge igualdad en Producto
           //            flag = true;
           //            break;
           //        }
           //    }
           //    if (!flag)
           //    {
           //        p = new Producto(d2.productos[i].nombre, d2.productos[i].stock);
           //        aux[count] = p;
           //        count++;
           //    }
           //    else
           //    {
           //        flag = false;
           //    }
           //}
           //return aux;
       }
   }
}


            //int cant = d1.cantidad + d2.cantidad;
            //Producto[] aux = new Producto[cant];
            //Producto[] aux2 = new Producto[cant];
            //for (int i = 0; i < d1.cantidad; i++)
            //{
            //    aux[i] = d1.productos[i];
            //}

            //for (int i = 0; i < d2.cantidad; i++)
            //{
            //    for (int j = 0; j < aux.Length; j++)
            //    {
            //        if (aux[j] == null)
            //        {
            //            aux[j] = d1.productos[i];
            //            break;
            //        }
            //    }
            //}
            //for (int i = 0; i < aux2.Length; i++)
            //{
            //    for (int j = 0; i < aux.Length; j++)
            //    {
            //        for (int k = 1; j < aux.Length -1; k++)
            //        {
            //            if (aux[j].nombre == aux[k].nombre)
            //            {
            //                aux[j].stock += aux[k].stock;
            //            }
            //        }
            //        aux2[i] = aux[j];
            //    }
            //}

            //return aux;


        
