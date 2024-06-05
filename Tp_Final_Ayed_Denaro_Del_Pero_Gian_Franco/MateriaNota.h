#ifndef MATERIANOTA_H_INCLUDED
#define MATERIANOTA_H_INCLUDED

#include "ListaMaterias.h"

typedef struct MateriaNota MateriaNota;

MateriaNota* crearMateriaNota(Materia*, int nota);

void mostrarMateriaNota(MateriaNota*);

int getIdMateriaNota(MateriaNota*);
const char* getNombreMateriaNota(MateriaNota*);
int getNota(MateriaNota*);

void setNotaMateriaNota(MateriaNota*, int);

void destruirMateriaNota(MateriaNota*);


#endif // MATERIANOTA_H_INCLUDED
