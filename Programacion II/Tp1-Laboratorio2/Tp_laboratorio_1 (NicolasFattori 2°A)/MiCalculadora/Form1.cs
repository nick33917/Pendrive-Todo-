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

namespace MiCalculadora
{
    public partial class LaCalculadora : Form
    {
        public LaCalculadora()
        {
            InitializeComponent();
            lblResultado.Text = "";
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }


        /// <summary>
        /// Limpia los textBoxs , el comboBox y el label.
        /// </summary>
        private void Limpiar()
        {
            this.txtNumero1.Clear();
            this.txtNumero2.Clear();
            this.lblResultado.Text = "";
            this.cmbOperador.Text = "";
        }

        private void btnLimpiar_Click(object sender, EventArgs e)
        {
            this.Limpiar();
            
        }

        private void btnCerrar_Click(object sender, EventArgs e)
        {
            this.Close();
        }


        /// <summary>
        /// Realiza la operacion  que queramos entre 2 numeros y devuelve el resultado.
        /// </summary>
        /// <param name="numero1">1er numero</param>
        /// <param name="numero2">2do numero</param>
        /// <param name="operador">operador para realizar la cuenta</param>
        /// <returns></returns>
        private static double Operar(string numero1,string numero2,string operador)
        {
            double resultado;
            Calculadora calcu = new Calculadora();
            Numero n1= new Numero(numero1);
            Numero n2 = new Numero(numero2);

            resultado = calcu.Operar(n1,n2,operador);
            return resultado;

        }
        private  void btnOperar_Click(object sender, EventArgs e)
        {
            string num1 = txtNumero1.Text;
            string num2 = txtNumero2.Text;
            string operador = cmbOperador.Text;
            if (operador == "/" && num2 == "0")
            {
                MessageBox.Show("No se puede dividir por 0", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                lblResultado.Visible = true;
                double resultado = LaCalculadora.Operar(num1, num2, operador);
                lblResultado.Text = resultado.ToString();
            }

        }

        private void btnConvertirABinario_Click(object sender, EventArgs e)
        {
            if (lblResultado.Text != "")
            {
                string resultado = Numero.DecimalBinario(Convert.ToDouble(lblResultado.Text));
                lblResultado.Text = resultado;
            }
            else
            {
                MessageBox.Show("No hay resultado para convertir a Binario", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);

            }
        }

        private void btnConvertirADecimal_Click(object sender, EventArgs e)
        {
            if (lblResultado.Text != "")
            {
                string resultado = Numero.BinarioDecimal(lblResultado.Text);
                lblResultado.Text = resultado;
            }
            else
            {
                MessageBox.Show("No hay resultado para convertir a Decimal", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
         }

        private void lblResultado_Click(object sender, EventArgs e)
        {

        }
    }
}
