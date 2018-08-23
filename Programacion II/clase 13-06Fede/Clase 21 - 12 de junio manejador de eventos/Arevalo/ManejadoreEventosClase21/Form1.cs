using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ManejadoreEventosClase21
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.btnAceptar.Click += new EventHandler(Calcular);
        }

        private void lblBilleteCienPesos_Click(object sender, EventArgs e)
        {

        }

        private void btnAceptar_Click(object sender, EventArgs e)
        {
            this.btnAceptar.Click -= new EventHandler(Calcular);
            this.btnLimpiar.Click += new EventHandler(btnLimpiar_Click);
        }

        private void Calcular(object sender, EventArgs e)
        {
            int cantidad;
            int.TryParse(this.txtCantidad.Text, out cantidad);
            int cantidadBilletes = 0;

            if (cantidad >= 100)
            {
                cantidadBilletes = cantidad / 100;
                this.txtBilleteCien.Text = cantidadBilletes.ToString();
                cantidad = cantidad % 100;
                
            }
            if (cantidad >= 50)
            {
                cantidadBilletes = cantidad / 50;
                this.txtBilleteCincuenta.Text = cantidadBilletes.ToString();
                cantidad = cantidad % 50;
            }
            if (cantidad >= 20)
            {
                cantidadBilletes = cantidad / 20;
                this.txtBilleteVeinte.Text = cantidadBilletes.ToString();
                cantidad =  cantidad % 20;
            }
            if (cantidad >= 10)
            {
                cantidadBilletes = cantidad / 10;
                this.txtBilleteDiez.Text = cantidadBilletes.ToString();
                cantidad = cantidad % 10;
            }
            if (cantidad >= 5)
            {
                cantidadBilletes = cantidad / 5;
                this.txtBilleteCinco.Text = cantidadBilletes.ToString();
                cantidad = cantidad % 5;
            }
            if (cantidad >= 2)
            {
                cantidadBilletes = cantidad / 2;
                this.txtBilleteDos.Text = cantidadBilletes.ToString();
                cantidad = cantidad % 2;
            }
            if (cantidad == 1)
            {
                MessageBox.Show("Su vuelto es de 1$", "Vuelto");
            }

            this.btnAceptar.Click += new EventHandler(Informar);
        }

        private void btnLimpiar_Click(object sender, EventArgs e)
        {
            this.txtCantidad.Text = "";
            this.txtBilleteVeinte.Text = "";
            this.txtBilleteDos.Text = "";
            this.txtBilleteDiez.Text = "";
            this.txtBilleteCincuenta.Text = "";
            this.txtBilleteCinco.Text = "";
            this.txtBilleteCien.Text = "";

            this.btnAceptar.Click += new EventHandler(Calcular);
            this.btnLimpiar.Click -= new EventHandler(btnLimpiar_Click);
            this.btnAceptar.Click -= new EventHandler(Informar);
        }

        private void btnSalir_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Informar(object sender, EventArgs e)
        {
            MessageBox.Show("Debe limpiar la pantalla para seguir operando", "Informacion");
        }
    }
}
