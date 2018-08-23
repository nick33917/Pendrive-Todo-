namespace Formularios
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
            this.lblVisor = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // lblVisor
            // 
            this.lblVisor.AutoSize = true;
            this.lblVisor.Location = new System.Drawing.Point(106, 195);
            this.lblVisor.Name = "lblVisor";
            this.lblVisor.Size = new System.Drawing.Size(35, 13);
            this.lblVisor.TabIndex = 0;
            this.lblVisor.Text = "label1";
            // 
            // FrmDatos
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.lblVisor);
            this.Name = "FrmDatos";
            this.Text = "FrmDatos";
            this.Load += new System.EventHandler(this.FrmDatos_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblVisor;
    }
}