#include <iostream>
#include <climits> 
#include <fstream>   
#include <sstream>   
#include "Grafo.h"

using namespace std;


GrafoBase::GrafoBase(bool dirigido) {
    numNodos = 0;
    numAristas = 0;
    numRutas = 0;
    limiteUsuario = 100;
    esDirigido = dirigido;
}

void GrafoBase::setMaximo(int m) {
    if (m > 0 && m <= 100) limiteUsuario = m;
    else limiteUsuario = 100;
}

bool GrafoBase::nodoExiste(int id) {
    for (int i = 0; i < numNodos; i++) {
        if (nodos[i] == id) return true;
    }
    return false;
}

void GrafoBase::agregarNodo(int id) {
    if (numNodos < limiteUsuario) {
        if (!nodoExiste(id)) {
            nodos[numNodos] = id;
            numNodos++;
        }
    } else {
        cout << "Limite de nodos alcanzado.\n";
    }
}

void GrafoBase::agregarRuta(int inicio, int fin, string nombreArista, int t, int c) {
    if (numRutas >= limiteUsuario) {
        cout << "Limite de rutas alcanzado.\n";
        return;
    }
    
    agregarNodo(inicio);
    agregarNodo(fin);
    
    aristas[numAristas] = nombreArista;
    numAristas++;
    
    rutas[numRutas].nodoInicial = inicio;
    rutas[numRutas].nodoFinal = fin;
    rutas[numRutas].aristaConexion = nombreArista;
    rutas[numRutas].tiempo = t;
    rutas[numRutas].costo = c;
    numRutas++;
}

void GrafoBase::mostrarRutas() {
    if (numRutas == 0) {
        cout << "No hay conexiones registradas.\n";
        return;
    }
    for (int i = 0; i < numRutas; i++) {
        cout << "Ruta [" << rutas[i].aristaConexion << "]: Nodo " 
             << rutas[i].nodoInicial << " -> Nodo " << rutas[i].nodoFinal 
             << " | Tiempo: " << rutas[i].tiempo << " min | Costo: $" << rutas[i].costo << "\n";
    }
}

void GrafoBase::calcularDijkstra(int origen, bool porCosto) {
    if (!nodoExiste(origen)) {
        cout << "El nodo origen no existe en el mapa.\n";
        return;
    }

    int adj[100][100];
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            adj[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }

    for (int i = 0; i < numRutas; i++) {
        int u = rutas[i].nodoInicial;
        int v = rutas[i].nodoFinal;
        int peso = porCosto ? rutas[i].costo : rutas[i].tiempo;
        
        if (peso < adj[u][v]) adj[u][v] = peso;
        if (!esDirigido) {
            if (peso < adj[v][u]) adj[v][u] = peso;
        }
    }

    int dist[100];
    bool visitado[100];
    for (int i = 0; i < 100; i++) {
        dist[i] = INT_MAX;
        visitado[i] = false;
    }

    dist[origen] = 0;

    for (int count = 0; count < numNodos - 1; count++) {
        int minimo = INT_MAX, u = -1;

        for (int v = 0; v < 100; v++) {
            if (nodoExiste(v) && !visitado[v] && dist[v] <= minimo) {
                minimo = dist[v];
                u = v;
            }
        }

        if (u == -1) break;
        visitado[u] = true;

        for (int v = 0; v < 100; v++) {
            if (nodoExiste(v) && !visitado[v] && adj[u][v] != INT_MAX 
                && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    cout << "\nCaminos mas cortos desde el Nodo " << origen 
         << (porCosto ? " (Optimizado por Costo):\n" : " (Optimizado por Tiempo):\n");
    for (int i = 0; i < 100; i++) {
        if (nodoExiste(i)) {
            cout << "  Hacia Nodo " << i << " -> ";
            if (dist[i] == INT_MAX) cout << "Inalcanzable\n";
            else cout << dist[i] << (porCosto ? " pesos." : " min.") << "\n";
        }
    }
}



// --- CSV ---
void GrafoBase::escribirCSV(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        archivo << "Origen,Destino,Arista,Tiempo,Costo\n";
        for (int i = 0; i < numRutas; i++) {
            archivo << rutas[i].nodoInicial << "," << rutas[i].nodoFinal << ","
                    << rutas[i].aristaConexion << "," << rutas[i].tiempo << "," << rutas[i].costo << "\n";
        }
        archivo.close();
        cout << "Mapa guardado en formato CSV.\n";
    }
}

void GrafoBase::leerCSV(string ruta) {
    ifstream archivo(ruta);
    string linea, orig, dest, arista, tiempo, costo;
    if (archivo.is_open()) {
        numNodos = 0; numAristas = 0; numRutas = 0; 
        getline(archivo, linea); 
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            getline(ss, orig, ','); getline(ss, dest, ','); getline(ss, arista, ',');
            getline(ss, tiempo, ','); getline(ss, costo, ',');
            if (!orig.empty() && !dest.empty()) {
                agregarRuta(stoi(orig), stoi(dest), arista, stoi(tiempo), stoi(costo));
            }
        }
        archivo.close();
        cout << "Mapa cargado desde CSV.\n";
    } else { cout << "No se pudo abrir el archivo CSV.\n"; }
}

// --- TXT ---
void GrafoBase::escribirTXT(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        for (int i = 0; i < numRutas; i++) {
            archivo << rutas[i].nodoInicial << "\n" << rutas[i].nodoFinal << "\n"
                    << rutas[i].aristaConexion << "\n" << rutas[i].tiempo << "\n" << rutas[i].costo << "\n";
        }
        archivo.close();
        cout << "Mapa guardado en formato TXT.\n";
    }
}

