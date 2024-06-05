#ifndef MATERIASISTEMA_H_INCLUDED
#define MATERIASISTEMA_H_INCLUDED


#include "Lista.h"
#include "ListaMaterias.h"
#include "Estudiantes.h"

typedef struct MateriaSistema MateriaSistema;

MateriaSistema* crearMateriaSistema(Materia*, int);

void mostrarMateriaSistema(MateriaSistema*);
void mostrarMateriaSistemaConInscriptos(MateriaSistema*);

int getIdMateriaSistema(MateriaSistema*);
const char* getNombreMateriaSistema(MateriaSistema*);
int getCupoMateriaSistema(MateriaSistema*);
// Retorno un duplicado de la lista para asegurarme que no sea modificada en otra parte
// del programa.
Lista* getListaInscriptosMateriaSistema(MateriaSistema*);

void setCupoMateriaSistema(MateriaSistema*, int);

void agregarEstudianteAMateria(MateriaSistema*, Estudiante*);

void destruirMateriaSistema(MateriaSistema*);

#endif // MATERIASISTEMA_H_INCLUDED
