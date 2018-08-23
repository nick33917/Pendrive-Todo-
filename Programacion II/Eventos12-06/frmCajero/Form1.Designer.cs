namespace frmCajero
{
    partial class frmCajeroAutomatico
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
            this.gpCantidadARetirar = new System.Windows.Forms.GroupBox();
            this.txtCantidadARetirar = new System.Windows.Forms.TextBox();
            this.lblCantidadARetirar = new System.Windows.Forms.Label();
            this.gpCantidadDeBilletes = new System.Windows.Forms.GroupBox();
            this.label3 = new System.Windows.Forms.Label();
            this.txtBilleteDe2 = new System.Windows.Forms.TextBox();
            this.txtBilleteDe5 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.txtBilleteDe10 = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.txtBilleteDe20 = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.txtBilleteDe50 = new System.Windows.Forms.TextBox();
            this.txtBilleteDe100 = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.btnAceptar = new System.Windows.Forms.Button();
            this.btnLimpiar = new System.Windows.Forms.Button();
            this.btnSalir = new System.Windows.Forms.Button();
            this.gpCantidadARetirar.SuspendLayout();
            this.gpCantidadDeBilletes.SuspendLayout();
            this.SuspendLayout();
            // 
            // gpCantidadARetirar
            // 
            this.gpCantidadARetirar.Controls.Add(this.lblCantidadARetirar);
            this.gpCantidadARetirar.Controls.Add(this.txtCantidadARetirar);
            this.gpCantidadARetirar.Location = new System.Drawing.Point(25, 12);
            this.gpCantidadARetirar.Name = "gpCantidadARetirar";
            this.gpCantidadARetirar.Size = new System.Drawing.Size(286, 78);
            this.gpCantidadARetirar.TabIndex = 0;
            this.gpCantidadARetirar.TabStop = false;
            this.gpCantidadARetirar.Text = "Cantidad a Retirar";
            // 
            // txtCantidadARetirar
            // 
            this.txtCantidadARetirar.Location = new System.Drawing.Point(126, 37);
            this.txtCantidadARetirar.Name = "txtCantidadARetirar";
            this.txtCantidadARetirar.Size = new System.Drawing.Size(112, 20);
            this.txtCantidadARetirar.TabIndex = 2;
            // 
            // lblCantidadARetirar
            // 
            this.lblCantidadARetirar.AutoSize = true;
            this.lblCantidadARetirar.Location = new System.Drawing.Point(25, 40);
            this.lblCantidadARetirar.Name = "lblCantidadARetirar";
            this.lblCantidadARetirar.Size = new System.Drawing.Size(95, 13);
            this.lblCantidadARetirar.TabIndex = 2;
            this.lblCantidadARetirar.Text = "Cantidad a Retirar:";
            // 
            // gpCantidadDeBilletes
            // 
            this.gpCantidadDeBilletes.Controls.Add(this.label7);
            this.gpCantidadDeBilletes.Controls.Add(this.label6);
            this.gpCantidadDeBilletes.Controls.Add(this.txtBilleteDe100);
            this.gpCantidadDeBilletes.Controls.Add(this.txtBilleteDe50);
            this.gpCantidadDeBilletes.Controls.Add(this.label5);
            this.gpCantidadDeBilletes.Controls.Add(this.txtBilleteDe20);
            this.gpCantidadDeBilletes.Controls.Add(this.label4);
            this.gpCantidadDeBilletes.Controls.Add(this.txtBilleteDe10);
            this.gpCantidadDeBilletes.Controls.Add(this.label1);
            this.gpCantidadDeBilletes.Controls.Add(this.txtBilleteDe5);
            this.gpCantidadDeBilletes.Controls.Add(this.label3);
            this.gpCantidadDeBilletes.Controls.Add(this.txtBilleteDe2);
            this.gpCantidadDeBilletes.Location = new System.Drawing.Point(25, 118);
            this.gpCantidadDeBilletes.Name = "gpCantidadDeBilletes";
            this.gpCantidadDeBilletes.Size = new System.Drawing.Size(286, 336);
            this.gpCantidadDeBilletes.TabIndex = 3;
            this.gpCantidadDeBilletes.TabStop = false;
            this.gpCantidadDeBilletes.Text = "Cantidad de Billetes";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(25, 44);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(68, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Billete de $ 2";
            // 
            // txtBilleteDe2
            // 
            this.txtBilleteDe2.Enabled = false;
            this.txtBilleteDe2.Location = new System.Drawing.Point(126, 37);
            this.txtBilleteDe2.Name = "txtBilleteDe2";
            this.txtBilleteDe2.Size = new System.Drawing.Size(112, 20);
            this.txtBilleteDe2.TabIndex = 2;
            // 
            // txtBilleteDe5
            // 
            this.txtBilleteDe5.Enabled = false;
            this.txtBilleteDe5.Location = new System.Drawing.Point(126, 82);
            this.txtBilleteDe5.Name = "txtBilleteDe5";
            this.txtBilleteDe5.Size = new System.Drawing.Size(112, 20);
            this.txtBilleteDe5.TabIndex = 3;
            this.txtBilleteDe5.TextChanged += new System.EventHandler(this.txtBilleteDe5_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(25, 89);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(68, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Billete de $ 5";
            // 
            // txtBilleteDe10
            // 
            this.txtBilleteDe10.Enabled = false;
            this.txtBilleteDe10.Location = new System.Drawing.Point(126, 131);
            this.txtBilleteDe10.Name = "txtBilleteDe10";
            this.txtBilleteDe10.Size = new System.Drawing.Size(112, 20);
            this.txtBilleteDe10.TabIndex = 5;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(25, 138);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(74, 13);
            this.label4.TabIndex = 6;
            this.label4.Text = "Billete de $ 10";
            // 
            // txtBilleteDe20
            // 
            this.txtBilleteDe20.Enabled = false;
            this.txtBilleteDe20.Location = new System.Drawing.Point(126, 179);
            this.txtBilleteDe20.Name = "txtBilleteDe20";
            this.txtBilleteDe20.Size = new System.Drawing.Size(112, 20);
            this.txtBilleteDe20.TabIndex = 7;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(25, 186);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(74, 13);
            this.label5.TabIndex = 8;
            this.label5.Text = "Billete de $ 20";
            // 
            // txtBilleteDe50
            // 
            this.txtBilleteDe50.Enabled = false;
            this.txtBilleteDe50.Location = new System.Drawing.Point(126, 235);
            this.txtBilleteDe50.Name = "txtBilleteDe50";
            this.txtBilleteDe50.Size = new System.Drawing.Size(112, 20);
            this.txtBilleteDe50.TabIndex = 9;
            // 
            // txtBilleteDe100
            // 
            this.txtBilleteDe100.Enabled = false;
            this.txtBilleteDe100.Location = new System.Drawing.Point(126, 287);
            this.txtBilleteDe100.Name = "txtBilleteDe100";
            this.txtBilleteDe100.Size = new System.Drawing.Size(112, 20);
            this.txtBilleteDe100.TabIndex = 10;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(25, 242);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(74, 13);
            this.label6.TabIndex = 11;
            this.label6.Text = "Billete de $ 50";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(25, 290);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(80, 13);
            this.label7.TabIndex = 12;
            this.label7.Text = "Billete de $ 100";
            // 
            // btnAceptar
            // 
            this.btnAceptar.Location = new System.Drawing.Point(336, 149);
            this.btnAceptar.Name = "btnAceptar";
            this.btnAceptar.Size = new System.Drawing.Size(85, 31);
            this.btnAceptar.TabIndex = 4;
            this.btnAceptar.Text = "Aceptar";
            this.btnAceptar.UseVisualStyleBackColor = true;
            // 
            // btnLimpiar
            // 
            this.btnLimpiar.Location = new System.Drawing.Point(336, 267);
            this.btnLimpiar.Name = "btnLimpiar";
            this.btnLimpiar.Size = new System.Drawing.Size(85, 31);
            this.btnLimpiar.TabIndex = 5;
            this.btnLimpiar.Text = "Limpiar";
            this.btnLimpiar.UseVisualStyleBackColor = true;
            // 
            // btnSalir
            // 
            this.btnSalir.Location = new System.Drawing.Point(336, 399);
            this.btnSalir.Name = "btnSalir";
            this.btnSalir.Size = new System.Drawing.Size(85, 31);
            this.btnSalir.TabIndex = 6;
            this.btnSalir.Text = "Salir";
            this.btnSalir.UseVisualStyleBackColor = true;
            // 
            // frmCajeroAutomatico
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(433, 495);
            this.Controls.Add(this.btnSalir);
            this.Controls.Add(this.btnLimpiar);
            this.Controls.Add(this.btnAceptar);
            this.Controls.Add(this.gpCantidadDeBilletes);
            this.Controls.Add(this.gpCantidadARetirar);
            this.Name = "frmCajeroAutomatico";
            this.Text = "Cajero Automático";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.gpCantidadARetirar.ResumeLayout(false);
            this.gpCantidadARetirar.PerformLayout();
            this.gpCantidadDeBilletes.ResumeLayout(false);
            this.gpCantidadDeBilletes.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox gpCantidadARetirar;
        private System.Windows.Forms.Label lblCantidadARetirar;
        private System.Windows.Forms.TextBox txtCantidadARetirar;
        private System.Windows.Forms.GroupBox gpCantidadDeBilletes;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox txtBilleteDe100;
        private System.Windows.Forms.TextBox txtBilleteDe50;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox txtBilleteDe20;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtBilleteDe10;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtBilleteDe5;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtBilleteDe2;
        private System.Windows.Forms.Button btnAceptar;
        private System.Windows.Forms.Button btnLimpiar;
        private System.Windows.Forms.Button btnSalir;
    }
}

