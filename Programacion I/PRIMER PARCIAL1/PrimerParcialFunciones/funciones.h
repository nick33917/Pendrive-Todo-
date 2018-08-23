#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{

    char nombre[MAX];
    int edad;
    int estado;
    int dni;

} EPersona;

/** \brief Obtiene el primer indice libre del array.
 *
 * @param lista el array se pasa como parametro.
 * @param tamaño del array de la estructura.
 * @return el primer indice disponible
 *
 */
int obtenerEspacioLibre(EPersona lista[],int tamb);




/** \brief Obtiene el indice que coincide con el dni pasado por parametro.
 *
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param tamaño del array de la estructura.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni y si no lo encuentra devuelve -1.
 *
 */
int buscarPorDni(EPersona lista[], int docum, int tam);




/** \brief inicia todos los estados de la estructura en 0.
 *
 * \param el array de la estrucutura.
 * \param tamaño del array de la estructura.
 * \return void.
 *
 */
void estadosEn0(EPersona personas[],int tam);




/** \brief ordena los nombres alfabeticamente y si hay 2 nombres iguales los ordena por dni.
 *
 * \param el array de la estrucutura.
 * \param tamaño del array de la estructura.
 * \return void.
 *
 */
void ordenarNombre(EPersona lista[],int tam);



/** \brief ingreso de una persona al sistema.Pide dni,nombre,edad y las valida.
 *
 * \param el array de la estrucutura.
 * \param tamaño del array de la estructura.
 * \param cantidad maxima de caracteres para ingresar el nombre.
 * \return void.
 *
 */
void altaPersona(EPersona lista[],int tam,int maximo);



/** \brief valida la cantidad maxima de caracteres que se puede ingresar.
 *
 * \param array donde se guarda el nombre ingresado.
 * \param cantidad maxima de caracteres para ingresar el nombre.
 * \return devuelve 0 si cumple con la condicion y devuelve 1 si no cumple .
 *
 */
int validarNombre(char aux[],int tam);



/** \brief cambia el estado a 0 de la persona que se quiere dar de baja en el sistema.
 *
 * \param el array de la estrucutura.
 * \param tamaño del array de la estructura.
 * \return void.
 *
 */
void bajaPersona(EPersona lista[],int tam);



/** \brief Muestra los datos de las personas (dni,nombre,edad).
 *
 * \param el array de la estrucutura.
 * \param tamaño del array de la estructura.
 * \return void.
 *
 */
void mostrarPersonas(EPersona lista[],int tam);



/** \brief muestra los datos de 1 sola persona(dni,nombre,edad).
 *
 * \param un array solo de la estructura.
 * \return void.
 *
 */
void mostrarPersona(EPersona unaPersona);




/** \brief valida si el numero ingresado no contenga letras.
 *
 * \param cadena de char donde se guarda el numero
 * \return devuelve distinto de 0 si contiene letras.
 *
 */
int validarNumero(char num[]);



/** \brief cuenta la cantidad de edades ingresadas y las separa en 3 rangos
 *
 * \param el array de la estrucutura.
 * \param cantidad de rangos en la que quiero dividir las edades.
 * \param tamaño del array de la estructura.
 * \return void.
 *
 */
void cantidadEdad(EPersona lista[],int cont[],int tam);



/** \brief busca el rango que mayor cantidad de edades tiene.
 *
 * \param rango.
 * \param cantidad de rangos.
 * \return devuelve el rango que mas cantidad de edades contiene.
 *
 */
int maximoContEdad(int cont[],int tam);




/** \brief va mostrando con un "*" a que rango pertenece cada edad ingresada.
 *
 * \param el array de la estrucutura.
 * \param tamaño del array de la estructura.
 * \return void.
 *
 */
void graficoRango(EPersona lista[],int tam);

/** \brief modifica los datos de una persona.
 *
 * \param [] el array de la estructura.
 * \param int tamaño del array.
 * \param int maxima cantidad de letras que tiene el nombre.
 * \return void.
 *
 */
void ModificarPersona(EPersona [],int ,int );



#endif // FUNCIONES_H_INCLUDED


//-------------------------****************-------------------
/** \brief hardcodea los campos de una estructura.
 *
 * \param personas[] eCliente el array de la estructuca.
 * \param CantCliente int tamaño del array.
 * \return void
 *
 */
void cargarClientes(eCliente[],int);



