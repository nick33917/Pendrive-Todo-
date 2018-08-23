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
    int costo;
    int estado;
    int nroServicio;


}eServicio;


/*int parser_Cliente(ArrayList* empleados,char* path,FILE* personal);
void set_id(eEmpleado* empleado,int id);
int altaEmpleado(ArrayList* empleados,FILE* personal,char* path);
void escribirArchivoModif_Baja(FILE* personal,char* path,ArrayList* empleado);
void EscribirEnArchivo(eEmpleado* persona,FILE* personal,char* path);
void modificarEmpleado(ArrayList* empleados,FILE* personal,char* path);
void printeo(ArrayList* empleado);
*/
eCliente* new_cliente();
int altaCliente(ArrayList* cliente);
void printeo(ArrayList* cliente);
void lecturaBinario(ArrayList* cliente, char* path, FILE* clientes);
void EscrituraBinario(eCliente* cliente, char* path, FILE* clientes);
void setId(ArrayList* cliente , eCliente* persona);
void setDni(eCliente* persona, int aux);
void setApellido(eCliente* persona, char* apellido);
void setNombre(eCliente* persona, char* nombre);
void modificarCliente(ArrayList* cliente);
void bajaCliente(ArrayList* cliente);
int compararApellido(void* apellido1,void* apellido2);
void ordenarYMuestra(ArrayList* cliente);
eServicio*  new_servicio();
