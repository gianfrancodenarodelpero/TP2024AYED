#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//#include "MateriaNota.h"
#include "ListaMaterias.h"
#include "Estudiante.h"
#include "Sistema.h"
//#include "CargarDatos.h"
#include "Lista.h"


void limpiarPantalla(){
    #ifdef _WIN32
    // Para windows
        system("cls");
    #else
    //Para sistemas de unix
        system("clear");
    #endif
};

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void pedidoDeOpciones(char opcion[30]){
    printf("\tOpcion: ");
    scanf("%29[^\n]", opcion);
    limpiarBuffer();
};

//muestreo por pantalla
void mostrarCalificaciones(void* d){
    mostrarMateriaNota((MateriaNota*)d);
    puts("");
};

void mostrarMaterias(void* m){
    mostrarMateria((Materias*)m);
    puts("");
};

void mostrarEstudiantes(void* e){
    mostrarEstudiante((estudiante*)e);
    puts("");
};

void mostrarMateriasEnElSistema(void* m){
    mostrarMateriasEnElSistema(m);
};

//comparaciones con valores booleanos
bool compararPromediosDeEstudiantes(void* a, void* b){
    return (getPromedioEstudiante((Estudiante*)enLista) < getPromedioEstudiante((Estudiante*)insertado)) ? true:false;
};

bool compararCantidadDeMateriasAprobadas(void* a , void* b){
     return (getCantidadDeMateriasAprobadas((Estudiante*) a) < getCantidadDeMateriasAprobadas((Estudiante*)b)) ? true:false;
};
bool esIdDeMateriaCorrecto(void* m, void* a){
    return (getIdMateriaSistema((MateriaSistema*)m) == (int)a) ? true:false;
};

bool esMateria(void* a, void* b){
    return (getIdMateriaNota((MateriaNota*)mn) == getIdMateriaSistema((MateriaSistema*)ms)) ? true:false;
};

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
//destruir
void destruirDatoListaMateriaNota(void* m){
    destr
};
void destruirDatoListaMaterias(void* m){
    destruirMateria((Materia*)m);
};
void destruirDatoListaEstudiantes(void* e){
    EliminarEstudiante((estudiante*)e);
};
void destruirDatoListaMateriaSistema(void* m){
     destruirMateriaSistema((MateriaSistema*)m);
}
};

//menues
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
};
void menuComplejo(){
Lista* lMaterias = cargarMaterias();
    Lista* lEstudiantes = cargarEstudiantes(lMaterias);
    Lista* lMateriasSistema = cargarMateriasSistema(lMaterias, lEstudiantes);

    char opcion[30];
    bool bVerMenu = true, bOpcion1, bOpcion2;
    bool bEsNumeroValido;
    int aux;
    while(bVerMenu){
        puts("-----------------TP AyED 2024 C1 - Alumno: Ramil Elias 42.396.413---------------");
        puts("Seleccione la opcion que desee:");
        puts("1- Ver materias.");
        puts("2- Ver estudiantes.");
        puts("0- Finalizar.");
        do {
            pedidoDeOpciones(opcion);
        } while(strcmp("0", opcion) != 0 && strcmp("1", opcion) != 0 && strcmp("2", opcion) != 0);

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
        }

        limpiarPantalla();
    }

    destruirListaYDatos(lMateriasSistema, destruirDatoListaMateriaSistema);
    destruirListaYDatos(lEstudiantes, destruirDatoListaEstudiantes);
    destruirListaYDatos(lMaterias, destruirDatoListaMaterias);
    puts("Hasta luego :)");
};
