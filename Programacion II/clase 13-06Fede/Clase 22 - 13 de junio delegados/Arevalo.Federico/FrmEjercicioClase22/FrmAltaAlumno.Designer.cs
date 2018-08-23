namespace FrmEjercicioClase22
{
    partial class FrmAltaAlumno
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
            this.lblApellido = new System.Windows.Forms.Label();
            this.txtApellido = new System.Windows.Forms.TextBox();
            this.lblNombre = new System.Windows.Forms.Label();
            this.txtNombre = new System.Windows.Forms.TextBox();
            this.lblDNI = new System.Windows.Forms.Label();
            this.txtDNI = new System.Windows.Forms.TextBox();
            this.lblFoto = new System.Windows.Forms.Label();
            this.txtFoto = new System.Windows.Forms.TextBox();
            this.btnAceptar = new System.Windows.Forms.Button();
            this.btnCancelar = new System.Windows.Forms.Button();
            this.opfFotoAlumno = new System.Windows.Forms.OpenFileDialog();
            this.SuspendLayout();
            // 
            // lblApellido
            // 
            this.lblApellido.AutoSize = true;
            this.lblApellido.Location = new System.Drawing.Point(41, 23);
            this.lblApellido.Name = "lblApellido";
            this.lblApellido.Size = new System.Drawing.Size(44, 13);
            this.lblApellido.TabIndex = 0;
            this.lblApellido.Text = "Apellido";
            // 
            // txtApellido
            // 
            this.txtApellido.Location = new System.Drawing.Point(41, 42);
            this.txtApellido.Name = "txtApellido";
            this.txtApellido.Size = new System.Drawing.Size(139, 20);
            this.txtApellido.TabIndex = 1;
            // 
            // lblNombre
            // 
            this.lblNombre.AutoSize = true;
            this.lblNombre.Location = new System.Drawing.Point(41, 68);
            this.lblNombre.Name = "lblNombre";
            this.lblNombre.Size = new System.Drawing.Size(44, 13);
            this.lblNombre.TabIndex = 0;
            this.lblNombre.Text = "Nombre";
            // 
            // txtNombre
            // 
            this.txtNombre.Location = new System.Drawing.Point(41, 87);
            this.txtNombre.Name = "txtNombre";
            this.txtNombre.Size = new System.Drawing.Size(139, 20);
            this.txtNombre.TabIndex = 2;
            // 
            // lblDNI
            // 
            this.lblDNI.AutoSize = true;
            this.lblDNI.Location = new System.Drawing.Point(41, 113);
            this.lblDNI.Name = "lblDNI";
            this.lblDNI.Size = new System.Drawing.Size(26, 13);
            this.lblDNI.TabIndex = 0;
            this.lblDNI.Text = "DNI";
            // 
            // txtDNI
            // 
            this.txtDNI.Location = new System.Drawing.Point(41, 132);
            this.txtDNI.Name = "txtDNI";
            this.txtDNI.Size = new System.Drawing.Size(139, 20);
            this.txtDNI.TabIndex = 3;
            // 
            // lblFoto
            // 
            this.lblFoto.AutoSize = true;
            this.lblFoto.Location = new System.Drawing.Point(41, 158);
            this.lblFoto.Name = "lblFoto";
            this.lblFoto.Size = new System.Drawing.Size(28, 13);
            this.lblFoto.TabIndex = 0;
            this.lblFoto.Text = "Foto";
            // 
            // txtFoto
            // 
            this.txtFoto.Location = new System.Drawing.Point(41, 177);
            this.txtFoto.Name = "txtFoto";
            this.txtFoto.Size = new System.Drawing.Size(139, 20);
            this.txtFoto.TabIndex = 4;
            this.txtFoto.DoubleClick += new System.EventHandler(this.txtFoto_TextChanged);
            // 
            // btnAceptar
            // 
            this.btnAceptar.Location = new System.Drawing.Point(32, 246);
            this.btnAceptar.Name = "btnAceptar";
            this.btnAceptar.Size = new System.Drawing.Size(75, 23);
            this.btnAceptar.TabIndex = 5;
            this.btnAceptar.Text = "Aceptar";
            this.btnAceptar.UseVisualStyleBackColor = true;
            this.btnAceptar.Click += new System.EventHandler(this.btnAceptar_Click);
            // 
            // btnCancelar
            // 
            this.btnCancelar.Location = new System.Drawing.Point(113, 246);
            this.btnCancelar.Name = "btnCancelar";
            this.btnCancelar.Size = new System.Drawing.Size(75, 23);
            this.btnCancelar.TabIndex = 6;
            this.btnCancelar.Text = " Cancelar";
            this.btnCancelar.UseVisualStyleBackColor = true;
            this.btnCancelar.Click += new System.EventHandler(this.btnCancelar_Click);
            // 
            // opfFotoAlumno
            // 
            this.opfFotoAlumno.FileName = "openFileDialog1";
            // 
            // FrmAltaAlumno
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(221, 299);
            this.Controls.Add(this.btnCancelar);
            this.Controls.Add(this.btnAceptar);
            this.Controls.Add(this.txtFoto);
            this.Controls.Add(this.lblFoto);
            this.Controls.Add(this.txtDNI);
            this.Controls.Add(this.lblDNI);
            this.Controls.Add(this.txtNombre);
            this.Controls.Add(this.lblNombre);
            this.Controls.Add(this.txtApellido);
            this.Controls.Add(this.lblApellido);
            this.Name = "FrmAltaAlumno";
            this.Text = "FrmAltaAlumno";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        public System.Windows.Forms.Label lblApellido;
        public System.Windows.Forms.TextBox txtApellido;
        public System.Windows.Forms.Label lblNombre;
        public System.Windows.Forms.TextBox txtNombre;
        public System.Windows.Forms.Label lblDNI;
        public System.Windows.Forms.TextBox txtDNI;
        public System.Windows.Forms.Label lblFoto;
        public System.Windows.Forms.TextBox txtFoto;
        public System.Windows.Forms.Button btnAceptar;
        public System.Windows.Forms.Button btnCancelar;
        public System.Windows.Forms.OpenFileDialog opfFotoAlumno;
    }
}