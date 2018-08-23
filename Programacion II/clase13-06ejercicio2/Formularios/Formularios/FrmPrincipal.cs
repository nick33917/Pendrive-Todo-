using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Formularios
{
    public delegate void DelegadoActualizarNombre(string msj);
    public partial class FrmPrincipal : Form
    {

        public DelegadoActualizarNombre nom;
        public FrmPrincipal()
        {
            InitializeComponent();
        }

        private void testDelegadoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FrmTestDelegados form = new FrmTestDelegados();
            form.Show(this);
        }

        private void mostrarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FrmDatos form = new FrmDatos();
            this.nom = new DelegadoActualizarNombre(form.ActualizarNombre);
            //hace que el formulario principal sea visible , sigue haciendo foco al principal //
            form.Show(this);
            //si hago this.owner en el formulario datos voy a poder acceder a la instancia del frmprincipal//
        }
    }
}
