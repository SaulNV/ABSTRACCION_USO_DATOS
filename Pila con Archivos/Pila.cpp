#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include "Pila.h"

using namespace std;

PilaBase::PilaBase() {
    tope = -1; 
    limiteUsuario = 100;
}

void PilaBase::setMaximo(int m) {
    if (m > 0 && m <= 100) limiteUsuario = m;
    else limiteUsuario = 100;
}

void PilaBase::apilar(Entidad p) {
    if (!estaLlena()) {
        tope++;
        arreglo[tope] = p;
    } else {
        cout << "La pila esta llena.\n";
    }
}

void PilaBase::desapilar() {
    if (!estaVacia()) {
        tope--; 
    } else {
        cout << "La pila esta vacia.\n";
    }
}

void PilaBase::mostrarTodo() {
    if (estaVacia()) {
        cout << "La pila esta vacia.\n";
        return;
    }
    for (int i = tope; i >= 0; i--) {
        cout << "[Nivel " << i << "] ";
        arreglo[i].mostrar();
    }
}

bool PilaBase::estaVacia() { return (tope == -1); }
bool PilaBase::estaLlena() { return (tope == limiteUsuario - 1); }
int PilaBase::getTamanoActual() { return tope + 1; }

// =======================================================
// PERSISTENCIA DE ARCHIVOS (MÉTODOS R Y W)
// =======================================================

void PilaBase::escribirCSV(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        archivo << "Nombre,Edad\n";
        for (int i = 0; i <= tope; i++) {
            archivo << arreglo[i].getNombre() << "," << arreglo[i].getEdad() << "\n";
        }
        archivo.close();
        cout << "Archivo CSV guardado.\n";
    }
}

void PilaBase::leerCSV(string ruta) {
    ifstream archivo(ruta);
    string linea, nombre, edadStr;
    if (archivo.is_open()) {
        tope = -1; 
        getline(archivo, linea);
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            getline(ss, nombre, ',');
            getline(ss, edadStr, ',');
            if (!nombre.empty() && !edadStr.empty()) {
                apilar(Entidad(nombre, stoi(edadStr)));
            }
        }
        archivo.close();
        cout << "Datos cargados desde CSV.\n";
    } else { cout << "No se pudo abrir el archivo CSV.\n"; }
}

void PilaBase::escribirTXT(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        for (int i = 0; i <= tope; i++) {
            archivo << arreglo[i].getNombre() << "\n" << arreglo[i].getEdad() << "\n";
        }
        archivo.close();
        cout << "Archivo TXT guardado.\n";
    }
}

void PilaBase::leerTXT(string ruta) {
    ifstream archivo(ruta);
    string nombre, edadStr;
    if (archivo.is_open()) {
        tope = -1;
        while (getline(archivo, nombre)) {
            getline(archivo, edadStr);
            if (!nombre.empty() && !edadStr.empty()) {
                apilar(Entidad(nombre, stoi(edadStr)));
            }
        }
        archivo.close();
        cout << "Datos cargados desde TXT.\n";
    } else { cout << "No se pudo abrir el archivo TXT.\n"; }
}

void PilaBase::escribirXML(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        archivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<entidades>\n";
        for (int i = 0; i <= tope; i++) {
            archivo << "  <entidad>\n    <nombre>" << arreglo[i].getNombre() << "</nombre>\n";
            archivo << "    <edad>" << arreglo[i].getEdad() << "</edad>\n  </entidad>\n";
        }
        archivo << "</entidades>\n";
        archivo.close();
        cout << "Archivo XML guardado.\n";
    }
}

void PilaBase::leerXML(string ruta) {
    ifstream archivo(ruta);
    string linea, nombre, edadStr;
    if (archivo.is_open()) {
        tope = -1;
        while (getline(archivo, linea)) {
            size_t pNom = linea.find("<nombre>");
            if (pNom != string::npos) {
                nombre = linea.substr(pNom + 8, linea.find("</nombre>") - (pNom + 8));
            }
            size_t pEdad = linea.find("<edad>");
            if (pEdad != string::npos) {
                edadStr = linea.substr(pEdad + 6, linea.find("</edad>") - (pEdad + 6));
                apilar(Entidad(nombre, stoi(edadStr)));
            }
        }
        archivo.close();
        cout << "Datos cargados desde XML.\n";
    } else { cout << "No se pudo abrir el archivo XML.\n"; }
}

void PilaBase::escribirJSON(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        archivo << "[\n";
        for (int i = 0; i <= tope; i++) {
            archivo << "  {\n    \"nombre\": \"" << arreglo[i].getNombre() << "\",\n";
            archivo << "    \"edad\": " << arreglo[i].getEdad() << "\n  }";
            if (i < tope) archivo << ",";
            archivo << "\n";
        }
        archivo << "]\n";
        archivo.close();
        cout << "Archivo JSON guardado.\n";
    }
}

void PilaBase::leerJSON(string ruta) {
    ifstream archivo(ruta);
    string linea, nombre, edadStr;
    if (archivo.is_open()) {
        tope = -1;
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
                    apilar(Entidad(nombre, stoi(edadStr)));
                }
            }
        }
        archivo.close();
        cout << "Datos cargados desde JSON.\n";
    } else { cout << "No se pudo abrir el archivo JSON.\n"; }
}