/** \brief hardcodea los campos de la estructura.
 *
 * \param estados[] eSituacion un array de estructuca.
 * \param cantEst int tamaño del array.
 * \return void
 *
 */
void cargarSituaciones(eSituacion[],int );



/** \brief hardcodea los campos de la estructura.
 *
 * \param herramientas[] eEquipo un array de estructura.
 * \param cantEquip int tamaño del array.
 * \return void
 *
 */
void cargarEquipo(eEquipo[],int );




/** \brief muestra cada clientes con los productos que alquilo.
 *
 * \param personas[] eCliente un array de estructura (uno).
 * \param cantCliente int tamaño del array uno.
 * \param herramientas[] eEquipo otro array de estructura(dos).
 * \param cantEquipo int tamaño del array dos.
 * \param alquileres[] eAlquiler otro array de estructura(tres).
 * \param cantAlq int tamaño del array tres.
 * \return void
 *
 */
void mostrarClientesConAlquileres(eCliente [],int,eEquipo [],int,eAlquiler [],int );



/** \brief hardcodea los campos de la estructura.
 *
 * \param alquileres[] eAlquiler un array de estructura.
 * \param cantAlq int tamaño del array.
 * \return void
 *
 */
void cargarAlquileres(eAlquiler [],int);



/** \brief calcula y muestra el promedio de tiempo real que se alquilaron los productos.
 *
 * \param eEquipo[] un array de estructura(uno).
 * \param int tamaño del array uno.
 * \param eAlquiler[] otro array de estructura(dos).
 * \param int tamaño del array dos.
 * \param eSituacion[] otro array de estructura(tres).
 * \param int tamaño del array tres.
 * \return void
 *
 */
void promedioTiempoReal(eEquipo[],int ,eAlquiler[],int,eSituacion[],int);




/** \brief muestra las herramientas que mas fueron alquiladas.
 *
 * \param eEquipo[] un array de estructura (uno).
 * \param int tamaño del array 1.
 * \param [] eAlquiler un array de estructura (dos).
 * \param int tamaño del array dos.
 * \return void
 *
 */
void mostrarEquiposMasAlquilados(eEquipo[],int,eAlquiler [],int);



/** \brief calcula el producto que mas se alquilo(el maximo).
 *
 * \param [] eAlquiler un array de estructura(uno).
 * \param int tamaño del array uno.
 * \param eEquipo[] un array de estructura(dos).
 * \param int tamaño del array dos.
 * \return int devuelve el maximo.
 *
 */
int maximoDeEquipos(eAlquiler [],int ,eEquipo[],int );




/** \brief cuenta la cantidad de 1 producto que se alquilo.
 *
 * \param int un producto.
 * \param eAlquiler[] un array de estructura.
 * \param int tamaño del array.
 * \return int devuelve la cantidad .
 *
 */
int cantidadDeEquipos(int ,eAlquiler[],int );



/** \brief muestra los clientes que tienen mas productos alquilados.
 *
 * \param eCliente[] un array de estructura(uno).
 * \param int tamaño del array uno.
 * \param eAlquiler[] otro array de estructura(dos).
 * \param int tamaño del array dos.
 * \return void
 *
 */
void mostrarClientesConMasAlquileres(eCliente[],int ,eAlquiler[],int );



/** \brief calcula el cliente que mas alquilo productos(el maximo).
 *
 * \param [] eAlquiler un array de estructura(uno).
 * \param int tamaño del array uno.
 * \param [] eCliente un array de estructura(dos).
 * \param int tamaño del array dos.
 * \return int devuelve el maximo.
 *
 */
int maximoDeClientes(eAlquiler [],int ,eCliente [],int );





/** \brief cuenta la cantidad de alquileres que tiene un cliente.
 *
 * \param int un cliente.
 * \param [] eAlquiler un array de estructura.
 * \param int tamaño del array.
 * \return int devuelve la cantidad .
 *
 */
int cantidadDeClientes(int ,eAlquiler [],int );




/** \brief muestra cada materia con la cantidad de veces que se inscribieron.
 *
 * \param [] eMateria un array de estructura(uno).
 * \param int tamaño del array uno.
 * \param [] eInscripcion un array de estructura(dos).
 * \param int tamaño del array dos.
 * \return void
 *
 */
void mostrarMateriaConCantDeInscriptos(eMateria [],int,eInscripcion [],int);


