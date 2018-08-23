using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FrmEjercicioClase22
{
    public partial class FrmDatos : Form
    {
        public FrmDatos()
        {
            InitializeComponent();
        }

        private void FrmDatos_Load(object sender, EventArgs e)
        {

        }

        public void ActualizarNombre(string texto)
        {
            this.lblTexto.Text = texto;
        }

        public void ActualizarFoto(string texto)
        {
            this.ptbFoto.ImageLocation = texto;
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }
    }
}
