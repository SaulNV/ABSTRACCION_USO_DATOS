#ifndef ORDENAMIENTOBUR_H
#define ORDENAMIENTOBUR_H

#include <string>
#include "Entidad.h"

using namespace std;

// CLASE ABSTRACTA / BASE
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

    // Métodos de archivos integrados en la clase
    void escribirCSV(string ruta);
    void leerCSV(string ruta);
    
    void escribirTXT(string ruta);
    void leerTXT(string ruta);
    
    void escribirXML(string ruta);
    void leerXML(string ruta);
    
    void escribirJSON(string ruta);
    void leerJSON(string ruta);
};

// CLASE CONCRETA (Burbuja)
class OrdenadorBurbuja : public OrdenadorBase {
public:
    void ordenar();
};

#endif