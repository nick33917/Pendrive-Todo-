using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace frmCalculadora
{
    public partial class frmCalculadora : Form
    {
        public frmCalculadora()
        {
            InitializeComponent();

            this.Load += new EventHandler(Inicializar);
        }

        private void Inicializar(object sender, EventArgs e)
        {

            foreach (Control b in this.Controls)
            {
                //if (b is Button)
                //{
                //    if( ((Button)b).Text.ToString().Contains("0") ) 
                //}

                //Usar panel
            }
            this.btn0.Click += new EventHandler(ManejadorCentral);
            this.btn1.Click += new EventHandler(ManejadorCentral);
            this.btn2.Click += new EventHandler(ManejadorCentral);
            this.btn3.Click += new EventHandler(ManejadorCentral);
            this.btn4.Click += new EventHandler(ManejadorCentral);
            this.btn5.Click += new EventHandler(ManejadorCentral);
            this.btn6.Click += new EventHandler(ManejadorCentral);
            this.btn7.Click += new EventHandler(ManejadorCentral);
            this.btn8.Click += new EventHandler(ManejadorCentral);
            this.btn9.Click += new EventHandler(ManejadorCentral);
        }

        private void ManejadorCentral(object sender, EventArgs e)
        {

        }

        private void frmCalculadora_Load(object sender, EventArgs e)
        {

        }
    }
}
