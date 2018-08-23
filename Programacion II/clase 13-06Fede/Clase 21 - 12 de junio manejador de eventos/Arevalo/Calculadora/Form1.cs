using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculadora
{
    public partial class Form1 : Form
    {
        private double numero1 = 0;
        private double numero2 = 0;
        private double resultado = 0;
        private EOperaciones operacion;
        private bool pasarACalcular = false;

        public Form1()
        {
            InitializeComponent();

            this.Numeros(true);
        }

        private void ManejadorCentral(object sender, EventArgs e)
        {
            if (((Button)sender) == btnUno ||
                ((Button)sender) == btnDos ||
                ((Button)sender) == btnTres ||
                ((Button)sender) == btnCuatro ||
                ((Button)sender) == btnCinco ||
                ((Button)sender) == btnSeis ||
                ((Button)sender) == btnSiete ||
                ((Button)sender) == btnOcho ||
                ((Button)sender) == btnNueve ||
                ((Button)sender) == btnCero)
            {
                if (this.pasarACalcular)
                {
                    double.TryParse(this.txtNumeros.Text, out this.numero2);
                    this.btnCalcular.Click += new EventHandler(ManejadorCentral);
                    this.pasarACalcular = false;
                }
                else
                    this.Operadores(true);                
            }

            if (((Button)sender) == btnSumar ||
                ((Button)sender) == btnRestar ||
                ((Button)sender) == btnMultiplicar ||
                ((Button)sender) == btnDividir)
            {
                double.TryParse(this.txtNumeros.Text, out this.numero1);
                this.txtNumeros.ResetText();
                this.pasarACalcular = true;
                
            }

            if (((Button)sender) == btnCalcular)
            {
                this.Operar(operacion, numero1, numero2);
                this.txtNumeros.Text = this.resultado.ToString();
                this.btnCalcular.Click -= new EventHandler(ManejadorCentral);
                this.Numeros(true);
            }

            
        }

        private void btnCero_Click(object sender, EventArgs e)
        {
            this.txtNumeros.Text += 0;

            //this.Operadores(true);
        }

        private void btnUno_Click(object sender, EventArgs e)
        {
            this.txtNumeros.Text += 1;

            //this.Operadores(true);
        }

        private void btnDos_Click(object sender, EventArgs e)
        {
            this.txtNumeros.Text += 2;

            //this.Operadores(true);
        }

        private void btnTres_Click(object sender, EventArgs e)
        {
            this.txtNumeros.Text += 3;

            //this.Operadores(true);
        }

        private void btnCuatro_Click(object sender, EventArgs e)
        {
            this.txtNumeros.Text += 4;

            //this.Operadores(true);
        }

        private void btnCinco_Click(object sender, EventArgs e)
        {
            this.txtNumeros.Text += 5;

            //this.Operadores(true);
        }

        private void btnSeis_Click(object sender, EventArgs e)
        {
            this.txtNumeros.Text += 6;

            //this.Operadores(true);
        }

        private void btnSiete_Click(object sender, EventArgs e)
        {
            this.txtNumeros.Text += 7;

            //this.Operadores(true);
        }

        private void btnOcho_Click(object sender, EventArgs e)
        {
            this.txtNumeros.Text += 8;

            //this.Operadores(true);
        }

        private void btnNueve_Click(object sender, EventArgs e)
        {
            this.txtNumeros.Text += 9;

            //this.Operadores(true);
        }

        private void btnSumar_Click(object sender, EventArgs e)
        {
            //double.TryParse(this.txtNumeros.Text, out this.numero1);
            this.operacion = EOperaciones.Sumar;
            //this.Operadores(false);
            //this.txtNumeros.Text = "";
        }

        private void btnRestar_Click(object sender, EventArgs e)
        {
            //double.TryParse(this.txtNumeros.Text, out this.numero1);
            this.operacion = EOperaciones.Restar;
            //this.Operadores(false);
            //this.txtNumeros.Text = "";
        }

        private void btnMultiplicar_Click(object sender, EventArgs e)
        {
            //double.TryParse(this.txtNumeros.Text, out this.numero1);
            this.operacion = EOperaciones.Multiplicar;
            //this.Operadores(false);
            //this.txtNumeros.Text = "";
        }

        private void btnDividir_Click(object sender, EventArgs e)
        {
            //double.TryParse(this.txtNumeros.Text, out this.numero1);
            this.operacion = EOperaciones.Dividir;
            //this.Operadores(false);
            //this.txtNumeros.Text = "";
        }

        private void Operadores(bool estado)
        {
            foreach (Control item in this.pnlOperadores.Controls)
            {
                if (estado == true)
                {
                    item.Click += new EventHandler(ManejadorCentral);
                    //this.btnSumar.Click += new EventHandler(ManejadorCentral);
                    //this.btnRestar.Click += new EventHandler(ManejadorCentral);
                    //this.btnDividir.Click += new EventHandler(ManejadorCentral);
                    //this.btnMultiplicar.Click += new EventHandler(ManejadorCentral);
                }
                else
                {
                    item.Click -= new EventHandler(ManejadorCentral);
                    //this.btnSumar.Click -= new EventHandler(ManejadorCentral);
                    //this.btnRestar.Click -= new EventHandler(ManejadorCentral);
                    //this.btnDividir.Click -= new EventHandler(ManejadorCentral);
                    //this.btnMultiplicar.Click -= new EventHandler(ManejadorCentral);
                }
            }
            
        }

        private void Numeros(bool estado)
        {

            //this.btnUno.Click += new EventHandler(ManejadorCentral);
            //this.btnDos.Click += new EventHandler(ManejadorCentral);
            //this.btnTres.Click += new EventHandler(ManejadorCentral);
            //this.btnCuatro.Click += new EventHandler(ManejadorCentral);
            //this.btnCinco.Click += new EventHandler(ManejadorCentral);
            //this.btnSeis.Click += new EventHandler(ManejadorCentral);
            //this.btnSiete.Click += new EventHandler(ManejadorCentral);
            //this.btnOcho.Click += new EventHandler(ManejadorCentral);
            //this.btnNueve.Click += new EventHandler(ManejadorCentral);
            //this.btnCero.Click += new EventHandler(ManejadorCentral);

            foreach (Control item in this.pnlNumeros.Controls)
            {
                if (estado == true)
                    ((Button)item).Click += new EventHandler(ManejadorCentral);
                else
                    ((Button)item).Click -= new EventHandler(ManejadorCentral);

                //this.btnUno.Click -= new EventHandler(ManejadorCentral);
                //this.btnDos.Click -= new EventHandler(ManejadorCentral);
                //this.btnTres.Click -= new EventHandler(ManejadorCentral);
                //this.btnCuatro.Click -= new EventHandler(ManejadorCentral);
                //this.btnCinco.Click -= new EventHandler(ManejadorCentral);
                //this.btnSeis.Click -= new EventHandler(ManejadorCentral);
                //this.btnSiete.Click -= new EventHandler(ManejadorCentral);
                //this.btnOcho.Click -= new EventHandler(ManejadorCentral);
                //this.btnNueve.Click -= new EventHandler(ManejadorCentral);
                //this.btnCero.Click -= new EventHandler(ManejadorCentral);
            }
        }

        private double Operar(EOperaciones operacion, double n1, double n2)
        {
            double returnValue = 0;

            switch (operacion)
            {
                case EOperaciones.Sumar:
                    returnValue = n1 + n2;
                    break;
                case EOperaciones.Restar:
                    returnValue = n1 - n2;
                    break;
                case EOperaciones.Multiplicar:
                    returnValue = n1 - n2;
                    break;
                case EOperaciones.Dividir:
                    returnValue = n1 / n2;
                    break;
                default:
                    break;
            }

            return returnValue;

        }

        private void btnCalcular_Click(object sender, EventArgs e)
        {
            //double.TryParse(this.txtNumeros.Text, out this.numero2);

            this.txtNumeros.Text = this.Operar(this.operacion, this.numero1, this.numero2).ToString();

            //this.btnCalcular.Click -= new EventHandler(ManejadorCentral);
        }

    }
}
