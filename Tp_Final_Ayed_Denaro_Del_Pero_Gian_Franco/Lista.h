#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


struct Lista;

typedef Lista * lista;

lista crearLista();

int getTamanio(lista* l);

//mostrar lista
void mostrarLista(lista* l);


//eliminar lista
void eliminarLista(lista* l);
void destruirListaYDatos(lista* l, void callback(void*));

//insertar datos a la lista

void insertarDatoAlInicioEnLaLista(lista* l, void* d);
bool insertarDatoEnLaLista(lista* l, int pos, void* d);
void insertarDatoAlFinalDeLaLista(lista* l, void* d);
void insertarDatoEnOrdenEnLista(lista* l, void* d, bool callback(void*, void*));

//obtener datos de la lista
void* obtenerDatoInicialDeLaLista(lista* l);
void* obtenerDatoEnLaLista(lista* l, int pos);
void* obtenerDatoFinalDeLaLista(lista* l);

//eliminar datos de la lista
void* eliminarDatoInicialDeLaLista(lista* l);
void* eliminarDatoDeLaLista(lista* l, int pos);
void* eliminarDatoFinalDeLaLista(lista* l);

//duplicar lista
lista* duplicar(lista* l);

//ordenar lista
void ordenarLista(lista* l, bool callback(void*, void*));


//buscar dato
int buscarDato(lista* l, void* d, bool callback(void*, void*));





#endif // LISTA_H_INCLUDED
