using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Entidades;

namespace FrmEjercicioClase22
{
    public partial class FrmAltaAlumno : Form
    {
        Alumno a1;

        public FrmAltaAlumno()
        {
            this.ConfigurarOpenSaveFileDialog();
            InitializeComponent();
        }

        private void btnAceptar_Click(object sender, EventArgs e)
        {
            string apellido = this.txtApellido.Text;
            string nombre = this.txtNombre.Text;
            string dni = this.txtDNI.Text;
            string foto = this.txtFoto.Text;

            a1 = new Alumno(apellido, nombre, dni, foto);

            ((FrmPrincipal)this.Owner).dAlumno(a1, new EventArgs());
        }

        private void txtFoto_TextChanged(object sender, EventArgs e)
        {
            this.opfFotoAlumno.ShowDialog();

            string ruta = this.opfFotoAlumno.FileName;           

            this.txtFoto.Text = ruta;
        }

        private void btnCancelar_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void ConfigurarOpenSaveFileDialog()
        {
            this.opfFotoAlumno = new OpenFileDialog();
            this.opfFotoAlumno.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyPictures);
            this.opfFotoAlumno.DefaultExt = ".jpg";
            this.opfFotoAlumno.CheckFileExists = true;
            this.opfFotoAlumno.CheckPathExists = true;
            this.opfFotoAlumno.Multiselect = false;
            this.opfFotoAlumno.Title = "Seleccione una foto...";

        }
    }
}
