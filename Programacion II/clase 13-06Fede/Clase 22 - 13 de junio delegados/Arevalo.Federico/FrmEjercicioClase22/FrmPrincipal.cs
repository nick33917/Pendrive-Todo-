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
    public delegate void Delegado(string texto);
    public delegate void DelegadoAlumno(Entidades.Alumno sender, EventArgs e);

    public partial class FrmPrincipal : Form
    {
        public Delegado d1;
        public Delegado dFoto;
        public DelegadoAlumno dAlumno;
        



        public FrmPrincipal()
        {
            InitializeComponent();
        }

        private void altaToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void testDelegadosToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FrmTestDelegados frmDelegados = new FrmTestDelegados();
            frmDelegados.Show(this);

            
        }

        private void datosToolStripMenuItem_Click(object sender, EventArgs e)
        {
            
        }

        private void mostrarToolStripMenuItem_Click(object sender, EventArgs e)
        {
           
        }

        private void FrmPrincipal_Load(object sender, EventArgs e)
        {

        }

        private void alumnosToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FrmAltaAlumno frmAltaAlumno = new FrmAltaAlumno();

            frmAltaAlumno.Show(this);
        }

        private void testToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FrmDatos frmDatos = new FrmDatos();
            frmDatos.Show(this);

            d1 = new Delegado(frmDatos.ActualizarNombre);
            dFoto = new Delegado(frmDatos.ActualizarFoto);
        }

        private void alumnoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FrmDatosAlumno frmDatosAlumno = new FrmDatosAlumno();
            frmDatosAlumno.Show(this);

            dAlumno = new DelegadoAlumno(frmDatosAlumno.ActualizarAlumno);
        }
    }
}
