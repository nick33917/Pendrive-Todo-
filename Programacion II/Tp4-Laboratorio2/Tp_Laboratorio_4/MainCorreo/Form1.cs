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
namespace MainCorreo
{
    public partial class Form1 : Form
    {
        private Correo _correo;
        
        public Form1()
        {
            InitializeComponent();
            this._correo = new Correo();
        }

        private void cmsListas_Opening(object sender, CancelEventArgs e)
        {

        }

        private void btnAgregar_Click(object sender, EventArgs e)
        {
            Paquete p = new Paquete(this.txtDirecciones.Text,this.maskedTackingID.Text);
            p.InformaEstado += new Paquete.DelegadoEstado(this.paq_InformaEstado);
            try
            {
                this._correo += p;
            }
            catch(TrackingIdRepetidoException excep)
            {
                MessageBox.Show(excep.Message, "Paquete repetido", MessageBoxButtons.OK, MessageBoxIcon.Question);
            }
            this.ActualizarEstados();
        }

        private void paq_InformaEstado(object sender, EventArgs e)
        {
            if (this.InvokeRequired)
            { 
                Paquete.DelegadoEstado d = new Paquete.DelegadoEstado(paq_InformaEstado); 
                this.Invoke( d, new object[] {sender, e} ); 
            } 
            else
            {
                this.ActualizarEstados();
            } 
        }

        private void ActualizarEstados()
        {
            this.lstIngresados.Items.Clear();
            this.lstEnViaje.Items.Clear();
            this.lstEstadoEntregado.Items.Clear();
            foreach (Paquete p in this._correo.Paquetes)
            {
                if (p.Estado == Paquete.EEstado.Ingresado)
                {
                    this.lstIngresados.Items.Add(p);
                }
                else if (p.Estado == Paquete.EEstado.EnViaje)
                {
                    this.lstEnViaje.Items.Add(p);
                }
                else
                {
                    this.lstEstadoEntregado.Items.Add(p);
                }
            }
        }

        private void FrmPpal_FormClosing(object sender, FormClosingEventArgs e)
        {
            this._correo.FinEntregas();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void btnMostrarTodos_Click(object sender, EventArgs e)
        {
            this.MostrarInformacion<List<Paquete>>((IMostrar<List<Paquete>>)this._correo); 
        }

        private void MostrarInformacion<T>(IMostrar<T> elemento)
        {
            if (elemento!=null)
            {
                this.rtbMostrar.Text = elemento.MostrarDatos(elemento);
                this.rtbMostrar.Text.Guardar("salida.txt");
            }
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void listBox3_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void mostrarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.MostrarInformacion<Paquete>((IMostrar<Paquete>)lstEstadoEntregado.SelectedItem);
        }


    }
}
