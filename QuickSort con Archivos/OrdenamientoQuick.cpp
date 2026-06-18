#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include "OrdenamientoQuick.h"

using namespace std;

// =======================================================
// ALGORITMO QUICK SORT (PARTICIÓN Y RECURSIVIDAD)
// =======================================================

int OrdenadorQuick::partition(int bajo, int alto) {
    int pivote = arreglo[alto].getEdad(); 
    int i = (bajo - 1); 

    for (int j = bajo; j <= alto - 1; j++) {
        if (arreglo[j].getEdad() < pivote) {
            i++; 
            Entidad temp = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temp;
        }
    }
    Entidad temp = arreglo[i + 1];
    arreglo[i + 1] = arreglo[alto];
    arreglo[alto] = temp;
    
    return (i + 1); 
}

void OrdenadorQuick::quickSortRec(int bajo, int alto) {
    if (bajo < alto) {
        int pi = partition(bajo, alto);
        quickSortRec(bajo, pi - 1);
        quickSortRec(pi + 1, alto);
    }
}

void OrdenadorQuick::ordenar() {
    if (n > 1) {
        quickSortRec(0, n - 1);
    }
}


OrdenadorBase::OrdenadorBase() { n = 0; limiteUsuario = 100; }
void OrdenadorBase::setMaximo(int m) { if (m > 0 && m <= 100) limiteUsuario = m; else limiteUsuario = 100; }
void OrdenadorBase::agregar(Entidad p) { if (!estaLlena()) { arreglo[n] = p; n++; } else { cout << "El arreglo esta lleno\n"; } }
void OrdenadorBase::quitarUltimo() { if (!estaVacia()) n--; }
void OrdenadorBase::mostrarTodo() { if (estaVacia()) { cout << "La lista esta vacia\n"; return; } for (int i = 0; i < n; i++) arreglo[i].mostrar(); }
bool OrdenadorBase::estaVacia() { return (n == 0); }
bool OrdenadorBase::estaLlena() { return (n == limiteUsuario); }
int OrdenadorBase::getTamanoActual() { return n; }



void OrdenadorBase::escribirCSV(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        archivo << "Nombre,Edad\n";
        for (int i = 0; i < n; i++) archivo << arreglo[i].getNombre() << "," << arreglo[i].getEdad() << "\n";
        archivo.close(); 
        cout << "Archivo CSV guardado.\n";
    }
}

void OrdenadorBase::leerCSV(string ruta) {
    ifstream archivo(ruta); string linea, nombre, edadStr;
    if (archivo.is_open()) {
        n = 0; getline(archivo, linea); 
        while (getline(archivo, linea)) {
            stringstream ss(linea); getline(ss, nombre, ','); getline(ss, edadStr, ',');
            if (!nombre.empty() && !edadStr.empty()) agregar(Entidad(nombre, stoi(edadStr)));
        }
        archivo.close(); 
        cout << "Datos cargados desde CSV a la RAM.\n";
    } else {
        cout << "No se pudo abrir el archivo CSV.\n";
    }
}

void OrdenadorBase::escribirTXT(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        for (int i = 0; i < n; i++) archivo << arreglo[i].getNombre() << "\n" << arreglo[i].getEdad() << "\n";
        archivo.close(); 
        cout << "Archivo TXT guardado.\n";
    }
}

void OrdenadorBase::leerTXT(string ruta) {
    ifstream archivo(ruta); string nombre, edadStr;
    if (archivo.is_open()) {
        n = 0;
        while (getline(archivo, nombre)) {
            getline(archivo, edadStr);
            if (!nombre.empty() && !edadStr.empty()) agregar(Entidad(nombre, stoi(edadStr)));
        }
        archivo.close(); 
        cout << "Datos cargados desde TXT a la RAM.\n";
    } else {
        cout << "No se pudo abrir el archivo TXT.\n";
    }
}

void OrdenadorBase::escribirXML(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        archivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<entidades>\n";
        for (int i = 0; i < n; i++) {
            archivo << "  <entidad>\n    <nombre>" << arreglo[i].getNombre() << "</nombre>\n";
            archivo << "    <edad>" << arreglo[i].getEdad() << "</edad>\n  </entidad>\n";
        }
        archivo << "</entidades>\n"; 
        archivo.close(); 
        cout << "Archivo XML guardado.\n";
    }
}

void OrdenadorBase::leerXML(string ruta) {
    ifstream archivo(ruta); string linea, nombre, edadStr;
    if (archivo.is_open()) {
        n = 0;
        while (getline(archivo, linea)) {
            size_t pNom = linea.find("<nombre>");
            if (pNom != string::npos) nombre = linea.substr(pNom + 8, linea.find("</nombre>") - (pNom + 8));
            size_t pEdad = linea.find("<edad>");
            if (pEdad != string::npos) {
                edadStr = linea.substr(pEdad + 6, linea.find("</edad>") - (pEdad + 6));
                agregar(Entidad(nombre, stoi(edadStr)));
            }
        }
        archivo.close(); 
        cout << "Datos cargados desde XML a la RAM.\n";
    } else {
        cout << "No se pudo abrir el archivo XML.\n";
    }
}

void OrdenadorBase::escribirJSON(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        archivo << "[\n";
        for (int i = 0; i < n; i++) {
            archivo << "  {\n    \"nombre\": \"" << arreglo[i].getNombre() << "\",\n";
            archivo << "    \"edad\": " << arreglo[i].getEdad() << "\n  }";
            if (i < n - 1) archivo << ","; archivo << "\n";
        }
        archivo << "]\n"; 
        archivo.close(); 
        cout << "Archivo JSON guardado.\n";
    }
}

void OrdenadorBase::leerJSON(string ruta) {
    ifstream archivo(ruta); string linea, nombre, edadStr;
    if (archivo.is_open()) {
        n = 0;
        while (getline(archivo, linea)) {
            size_t pNom = linea.find("\"nombre\": \"");
            if (pNom != string::npos) {
                size_t inicio = pNom + 11; nombre = linea.substr(inicio, linea.find("\"", inicio) - inicio);
            }
            size_t pEdad = linea.find("\"edad\": ");
            if (pEdad != string::npos) {
                size_t inicio = pEdad + 8; edadStr = "";
                for (size_t i = inicio; i < linea.length(); i++) {
                    if (isdigit(linea[i])) edadStr += linea[i]; else break;
                }
                if (!nombre.empty() && !edadStr.empty()) agregar(Entidad(nombre, stoi(edadStr)));
            }
        }
        archivo.close(); 
        cout << "Datos cargados desde JSON a la RAM.\n";
    } else {
        cout << "No se pudo abrir el archivo JSON.\n";
    }
}