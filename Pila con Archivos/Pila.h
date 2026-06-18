#ifndef PILA_H
#define PILA_H

#include <string>
#include "Entidad.h"

using namespace std;

class PilaBase {
protected:
    Entidad arreglo[100];
    int tope; 
    int limiteUsuario;

public:
    PilaBase();
    void setMaximo(int m);
    void apilar(Entidad p);    // Push
    void desapilar();          // Pop
    void mostrarTodo();
    bool estaVacia();
    bool estaLlena();
    int getTamanoActual();

   
    void escribirCSV(string ruta);
    void leerCSV(string ruta);
    
    void escribirTXT(string ruta);
    void leerTXT(string ruta);
    
    void escribirXML(string ruta);
    void leerXML(string ruta);
    
    void escribirJSON(string ruta);
    void leerJSON(string ruta);
};

class PilaEstatica : public PilaBase {
    // Clase concreta lista para usar
};

#endif