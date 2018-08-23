using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Clase23_05;
using System.IO;
namespace FrmJugador
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            foreach (EPuesto item in Enum.GetValues(typeof(EPuesto)))
            {
               this.cboPuesto.Items.Add(item);
            }
            //no me deja editar el combo box(no puedo agregarle letras//
            this.cboPuesto.DropDownStyle = ComboBoxStyle.DropDownList;

            //inicia por defecto en arquero//
            this.cboPuesto.SelectedItem = EPuesto.Arquero;


           
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void btnGuardar_Click(object sender, EventArgs e)
        {
            Jugador jug = new Jugador(this.txtNombre.Text, this.txtApellido.Text, ((EPuesto)this.cboPuesto.SelectedItem));
           // MessageBox.Show(jug.ToString());
            //se pone la barra \\ para poder guardarlo  o pongo @ para que no asuma ningun caracter de escape(\)//
            //StreamWriter archivo = new StreamWriter(@"D:\jugadores.txt",true)( agrego varios jugadores al archivo)//
            //StreamWriter archivo = new StreamWriter(@"D:\jugadores.txt",true);
            //archivo.WriteLine(jug.ToString());
            //archivo.Close();
            ////lectura archivo//
            ////StreamReader lectura = new StreamReader(@"D:\jugadores.txt");
            ////MessageBox.Show( lectura.ReadToEnd());
            //StreamReader lectura = new StreamReader(@"D:\jugadores.txt");
            //string linea;
            //while ((linea = lectura.ReadLine()) != null)
            //{
            //    MessageBox.Show(linea);

            //}

            //lectura.Close();
// escritura del archivo 
            
           //string path = Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + @"\jugadores.txt";//(ruta relativa)devuelve el usuario donde estamos parado + el archivo que voy a crear//
           string path = ""; 
            //recupero el path//
           if (this.saveFileDialog1.ShowDialog() == DialogResult.OK)
           {
                path= this.saveFileDialog1.FileNames[0];
           }
           bool flag = AdministradorDeArchivos.Escribir(path, jug.ToString(), true);
           if (flag)
           {
               MessageBox.Show(jug.ToString());
           }
           else
           {
               MessageBox.Show("No se pudo agregar al archivo");
           }


 // lectura del archivo
            //string s;
            //bool flag1 = AdministradorDeArchivos.Leer(@"C:\usuarios\alumno\desktop\jugadores.txt",out s);
            //if (flag1)
            //{
            //    MessageBox.Show("Se leyo el  archivo correctamente");
            //}
            //else
            //{
            //    MessageBox.Show("No se pudo leer el archivo");
            //}

        }

        private void saveFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            
        }

        private void btnTraer_Click(object sender, EventArgs e)
        {
            Jugador jug = new Jugador(txtNombre.Text, txtApellido.Text, ((EPuesto)this.cboPuesto.SelectedItem));
            MessageBox.Show("Buscando");
            this.txtNombre.Clear();
            this.txtApellido.Clear();
            Jugador jugEncontrado;
            bool flag = Jugador.TraerUno(@"D:\jugadores.txt", jug, out jugEncontrado);
            if (flag)
            {
                txtNombre.Text = jugEncontrado.Nombre;
                txtApellido.Text = jugEncontrado.Apellido;
                cboPuesto.SelectedItem = jugEncontrado.Puesto;
            }
            else
            {
                MessageBox.Show("No se encontro");
            }
            
            

        }

        private void txtNombre_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
