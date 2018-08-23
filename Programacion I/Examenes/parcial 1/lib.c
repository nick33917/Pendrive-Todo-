#include "lib.h"
int menu(char mensaje[])
{
    int opcion;
    printf("%s",mensaje);
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);
    return opcion;
}
void inicializarEstados(eProgramador programadores[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        programadores[i].estado=0;
    }
}
int alta(eProgramador programadores[],int tam)
{
    char auxStringId[100],auxStringNombre[100], auxStringApellido[100],auxStringIdCategoria[100]; // 4 VARIABLES AUXILIARES STRINGS
    int auxId,auxIdCategoria,libre;// 3 VARIABLES AUXILIARES ENTERAS
    libre=posicionLibre(programadores,tam);//ASIGNA LA POSICION LIBRE A LA VARIABLE SINO HAY LIBRES ENTREGA -1
    if(libre==-1)//SI LIBRE ES -1 ES POR QUE ESTA LLENO
    {
        printf("Error 404 la base de datos esta llena.\n");
        return 0;
    }
    if(!getStringNumeros("Ingrese ID para crear programador: ",auxStringId)) // VERIFICACION DEL ID
    {
        printf("El id debe contener solo numeros.\n");
        return 0;
    }
    auxId=atoi(auxStringId);// PASA EL STRING DE ID AL INT
    if(!verificarId(programadores,tam,auxId))// VERIFICACION DEL ID
    {
        printf("El ID ya se encuentra en uso.");
        return 0;
    }
    if(!getStringLetras("Ingrese nombre: ",auxStringNombre)) // VERIFICACION DEL NOMBRE
    {
        printf("El nombre debe contener solo letras.\n");
        return 0;
    }
    if(!getStringLetras("Ingrese apellido: ",auxStringApellido))// VERIFICACION APELLIDO
    {
        printf("El apellido debe contener solo letras.\n");
        return 0;
    }
    if(!getStringNumeros("Ingrese categoria(1-Junior 2-Semi-Senior 3-Senior)\n",auxStringIdCategoria)) // VERIFICACION APELLIDO
    {
        printf("La categoria tiene que ser en numeros.\n");
        return 0;
    }
    auxIdCategoria=atoi(auxStringIdCategoria); // PASA EL STRING DE IDCATEGORIA AL INT
    if(auxIdCategoria<1 || auxIdCategoria>3)// VALIDACION CATEGORIA
    {
        printf("La categoria tiene que ser entre 1 y 3.\n");
        return 0;
    }
    programadores[libre].id=auxId;
    strcpy(programadores[libre].nombre,auxStringNombre);
    strcpy(programadores[libre].apellido,auxStringApellido);
    programadores[libre].idCategoria=auxIdCategoria;
    programadores[libre].estado=1;
    return 1;
}
int posicionLibre(eProgramador programadores[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        if(programadores[i].estado==0)
            return i;
    }
    return -1;
}
int verificarId(eProgramador programadores[],int tam,int id)
{
    for(int i=0; i<tam; i++)
    {
        if(programadores[i].id==id) // SI MATCHEA RETORNA FALSO
        {
            return 0;
        }
    }
    return 1;
}
void hardCodear(eProgramador programadores[],eProyecto proyectos[],eCategoria categorias[],eProgramadorProyecto programadorproyectos[])
{
    //AUX PROGRAMADOR
    eProgramador AuxProgramadores[5]= {{1,"Lucas","Massa",3,1},{2,"Augusto","Alviggi",2,1},{3,"Martin","Alberio",1,1},{4,"Santi","Bonasi",2,1},{5,"Leandro","Ripo",3,1}};
    // CARGA 5 PERSONAS CON EL AUXILIAR
    for(int i=0; i<5; i++)
    {
        programadores[i]=AuxProgramadores[i];
    }
    //AUX CATEGORIA
    eCategoria AuxCategoria[3]= {{1,"Junior",30},{2,"Semi-Senior",60},{3,"Senior",90}};
    //CARGA 3 CATEGORIAS CON EL AUXILIAR
    for(int i=0; i<3; i++)
    {
        categorias[i]=AuxCategoria[i];
    }
    //AUX PROYECTOS
    eProyecto AuxProyectos[5]= {{1,"Bronze"},{2,"Silver"},{3,"Gold"},{4,"Platinum"},{5,"Diamond"}};
    //CARGA 5 PROYECTOS CON EL AUXILIAR
    for(int i=0; i<5; i++)
    {
        proyectos[i]=AuxProyectos[i];
    }
    //AUX PP
    eProgramadorProyecto AuxPP[10]= {{1,2,8},{1,3,9},{2,1,5},{2,5,7},{3,4,7},{3,2,5},{4,1,8},{4,5,4},{4,2,3},{5,5,6}};
    for(int i=0; i<10; i++)
    {
        programadorproyectos[i]=AuxPP[i];
    }
}
int modificar(eProgramador programadores[],eProgramadorProyecto pp[],eProyecto proyectos[],int tam,int tamPP,int tamp)
{
    char auxStringId[100],auxStringNombre[100], auxStringApellido[100],auxStringIdCategoria[100],auxStringHoras[100],auxStringIdProyecto[100]; // 4 VARIABLES AUXILIARES STRINGS
    int auxId,id,auxIdCategoria,auxHoras,auxIdProyecto,flag=0;// 3 VARIABLES AUXILIARES ENTERAS
    if(!getStringNumeros("Ingrese ID a modificar: ",auxStringId)) // VERIFICACION DEL ID
    {
        printf("El id debe contener solo numeros.\n");
        return 0;
    }
    id=atoi(auxStringId);// PASA EL STRING DE ID AL INT
    for(int i=0; i<tam; i++)
    {
        if(id==programadores[i].id && programadores[i].estado==1)
        {
            flag=1;
            switch(menu("¿Que opcion quiere modificar?\n1-ID\n2-Nombre\n3-Apellido\n4-Categoria\n5-Horas de trabajo\n6-Ninguna\n"))
            {
            case 1:
                if(!getStringNumeros("ID modificado: ",auxStringId))// VERIFICA EL ID
                {
                    printf("El id debe tener solo numeros\n");
                    return 0;
                }
                auxId=atoi(auxStringId);// PASA LA CADENA A UN ENTERO
                if(!verificarId(programadores,tam,auxId))//VERIFICA QUE NO SEA UN ID REPETIDO
                {
                    printf("Ese ID ya existe.\n");
                    return 0;
                }
                for(int i=0; i<tamPP; i++)
                {
                    if(id==pp[i].idProgramador)
                    {
                        pp[i].idProgramador=id;
                    }
                }
                programadores[i].id=auxId;
                break;
            case 2:
                if(!getStringLetras("Nombre modificado: ",auxStringNombre))//VERIFICA QUE TENGA SOLO LETRAS
                {
                    printf("El nombre debe tener solo letras.\n");
                    return 0;
                }
                strcpy(programadores[i].nombre,auxStringNombre);//COPIA EL AUXILIAR A EL ORIGINAL
                break;
            case 3:
                if(!getStringLetras("Apellido modificado: ",auxStringApellido))//VERIFICA QUE TENGA SOLO LETRAS
                {
                    printf("El nombre debe tener solo letras.\n");
                    return 0;
                }
                strcpy(programadores[i].apellido,auxStringApellido);//COPIA EL AUXILIAR A EL ORIGINAL
                break;
            case 4:
                if(!getStringNumeros("\nCategorias: (1-Junior\2-Semi Senior\3-Senior): ",auxStringIdCategoria))//VERIFICA QUE LA CATEGORIA SOLO TENGA NUMEROS
                {
                    printf("La categoria debe ser solo numeros.\n");
                    return 0;
                }
                auxIdCategoria=atoi(auxStringIdCategoria);// PASA LA CADENA A UN ENTERO
                if(auxIdCategoria<1 || auxIdCategoria>3)//VALIDA QUE SEA UNA CATEGORIA CORRECTA
                {
                    printf("La categoria debe estar entre 1 y 3.\n");
                    return 0;
                }
                programadores[i].idCategoria=auxId;//LE ASIGNA EL ID AL ORIGINAL


                break;
            case 5:
                if(!getStringNumeros("Ingrese las horas de trabajo modificado: ",auxStringHoras))//VALIDA QUE NO INGRESEN LETRAS
                {
                    printf("La hora debe tener solo numeros.\n");
                    return 0;
                }
                auxHoras=atoi(auxStringHoras);// PASA LA CADENA A ENTERO
                for(int j=0; j<tamPP; j++)//RECORRO PP
                {
                    if(programadores[i].id==pp[j].idProgramador)//MATCH ID DE PROG CON ID DE PP
                    {
                        for(int k=0; k<tamp; k++) //RECORRO PROYECTOS
                        {
                            if(pp[j].idProyecto==proyectos[k].idProyecto)// MATCH ID PROYECTO CON EL OTRO PROYECTO
                            {
                                printf("\n%d\t\t%s\n",proyectos[k].idProyecto,proyectos[k].nombre);// MUESTRO NOMBRE Y ID
                            }
                        }
                    }
                }
                if(!getStringNumeros("A cual proyecto quiere modificarle las horas?: ",auxStringIdProyecto))//VALIDO NUMEROS
                {
                    printf("El proyecto debe tener solo numeros.\n");
                    return 0;
                }
                auxIdProyecto=atoi(auxStringIdProyecto);//PASO DE CADENA A ENTERO
                for(int j=0; j<tamPP; j++)// RECORRO PP
                {
                    if(programadores[i].id==pp[j].idProgramador && pp[j].idProyecto==auxIdProyecto)//MATCHEO ID
                    {
                        pp[j].horasDeTrabajo=auxHoras;// PASA EL AUXILIAR AL ORIGINAL
                        break;
                    }
                }
                break;
            default:
                printf("Modificacion cancelada");
                return 0;
                break;
            }
        }
    }
    if(!flag)// FLAG DE CONTROL PARA VER SI NO ENCONTRO EL IF
    {
        printf("No se encuentra el ID ingresado.\n");
        return 0;
    }
    return 1;
}
int baja(eProgramador programadores[],eProgramadorProyecto pp[],int tam,int tamPP)
{
    char auxStringId[100],respuesta;
    int auxId,flag=0;
    if(!getStringNumeros("Ingrese id para eliminar a un programador: ",auxStringId))//VALIDA QUE NO INGRESEN LETRAS
    {
        printf("El id debe contener solo numeros\n");
        return 0;
    }
    auxId=atoi(auxStringId);//PASA CADENA A ENTERO
    for(int i=0; i<tam; i++) //RECORRE LOS ID
    {
        if(auxId==programadores[i].id && programadores[i].estado==1)//MATCHEA EL ID
        {
            flag=1;
            printf("%s %s [ID:%d] [IDC:%d]\n",programadores[i].nombre,programadores[i].apellido,programadores[i].id,programadores[i].idCategoria);
            printf("Esta seguro de eliminar a este programador? [S]i. [N]o.\n");
            respuesta=getche();// RECIBE S O N
            if(respuesta=='s' || respuesta=='S')
            {
                programadores[i].estado=0;// ELIMINA
                for(int j=0; j<tamPP; j++)
                {
                    if(auxId==pp[j].idProgramador)// MATCHEA PROGRAMADORES PROYECTOS PARA QUE NO QUEDE GUARDADO EL ANTERIOR ID
                    {
                        pp[j].idProgramador=-1;
                        pp[j].idProyecto=-1;
                    }
                }
            }
            else
            {
                printf("Eliminacion cancelada.\n");//CANCELA
                return 0;
            }
        }
    }
    if(!flag)// SINO SE ENCUENTRA EL ID
    {
        printf("No se encuentra el id para eliminar.\n");
        return 0;
    }
    return 1;
}
int asignarProgramador(eProgramador programadores[],eProyecto proyectos[],eProgramadorProyecto pp[],int tam,int tamp,int tampp)
{
    char auxStringId[100],auxStringIdProyecto[100],auxStringHoras[100];
    int auxId,auxIdProyecto,auxHoras,flag=0,flag2=0,flag3=0;
    for(int i=0; i<tam; i++)
    {
        if(programadores[i].estado==1)
        {
            if(!flag)//PARA MOSTRAR LA PRIMERA BARRA
                printf("ID\t\tNombre\t\tApellido\t\tCategoria 1-J 2-SS 3-S\n");
            printf("%d\t\t%s\t\t%s\t\t\t%d\n",programadores[i].id,programadores[i].nombre,programadores[i].apellido,programadores[i].idCategoria);
            flag=1;
        }
    }
    if(!getStringNumeros("Elija un ID del programador al que quiere asignarle un proyecto: ",auxStringId))//VALIDA EL ID
    {
        printf("El ID debe tener solo numeros.\n");
        return 0;
    }
    auxId=atoi(auxStringId);//PASA DE CADENA A ENTERO
    for(int i=0; i<tam; i++) //RECORE PROGRAMADORES
    {
        if(auxId==programadores[i].id && programadores[i].estado==1)// MATCHEA EL ID
        {
            flag2=1;// FLAG PARA SABER SI SE ENCONTRO EL ID DEL PROGRAMADOR
            for(int j=0; j<tamp; j++) // RECORRE PROYECTOS
            {
                if(proyectos[j].idProyecto!=-1) // MATCH PARA NO BUSCAR POSICIONES LIBRES
                {
                    printf("%d\t%s\n",proyectos[j].idProyecto,proyectos[j].nombre);//MUESTRA LOS PROYECTOS CON SU ID
                }
            }
            if(!getStringNumeros("Elija una ID para asignarle al programador un proyecto: ",auxStringIdProyecto))//VALIDA LA ID
            {
                printf("Debe ingresar solo numeros para la ID\n");
                return 0;
            }
            auxIdProyecto=atoi(auxStringIdProyecto);//PASA DE CADENA A ENTERO
            for(int j=0; j<tamp; j++) // RECORRE PROYECTOS
            {
                if(auxIdProyecto==proyectos[j].idProyecto)//MATCHEA ID PROYECTO
                {
                    flag3=1;//FLAG PARA SABER SI ENCONTRO EL ID DEL PROYECTO
                    for(int k=0; k<tampp; k++) // RECORRE PROGRAMADORES PROYECTOS
                    {
                        if(pp[k].idProgramador==-1 && pp[k].idProyecto==-1)// RECORRO PP Y LE ASIGNO LOS AUXILIARES A UN ESPACIO VACIO
                        {
                            if(!getStringNumeros("Ingrese la cantidad de horas de trabajo para el programador: ",auxStringHoras))//VALIDO NUM
                            {
                                printf("Debe ingresar solo numeros para las horas\n");
                                return 0;
                            }
                            auxHoras=atoi(auxStringHoras);//CADENA A ENTERO
                            pp[k].idProgramador=auxId;//ASIGNO EL ID AL ORIGINAL
                            pp[k].idProyecto=auxIdProyecto;//ASIGNO EL ID AL ORIGINAL
                            pp[k].horasDeTrabajo=auxHoras;//ASIGNO LAS HORAS AL ORIGINAL
                            break;
                        }

                    }
                }
            }
        }
    }
    if(!flag2)// FLAG PARA VER SI SE ENCONTRO EL ID DEL PROGRAMADOR
    {
        printf("No se encontro el Id del programador.\n");
        return 0;
    }
    if(!flag3)// FLAG PARA VER SI SE ENCONTRO EL ID DEL PROYECTO
    {
        printf("No se encontro el ID del proyecto.\n");
        return 0;
    }
    return 1;
}

