#ifndef ARBOL_H
#define ARBOL_H

#include "Entidad.h"


struct Nodo {
    Entidad dato;
    Nodo* izq;
    Nodo* der;
    

    Nodo(Entidad p) {
        dato = p;
        izq = nullptr;
        der = nullptr;
    }
};

class ArbolBinario {
private:
    Nodo* raiz;

    Nodo* insertarRec(Nodo* nodo, Entidad p);
    Nodo* eliminarRec(Nodo* nodo, int edadBusqueda);
    Nodo* encontrarMinimo(Nodo* nodo);
    
    void inOrdenRec(Nodo* nodo);
    void preOrdenRec(Nodo* nodo);
    void postOrdenRec(Nodo* nodo);
    void destruirArbol(Nodo* nodo);

    void guardarPreOrdenTXT(Nodo* nodo, ofstream& archivo);
    void guardarPreOrdenCSV(Nodo* nodo, ofstream& archivo);
    void guardarPreOrdenXML(Nodo* nodo, ofstream& archivo);
    void guardarPreOrdenJSON(Nodo* nodo, ofstream& archivo, bool& primero);

public:
    ArbolBinario();
    ~ArbolBinario(); 

  
    void insertar(Entidad p);
    void eliminar(int edad);
    void mostrarInOrden();   
    void mostrarPreOrden();  
    void mostrarPostOrden(); 
    bool estaVacio();

    void escribirCSV(string ruta);
    void leerCSV(string ruta);
    void escribirTXT(string ruta);
    void leerTXT(string ruta);
    void escribirXML(string ruta);
    void leerXML(string ruta);
    void escribirJSON(string ruta);
    void leerJSON(string ruta);
};

#endif