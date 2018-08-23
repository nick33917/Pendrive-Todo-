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
    public partial class FrmDatosAlumno : FrmAltaAlumno
    {
        public FrmDatosAlumno()
        {
            InitializeComponent();
        }

        public void ActualizarAlumno(Entidades.Alumno sender, EventArgs e)
        {
            this.txtApellido.Text = sender.Apellido;
            this.txtDNI.Text = sender.DNI;
            this.txtNombre.Text = sender.Nombre;
            this.ptbFoto.ImageLocation = sender.FotoAlumno;
        }
    }
}
