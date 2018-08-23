using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FrmEjercicioClase22
{
    public partial class FrmTestDelegados : Form
    {
        private string ruta;

        public FrmTestDelegados()
        {
            this.ConfigurarOpenSaveFileDialog();
            InitializeComponent();
        }

        private void FrmTestDelegados_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            ((FrmPrincipal)this.Owner).d1(this.txtTexto.Text);
            ((FrmPrincipal)this.Owner).dFoto(this.ruta);

        }

        private void ConfigurarOpenSaveFileDialog()
        {
            this.opfFoto = new OpenFileDialog();
            this.opfFoto.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyPictures);
            this.opfFoto.DefaultExt = ".jpg";
            this.opfFoto.CheckFileExists = true;
            this.opfFoto.CheckPathExists = true;
            this.opfFoto.Multiselect = false;
            this.opfFoto.Title = "Seleccione una foto...";
            
        }

        private void btnBuscarFoto_Click(object sender, EventArgs e)
        {
            this.opfFoto.ShowDialog();
            this.ruta = this.opfFoto.FileName;
        }
    }
}
