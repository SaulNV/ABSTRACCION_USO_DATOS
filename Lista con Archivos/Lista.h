#ifndef LISTA_H
#define LISTA_H

#include <string>
#include "Entidad.h"

using namespace std;

class ListaBase {
protected:
    Entidad arreglo[100];
    int n;
    int limiteUsuario;

public:
    ListaBase();
    void setMaximo(int m);
    void agregar(Entidad p);             // Inserta al final de la lista
    void eliminarEnPosicion(int pos);    // Elimina en un indice especifico y recorre los datos
    void mostrarTodo();
    bool estaVacia();
    bool estaLlena();
    int getTamanoActual();

    // Métodos para persistencia de archivos
    void escribirCSV(string ruta);
    void leerCSV(string ruta);
    
    void escribirTXT(string ruta);
    void leerTXT(string ruta);
    
    void escribirXML(string ruta);
    void leerXML(string ruta);
    
    void escribirJSON(string ruta);
    void leerJSON(string ruta);
};

class ListaEstatica : public ListaBase {
    // Clase concreta lista para ser instanciada en el main
};

#endif