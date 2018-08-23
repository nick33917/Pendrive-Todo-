using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Entidades_Clase7;
namespace Equipo_Jugadores_Form
{
    public partial class FrmEquipo : Form
    {
        public FrmEquipo()
        {
            InitializeComponent();
        }

        private Equipo _equipo;

        private void btnAceptar_Click(object sender, EventArgs e)
        {
            string nombre = txtNombre.Text;
            short cantidad = short.Parse(txtCantJug.Text);
            this._equipo = new Equipo(cantidad, nombre);
            this.txtNombre.Enabled = false;
            this.txtCantJug.Enabled = false;
            this.btnAceptar.Visible = false;
            this.btnCancelar.Visible = false;

            this.btnMas.Visible = true;
            this.txtListBox.Visible = true;
        }

        private void btnMas_Click(object sender, EventArgs e)
        {

        }
    }
}
