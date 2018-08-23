typedef struct
{
    char nombre[150];
    char email[150];

}eDestinatario;

/** \brief Constructor del destinatario.
 *
 * \return Puntero a estructura destinatario.
 *
 */
eDestinatario* new_destinatario();
/** \brief Lee el archivo y lo guarda en una lista.
 *
 * \param Puntero a lista.
 * \param Nombre del archivo (path).
 * \return (-1) Si hay algun error (pFile es NULL o lista es NULL) y devuelve (0) si todo esta correcto.
 *
 */
int parserGenerico(FILE* pFile, ArrayList* lista, char* path);
/** \brief Genera la lista definitiva.
 *
 * \param Puntero a la listaBlanca.
 * \param Puntero a la listaNegra.
 * \param Puntero a la listaFinal.
 * \return (-1) Si hay algun error (si pFile o alguna de las listas es NULL) y devuelve (0) si todo esta correcto.
 *
 */
int listaDefinitiva(ArrayList* listaBlanca, ArrayList* listaNegra, ArrayList* listaFinal);
/** \brief Ordena el arraylist de una lista de A-Z.
 *
 * \param Puntero a lista.
 *
 */
void ordenar(ArrayList* lista);
/** \brief Imprime una lista.
 *
 * \param Puntero a lista
 *
 */
void imprimir(ArrayList* lista);
/** \brief Setea el nombre del destinatario.
 *
 * \param Puntero a estructura del destinatario.
 * \param Nombre del destinatario.
 * \return
 *
 */
int destinatario_setNombre(eDestinatario* destinatario, char* nombre);
/** \brief Obtiene el nombre del destinatario.
 *
 * \param Puntero a estructura del destinatario.
 * \return Si todo es correcto devuelve el nombre del destinatario, sino devuelve (NULL)
 *
 */
char* destinatario_getNombre(eDestinatario* destinatario);
/** \brief Setea el email del destinatario.
 *
 * \param Puntero a estructura del destinatario.
 * \param Email del destinatario.
 * \return Retorna (0) si todo es correcto y (-1) si hay fallos.
 *
 */
int destinatario_setEmail(eDestinatario* destinatario, char* email);
/** \brief Obtiene el email del destinatario.
 *
 * \param Puntero a estructura del destinatario.
 * \return Si todo es correcto devuelve el email del destinatario, sino devuelve (NULL)
 *
 */
char* destinatario_getEmail(eDestinatario* destinatario);


