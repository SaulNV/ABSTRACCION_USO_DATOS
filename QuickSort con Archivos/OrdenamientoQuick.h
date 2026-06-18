#ifndef ORDENAMIENTOQUICK_H
#define ORDENAMIENTOQUICK_H

#include <string>
#include "Entidad.h"

using namespace std;

// CLASE ABSTRACTA / BASE (Mantiene el control de archivos y arreglo)
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

// CLASE CONCRETA (Quick Sort)
class OrdenadorQuick : public OrdenadorBase {
private:
    // Métodos privados para la lógica de partición y recursividad
    int partition(int bajo, int alto);
    void quickSortRec(int bajo, int alto);

public:
    void ordenar(); // Método público principal
};

#endif