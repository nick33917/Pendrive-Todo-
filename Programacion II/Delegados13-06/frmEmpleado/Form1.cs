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

namespace frmEmpleado
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void btnAceptar_Click(object sender, EventArgs e)
        {
            Empleado empleado = new Empleado(txtNombre.Text, txtApellido.Text, int.Parse(txtDni.Text));

            empleado.SueldoCero += new DelegadoSueldoCero(this.ManejadorEvento);
            empleado.SueldoMaximo += new DelegadoDeLimiteSueldo(this.ManejadorSueldoMaximo);
            empleado.SueldoMaximoMejorado += new DelegadoDeLimiteSueldoMejorado(this.ManejadorSueldoMaximoMejorado);

            try
            {
                empleado.Sueldo = int.Parse(txtSueldo.Text);
            }
            catch (SueldoNegativoException excepcion)
            {
                MessageBox.Show(excepcion.Message);
            }
        }

        public void ManejadorEvento()
        {
            MessageBox.Show("Metodo Manejador: Error, el sueldo es 0!");
        }

        public void ManejadorSueldoMaximo(double sueldo, Empleado e)
        {
            MessageBox.Show("Error! \nEl empleado: " + e.ToString() + "\nQuiere ganar: " + sueldo);
        }

        public void ManejadorSueldoMaximoMejorado(Empleado sender, EmpleadoEventArgs e)
        {
            MessageBox.Show("Error! \nEl empleado: " + sender.ToString() + "\nQuiere ganar: " + e.Sueldo);
        }
    }
}