void GrafoBase::leerTXT(string ruta) {
    ifstream archivo(ruta);
    string orig, dest, arista, tiempo, costo;
    if (archivo.is_open()) {
        numNodos = 0; numAristas = 0; numRutas = 0;
        while (getline(archivo, orig) && getline(archivo, dest) && getline(archivo, arista) && 
               getline(archivo, tiempo) && getline(archivo, costo)) {
            if (!orig.empty() && !dest.empty()) {
                agregarRuta(stoi(orig), stoi(dest), arista, stoi(tiempo), stoi(costo));
            }
        }
        archivo.close();
        cout << "Mapa cargado desde TXT.\n";
    } else { cout << "No se pudo abrir el archivo TXT.\n"; }
}

// --- XML ---
void GrafoBase::escribirXML(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        archivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<rutas>\n";
        for (int i = 0; i < numRutas; i++) {
            archivo << "  <conexion>\n";
            archivo << "    <origen>" << rutas[i].nodoInicial << "</origen>\n";
            archivo << "    <destino>" << rutas[i].nodoFinal << "</destino>\n";
            archivo << "    <arista>" << rutas[i].aristaConexion << "</arista>\n";
            archivo << "    <tiempo>" << rutas[i].tiempo << "</tiempo>\n";
            archivo << "    <costo>" << rutas[i].costo << "</costo>\n";
            archivo << "  </conexion>\n";
        }
        archivo << "</rutas>\n";
        archivo.close();
        cout << "Mapa guardado en formato XML.\n";
    }
}

void GrafoBase::leerXML(string ruta) {
    ifstream archivo(ruta); string linea, orig, dest, arista, tiempo, costo;
    if (archivo.is_open()) {
        numNodos = 0; numAristas = 0; numRutas = 0;
        while (getline(archivo, linea)) {
            if (linea.find("<origen>") != string::npos) orig = linea.substr(linea.find("<origen>") + 8, linea.find("</origen>") - (linea.find("<origen>") + 8));
            else if (linea.find("<destino>") != string::npos) dest = linea.substr(linea.find("<destino>") + 9, linea.find("</destino>") - (linea.find("<destino>") + 9));
            else if (linea.find("<arista>") != string::npos) arista = linea.substr(linea.find("<arista>") + 8, linea.find("</arista>") - (linea.find("<arista>") + 8));
            else if (linea.find("<tiempo>") != string::npos) tiempo = linea.substr(linea.find("<tiempo>") + 8, linea.find("</tiempo>") - (linea.find("<tiempo>") + 8));
            else if (linea.find("<costo>") != string::npos) {
                costo = linea.substr(linea.find("<costo>") + 7, linea.find("</costo>") - (linea.find("<costo>") + 7));
                agregarRuta(stoi(orig), stoi(dest), arista, stoi(tiempo), stoi(costo));
            }
        }
        archivo.close(); cout << "Mapa cargado desde XML.\n";
    } else { cout << "No se pudo abrir el archivo XML.\n"; }
}

// --- JSON ---
void GrafoBase::escribirJSON(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        archivo << "[\n";
        for (int i = 0; i < numRutas; i++) {
            archivo << "  {\n    \"origen\": " << rutas[i].nodoInicial << ",\n";
            archivo << "    \"destino\": " << rutas[i].nodoFinal << ",\n";
            archivo << "    \"arista\": \"" << rutas[i].aristaConexion << "\",\n";
            archivo << "    \"tiempo\": " << rutas[i].tiempo << ",\n";
            archivo << "    \"costo\": " << rutas[i].costo << "\n  }";
            if (i < numRutas - 1) archivo << ","; archivo << "\n";
        }
        archivo << "]\n"; archivo.close(); cout << "Mapa guardado en formato JSON.\n";
    }
}

void GrafoBase::leerJSON(string ruta) {
    ifstream archivo(ruta); string linea, orig, dest, arista, tiempo, costo;
    if (archivo.is_open()) {
        numNodos = 0; numAristas = 0; numRutas = 0;
        while (getline(archivo, linea)) {
            if (linea.find("\"origen\": ") != string::npos) orig = linea.substr(linea.find(": ") + 2, linea.find(",") - (linea.find(": ") + 2));
            else if (linea.find("\"destino\": ") != string::npos) dest = linea.substr(linea.find(": ") + 2, linea.find(",") - (linea.find(": ") + 2));
            else if (linea.find("\"arista\": \"") != string::npos) arista = linea.substr(linea.find("\"arista\": \"") + 11, linea.find("\"", linea.find("\"arista\": \"") + 11) - (linea.find("\"arista\": \"") + 11));
            else if (linea.find("\"tiempo\": ") != string::npos) tiempo = linea.substr(linea.find(": ") + 2, linea.find(",") - (linea.find(": ") + 2));
            else if (linea.find("\"costo\": ") != string::npos) {
                costo = "";
                for (size_t i = linea.find(": ") + 2; i < linea.length(); i++) { if (isdigit(linea[i])) costo += linea[i]; else break; }
                agregarRuta(stoi(orig), stoi(dest), arista, stoi(tiempo), stoi(costo));
            }
        }
        archivo.close(); cout << "Mapa cargado desde JSON.\n";
    } else { cout << "No se pudo abrir el archivo JSON.\n"; }
}