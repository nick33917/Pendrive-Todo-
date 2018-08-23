using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Interfaces;
using System.Threading;
namespace Entidades
{
    public class InfoHilo
    {
        private IRespuesta<int> _callBack;
        private Thread _hilo;
        private int _id;
        private static Random _randomizer;

        static InfoHilo()
        {
            _randomizer = new Random();
        }

        public InfoHilo(int id, IRespuesta<int> callback)

        {
            this._id = id;
            this._callBack = callback;
            this._hilo = new Thread(Ejecutar);
            this._hilo.Start();
            
        }

        private void Ejecutar()
        {
            int tiempo = InfoHilo._randomizer.Next(1000,5000);
            Thread.Sleep(tiempo);
            this._callBack.RespuestaHilo(this._id);
        }

        
    }
}
