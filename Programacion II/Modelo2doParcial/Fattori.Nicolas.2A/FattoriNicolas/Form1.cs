using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Entidades;
using Interfaces;

namespace FattoriNicolas
{
    public partial class Form1 : Form
    {
        public LosHilos hilos;

        public Form1()
        {
            InitializeComponent();
            this.hilos = new LosHilos();
            // this.hilos.AvisoFin += this.MostrarMensajeFin;
            //relaciono el evento: avisoFin con el metodo mostrarMensajeFin
            this.hilos.AvisoFin += this.MostrarMensajeFin;
        }

        public void MostrarMensajeFin(string msj)
        {
            MessageBox.Show(msj);
        }

        private void btnLanzar_Click(object sender, EventArgs e)
        {
            try
            {
                //tambien puede quedar this.hilos += +1;
                //agrego un hilo mas por cada vez que apreto el boton lanzar 
                this.hilos = this.hilos + 1;
            }
            catch(CantidadInvalidaException)
            {
                MessageBox.Show("Cantidad Invalida");
               
            }
        }

        private void btnBitacora_Click(object sender, EventArgs e)
        {
            MessageBox.Show(this.hilos.Bitacora);
        }

    }
}
