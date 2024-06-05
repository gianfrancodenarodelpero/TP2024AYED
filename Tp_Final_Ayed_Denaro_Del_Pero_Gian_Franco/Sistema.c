#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "MateriaNota.h"
#include "MateriaSistema.h"
#include "Estudiantes.h"
#include "Sistema.h"
#include "CargarDatos.h"
#include "Lista.h"

void limpiarPantalla(){
    #ifdef _WIN32
        system("cls");  // En Windows
    #else
        system("clear");  // En sistemas basados en Unix (Linux, macOS, etc.)
    #endif
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pedidoDeOpciones(char opcion[30]){
    printf("\tOpcion: ");
    scanf("%29[^\n]", opcion); // Lee hasta encontrar un salto de línea o el máximo de caracteres - 1
    limpiarBuffer(); // Limpia el buffer después de leer la entrada
}

void mostrarCalificaciones(void* d){
    mostrarMateriaNota((MateriaNota*)d);
    puts("");
}

void mostrarMaterias(void* m){
    mostrarMateria((Materia*)m);
    puts("");
}

void mostrarEstudiantes(void* e){
    mostrarEstudiante((Estudiante*)e);
    puts("");
}

void mostrarEstudiantesCompletos(void* e){
    mostrarEstudianteCompleto((Estudiante*)e);
}

void mostrarMateriasEnElSistema(void* m){
    mostrarMateriaSistemaConInscriptos(m);
}

bool compararPromediosEstudiantes(void* enLista, void* insertado){
    return (getPromedioEstudiante((Estudiante*)enLista) < getPromedioEstudiante((Estudiante*)insertado)) ? true:false;
}

bool compararCantidadDeMateriasAprobadas(void* a, void* b){
    return (getCantidadDeMateriasAprobadas((Estudiante*) a) < getCantidadDeMateriasAprobadas((Estudiante*)b)) ? true:false;
}

bool esIdDeMateriaCorrecto(void* m, void* id){
    return (getIdMateriaSistema((MateriaSistema*)m) == (int)id) ? true:false;
}

bool esMateria(void* mn, void* ms){
    return (getIdMateriaNota((MateriaNota*)mn) == getIdMateriaSistema((MateriaSistema*)ms)) ? true:false;
}

void destruirDatoListaMateriaNota(void* d){
    destruirMateriaNota((MateriaNota*)d);
}

void destruirDatoListaMaterias(void* d){
    destruirMateria((Materia*)d);
}

void destruirDatoListaEstudiantes(void* d){
    destruirEstudiante((Estudiante*)d);
}

void destruirDatoListaMateriaSistema(void* d){
    destruirMateriaSistema((MateriaSistema*)d);
}

void menuSimple(){
    Lista* lMaterias = cargarMaterias();
    Lista* lEstudiantes = cargarEstudiantes(lMaterias);

    puts("--------------ESTUDIANTES--------------");
    mostrarLista(lEstudiantes, mostrarEstudiantesCompletos);

    Lista* lMateriasSistema = cargarMateriasSistema(lMaterias, lEstudiantes);
    puts("\n\n--------------MATERIAS--------------");
    mostrarLista(lMateriasSistema, mostrarMateriasEnElSistema);

    destruirListaYDatos(lMateriasSistema, destruirDatoListaMateriaSistema);
    destruirListaYDatos(lEstudiantes, destruirDatoListaEstudiantes);
    destruirListaYDatos(lMaterias, destruirDatoListaMaterias);
}

bool compararIDMateriaSistema(void* m1, void* m2){
    return (getIdMateriaSistema((MateriaSistema*)m1) == (int)m2) ? true:false;
}

bool compararDNIEstudiante(void* e1, void* e2){
    return (getDNI((Estudiante*)e1) == (int)e2) ? true:false;
}

int comprobarSiEsValorValido(Lista* l, char opcion[30], bool callback(void*, void*)){
    bool bCorrecto;
    int aux, posAux;

    do {
        bCorrecto = true;
        pedidoDeOpciones(opcion);
        int aux = strlen(opcion);
        for(int i=0; i<aux && bCorrecto; i++){

            if(!isdigit(opcion[i]))
                bCorrecto = false;

        }

        if(bCorrecto){
            aux = atoi(opcion);
            posAux = buscarDato(l, (void*)aux, callback);

            if(aux != 0 && posAux == -1)
                bCorrecto = false;

        }

    } while(!bCorrecto);

    return posAux;
}

bool existeEstudianteEnMateria(void* e, void* el){
    return (getDNI((Estudiante*)e) == getDNI((Estudiante*)el)) ? true:false;
}

void menuComplejo(){
    Lista* lMaterias = cargarMaterias();
    Lista* lEstudiantes = cargarEstudiantes(lMaterias);
    Lista* lMateriasSistema = cargarMateriasSistema(lMaterias, lEstudiantes);

    char opcion[30];
    bool bVerMenu = true, bOpcion1, bOpcion2, bopcion3 , bopcion4;
    bool bEsNumeroValido;
    int aux;
    while(bVerMenu){
        puts("-----------------TP AyED 2024 C1 - Alumno: Denaro Del Pero Gian Franco 41065731---------------");
        puts("Seleccione la opcion que desee:");
        puts("1- Ver materias.");
        puts("2- Ver estudiantes.");
        puts("3- inscribir estudiante");
        puts("4- inscribir");
        puts("0- Finalizar.");
        do {
            pedidoDeOpciones(opcion);
        } while(strcmp("0", opcion) != 0 && strcmp("1", opcion) != 0 && strcmp("2", opcion) != 0 && strcmp("3", opcion) != 0 && strcmp("4", opcion) != 0);

        switch(atoi(opcion)){
            case 0:
                bVerMenu = false;
                break;
            case 1:
                bOpcion1 = true;
                while(bOpcion1){
                    limpiarPantalla();
                    puts("------------LISTA DE MATERIAS------------");
                    mostrarLista(lMaterias, mostrarMaterias);

                    puts("\nSeleccione la opcion que desee:");
                    puts("0 si desea volver hacia atras.");
                    puts("ID de materia si quiere ver el detalle de la misma.");
                    aux = comprobarSiEsValorValido(lMateriasSistema, opcion, compararIDMateriaSistema);

                    if(strcmp(opcion, "0") != 0){
                        limpiarPantalla();
                        mostrarMateriaSistemaConInscriptos((MateriaSistema*)obtenerDatoEnLaLista(lMateriasSistema, aux));
                        puts("\n\n0 para volver atras.");
                        do {
                            pedidoDeOpciones(opcion);
                        } while(strcmp("0", opcion) != 0);

                    } else
                        bOpcion1 = false;

                }
            break;
        case 2:
            bOpcion2 = true;
            while(bOpcion2){
                limpiarPantalla();
                puts("------------ESTUDIANTES------------");
                    mostrarLista(lEstudiantes, mostrarEstudiantes);

                    puts("\nSeleccione la opcion que desee:");
                    puts("0 si desea volver hacia atras.");
                    puts("DNI del Estudiante si quiere ver el detalle del mismo.");
                    aux = comprobarSiEsValorValido(lEstudiantes, opcion, compararDNIEstudiante);

                    if(strcmp(opcion, "0") != 0){
                        limpiarPantalla();
                        Estudiante* e = (Estudiante*)obtenerDatoEnLaLista(lEstudiantes, aux);
                        mostrarEstudianteCompleto(e);
                        puts("--MATERIAS ANOTADO/A--");
                        int temp, tam = getTamanioLista(lMateriasSistema);
                        MateriaSistema* ms = NULL;
                        for(int i=0; i<tam; i++){
                            ms = (MateriaSistema*)obtenerDatoEnLaLista(lMateriasSistema, i);
                            temp = buscarDato(getListaInscriptosMateriaSistema(ms), (void*)e, existeEstudianteEnMateria);

                            if(temp != -1)
                                printf("%d - %s\n\n", getIdMateriaSistema(ms), getNombreMateriaSistema(ms));
                        }

                        puts("\n\n0 para volver atras.");
                        do {
                            pedidoDeOpciones(opcion);
                        } while(strcmp("0", opcion) != 0);

                    } else
                        bOpcion2 = false;
            }
            break;
        case 3:
            bopcion3 = true;
            while(bopcion3){
                limpiarPantalla();
                puts("------------INSCRIBIR ESTUDIANTES------------");
                    Lista* list = crearLista();
                    char auxNombre[20];
                    char auxApellido[20];
                    int auxDni;

                    puts("Agregar dni del estudiante: \n");
                    scanf("%d",&auxDni);
                    puts("Agregar apellido del alumno: \n");
                    fflush(stdin);
                    gets(auxApellido);
                    puts("Agregar nombre del alumno: \n");
                    fflush(stdin);
                    gets(auxNombre);
                  Estudiante * lis = crearEstudiante(auxDni,auxApellido,auxNombre);




                   // mostrarLista(lEstudiantes, mostrarEstudiantes);


                    puts("\nSeleccione la opcion que desee:");
                    puts("0 si desea volver hacia atras.");
                    puts("DNI del Estudiante si quiere ver el detalle del mismo.");
                    aux = comprobarSiEsValorValido(lEstudiantes, opcion, compararDNIEstudiante);

                    if(strcmp(opcion, "0") != 0){
                        limpiarPantalla();
                        Estudiante* e = (Estudiante*)obtenerDatoEnLaLista(lEstudiantes, aux);
                        mostrarEstudianteCompleto(e);
                        puts("--MATERIAS ANOTADO/A--");
                        int temp, tam = getTamanioLista(lMateriasSistema);
                        MateriaSistema* ms = NULL;
                        for(int i=0; i<tam; i++){
                            ms = (MateriaSistema*)obtenerDatoEnLaLista(lMateriasSistema, i);
                            temp = buscarDato(getListaInscriptosMateriaSistema(ms), (void*)e, existeEstudianteEnMateria);

                            if(temp != -1)
                                printf("%d - %s\n\n", getIdMateriaSistema(ms), getNombreMateriaSistema(ms));
                        }

                        puts("\n\n0 para volver atras.");
                        do {
                            pedidoDeOpciones(opcion);
                        } while(strcmp("0", opcion) != 0);

                    } else
                        bopcion3 = false;
            }
            break;

        }

        limpiarPantalla();
    }

    destruirListaYDatos(lMateriasSistema, destruirDatoListaMateriaSistema);
    destruirListaYDatos(lEstudiantes, destruirDatoListaEstudiantes);
    destruirListaYDatos(lMaterias, destruirDatoListaMaterias);
    puts("Hasta luego :)");
}