void inicializarPp(eProgramadorProyecto pp[],int tampp)
{
    for(int i=0; i<tampp; i++) //RECORRE PROGRAMADORES Y PROYECTOS Y INICIALIZA EN -1 PARA SABER SI ESTA VACIO
    {
        pp[i].idProgramador=-1;
        pp[i].idProyecto=-1;
        pp[i].horasDeTrabajo=-1;
    }
}
void inicializarProyectos(eProyecto proyectos[],int tampy)
{
    for(int i=0; i<tampy; i++) //RECORRE PROYECTOS Y LO INICIALIZA EN -1 PARA MARCAR QUE ESTA VACIO
    {
        proyectos[i].idProyecto=-1;
    }
}

int listadoProgramadores(eProgramador programadores[],eCategoria categorias[],eProyecto proyectos[],eProgramadorProyecto pp[],int tam,int tamp,int tampp)
{
    int flag=0,flag2=0;
    eProgramador auxp; // AUXILIAR PROGRAMADOR
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(programadores[i].id>programadores[j].id)// ORDENA DE MENOR A MAYOR
            {
                auxp=programadores[i];
                programadores[i]=programadores[j];
                programadores[j]=auxp;
            }
        }
    }
    for(int i=0; i<tam; i++)
    {
        if(programadores[i].estado==1)// VERIFICO QUE NO ESTEN VACIOS
        {
            flag2=1;
            if(!flag)// TABLA PARA MOSTRAR EN LA PRIMERA VEZ
            {
                printf("ID\t\tNOMBRE\t\tAPELLIDO\t\tCATEGORIA\t\tPROYECTOS \n");
                flag=1;
            }
            printf("%d\t\t%s\t\t%s\t\t",programadores[i].id,programadores[i].nombre,programadores[i].apellido);// PRINTEO ID NOMBRE Y APELLIDO
            for(int c=0; c<3; c++) //RECORRO CATEGORIAS
            {
                if(programadores[i].idCategoria==categorias[c].idCategoria)//VERIFICO EL ID DE CAT DEL PROG CON LA CATEGORIA
                {
                    printf("\t%.6s\t\t",categorias[c].descripcion);// PRINTEO EL NOMBRE
                    for(int j=0; j<tampp; j++) // RECORRO PP
                    {
                        if(programadores[i].id==pp[j].idProgramador)// MATCH DEL ID DE PROGRAMADOR CON EL DE PP
                        {
                            for(int k=0; k<tamp; k++)
                            {
                                if(pp[j].idProyecto==proyectos[k].idProyecto)// MATCH DE ID DE PROYECTO DE PP CON ID PROYECTO DE PROYECTO
                                {
                                    int horas,pago,resultado;
                                    pago=categorias[c].pagoHora;// ASIGNO PAGO HORA A PAGO
                                    horas=pp[j].horasDeTrabajo;// ASIGNO HORA DE TRABAJO A HORA
                                    resultado=pago*horas;// RESULTADO ES PAGO * HORAS
                                    printf("%s-$%d ",proyectos[k].nombre,resultado);// MUESTRO NOMBRE DEL PROYECTO Y EL PAGO MULTIPLICADO LAS HORAS DEL PROYECTO
                                }
                            }
                        }
                    }
                    printf("\n");// DEJO UN RENGLON POR CADA PERSONA
                }
            }
        }
    }
    if(!flag2)// SI NO SE ENCONTRO PROGRAMADORES
    {
        printf("No se encontro programadores para hacer un listado.\n");
        return 0;
    }
    return 1;
}

