
typedef struct
{
    char nombre[20];
    char mail[51];
}ePersona;




ePersona* persona_new(void);

/** \brief parsea un archivo y guarda los elementos en un arrayList
 *
 * \param pFile FILE* archivo
 * \param thisPersona ArrayList*
 * \return int
 *
 */
int parserPersona(FILE* pFile , ArrayList* thisPersona);

/** \brief compara 2 elementos si son iguales
 *
 * \param mail1 void* puntero al elemento1
 * \param mail2 void* puntero al elemento2
 * \return int devuelve 1 si son iguales , devuelve 0 si son diferentes
 *
 */
int compararMail(void* mail1,void* mail2);

/** \brief crea una nueva lista con los elementos depurados
 *
 * \param lista ArrayList*
 * \param listaNegra ArrayList*
 * \param depurada ArrayList*
 * \return int devuelve 1 si la pudo crear , devuelve -1 si no la pudo crear
 *
 */
int depurar(ArrayList* lista, ArrayList* listaNegra,ArrayList* depurada);


/** \brief muestra los elementos que contiene el arrayList
 *
 * \param lista ArrayList*
 * \return void
 *
 */
void mostrarLista(ArrayList* lista);



void set_name(ePersona* persona, char* nombre);
void set_mail(ePersona* persona, char* mail);
ePersona* get_name(ePersona* persona,int index);
ePersona* get_mail(ArrayList* this,int index);
int parserBlackList(FILE* black_list,ArrayList* listaNegra,ArrayList* lista);
