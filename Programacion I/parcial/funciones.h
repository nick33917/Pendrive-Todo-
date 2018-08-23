typedef struct
{
    int id;
    char descrip[20];
    int valorHs;
} eCategoria;

typedef struct
{
    int idprog;
    int idproy;
    int hstrabaj;
    int estado;
} eProg_proy;

typedef struct
{
    int idproy;
    char descrip[20];
} eProyecto;

typedef struct
{
    int id;
    char nombre[20];
    int estado;
    char cat[20];
    int sueldo;

}eProgramador;


void inicializarEn0(eProg_proy realcion[],int tam);
void inicializarVector(eProgramador lista[],int tam);
void ingresarUsuarios(eProgramador lista[],int tam);
void cargarProg_proy(eProg_proy relacion[],int tam);
void cargarProyecto(eProyecto proy[],int tam);
void mostrarProg_Proy(eProgramador lista[],eProyecto proy[],eProg_proy relacion[],int cantProg,int cantProy,int cantProgProy);
void mostrarCadaProyecto(eProgramador lista[],eProyecto proy[],eProg_proy relacion[],int cantProg,int cantProy,int cantProgProy);
void cargarCat(eCategoria cat[], int tam);
void saladrioProg(eProgramador lista[],eProg_proy relacion[],eCategoria categoria[],int cantProg,int cantProgProy,int cantcat);
void proyectoConMasProg(eProgramador lista[],eProyecto proy[],eProg_proy relacion[],int cantProg,int cantProy,int cantProgProy);
