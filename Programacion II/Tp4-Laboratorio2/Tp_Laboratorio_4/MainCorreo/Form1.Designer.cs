namespace MainCorreo
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador requerida.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén utilizando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben eliminar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido del método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.rtbMostrar = new System.Windows.Forms.RichTextBox();
            this.lstIngresados = new System.Windows.Forms.ListBox();
            this.lstEnViaje = new System.Windows.Forms.ListBox();
            this.lstEstadoEntregado = new System.Windows.Forms.ListBox();
            this.cmsListas = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.mostrarToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.maskedTackingID = new System.Windows.Forms.MaskedTextBox();
            this.txtDirecciones = new System.Windows.Forms.TextBox();
            this.btnMostrarTodos = new System.Windows.Forms.Button();
            this.btnAgregar = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.groupBox1.SuspendLayout();
            this.cmsListas.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.lstEstadoEntregado);
            this.groupBox1.Controls.Add(this.lstEnViaje);
            this.groupBox1.Controls.Add(this.lstIngresados);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(616, 270);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Estados Paquetes";
            // 
            // rtbMostrar
            // 
            this.rtbMostrar.Enabled = false;
            this.rtbMostrar.Location = new System.Drawing.Point(12, 288);
            this.rtbMostrar.Name = "rtbMostrar";
            this.rtbMostrar.Size = new System.Drawing.Size(424, 131);
            this.rtbMostrar.TabIndex = 2;
            this.rtbMostrar.Text = "";
            this.rtbMostrar.TextChanged += new System.EventHandler(this.richTextBox1_TextChanged);
            // 
            // lstIngresados
            // 
            this.lstIngresados.FormattingEnabled = true;
            this.lstIngresados.Location = new System.Drawing.Point(0, 47);
            this.lstIngresados.Name = "lstIngresados";
            this.lstIngresados.Size = new System.Drawing.Size(187, 212);
            this.lstIngresados.TabIndex = 3;
            // 
            // lstEnViaje
            // 
            this.lstEnViaje.FormattingEnabled = true;
            this.lstEnViaje.Location = new System.Drawing.Point(193, 47);
            this.lstEnViaje.Name = "lstEnViaje";
            this.lstEnViaje.Size = new System.Drawing.Size(184, 212);
            this.lstEnViaje.TabIndex = 4;
            // 
            // lstEstadoEntregado
            // 
            this.lstEstadoEntregado.ContextMenuStrip = this.cmsListas;
            this.lstEstadoEntregado.FormattingEnabled = true;
            this.lstEstadoEntregado.Location = new System.Drawing.Point(386, 47);
            this.lstEstadoEntregado.Name = "lstEstadoEntregado";
            this.lstEstadoEntregado.Size = new System.Drawing.Size(187, 212);
            this.lstEstadoEntregado.TabIndex = 5;
            this.lstEstadoEntregado.SelectedIndexChanged += new System.EventHandler(this.listBox3_SelectedIndexChanged);
            // 
            // cmsListas
            // 
            this.cmsListas.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mostrarToolStripMenuItem});
            this.cmsListas.Name = "cmsListas";
            this.cmsListas.Size = new System.Drawing.Size(116, 26);
            this.cmsListas.Opening += new System.ComponentModel.CancelEventHandler(this.cmsListas_Opening);
            // 
            // mostrarToolStripMenuItem
            // 
            this.mostrarToolStripMenuItem.Name = "mostrarToolStripMenuItem";
            this.mostrarToolStripMenuItem.Size = new System.Drawing.Size(115, 22);
            this.mostrarToolStripMenuItem.Text = "Mostrar";
            this.mostrarToolStripMenuItem.Click += new System.EventHandler(this.mostrarToolStripMenuItem_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(21, 31);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(59, 13);
            this.label1.TabIndex = 8;
            this.label1.Text = "Ingresados";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(190, 31);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(46, 13);
            this.label2.TabIndex = 9;
            this.label2.Text = "En Viaje";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(383, 31);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(61, 13);
            this.label3.TabIndex = 10;
            this.label3.Text = "Entregados";
            // 
            // maskedTackingID
            // 
            this.maskedTackingID.Location = new System.Drawing.Point(6, 36);
            this.maskedTackingID.Mask = "000-000-0000";
            this.maskedTackingID.Name = "maskedTackingID";
            this.maskedTackingID.Size = new System.Drawing.Size(100, 20);
            this.maskedTackingID.TabIndex = 0;
            // 
            // txtDirecciones
            // 
            this.txtDirecciones.Location = new System.Drawing.Point(6, 86);
            this.txtDirecciones.Name = "txtDirecciones";
            this.txtDirecciones.Size = new System.Drawing.Size(100, 20);
            this.txtDirecciones.TabIndex = 1;
            // 
            // btnMostrarTodos
            // 
            this.btnMostrarTodos.Location = new System.Drawing.Point(193, 69);
            this.btnMostrarTodos.Name = "btnMostrarTodos";
            this.btnMostrarTodos.Size = new System.Drawing.Size(116, 37);
            this.btnMostrarTodos.TabIndex = 9;
            this.btnMostrarTodos.Text = "&Mostrar a Todos";
            this.btnMostrarTodos.UseVisualStyleBackColor = true;
            this.btnMostrarTodos.Click += new System.EventHandler(this.btnMostrarTodos_Click);
            // 
            // btnAgregar
            // 
            this.btnAgregar.Location = new System.Drawing.Point(193, 20);
            this.btnAgregar.Name = "btnAgregar";
            this.btnAgregar.Size = new System.Drawing.Size(116, 38);
            this.btnAgregar.TabIndex = 8;
            this.btnAgregar.Text = "&Agregar";
            this.btnAgregar.UseVisualStyleBackColor = true;
            this.btnAgregar.Click += new System.EventHandler(this.btnAgregar_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(6, 69);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(63, 13);
            this.label5.TabIndex = 12;
            this.label5.Text = "Direcciones";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(3, 20);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(63, 13);
            this.label4.TabIndex = 11;
            this.label4.Text = "Tracking ID";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.label4);
            this.groupBox3.Controls.Add(this.label5);
            this.groupBox3.Controls.Add(this.btnAgregar);
            this.groupBox3.Controls.Add(this.btnMostrarTodos);
            this.groupBox3.Controls.Add(this.txtDirecciones);
            this.groupBox3.Controls.Add(this.maskedTackingID);
            this.groupBox3.Location = new System.Drawing.Point(442, 288);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(330, 131);
            this.groupBox3.TabIndex = 6;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Paquetes";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(824, 514);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.rtbMostrar);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "Correo UTN por Nicolas.Fattori.2°A";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.cmsListas.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ListBox lstEstadoEntregado;
        private System.Windows.Forms.ListBox lstEnViaje;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ListBox lstIngresados;
        private System.Windows.Forms.RichTextBox rtbMostrar;
        private System.Windows.Forms.ContextMenuStrip cmsListas;
        private System.Windows.Forms.ToolStripMenuItem mostrarToolStripMenuItem;
        private System.Windows.Forms.MaskedTextBox maskedTackingID;
        private System.Windows.Forms.TextBox txtDirecciones;
        private System.Windows.Forms.Button btnMostrarTodos;
        private System.Windows.Forms.Button btnAgregar;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.GroupBox groupBox3;
    }
}

