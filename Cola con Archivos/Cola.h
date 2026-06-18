#ifndef COLA_H
#define COLA_H

#include <string>
#include "Entidad.h"

using namespace std;

class ColaBase {
protected:
    Entidad arreglo[100];
    int frente;
    int final;
    int n;
    int limiteUsuario;

public:
    ColaBase();
    void setMaximo(int m);
    void insertar(Entidad p); // Enqueue
    void eliminar();          // Dequeue
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

class ColaEstatica : public ColaBase {
    // Clase concreta lista para extensiones de comportamiento
};

#endif