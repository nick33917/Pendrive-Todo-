namespace Calculadora
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.txtNumeros = new System.Windows.Forms.TextBox();
            this.btnUno = new System.Windows.Forms.Button();
            this.btnDos = new System.Windows.Forms.Button();
            this.btnTres = new System.Windows.Forms.Button();
            this.btnCuatro = new System.Windows.Forms.Button();
            this.btnCinco = new System.Windows.Forms.Button();
            this.btnSeis = new System.Windows.Forms.Button();
            this.btnSiete = new System.Windows.Forms.Button();
            this.btnOcho = new System.Windows.Forms.Button();
            this.btnNueve = new System.Windows.Forms.Button();
            this.btnCero = new System.Windows.Forms.Button();
            this.btnSumar = new System.Windows.Forms.Button();
            this.btnRestar = new System.Windows.Forms.Button();
            this.btnMultiplicar = new System.Windows.Forms.Button();
            this.btnDividir = new System.Windows.Forms.Button();
            this.btnCalcular = new System.Windows.Forms.Button();
            this.pnlNumeros = new System.Windows.Forms.Panel();
            this.pnlOperadores = new System.Windows.Forms.Panel();
            this.pnlNumeros.SuspendLayout();
            this.pnlOperadores.SuspendLayout();
            this.SuspendLayout();
            // 
            // txtNumeros
            // 
            this.txtNumeros.Location = new System.Drawing.Point(13, 13);
            this.txtNumeros.Name = "txtNumeros";
            this.txtNumeros.ReadOnly = true;
            this.txtNumeros.Size = new System.Drawing.Size(203, 20);
            this.txtNumeros.TabIndex = 0;
            // 
            // btnUno
            // 
            this.btnUno.Location = new System.Drawing.Point(11, 63);
            this.btnUno.Name = "btnUno";
            this.btnUno.Size = new System.Drawing.Size(37, 23);
            this.btnUno.TabIndex = 1;
            this.btnUno.Text = "1";
            this.btnUno.UseVisualStyleBackColor = true;
            this.btnUno.Click += new System.EventHandler(this.btnUno_Click);
            // 
            // btnDos
            // 
            this.btnDos.Location = new System.Drawing.Point(53, 62);
            this.btnDos.Name = "btnDos";
            this.btnDos.Size = new System.Drawing.Size(37, 23);
            this.btnDos.TabIndex = 1;
            this.btnDos.Text = "2";
            this.btnDos.UseVisualStyleBackColor = true;
            this.btnDos.Click += new System.EventHandler(this.btnDos_Click);
            // 
            // btnTres
            // 
            this.btnTres.Location = new System.Drawing.Point(96, 63);
            this.btnTres.Name = "btnTres";
            this.btnTres.Size = new System.Drawing.Size(37, 23);
            this.btnTres.TabIndex = 1;
            this.btnTres.Text = "3";
            this.btnTres.UseVisualStyleBackColor = true;
            this.btnTres.Click += new System.EventHandler(this.btnTres_Click);
            // 
            // btnCuatro
            // 
            this.btnCuatro.Location = new System.Drawing.Point(10, 34);
            this.btnCuatro.Name = "btnCuatro";
            this.btnCuatro.Size = new System.Drawing.Size(37, 23);
            this.btnCuatro.TabIndex = 1;
            this.btnCuatro.Text = "4";
            this.btnCuatro.UseVisualStyleBackColor = true;
            this.btnCuatro.Click += new System.EventHandler(this.btnCuatro_Click);
            // 
            // btnCinco
            // 
            this.btnCinco.Location = new System.Drawing.Point(52, 33);
            this.btnCinco.Name = "btnCinco";
            this.btnCinco.Size = new System.Drawing.Size(37, 23);
            this.btnCinco.TabIndex = 1;
            this.btnCinco.Text = "5";
            this.btnCinco.UseVisualStyleBackColor = true;
            this.btnCinco.Click += new System.EventHandler(this.btnCinco_Click);
            // 
            // btnSeis
            // 
            this.btnSeis.Location = new System.Drawing.Point(95, 34);
            this.btnSeis.Name = "btnSeis";
            this.btnSeis.Size = new System.Drawing.Size(37, 23);
            this.btnSeis.TabIndex = 1;
            this.btnSeis.Text = "6";
            this.btnSeis.UseVisualStyleBackColor = true;
            this.btnSeis.Click += new System.EventHandler(this.btnSeis_Click);
            // 
            // btnSiete
            // 
            this.btnSiete.Location = new System.Drawing.Point(10, 5);
            this.btnSiete.Name = "btnSiete";
            this.btnSiete.Size = new System.Drawing.Size(37, 23);
            this.btnSiete.TabIndex = 1;
            this.btnSiete.Text = "7";
            this.btnSiete.UseVisualStyleBackColor = true;
            this.btnSiete.Click += new System.EventHandler(this.btnSiete_Click);
            // 
            // btnOcho
            // 
            this.btnOcho.Location = new System.Drawing.Point(53, 4);
            this.btnOcho.Name = "btnOcho";
            this.btnOcho.Size = new System.Drawing.Size(37, 23);
            this.btnOcho.TabIndex = 1;
            this.btnOcho.Text = "8";
            this.btnOcho.UseVisualStyleBackColor = true;
            this.btnOcho.Click += new System.EventHandler(this.btnOcho_Click);
            // 
            // btnNueve
            // 
            this.btnNueve.Location = new System.Drawing.Point(95, 5);
            this.btnNueve.Name = "btnNueve";
            this.btnNueve.Size = new System.Drawing.Size(37, 23);
            this.btnNueve.TabIndex = 1;
            this.btnNueve.Text = "9";
            this.btnNueve.UseVisualStyleBackColor = true;
            this.btnNueve.Click += new System.EventHandler(this.btnNueve_Click);
            // 
            // btnCero
            // 
            this.btnCero.Location = new System.Drawing.Point(10, 90);
            this.btnCero.Name = "btnCero";
            this.btnCero.Size = new System.Drawing.Size(122, 23);
            this.btnCero.TabIndex = 1;
            this.btnCero.Text = "0";
            this.btnCero.UseVisualStyleBackColor = true;
            this.btnCero.Click += new System.EventHandler(this.btnCero_Click);
            // 
            // btnSumar
            // 
            this.btnSumar.Location = new System.Drawing.Point(3, 5);
            this.btnSumar.Name = "btnSumar";
            this.btnSumar.Size = new System.Drawing.Size(43, 23);
            this.btnSumar.TabIndex = 1;
            this.btnSumar.Text = "+";
            this.btnSumar.UseVisualStyleBackColor = true;
            this.btnSumar.Click += new System.EventHandler(this.btnSumar_Click);
            // 
            // btnRestar
            // 
            this.btnRestar.Location = new System.Drawing.Point(3, 33);
            this.btnRestar.Name = "btnRestar";
            this.btnRestar.Size = new System.Drawing.Size(43, 23);
            this.btnRestar.TabIndex = 1;
            this.btnRestar.Text = "-";
            this.btnRestar.UseVisualStyleBackColor = true;
            this.btnRestar.Click += new System.EventHandler(this.btnRestar_Click);
            // 
            // btnMultiplicar
            // 
            this.btnMultiplicar.Location = new System.Drawing.Point(3, 62);
            this.btnMultiplicar.Name = "btnMultiplicar";
            this.btnMultiplicar.Size = new System.Drawing.Size(43, 23);
            this.btnMultiplicar.TabIndex = 1;
            this.btnMultiplicar.Text = "*";
            this.btnMultiplicar.UseVisualStyleBackColor = true;
            this.btnMultiplicar.Click += new System.EventHandler(this.btnMultiplicar_Click);
            // 
            // btnDividir
            // 
            this.btnDividir.Location = new System.Drawing.Point(3, 91);
            this.btnDividir.Name = "btnDividir";
            this.btnDividir.Size = new System.Drawing.Size(43, 23);
            this.btnDividir.TabIndex = 1;
            this.btnDividir.Text = "/";
            this.btnDividir.UseVisualStyleBackColor = true;
            this.btnDividir.Click += new System.EventHandler(this.btnDividir_Click);
            // 
            // btnCalcular
            // 
            this.btnCalcular.Location = new System.Drawing.Point(23, 168);
            this.btnCalcular.Name = "btnCalcular";
            this.btnCalcular.Size = new System.Drawing.Size(57, 23);
            this.btnCalcular.TabIndex = 1;
            this.btnCalcular.Text = "=";
            this.btnCalcular.UseVisualStyleBackColor = true;
            this.btnCalcular.Click += new System.EventHandler(this.btnCalcular_Click);
            // 
            // pnlNumeros
            // 
            this.pnlNumeros.Controls.Add(this.btnTres);
            this.pnlNumeros.Controls.Add(this.btnUno);
            this.pnlNumeros.Controls.Add(this.btnDos);
            this.pnlNumeros.Controls.Add(this.btnCuatro);
            this.pnlNumeros.Controls.Add(this.btnCinco);
            this.pnlNumeros.Controls.Add(this.btnSeis);
            this.pnlNumeros.Controls.Add(this.btnCero);
            this.pnlNumeros.Controls.Add(this.btnSiete);
            this.pnlNumeros.Controls.Add(this.btnNueve);
            this.pnlNumeros.Controls.Add(this.btnOcho);
            this.pnlNumeros.Location = new System.Drawing.Point(13, 39);
            this.pnlNumeros.Name = "pnlNumeros";
            this.pnlNumeros.Size = new System.Drawing.Size(145, 123);
            this.pnlNumeros.TabIndex = 2;
            // 
            // pnlOperadores
            // 
            this.pnlOperadores.Controls.Add(this.btnSumar);
            this.pnlOperadores.Controls.Add(this.btnRestar);
            this.pnlOperadores.Controls.Add(this.btnMultiplicar);
            this.pnlOperadores.Controls.Add(this.btnDividir);
            this.pnlOperadores.Location = new System.Drawing.Point(164, 39);
            this.pnlOperadores.Name = "pnlOperadores";
            this.pnlOperadores.Size = new System.Drawing.Size(52, 123);
            this.pnlOperadores.TabIndex = 3;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(257, 213);
            this.Controls.Add(this.pnlOperadores);
            this.Controls.Add(this.pnlNumeros);
            this.Controls.Add(this.btnCalcular);
            this.Controls.Add(this.txtNumeros);
            this.Name = "Form1";
            this.Text = "Form1";
            this.pnlNumeros.ResumeLayout(false);
            this.pnlOperadores.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtNumeros;
        private System.Windows.Forms.Button btnUno;
        private System.Windows.Forms.Button btnDos;
        private System.Windows.Forms.Button btnTres;
        private System.Windows.Forms.Button btnCuatro;
        private System.Windows.Forms.Button btnCinco;
        private System.Windows.Forms.Button btnSeis;
        private System.Windows.Forms.Button btnSiete;
        private System.Windows.Forms.Button btnOcho;
        private System.Windows.Forms.Button btnNueve;
        private System.Windows.Forms.Button btnCero;
        private System.Windows.Forms.Button btnSumar;
        private System.Windows.Forms.Button btnRestar;
        private System.Windows.Forms.Button btnMultiplicar;
        private System.Windows.Forms.Button btnDividir;
        private System.Windows.Forms.Button btnCalcular;
        private System.Windows.Forms.Panel pnlNumeros;
        private System.Windows.Forms.Panel pnlOperadores;
    }
}

