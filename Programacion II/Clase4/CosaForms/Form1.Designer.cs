namespace CosaForms
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
            this.textEntero = new System.Windows.Forms.TextBox();
            this.textCadena = new System.Windows.Forms.TextBox();
            this.textFecha = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // textEntero
            // 
            this.textEntero.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.textEntero.ForeColor = System.Drawing.SystemColors.Menu;
            this.textEntero.Location = new System.Drawing.Point(150, 27);
            this.textEntero.Name = "textEntero";
            this.textEntero.Size = new System.Drawing.Size(100, 20);
            this.textEntero.TabIndex = 0;
            // 
            // textCadena
            // 
            this.textCadena.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.textCadena.ForeColor = System.Drawing.SystemColors.Menu;
            this.textCadena.Location = new System.Drawing.Point(150, 140);
            this.textCadena.Name = "textCadena";
            this.textCadena.Size = new System.Drawing.Size(100, 20);
            this.textCadena.TabIndex = 1;
            // 
            // textFecha
            // 
            this.textFecha.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.textFecha.ForeColor = System.Drawing.SystemColors.Menu;
            this.textFecha.Location = new System.Drawing.Point(150, 83);
            this.textFecha.Name = "textFecha";
            this.textFecha.Size = new System.Drawing.Size(100, 20);
            this.textFecha.TabIndex = 2;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(285, 197);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 3;
            this.button1.Text = "Aceptar";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(12, 12);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(132, 37);
            this.label1.TabIndex = 4;
            this.label1.Text = "Numero";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(12, 68);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(106, 37);
            this.label2.TabIndex = 5;
            this.label2.Text = "Fecha";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(12, 125);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(129, 37);
            this.label3.TabIndex = 6;
            this.label3.Text = "Cadena";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Gray;
            this.ClientSize = new System.Drawing.Size(629, 262);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.textFecha);
            this.Controls.Add(this.textCadena);
            this.Controls.Add(this.textEntero);
            this.ForeColor = System.Drawing.SystemColors.ControlText;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textEntero;
        private System.Windows.Forms.TextBox textCadena;
        private System.Windows.Forms.TextBox textFecha;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
    }
}

