
void mostrar(eDuenio cliente[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(cliente[i].estado==1)
        {
            printf("  %d     %6s    %6s   %6s    %li    %d\n",cliente[i].idDuenio,cliente[i].nombre,cliente[i].apellido,cliente[i].direccion,cliente[i].numTarjCred,cliente[i].estado);
        }
    }
}


void mostrarAutos(eEstacionamiento autos[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(autos[i].estado==1)
        {

            if(autos[i].marca==1)
            {
                printf("%s    ALPHA_ROMEO    %d         %d          %d\n",autos[i].patente,autos[i].horaEntrada,autos[i].idDuenio,autos[i].estado);

            }
            else if(autos[i].marca==2)
            {
                printf("%s    FERRARI        %d         %d          %d\n",autos[i].patente,autos[i].horaEntrada,autos[i].idDuenio,autos[i].estado);

            }
            else if(autos[i].marca==3)
            {
                printf("%s    AUDI           %d         %d          %d\n",autos[i].patente,autos[i].horaEntrada,autos[i].idDuenio,autos[i].estado);

            }
            else
            {
                printf("%s    OTRO           %d        %d          %d\n",autos[i].patente,autos[i].horaEntrada,autos[i].idDuenio,autos[i].estado);

            }

        }
    }
}


void cargarPersonas(eDuenio personas[],int cantPer)
{
    int id[]= {1,2,3};
    char nombre[][20]= {"juan","roberto","pedro"};
    char apellido[][20]= {"figueiras","petinato","alfonso"};
    char direccion[][20]= {"mitre750","mitre150","mitre900"};
    long int numTarjeta[]= {1205,1563,1893};
    int estado[]= {1,1,1};
    int i;
    for(i=0; i<cantPer; i++)
    {
        personas[i].idDuenio=id[i];
        strcpy(personas[i].nombre,nombre[i]);
        strcpy(personas[i].apellido,apellido[i]);
        personas[i].estado=estado[i];
        strcpy(personas[i].direccion,direccion[i]);
        personas[i].numTarjCred=numTarjeta[i];


    }

}


void cargarEstacionamiento(eEstacionamiento automoviles[],int cantAut)
{
    char patente[][20]= {"AOY405","RPO383","JKI268"};
    int marca[]= {1,2,2};
    int idDuenio[]= {1,2,3};
    int horarioEntrada[]= {15,20,20};
    int horarioSalida[]={0,0,0};
    int estado[]= {1,1,1};
    int i;
    for(i=0; i<cantAut; i++)
    {
        automoviles[i].idDuenio=idDuenio[i];
        automoviles[i].marca=marca[i];
        strcpy(automoviles[i].patente,patente[i]);
        automoviles[i].horaEntrada=horarioEntrada[i];
        automoviles[i].horaSalida=horarioSalida[i];
        automoviles[i].estado=estado[i];

    }

}
