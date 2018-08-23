using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using ClassLibrary1;

namespace CosaForms
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
       
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string cadena;
            int numero;
            DateTime fecha;

            numero=int.Parse( this.textEntero.Text);
            cadena = this.textCadena.Text;
            fecha = DateTime.Parse(this.textFecha.Text);

            Cosa valores = new Cosa(numero, cadena, fecha);
            MessageBox.Show(valores.Mostrar());
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
