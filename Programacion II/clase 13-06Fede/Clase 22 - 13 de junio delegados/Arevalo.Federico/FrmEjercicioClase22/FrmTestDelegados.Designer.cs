namespace FrmEjercicioClase22
{
    partial class FrmTestDelegados
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
            this.txtTexto = new System.Windows.Forms.TextBox();
            this.btnActualizar = new System.Windows.Forms.Button();
            this.btnBuscarFoto = new System.Windows.Forms.Button();
            this.opfFoto = new System.Windows.Forms.OpenFileDialog();
            this.SuspendLayout();
            // 
            // txtTexto
            // 
            this.txtTexto.Location = new System.Drawing.Point(92, 177);
            this.txtTexto.Name = "txtTexto";
            this.txtTexto.Size = new System.Drawing.Size(100, 20);
            this.txtTexto.TabIndex = 0;
            // 
            // btnActualizar
            // 
            this.btnActualizar.Location = new System.Drawing.Point(92, 216);
            this.btnActualizar.Name = "btnActualizar";
            this.btnActualizar.Size = new System.Drawing.Size(100, 23);
            this.btnActualizar.TabIndex = 1;
            this.btnActualizar.Text = "Actualizar";
            this.btnActualizar.UseVisualStyleBackColor = true;
            this.btnActualizar.Click += new System.EventHandler(this.button1_Click);
            // 
            // btnBuscarFoto
            // 
            this.btnBuscarFoto.Location = new System.Drawing.Point(92, 135);
            this.btnBuscarFoto.Name = "btnBuscarFoto";
            this.btnBuscarFoto.Size = new System.Drawing.Size(100, 23);
            this.btnBuscarFoto.TabIndex = 2;
            this.btnBuscarFoto.Text = "Buscar foto";
            this.btnBuscarFoto.UseVisualStyleBackColor = true;
            this.btnBuscarFoto.Click += new System.EventHandler(this.btnBuscarFoto_Click);
            // 
            // opfFoto
            // 
            this.opfFoto.FileName = "openFileDialog1";
            // 
            // FrmTestDelegados
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.btnBuscarFoto);
            this.Controls.Add(this.btnActualizar);
            this.Controls.Add(this.txtTexto);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "FrmTestDelegados";
            this.Text = "FrmTestDelegados";
            this.Load += new System.EventHandler(this.FrmTestDelegados_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtTexto;
        private System.Windows.Forms.Button btnActualizar;
        private System.Windows.Forms.Button btnBuscarFoto;
        private System.Windows.Forms.OpenFileDialog opfFoto;
    }
}