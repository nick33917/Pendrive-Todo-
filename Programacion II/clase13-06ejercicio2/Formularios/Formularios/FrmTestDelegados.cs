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
    public partial class FrmTestDelegados : Form
    {
        public FrmTestDelegados()
        {
            InitializeComponent();
        }

        private void txtVisor_TextChanged(object sender, EventArgs e)
        {

        }

        private void btnActualizar_Click(object sender, EventArgs e)
        {
            string msj = this.txtVisor.Text;
            ((FrmPrincipal)this.Owner).nom(msj);
        }


    }
}
