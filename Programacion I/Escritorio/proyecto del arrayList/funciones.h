typedef struct
{
    char nombre[20];
    char mail[51];
}ePersona;



ePersona* persona_new(void);
int parserPersona(FILE* pFile , ArrayList* thisPersona);
void depurar(ArrayList* lista, ArrayList* listaNegra,ArrayList* depurada);
int compararMail(void* mail1,void* mail2);
int ordenamiento(void* pElement,void*pElement2);
void print_Lista(ArrayList* lista);
