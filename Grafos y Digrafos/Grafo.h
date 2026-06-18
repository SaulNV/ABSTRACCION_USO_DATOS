#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include "Conexion.h"

using namespace std;

class GrafoBase {
protected:
    int nodos[100];
    string aristas[100];
    Conexion rutas[100];
    
    int numNodos;
    int numAristas;
    int numRutas;
    int limiteUsuario;
    bool esDirigido;

public:

    GrafoBase(bool dirigido);
    void setMaximo(int m);
    void agregarNodo(int id);
    void agregarRuta(int inicio, int fin, string nombreArista, int tiempo, int costo);
    void mostrarRutas();
    void calcularDijkstra(int origen, bool porCosto);
    bool nodoExiste(int id);
    void escribirCSV(string ruta);
    void leerCSV(string ruta);
    void escribirTXT(string ruta);
    void leerTXT(string ruta);
    void escribirXML(string ruta);
    void leerXML(string ruta);
    void escribirJSON(string ruta);
    void leerJSON(string ruta);
};

// CLASE HIJA 1: Grafo No Dirigido
class GrafoNoDirigido : public GrafoBase {
public:
    GrafoNoDirigido() : GrafoBase(false) {}
};

// CLASE HIJA 2: Digrafo Dirigido
class DigrafoDirigido : public GrafoBase {
public:
    DigrafoDirigido() : GrafoBase(true) {}
};

#endif