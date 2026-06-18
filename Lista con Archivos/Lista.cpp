#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include "Lista.h"

using namespace std;

ListaBase::ListaBase() {
    n = 0;
    limiteUsuario = 100;
}

void ListaBase::setMaximo(int m) {
    if (m > 0 && m <= 100) limiteUsuario = m;
    else limiteUsuario = 100;
}

void ListaBase::agregar(Entidad p) {
    if (!estaLlena()) {
        arreglo[n] = p;
        n++;
    } else {
        cout << "La lista esta llena.\n";
    }
}

// El núcleo de la Lista: Eliminar en cualquier índice válido
void ListaBase::eliminarEnPosicion(int pos) {
    if (!estaVacia()) {
        if (pos >= 0 && pos < n) {
            for (int i = pos; i < n - 1; i++) {
                arreglo[i] = arreglo[i + 1]; // Desplazamiento a la izquierda
            }
            n--;
        } else {
            cout << "Posicion invalida.\n";
        }
    } else {
        cout << "La lista esta vacia.\n";
    }
}

void ListaBase::mostrarTodo() {
    if (estaVacia()) {
        cout << "La lista esta vacia.\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << "[" << i << "] ";
        arreglo[i].mostrar();
    }
}

bool ListaBase::estaVacia() { return (n == 0); }
bool ListaBase::estaLlena() { return (n == limiteUsuario); }
int ListaBase::getTamanoActual() { return n; }

// =======================================================
// PERSISTENCIA DE ARCHIVOS (MÉTODOS R Y W)
// =======================================================

void ListaBase::escribirCSV(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        archivo << "Nombre,Edad\n";
        for (int i = 0; i < n; i++) {
            archivo << arreglo[i].getNombre() << "," << arreglo[i].getEdad() << "\n";
        }
        archivo.close();
        cout << "Archivo CSV guardado.\n";
    }
}

void ListaBase::leerCSV(string ruta) {
    ifstream archivo(ruta);
    string linea, nombre, edadStr;
    if (archivo.is_open()) {
        n = 0; 
        getline(archivo, linea);
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            getline(ss, nombre, ',');
            getline(ss, edadStr, ',');
            if (!nombre.empty() && !edadStr.empty()) {
                agregar(Entidad(nombre, stoi(edadStr)));
            }
        }
        archivo.close();
        cout << "Datos cargados desde CSV a la RAM.\n";
    } else { cout << "No se pudo abrir el archivo CSV.\n"; }
}

void ListaBase::escribirTXT(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        for (int i = 0; i < n; i++) {
            archivo << arreglo[i].getNombre() << "\n" << arreglo[i].getEdad() << "\n";
        }
        archivo.close();
        cout << "Archivo TXT guardado.\n";
    }
}

void ListaBase::leerTXT(string ruta) {
    ifstream archivo(ruta);
    string nombre, edadStr;
    if (archivo.is_open()) {
        n = 0;
        while (getline(archivo, nombre)) {
            getline(archivo, edadStr);
            if (!nombre.empty() && !edadStr.empty()) {
                agregar(Entidad(nombre, stoi(edadStr)));
            }
        }
        archivo.close();
        cout << "Datos cargados desde TXT a la RAM.\n";
    } else { cout << "No se pudo abrir el archivo TXT.\n"; }
}

void ListaBase::escribirXML(string ruta) {
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

void ListaBase::leerXML(string ruta) {
    ifstream archivo(ruta);
    string linea, nombre, edadStr;
    if (archivo.is_open()) {
        n = 0;
        while (getline(archivo, linea)) {
            size_t pNom = linea.find("<nombre>");
            if (pNom != string::npos) {
                nombre = linea.substr(pNom + 8, linea.find("</nombre>") - (pNom + 8));
            }
            size_t pEdad = linea.find("<edad>");
            if (pEdad != string::npos) {
                edadStr = linea.substr(pEdad + 6, linea.find("</edad>") - (pEdad + 6));
                agregar(Entidad(nombre, stoi(edadStr)));
            }
        }
        archivo.close();
        cout << "Datos cargados desde XML a la RAM.\n";
    } else { cout << "No se pudo abrir el archivo XML.\n"; }
}

void ListaBase::escribirJSON(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        archivo << "[\n";
        for (int i = 0; i < n; i++) {
            archivo << "  {\n    \"nombre\": \"" << arreglo[i].getNombre() << "\",\n";
            archivo << "    \"edad\": " << arreglo[i].getEdad() << "\n  }";
            if (i < n - 1) archivo << ",";
            archivo << "\n";
        }
        archivo << "]\n";
        archivo.close();
        cout << "Archivo JSON guardado.\n";
    }
}

void ListaBase::leerJSON(string ruta) {
    ifstream archivo(ruta);
    string linea, nombre, edadStr;
    if (archivo.is_open()) {
        n = 0;
        while (getline(archivo, linea)) {
            size_t pNom = linea.find("\"nombre\": \"");
            if (pNom != string::npos) {
                size_t inicio = pNom + 11;
                nombre = linea.substr(inicio, linea.find("\"", inicio) - inicio);
            }
            size_t pEdad = linea.find("\"edad\": ");
            if (pEdad != string::npos) {
                size_t inicio = pEdad + 8;
                edadStr = "";
                for (size_t i = inicio; i < linea.length(); i++) {
                    if (isdigit(linea[i])) edadStr += linea[i];
                    else break;
                }
                if (!nombre.empty() && !edadStr.empty()) {
                    agregar(Entidad(nombre, stoi(edadStr)));
                }
            }
        }
        archivo.close();
        cout << "Datos cargados desde JSON a la RAM.\n";
    } else { cout << "No se pudo abrir el archivo JSON.\n"; }
}