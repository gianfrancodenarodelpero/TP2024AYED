#ifndef SISTEMA_H_INCLUDED
#define SISTEMA_H_INCLUDED

#include <stdbool.h> // habilito valores booleanos

void limpiarPantalla();
void limpiarBuffer();
void pedidoDeOpciones(char opcion[30]);

//muestreo por pantalla
void mostrarCalificaciones(void* d);
void mostrarMaterias(void* m);
void mostrarEstudiantes(void* e);
void mostrarMateriasEnElSistema(void* m);

//comparaciones con valores booleanos
bool compararPromediosDeEstudiantes(void* a, void* b);
bool compararCantidadDeMateriasAprobadas(void* a , void* b);
bool esIdDeMateriaCorrecto(void* m, void* a);
bool esMateria(void* a, void* b);
bool compararIDMateriaSistema(void* m1, void* m2);
bool compararDNIEstudiante(void* e1, void* e2);
int comprobarSiEsValorValido(Lista* l, char opcion[30], bool callback(void*, void*));
bool existeEstudianteEnMateria(void* e, void* el);

//destruir
void destruirDatoListaMateriaNota(void* m);
void destruirDatoListaMaterias(void* m);
void destruirDatoListaEstudiantes(void* e);
void destruirDatoListaMateriaSistema(void* m);

//menues
void menuSimple();
void menuComplejo();

#endif // SISTEMA_H_INCLUDED
