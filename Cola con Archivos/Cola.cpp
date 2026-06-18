#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include "Cola.h"

using namespace std;

ColaBase::ColaBase() {
    frente = 0;
    final = -1;
    n = 0;
    limiteUsuario = 100;
}

void ColaBase::setMaximo(int m) {
    if (m > 0 && m <= 100) limiteUsuario = m;
    else limiteUsuario = 100;
}

void ColaBase::insertar(Entidad p) {
    if (!estaLlena()) {
        final = (final + 1) % limiteUsuario;
        arreglo[final] = p;
        n++;
    } else {
        cout << "La cola esta llena\n";
    }
}

void ColaBase::eliminar() {
    if (!estaVacia()) {
        frente = (frente + 1) % limiteUsuario;
        n--;
    } else {
        cout << "La cola esta vacia\n";
    }
}

void ColaBase::mostrarTodo() {
    if (estaVacia()) {
        cout << "La cola esta vacia\n";
        return;
    }
    int idx = frente;
    for (int i = 0; i < n; i++) {
        arreglo[idx].mostrar();
        idx = (idx + 1) % limiteUsuario;
    }
}

bool ColaBase::estaVacia() { return (n == 0); }
bool ColaBase::estaLlena() { return (n == limiteUsuario); }
int ColaBase::getTamanoActual() { return n; }

// =======================================================
// PERSISTENCIA DE ARCHIVOS (MÉTODOS R Y W)
// =======================================================

void ColaBase::escribirCSV(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        archivo << "Nombre,Edad\n";
        int idx = frente;
        for (int i = 0; i < n; i++) {
            archivo << arreglo[idx].getNombre() << "," << arreglo[idx].getEdad() << "\n";
            idx = (idx + 1) % limiteUsuario;
        }
        archivo.close();
        cout << "Archivo CSV guardado.\n";
    }
}

void ColaBase::leerCSV(string ruta) {
    ifstream archivo(ruta);
    string linea, nombre, edadStr;
    if (archivo.is_open()) {
        frente = 0; final = -1; n = 0; // Reiniciar estructura
        getline(archivo, linea);
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            getline(ss, nombre, ',');
            getline(ss, edadStr, ',');
            if (!nombre.empty() && !edadStr.empty()) {
                insertar(Entidad(nombre, stoi(edadStr)));
            }
        }
        archivo.close();
        cout << "Datos cargados desde CSV a la RAM.\n";
    } else { cout << "No se pudo abrir el archivo CSV.\n"; }
}

void ColaBase::escribirTXT(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        int idx = frente;
        for (int i = 0; i < n; i++) {
            archivo << arreglo[idx].getNombre() << "\n" << arreglo[idx].getEdad() << "\n";
            idx = (idx + 1) % limiteUsuario;
        }
        archivo.close();
        cout << "Archivo TXT guardado.\n";
    }
}

void ColaBase::leerTXT(string ruta) {
    ifstream archivo(ruta);
    string nombre, edadStr;
    if (archivo.is_open()) {
        frente = 0; final = -1; n = 0;
        while (getline(archivo, nombre)) {
            getline(archivo, edadStr);
            if (!nombre.empty() && !edadStr.empty()) {
                insertar(Entidad(nombre, stoi(edadStr)));
            }
        }
        archivo.close();
        cout << "Datos cargados desde TXT a la RAM.\n";
    } else { cout << "No se pudo abrir el archivo TXT.\n"; }
}

void ColaBase::escribirXML(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        archivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<entidades>\n";
        int idx = frente;
        for (int i = 0; i < n; i++) {
            archivo << "  <entidad>\n    <nombre>" << arreglo[idx].getNombre() << "</nombre>\n";
            archivo << "    <edad>" << arreglo[idx].getEdad() << "</edad>\n  </entidad>\n";
            idx = (idx + 1) % limiteUsuario;
        }
        archivo << "</entidades>\n";
        archivo.close();
        cout << "Archivo XML guardado.\n";
    }
}

void ColaBase::leerXML(string ruta) {
    ifstream archivo(ruta);
    string linea, nombre, edadStr;
    if (archivo.is_open()) {
        frente = 0; final = -1; n = 0;
        while (getline(archivo, linea)) {
            size_t pNom = linea.find("<nombre>");
            if (pNom != string::npos) {
                nombre = linea.substr(pNom + 8, linea.find("</nombre>") - (pNom + 8));
            }
            size_t pEdad = linea.find("<edad>");
            if (pEdad != string::npos) {
                edadStr = linea.substr(pEdad + 6, linea.find("</edad>") - (pEdad + 6));
                insertar(Entidad(nombre, stoi(edadStr)));
            }
        }
        archivo.close();
        cout << "Datos cargados desde XML a la RAM.\n";
    } else { cout << "No se pudo abrir el archivo XML.\n"; }
}

void ColaBase::escribirJSON(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        archivo << "[\n";
        int idx = frente;
        for (int i = 0; i < n; i++) {
            archivo << "  {\n    \"nombre\": \"" << arreglo[idx].getNombre() << "\",\n";
            archivo << "    \"edad\": " << arreglo[idx].getEdad() << "\n  }";
            if (i < n - 1) archivo << ",";
            archivo << "\n";
            idx = (idx + 1) % limiteUsuario;
        }
        archivo << "]\n";
        archivo.close();
        cout << "Archivo JSON guardado.\n";
    }
}

void ColaBase::leerJSON(string ruta) {
    ifstream archivo(ruta);
    string linea, nombre, edadStr;
    if (archivo.is_open()) {
        frente = 0; final = -1; n = 0;
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
                    insertar(Entidad(nombre, stoi(edadStr)));
                }
            }
        }
        archivo.close();
        cout << "Datos cargados desde JSON a la RAM.\n";
    } else { cout << "No se pudo abrir el archivo JSON.\n"; }
}