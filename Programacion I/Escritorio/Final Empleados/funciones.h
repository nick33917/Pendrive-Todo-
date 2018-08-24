typedef struct
{
    int idEmpleado;
    char nombre[20];
    char apellido[20];
    int dni;
}eEmpleado;

typedef struct
{
    int idRegistro;
    int idEmpleado;
    int cantHoras;

}eRegistro;

eEmpleado* new_empleado();
int parser_Empleado(ArrayList* empleados,char* path,FILE* personal);
void set_id(eEmpleado* empleado,int id);
int altaEmpleado(ArrayList* empleados,FILE* personal,char* path);
void escribirArchivoModif_Baja(FILE* personal,char* path,ArrayList* empleado);
void EscribirEnArchivo(eEmpleado* persona,FILE* personal,char* path);
void modificarEmpleado(ArrayList* empleados,FILE* personal,char* path);
void printeo(ArrayList* empleado);

