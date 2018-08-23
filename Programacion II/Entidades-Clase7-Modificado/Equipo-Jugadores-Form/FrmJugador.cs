using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Entidades_Clase7;
namespace Equipo_Jugadores_Form
{
    public partial class FrmJugador : Form
    {
        public FrmJugador()
        {
            InitializeComponent();// ejecuta el codigo que se autogenero//

        }
        public FrmJugador(Jugador objJugador) : this()
        {
            this._jugador = objJugador;
            this.txtDni.Text = Convert.ToString(objJugador.Dni);
            this.txtNombre.Text=objJugador.Nombre;
            this.txtPartidosJugados.Text = Convert.ToString(objJugador.PartidosJugador);
            this.txtGoles.Text = Convert.ToString(objJugador.TotalGoles);
            this.txtDni.Enabled = false ;
                
        }
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private Jugador _jugador;

        public Jugador getJugador()
        {
            return this._jugador;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            long dni = long.Parse(this.txtDni.Text);
            string nombre = this.txtNombre.Text;
            int goles = int.Parse(this.txtGoles.Text);
            int partidos = int.Parse(this.txtPartidosJugados.Text);
            // MessageBox.Show(_jugador.MostrarDatos());
          
            if (((object)this._jugador)!= null)
            {
               
                this._jugador.Nombre = this.txtNombre.Text;
                this._jugador.PartidosJugador = int.Parse(this.txtPartidosJugados.Text);
                this._jugador.TotalGoles = int.Parse(this.txtGoles.Text);
            }
            else
            {
                this._jugador = new Jugador(nombre, goles, partidos, dni);
            }

            this.DialogResult = System.Windows.Forms.DialogResult.OK;
        }


        

    }
}
