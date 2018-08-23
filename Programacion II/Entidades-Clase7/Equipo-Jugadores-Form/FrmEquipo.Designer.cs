namespace Equipo_Jugadores_Form
{
    partial class FrmEquipo
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.txtNombre = new System.Windows.Forms.TextBox();
            this.txtCantJug = new System.Windows.Forms.TextBox();
            this.btnCancelar = new System.Windows.Forms.Button();
            this.btnAceptar = new System.Windows.Forms.Button();
            this.btnMas = new System.Windows.Forms.Button();
            this.txtListBox = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(175, 19);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(44, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Nombre";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(175, 90);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(49, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Cant Jug";
            // 
            // txtNombre
            // 
            this.txtNombre.Location = new System.Drawing.Point(153, 44);
            this.txtNombre.Name = "txtNombre";
            this.txtNombre.Size = new System.Drawing.Size(100, 20);
            this.txtNombre.TabIndex = 2;
            // 
            // txtCantJug
            // 
            this.txtCantJug.Location = new System.Drawing.Point(153, 106);
            this.txtCantJug.Name = "txtCantJug";
            this.txtCantJug.Size = new System.Drawing.Size(100, 20);
            this.txtCantJug.TabIndex = 3;
            // 
            // btnCancelar
            // 
            this.btnCancelar.Location = new System.Drawing.Point(224, 171);
            this.btnCancelar.Name = "btnCancelar";
            this.btnCancelar.Size = new System.Drawing.Size(75, 23);
            this.btnCancelar.TabIndex = 4;
            this.btnCancelar.Text = "cancelar";
            this.btnCancelar.UseVisualStyleBackColor = true;
            // 
            // btnAceptar
            // 
            this.btnAceptar.Location = new System.Drawing.Point(78, 171);
            this.btnAceptar.Name = "btnAceptar";
            this.btnAceptar.Size = new System.Drawing.Size(75, 23);
            this.btnAceptar.TabIndex = 5;
            this.btnAceptar.Text = "aceptar";
            this.btnAceptar.UseVisualStyleBackColor = true;
            this.btnAceptar.Click += new System.EventHandler(this.btnAceptar_Click);
            // 
            // btnMas
            // 
            this.btnMas.Location = new System.Drawing.Point(173, 212);
            this.btnMas.Name = "btnMas";
            this.btnMas.Size = new System.Drawing.Size(46, 23);
            this.btnMas.TabIndex = 6;
            this.btnMas.Text = "+";
            this.btnMas.UseVisualStyleBackColor = true;
            this.btnMas.Visible = false;
            this.btnMas.Click += new System.EventHandler(this.btnMas_Click);
            // 
            // txtListBox
            // 
            this.txtListBox.FormattingEnabled = true;
            this.txtListBox.Location = new System.Drawing.Point(45, 265);
            this.txtListBox.Name = "txtListBox";
            this.txtListBox.Size = new System.Drawing.Size(436, 30);
            this.txtListBox.TabIndex = 7;
            this.txtListBox.Visible = false;
            // 
            // FrmEquipo
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(764, 394);
            this.Controls.Add(this.txtListBox);
            this.Controls.Add(this.btnMas);
            this.Controls.Add(this.btnAceptar);
            this.Controls.Add(this.btnCancelar);
            this.Controls.Add(this.txtCantJug);
            this.Controls.Add(this.txtNombre);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "FrmEquipo";
            this.Text = "FrmEquipo";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtNombre;
        private System.Windows.Forms.TextBox txtCantJug;
        private System.Windows.Forms.Button btnCancelar;
        private System.Windows.Forms.Button btnAceptar;
        private System.Windows.Forms.Button btnMas;
        private System.Windows.Forms.ListBox txtListBox;
    }
}