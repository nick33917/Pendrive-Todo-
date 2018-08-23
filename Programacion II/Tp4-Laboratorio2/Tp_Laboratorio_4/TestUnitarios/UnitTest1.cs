using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Entidades;
namespace TestUnitarios
{
    [TestClass]
    public class TestUnitario
    {
        [TestMethod]
        public void ListaInstanciada()
        {
            Correo correo = new Correo();
            Assert.IsNotNull(correo.Paquetes);
        }

        [TestMethod]
        public void PaquetesDiferentes()
        {
            Paquete p1 = new Paquete("Lynch3710", "126");
            Paquete p2 = new Paquete("Mitre750", "126");
            Correo correo = new Correo();
            correo += p1;

            try
            {
                correo += p2;
            }
            catch
            {
                Assert.Fail("Mismo trackingID");

            }

            
        }


    }
}
