typedef struct
{
    int idEmpleado;
    char nombre[20];
    char apellido[20];
    int dni;
}eCliente;

typedef struct
{
    char nombre [200];
    char apellido [200];
    int dni;
    char codigo[200];
    float costo;
    int estado;
    int nroServicio;


}eServicio;

eCliente*  new_cliente();
void altaPersona(ArrayList* cliente, char* path);
void mostrarClientes(ArrayList* clientes);
void modificarCliente(ArrayList* cliente , char* path);
void bajaCliente(ArrayList* cliente,char* path);
void lecturaArchivo(char* path, ArrayList* clientes);
void escrituraArchivo(char* path,ArrayList* clientes);
void setId(ArrayList* cliente , eCliente* persona);
void setDni(eCliente* persona, int aux);
void setApellido(eCliente* persona, char* apellido);
void setNombre(eCliente* persona, char* nombre);
void ordenaYmuestra(ArrayList* cliente);
int compararApellido(void* apellido1,void* apellido2);
void lecturaCsv(ArrayList* servicios);
eServicio* new_servicio();
void mostrarServicios(ArrayList* servicios);
void setNroServicio(eServicio* tarea, int nroServicio);
void setCosto(eServicio* tarea, float costo);
void setCodigo(eServicio* tarea, char* codigo);
void setEstado(eServicio* tarea, int estado);
void altaServicio(ArrayList* cliente, ArrayList* servicios ,char* path);
void escrituraTexto(ArrayList* servicios, char* path);
void bajaLogicaServicio(ArrayList* servicios, char* path);
