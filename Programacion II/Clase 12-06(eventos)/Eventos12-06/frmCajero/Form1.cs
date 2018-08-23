using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace frmCajero
{
    public partial class frmCajeroAutomatico : Form
    {
        public frmCajeroAutomatico()
        {
            InitializeComponent();

            this.Load += new EventHandler(Inicializar);
        }

        private void Inicializar(object sender, EventArgs e)
        {
            this.btnAceptar.Click += new EventHandler(Calcular);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void txtBilleteDe5_TextChanged(object sender, EventArgs e)
        {

        }

        private void Calcular(object sender, EventArgs e)
        {
            int retirar = int.Parse(this.txtCantidadARetirar.Text);

            int contadorDe2 = 0;
            int contadorDe5 = 0;
            int contadorDe10 = 0;
            int contadorDe20 = 0;
            int contadorDe50 = 0;
            int contadorDe100 = 0;

            while (retirar >= 100)
            {
                retirar -= 100;
                contadorDe100++;
            }

            while (retirar >= 50)
            {
                retirar -= 50;
                contadorDe50++;
            }

            while (retirar >= 20)
            {
                retirar -= 20;
                contadorDe20++;
            }

            while (retirar >= 10)
            {
                retirar -= 10;
                contadorDe10++;
            }

            while (retirar >= 5)
            {
                retirar -= 5;
                contadorDe5++;
            }

            while (retirar >= 2)
            {
                retirar -= 2;
                contadorDe2++;
            }

            this.txtBilleteDe2.Text = contadorDe2.ToString();
            this.txtBilleteDe5.Text = contadorDe5.ToString();
            this.txtBilleteDe10.Text = contadorDe10.ToString();
            this.txtBilleteDe20.Text = contadorDe20.ToString();
            this.txtBilleteDe50.Text = contadorDe50.ToString();
            this.txtBilleteDe100.Text = contadorDe100.ToString();

            if (retirar > 0)
            {
                MessageBox.Show("Le queda 1$ Peso", "Vuelto");
            }

        }

        private void btnAceptar_Click(object sender, EventArgs e)
        {
            this.btnAceptar.Click -= new EventHandler(Calcular);
            this.btnLimpiar.Click += new EventHandler(Limpiar);
            this.btnAceptar.Click -= new EventHandler(Informar);
            this.btnAceptar.Click += new EventHandler(Informar);
        }

        private void Limpiar(object sender, EventArgs e)
        {
            foreach (Control n in this.Controls)
            {
                if (n is Button)
                {
                    if (n == this.btnAceptar)
                    {
                        n.Click += new EventHandler(Calcular);
                        n.Click -= new EventHandler(Informar);
                    }
                    
                }

                if (n is GroupBox)
                {
                    foreach(Control m in n.Controls)
                    {
                        if(m is TextBox)
                        {
                            ((TextBox)m).Clear();
                        }
                    }
                }
            }

        }

        private void Informar(object sender, EventArgs e)
        {
            MessageBox.Show("Debe limpiar la pantalla para seguir operando", "Información");
        }

        private void btnLimpiar_Click(object sender, EventArgs e)
        {
        }


    }
}
