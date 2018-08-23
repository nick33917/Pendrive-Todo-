namespace frmPrincipal
{
    partial class frmDatos
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
            this.lblLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // lblLabel
            // 
            this.lblLabel.AutoSize = true;
            this.lblLabel.Location = new System.Drawing.Point(101, 218);
            this.lblLabel.Name = "lblLabel";
            this.lblLabel.Size = new System.Drawing.Size(33, 13);
            this.lblLabel.TabIndex = 0;
            this.lblLabel.Text = "Label";
            // 
            // frmDatos
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.lblLabel);
            this.Name = "frmDatos";
            this.Text = "frmDatos";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblLabel;
    }
}