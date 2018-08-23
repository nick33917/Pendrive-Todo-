using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace frmPrincipal
{
    public delegate void Delegado(string mensaje);

    public partial class frmPrincipal : Form
    {
        public event Delegado Delegado;

        public frmPrincipal()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void testDelegadosToolStripMenuItem_Click(object sender, EventArgs e)
        {
            frmTestDelegados TestDelegados = new frmTestDelegados();
            TestDelegados.Show(this);//El formulario principal se convierte en el owner

            //thisowner -> Form, para acceder al delegado desde el formulario test delegados.
            //Hay que castear el thisowner a Formulario, para acceder al delegado.

            this.Delegado = new Delegado(TestDelegados.
        }

        private void alumnoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            frmDatos Datos = new frmDatos();
            Datos.Show();
        }

    }
}
