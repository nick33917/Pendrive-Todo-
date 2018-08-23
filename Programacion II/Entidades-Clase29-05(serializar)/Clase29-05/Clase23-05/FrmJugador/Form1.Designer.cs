namespace FrmJugador
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
            this.cboPuesto = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.btnGuardar = new System.Windows.Forms.Button();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.btnTraer = new System.Windows.Forms.Button();
            this.btnSerializarBin = new System.Windows.Forms.Button();
            this.btnDesBin = new System.Windows.Forms.Button();
            this.btnSerXml = new System.Windows.Forms.Button();
            this.btnDesXml = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // txtNombre
            // 
            this.txtNombre.Location = new System.Drawing.Point(119, 21);
            this.txtNombre.Name = "txtNombre";
            this.txtNombre.Size = new System.Drawing.Size(100, 20);
            this.txtNombre.TabIndex = 0;
            // 
            // txtApellido
            // 
            this.txtApellido.Location = new System.Drawing.Point(119, 59);
            this.txtApellido.Name = "txtApellido";
            this.txtApellido.Size = new System.Drawing.Size(100, 20);
            this.txtApellido.TabIndex = 1;
            // 
            // cboPuesto
            // 
            this.cboPuesto.FormattingEnabled = true;
            this.cboPuesto.Location = new System.Drawing.Point(119, 92);
            this.cboPuesto.Name = "cboPuesto";
            this.cboPuesto.Size = new System.Drawing.Size(100, 21);
            this.cboPuesto.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(21, 28);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(47, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Nombre:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(21, 62);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(47, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "Apellido:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(25, 100);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(43, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Puesto:";
            // 
            // btnGuardar
            // 
            this.btnGuardar.Location = new System.Drawing.Point(153, 128);
            this.btnGuardar.Name = "btnGuardar";
            this.btnGuardar.Size = new System.Drawing.Size(108, 23);
            this.btnGuardar.TabIndex = 6;
            this.btnGuardar.Text = "&Guardar";
            this.btnGuardar.UseVisualStyleBackColor = true;
            this.btnGuardar.Click += new System.EventHandler(this.btnGuardar_Click);
            // 
            // saveFileDialog1
            // 
            this.saveFileDialog1.FileOk += new System.ComponentModel.CancelEventHandler(this.saveFileDialog1_FileOk);
            // 
            // btnTraer
            // 
            this.btnTraer.Location = new System.Drawing.Point(153, 215);
            this.btnTraer.Name = "btnTraer";
            this.btnTraer.Size = new System.Drawing.Size(108, 23);
            this.btnTraer.TabIndex = 7;
            this.btnTraer.Text = "&Traer";
            this.btnTraer.UseVisualStyleBackColor = true;
            this.btnTraer.Click += new System.EventHandler(this.btnTraer_Click);
            // 
            // btnSerializarBin
            // 
            this.btnSerializarBin.Location = new System.Drawing.Point(12, 154);
            this.btnSerializarBin.Name = "btnSerializarBin";
            this.btnSerializarBin.Size = new System.Drawing.Size(101, 23);
            this.btnSerializarBin.TabIndex = 8;
            this.btnSerializarBin.Text = "Ser.Bin";
            this.btnSerializarBin.UseVisualStyleBackColor = true;
            this.btnSerializarBin.Click += new System.EventHandler(this.btnSerializarBin_Click);
            // 
            // btnDesBin
            // 
            this.btnDesBin.Location = new System.Drawing.Point(12, 197);
            this.btnDesBin.Name = "btnDesBin";
            this.btnDesBin.Size = new System.Drawing.Size(98, 23);
            this.btnDesBin.TabIndex = 9;
            this.btnDesBin.Text = "Des.Bin";
            this.btnDesBin.UseVisualStyleBackColor = true;
            this.btnDesBin.Click += new System.EventHandler(this.btnDesBin_Click);
            // 
            // btnSerXml
            // 
            this.btnSerXml.Location = new System.Drawing.Point(297, 154);
            this.btnSerXml.Name = "btnSerXml";
            this.btnSerXml.Size = new System.Drawing.Size(89, 23);
            this.btnSerXml.TabIndex = 10;
            this.btnSerXml.Text = "Ser.XML";
            this.btnSerXml.UseVisualStyleBackColor = true;
            this.btnSerXml.Click += new System.EventHandler(this.btnSerXml_Click);
            // 
            // btnDesXml
            // 
            this.btnDesXml.Location = new System.Drawing.Point(297, 197);
            this.btnDesXml.Name = "btnDesXml";
            this.btnDesXml.Size = new System.Drawing.Size(89, 23);
            this.btnDesXml.TabIndex = 11;
            this.btnDesXml.Text = "Des.XML";
            this.btnDesXml.UseVisualStyleBackColor = true;
            this.btnDesXml.Click += new System.EventHandler(this.btnDesXml_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(535, 262);
            this.Controls.Add(this.btnDesXml);
            this.Controls.Add(this.btnSerXml);
            this.Controls.Add(this.btnDesBin);
            this.Controls.Add(this.btnSerializarBin);
            this.Controls.Add(this.btnTraer);
            this.Controls.Add(this.btnGuardar);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cboPuesto);
            this.Controls.Add(this.txtApellido);
            this.Controls.Add(this.txtNombre);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtNombre;
        private System.Windows.Forms.TextBox txtApellido;
        private System.Windows.Forms.ComboBox cboPuesto;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button btnGuardar;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.Button btnTraer;
        private System.Windows.Forms.Button btnSerializarBin;
        private System.Windows.Forms.Button btnDesBin;
        private System.Windows.Forms.Button btnSerXml;
        private System.Windows.Forms.Button btnDesXml;
    }
}

