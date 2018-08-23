using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using EntidadesClase22;

namespace FrmEmpleado
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void lblApellido_Click(object sender, EventArgs e)
        {

        }

        private void btnAceptar_Click(object sender, EventArgs e)
        {
            string nombre = this.txtNombre.Text;
            string apellido = this.txtApellido.Text;
            int dni;
            int.TryParse(this.txtDNI.Text, out dni);
            double sueldo;
            double.TryParse(this.txtSueldo.Text, out sueldo);

            Empleado e1 = new Empleado(nombre, apellido, dni);
            e1.SueldoMaximoMejorado += new DelegadoLimiteSueldoMejorado(ManejadorSueldoMaximoMejorado);
            e1.Sueldo = sueldo;            
        }

        private void ManejadorSueldoMaximoMejorado(Empleado sender, EmpleadoEventArgs e)
        {
            MessageBox.Show("El sueldo esta entre $20k y $30k");
        }
    }
}
