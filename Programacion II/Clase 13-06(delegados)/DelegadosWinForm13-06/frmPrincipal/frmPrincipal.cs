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
            TestDelegados.Show();
        }

        private void alumnoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            frmDatos Datos = new frmDatos();
            Datos.Show();
        }

    }
}
