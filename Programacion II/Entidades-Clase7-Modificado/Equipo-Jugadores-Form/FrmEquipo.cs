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
        private Jugador jug;
        bool flag;
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
            this.btnMenos.Visible = true;
            this.button1.Visible= true;
        }

        private void btnMas_Click(object sender, EventArgs e)
        {
            FrmJugador miFormulario = new FrmJugador();
            miFormulario.ShowDialog();

            if (miFormulario.DialogResult == System.Windows.Forms.DialogResult.OK)
            {

                jug = miFormulario.getJugador();

                flag = this._equipo + jug;
                if (flag)
                {
                    MessageBox.Show("Lo agrego correctamente");
                    this.AgregarYMostrar();
                }
                else
                {
                    MessageBox.Show("No lo pudo agregar");
                }
            }
        }

        private void AgregarYMostrar()
        {
            List<Jugador> list = this._equipo.GetJugadores();
            this.txtListBox.Items.Clear();
            for (int i = 0; i < list.Count; i++)
            {
                this.txtListBox.Items.Add(list[i].MostrarDatos());
            }


        }

        private void btnMenos_Click(object sender, EventArgs e)
        {
            bool flag = false;
            int indice = this.txtListBox.SelectedIndex;
            if (indice > -1)
            {
                List<Jugador> list = this._equipo.GetJugadores();
                DialogResult devuelve = MessageBox.Show("Desea eliminar a el siguiente jugador : " + list[indice].MostrarDatos(), "Mensaje", MessageBoxButtons.OKCancel, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2);
                if (devuelve == DialogResult.OK)
                {
                    flag = this._equipo - list[indice];
                    if (flag)
                    {
                        this.txtListBox.Items.Clear();
                        this.AgregarYMostrar();
                    }
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            bool flag = false;
            int indice = this.txtListBox.SelectedIndex;
            if (indice > -1)
            {
                List<Jugador> list = this._equipo.GetJugadores();
                DialogResult devuelve = MessageBox.Show("Desea Modificar el siguiente jugador : " + list[indice].MostrarDatos(), "Mensaje", MessageBoxButtons.OKCancel, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2);
                if (devuelve == DialogResult.OK)
                {
                    FrmJugador miFormulario = new FrmJugador(list[indice]);
                    miFormulario.ShowDialog();
                     



                }
            }
        }
    }
}
