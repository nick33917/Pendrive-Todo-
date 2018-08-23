#include "lib.h"
int main()
{
    int TAMP=50,TAMPY=1000,TAMPP=2000; // VARIABLES DE TAMAÑO TAMP = TAMAÑO PROGRAMADORES | TAMPY = TAMAÑO PROYECTOS | TAMPP = TAMAÑO PROYECTOS Y PROGRAMADORES
    eProgramador programadores[TAMP];
    eCategoria categorias[3];
    eProyecto proyectos[TAMPY];
    eProgramadorProyecto programadoresproyectos[TAMPP];
    char seguir='s';
    inicializarEstados(programadores,TAMP);//INICIALIZA ESTADOS DE PROGRAMADORES EN 0
    inicializarPp(programadoresproyectos,TAMPP);//INICIALIZA PROGRAMADORES Y PROYECTOS EN -1
    inicializarProyectos(proyectos,TAMPY);//INICIALIZA LOS PROYECTOS EN -1
    hardCodear(programadores,proyectos,categorias,programadoresproyectos);//HARDCODE A 5 PROGRAMADORES,5 PROYECTOS Y 10PP

    while(seguir=='s')
    {
        switch(menu("1-Alta\n2-Modificar\n3-Baja\n4-Asignar a proyecto\n5-Listado Programadores\n6-Listado Proyectos\n7-Listado proyecto de programadores\n8-Proyecto demandante.\n9-Salir\n"))// FUNCION MENU SOLO MUESTRA Y LEE LA OPCION
        {
        case 1:
            if(alta(programadores,TAMP)) // ALTA
            {
                printf("Alta exitosa\n");
            }
            break;
        case 2:
            if(modificar(programadores,programadoresproyectos,proyectos,TAMP,TAMPP,TAMPY))//MODIFICACION
            {
                printf("Modificacion exitosa\n");
            }
            break;
        case 3:
            if(baja(programadores,programadoresproyectos,TAMP,TAMPP))//BAJA
            {
                printf("Eliminacion exitosa.\n");
            }
            break;
        case 4:
            if(asignarProgramador(programadores,proyectos,programadoresproyectos,TAMP,TAMPY,TAMPP))//ASIGNACION Y NO UNIVERSAL
            {
                printf("Asignacion exitosa.\n");
            }
            break;
        case 5:
            if(listadoProgramadores(programadores,categorias,proyectos,programadoresproyectos,TAMP,TAMPY,TAMPP))// LISTADO PROGRAMADORES
            {
                printf("Listado exitoso.");
            }
            break;
        case 6:
            if(listadoProyectos(programadores,proyectos,programadoresproyectos,TAMP,TAMPY,TAMPP))// LISTADO DE PROYECTOS
            {
                printf("Listado exitoso");
            }
            break;
        case 7:
            if(listarProyectosProgramador(programadores,proyectos,programadoresproyectos,TAMP,TAMPY,TAMPP))//LISTAR PROYECTOS DE PROGS
            {
                printf("Listado exitoso");
            }
            break;
        case 8:
            if(proyectoDemandante(programadores,proyectos,programadoresproyectos,TAMP,TAMPY,TAMPP))//PROYECTO DEMANDANTE
            {
                printf("Accion exitosa");
            }
            break;
        case 9:
            seguir='n';
            break;
        default:
            printf("Opcion incorrecta.\n");
            break;
        }
        getch();
        system("cls");

    }
    return 0;
}