int listadoProyectos(eProgramador programadores[],eProyecto proyectos[],eProgramadorProyecto pp[],int tam,int tamp,int tampp)
{
    int flag=0,cj,css,cs;

    for(int i=0; i<tamp; i++) // RECORRE PROYECTOS
    {
        cj=0;
        css=0;
        cs=0;

        if(proyectos[i].idProyecto!=-1)
        {
            if(!flag)// PRIMERA BARRA
            {
                printf("ID\t\tNOMBRE PROYECTO\t\tJ\tSS\tS\n\n");
                flag=1;
            }
            printf("%d\t\t%.7s\t\t\t",proyectos[i].idProyecto,proyectos[i].nombre);// MUESTRA ID Y NOMBRE
            for(int j=0; j<tampp; j++) // RECORRE PP
            {
                if(proyectos[i].idProyecto==pp[j].idProyecto)// VERIFICA SI ES IGUAL EL ID
                {
                    for(int k=0; k<tam; k++) // RECORRE PROGRAMADORES
                    {
                        if(pp[j].idProgramador==programadores[k].id)// VERIFICA ID
                        {
                            if(programadores[k].idCategoria==1)// CATEGORIA JUNIOR
                            {
                                cj++;// AUMENTA EN 1
                            }
                            else if(programadores[k].idCategoria==2)// CATEGORIA SEMI SENIOR
                            {
                                css++;// AUMENTA EN 1
                            }
                            else if(programadores[k].idCategoria==3)// CATEGORIA SENIOR
                            {
                                cs++;// AUMENTA EN 1
                            }

                        }
                    }
                }
            }
            printf("%d\t%d\t%d\n",cj,css,cs);
        }
    }
return 1;
}

