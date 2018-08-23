typedef struct
{
    int idEmpleado;
    char nombre[20];
    char apellido[20];
    int dni;
}eCliente;

typedef struct
{

    int idCliente;
    char codigoProd [17];
    int cantidad;
    float precioUnit;
    char fechaVenta [200];
}eVenta;


eCliente*  new_cliente();
eVenta*  new_venta();
void lecturaClientes(ArrayList* clientes , char* path);
void escrituraClientes(ArrayList* clientes, char* path);
void setId(ArrayList* cliente, eCliente* persona);
void setDni(eCliente* persona, int aux);
void setNombre(eCliente* persona, char* nombre);
void setApellido(eCliente* persona, char* apellido);
void altaPersona(ArrayList* cliente, char* path);
void modificarCliente(ArrayList* cliente, char* path);
void bajaCliente(ArrayList* cliente,char* path);
int compararApellido(void* apellido1,void* apellido2);
void ordenaYmuestra(ArrayList* cliente);
void setFecha(eVenta* pedido, char* fecha);
void setCodigo(eVenta* pedido, char* codigo);
void setPrecio(eVenta* pedido, float aux);
void setCantidad (eVenta* pedido, int aux);
void setIdCliente(eVenta* pedido, int aux);
void altaVenta(ArrayList* ventas);
void mostrarVentas(ArrayList* ventas);
void generarCsvVentas(ArrayList* ventas,ArrayList* clientes);
void generarCsvVentasdeFecha(ArrayList* ventas,ArrayList* clientes);
