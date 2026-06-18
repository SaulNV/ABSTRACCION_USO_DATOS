#ifndef ORDENAMIENTOMERGE_H
#define ORDENAMIENTOMERGE_H

#include <string>
#include "Entidad.h"

using namespace std;

// CLASE ABSTRACTA / BASE (Mantiene todo el manejo de archivos)
class OrdenadorBase {
protected:
    Entidad arreglo[100];
    int n;
    int limiteUsuario;

public:
    OrdenadorBase();
    void setMaximo(int m);
    void agregar(Entidad p);
    void quitarUltimo();
    void mostrarTodo();
    bool estaVacia();
    bool estaLlena();
    int getTamanoActual();

    // Métodos de archivos
    void escribirCSV(string ruta);
    void leerCSV(string ruta);
    
    void escribirTXT(string ruta);
    void leerTXT(string ruta);
    
    void escribirXML(string ruta);
    void leerXML(string ruta);
    
    void escribirJSON(string ruta);
    void leerJSON(string ruta);
};

// CLASE CONCRETA (Merge Sort)
class OrdenadorMerge : public OrdenadorBase {
private:
    // Métodos ocultos para aplicar la recursividad y la mezcla
    void merge(int inicio, int mitad, int fin);
    void mergeSortRec(int inicio, int fin);

public:
    void ordenar(); // El método público que llama el main
};

#endif