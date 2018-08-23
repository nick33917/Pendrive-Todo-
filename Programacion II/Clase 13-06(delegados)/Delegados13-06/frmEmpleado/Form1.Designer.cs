namespace frmEmpleado
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
            this.txtNombre = new System.Windows.Forms.TextBox();
            this.txtApellido = new System.Windows.Forms.TextBox();
            this.txtDni = new System.Windows.Forms.TextBox();
            this.txtSueldo = new System.Windows.Forms.TextBox();
            this.lblNombre = new System.Windows.Forms.Label();
            this.lblApellido = new System.Windows.Forms.Label();
            this.lblDni = new System.Windows.Forms.Label();
            this.lblSueldo = new System.Windows.Forms.Label();
            this.btnAceptar = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // txtNombre
            // 
            this.txtNombre.Location = new System.Drawing.Point(107, 39);
            this.txtNombre.Name = "txtNombre";
            this.txtNombre.Size = new System.Drawing.Size(86, 20);
            this.txtNombre.TabIndex = 0;
            // 
            // txtApellido
            // 
            this.txtApellido.Location = new System.Drawing.Point(107, 65);
            this.txtApellido.Name = "txtApellido";
            this.txtApellido.Size = new System.Drawing.Size(86, 20);
            this.txtApellido.TabIndex = 1;
            // 
            // txtDni
            // 
            this.txtDni.Location = new System.Drawing.Point(107, 91);
            this.txtDni.Name = "txtDni";
            this.txtDni.Size = new System.Drawing.Size(86, 20);
            this.txtDni.TabIndex = 2;
            // 
            // txtSueldo
            // 
            this.txtSueldo.Location = new System.Drawing.Point(107, 117);
            this.txtSueldo.Name = "txtSueldo";
            this.txtSueldo.Size = new System.Drawing.Size(86, 20);
            this.txtSueldo.TabIndex = 3;
            // 
            // lblNombre
            // 
            this.lblNombre.AutoSize = true;
            this.lblNombre.Location = new System.Drawing.Point(41, 46);
            this.lblNombre.Name = "lblNombre";
            this.lblNombre.Size = new System.Drawing.Size(47, 13);
            this.lblNombre.TabIndex = 4;
            this.lblNombre.Text = "Nombre:";
            // 
            // lblApellido
            // 
            this.lblApellido.AutoSize = true;
            this.lblApellido.Location = new System.Drawing.Point(41, 72);
            this.lblApellido.Name = "lblApellido";
            this.lblApellido.Size = new System.Drawing.Size(47, 13);
            this.lblApellido.TabIndex = 5;
            this.lblApellido.Text = "Apellido:";
            this.lblApellido.Click += new System.EventHandler(this.label2_Click);
            // 
            // lblDni
            // 
            this.lblDni.AutoSize = true;
            this.lblDni.Location = new System.Drawing.Point(41, 98);
            this.lblDni.Name = "lblDni";
            this.lblDni.Size = new System.Drawing.Size(26, 13);
            this.lblDni.TabIndex = 6;
            this.lblDni.Text = "Dni:";
            // 
            // lblSueldo
            // 
            this.lblSueldo.AutoSize = true;
            this.lblSueldo.Location = new System.Drawing.Point(41, 124);
            this.lblSueldo.Name = "lblSueldo";
            this.lblSueldo.Size = new System.Drawing.Size(43, 13);
            this.lblSueldo.TabIndex = 7;
            this.lblSueldo.Text = "Sueldo:";
            // 
            // btnAceptar
            // 
            this.btnAceptar.Location = new System.Drawing.Point(65, 174);
            this.btnAceptar.Name = "btnAceptar";
            this.btnAceptar.Size = new System.Drawing.Size(106, 41);
            this.btnAceptar.TabIndex = 8;
            this.btnAceptar.Text = "Aceptar";
            this.btnAceptar.UseVisualStyleBackColor = true;
            this.btnAceptar.Click += new System.EventHandler(this.btnAceptar_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(247, 242);
            this.Controls.Add(this.btnAceptar);
            this.Controls.Add(this.lblSueldo);
            this.Controls.Add(this.lblDni);
            this.Controls.Add(this.lblApellido);
            this.Controls.Add(this.lblNombre);
            this.Controls.Add(this.txtSueldo);
            this.Controls.Add(this.txtDni);
            this.Controls.Add(this.txtApellido);
            this.Controls.Add(this.txtNombre);
            this.Name = "Form1";
            this.Text = "Empleado";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtNombre;
        private System.Windows.Forms.TextBox txtApellido;
        private System.Windows.Forms.TextBox txtDni;
        private System.Windows.Forms.TextBox txtSueldo;
        private System.Windows.Forms.Label lblNombre;
        private System.Windows.Forms.Label lblApellido;
        private System.Windows.Forms.Label lblDni;
        private System.Windows.Forms.Label lblSueldo;
        private System.Windows.Forms.Button btnAceptar;
    }
}