int listarProyectosProgramador(eProgramador programadores[],eProyecto proyectos[],eProgramadorProyecto pp[],int tam,int tamp,int tampp)
{
    char auxStringId[100];
    int flag=0,flag2=0,auxId;
    for(int i=0; i<tam; i++)
    {
        if(programadores[i].estado==1)// VERIFICA QUE EL ESPACIO NO ESTE LIBRE
        {
            if(!flag)// PRIMERA BARRA
            {
                printf("ID\t\tNOMBRE\t\tAPELLIDO\n");
                flag=1;
            }
            printf("%d\t\t%s\t\t%s\n",programadores[i].id,programadores[i].nombre,programadores[i].apellido);
        }

    }
    if(!getStringNumeros("Ingrese id para ver los proyectos del programador: ",auxStringId))//VERIFICA NUMEROS
        {
            printf("El id debe contener solo numeros.\n");
            return 0;
        }
    auxId=atoi(auxStringId);// CADENA A ENTERO
    for(int i=0; i<tam; i++)// RECORE PROGRAMADORES
    {
        if(programadores[i].estado==1 && auxId==programadores[i].id)// VERIFICA QUE SEA UN PROGRAMADOR Y QUE CONCUERDE LA ID
        {
            flag2=1;
            printf("Proyectos de ID (%d) %s: ",programadores[i].id,programadores[i].nombre);// MUESTRA
            for(int j=0; j<tampp; j++)// RECORRE PP
            {
                if(programadores[i].id==pp[j].idProgramador)// VERIFICA LOS 2 ID
                {
                    for(int k=0; k<tamp; k++)// RECORRE PROYECTOS
                    {
                        if(pp[j].idProyecto==proyectos[k].idProyecto)// VERIFICA LOS 2 ID
                        {
                            printf("%s ",proyectos[k].nombre);// MUESTRA LOS PROYECTOS
                        }
                    }
                }
            }
            printf("\n");// DEJA UN ESPACIO
        }
    }
    if(!flag2)// VERIFICO SI EL ID NO SE ENCUENTRA
    {
        printf("No se encuentra el ID ingresado.\n");
        return 0;
    }
    return 1;
}

