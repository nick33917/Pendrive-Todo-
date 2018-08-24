typedef struct
{
    int id;
    char nombre[200];
    char apellido[200];
    char dni[200];
}eCliente;

typedef struct
{
    int idCliente;
    int idServicio;
    char codProducto[200];
    char fechaIngreso[200];
    float costoReparacion;
    int estado;

}eServicio;
