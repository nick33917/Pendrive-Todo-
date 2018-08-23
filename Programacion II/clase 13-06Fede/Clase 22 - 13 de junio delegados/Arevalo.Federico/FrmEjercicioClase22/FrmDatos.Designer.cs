namespace FrmEjercicioClase22
{
    partial class FrmDatos
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
            this.lblTexto = new System.Windows.Forms.Label();
            this.ptbFoto = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.ptbFoto)).BeginInit();
            this.SuspendLayout();
            // 
            // lblTexto
            // 
            this.lblTexto.AutoSize = true;
            this.lblTexto.Location = new System.Drawing.Point(158, 252);
            this.lblTexto.Name = "lblTexto";
            this.lblTexto.Size = new System.Drawing.Size(0, 13);
            this.lblTexto.TabIndex = 0;
            // 
            // ptbFoto
            // 
            this.ptbFoto.Location = new System.Drawing.Point(33, 12);
            this.ptbFoto.Name = "ptbFoto";
            this.ptbFoto.Size = new System.Drawing.Size(273, 204);
            this.ptbFoto.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.ptbFoto.TabIndex = 1;
            this.ptbFoto.TabStop = false;
            this.ptbFoto.Click += new System.EventHandler(this.pictureBox1_Click);
            // 
            // FrmDatos
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(340, 295);
            this.Controls.Add(this.ptbFoto);
            this.Controls.Add(this.lblTexto);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "FrmDatos";
            this.Text = "FrmDatos";
            this.Load += new System.EventHandler(this.FrmDatos_Load);
            ((System.ComponentModel.ISupportInitialize)(this.ptbFoto)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblTexto;
        private System.Windows.Forms.PictureBox ptbFoto;
    }
}