namespace FrmEjercicioClase22
{
    partial class FrmDatosAlumno
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
            this.ptbFoto = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.ptbFoto)).BeginInit();
            this.SuspendLayout();
            // 
            // ptbFoto
            // 
            this.ptbFoto.Location = new System.Drawing.Point(194, 23);
            this.ptbFoto.Name = "ptbFoto";
            this.ptbFoto.Size = new System.Drawing.Size(347, 246);
            this.ptbFoto.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.ptbFoto.TabIndex = 4;
            this.ptbFoto.TabStop = false;
            // 
            // FrmDatosAlumno
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(553, 319);
            this.Controls.Add(this.ptbFoto);
            this.Name = "FrmDatosAlumno";
            this.Text = "FrmDatosAlumno";
            this.Controls.SetChildIndex(this.lblApellido, 0);
            this.Controls.SetChildIndex(this.txtApellido, 0);
            this.Controls.SetChildIndex(this.lblNombre, 0);
            this.Controls.SetChildIndex(this.txtNombre, 0);
            this.Controls.SetChildIndex(this.lblDNI, 0);
            this.Controls.SetChildIndex(this.txtDNI, 0);
            this.Controls.SetChildIndex(this.lblFoto, 0);
            this.Controls.SetChildIndex(this.txtFoto, 0);
            this.Controls.SetChildIndex(this.btnAceptar, 0);
            this.Controls.SetChildIndex(this.btnCancelar, 0);
            this.Controls.SetChildIndex(this.ptbFoto, 0);
            ((System.ComponentModel.ISupportInitialize)(this.ptbFoto)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox ptbFoto;
    }
}