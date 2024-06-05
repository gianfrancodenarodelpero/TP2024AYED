#ifndef SISTEMA_H_INCLUDED
#define SISTEMA_H_INCLUDED

#include <stdbool.h> // habilito valores booleanos


void limpiarPantalla();
void pedidoDeOpciones(char opcion[30]);

//muestreo por pantalla
void mostrarCalificaciones(void*);
void mostrarMaterias(void*);
void mostrarEstudiantes(void*);
void mostrarEstudiantesCompletos(void*);
void mostrarMateriasEnElSistema(void*);

//comparaciones con valores booleanos
bool compararPromediosEstudiantes(void*, void*);
bool compararCantidadDeMateriasAprobadas(void*, void*);

bool esIdDeMateriaCorrecto(void*, void*);
bool esMateria(void*, void*);

//destruir
void destruirDatoListaMateriaNota(void*);
void destruirDatoListaMaterias(void*);
void destruirDatoListaEstudiantes(void*);
void destruirDatoListaMateriaSistema(void*);

//menues
void menuSimple();
void menuComplejo();

#endif // SISTEMA_H_INCLUDED
