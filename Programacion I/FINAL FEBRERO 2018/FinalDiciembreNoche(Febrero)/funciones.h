typedef struct
{
    int idEmpleado;
    char nombre[20];
    char apellido[20];
    int dni;
}eCliente;

typedef struct
{
    int idVenta;
    int idCliente;
    int codigoProd;
    int cantidad;
    float precioUnit;

}eVenta;


eCliente*  new_cliente();
eVenta*  new_venta();
void lecturaClientes(ArrayList* clientes , char* path);
void lecturaVentas(ArrayList* ventas, char* path);
void escrituraClientes(ArrayList* clientes, char* path);
void escrituraVentas(ArrayList* ventas, char* path);
void setId(ArrayList* cliente, eCliente* persona);
void setDni(eCliente* persona, int aux);
void setNombre(eCliente* persona, char* nombre);
void setApellido(eCliente* persona, char* apellido);
void altaPersona(ArrayList* cliente, char* path);
void modificarCliente(ArrayList* cliente, char* path);
void bajaCliente(ArrayList* cliente,char* path);
int compararApellido(void* apellido1,void* apellido2);
void ordenaYmuestra(ArrayList* cliente);
