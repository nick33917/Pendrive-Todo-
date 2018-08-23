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
using System.Threading;
namespace Fattori.Nicolas._2A
{
    public partial class Form1 : Form
    {
        private List<Persona> _corredores;
        private List<Thread> _corredoresActivos;
        private bool _hayGanador;
        public Form1()
        {
            InitializeComponent();
            this._corredores = new List<Persona>();
            this._corredoresActivos = new List<Thread>();
            this._corredores.Add(new Persona("Fernando", 9, Corredor.Carril.Carril_1));
            this._corredores.Add(new Persona("Fernando", 15, Corredor.Carril.Carril_2));
            this._hayGanador = false;
        }

        private void LimpiarCarriles()
        {
            
        }

        private void HayGanador(Corredor corredor)
        {
            foreach (Thread hilo in this._corredoresActivos)
            {
                hilo.Suspend();
            }

        }

        private void btnCorrer_Click(object sender, EventArgs e)
        {
            foreach(Persona per in this._corredores)
            {
                
            }
            
        }

        private void PersonaCorriendo(int avance, Corredor corredor)
        {
            if (pgbCarril1.InvokeRequired || pgbCarril2.InvokeRequired)
            {
                CorrenCallback d = new CorrenCallback(PersonaCorriendo);
                this.Invoke(d, new object[] { avance, corredor });
            }
            else
            {
                // Aquí irá el código del alumno
            }
        }

    }
}