int proyectoDemandante(eProgramador programadores[],eProyecto proyectos[],eProgramadorProyecto pp[],int tam,int tamp,int tampp)
{
    int max,flag=0,cP,idMax;
    char nombreMax[50];

    for(int i=0;i<tamp;i++)// RECORRE PROYECTOS
    {
        cP=0;
        if(proyectos[i].idProyecto!=-1)// VERIFICA QUE NO ESTEN LIBRESZ
        {
            for(int j=0;j<tampp;j++)// RECORRO PP
            {
                if(proyectos[i].idProyecto==pp[j].idProyecto)// VERIFICO LOS 2 ID
                {
                    cP++;// SUMO 1
                }
            }
            if(!flag)// PRIMERA VEZ ENTRA SI O SI EL MAXIMO
            {https://www.facebook.com/cronicadiario/photos/a.10150268409934165.346180.155703934164/10155481126614165/?type=3
                max=cP;
                idMax=proyectos[i].idProyecto;
                strcpy(nombreMax,proyectos[i].nombre);
                flag=1;
            }
        }
        if(cP>max)// PREGUNTO SI EL CONTADOR ES MAYOR AL MAX
        {
            max=cP;
            idMax=proyectos[i].idProyecto;
            strcpy(nombreMax,proyectos[i].nombre);
        }
    }
    printf("El proyecto %s (ID:%d) es el que mas programadores tiene con:%d\n",nombreMax,idMax,max);//MUESTRO
    return 1;
}
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}
