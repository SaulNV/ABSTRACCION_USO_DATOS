#include <iostream>
#include <fstream>   
#include <sstream>   
#include "Arbol.h"

using namespace std;

ArbolBinario::ArbolBinario() {
    raiz = nullptr;
}


ArbolBinario::~ArbolBinario() {
    destruirArbol(raiz);
}

void ArbolBinario::destruirArbol(Nodo* nodo) {
    if (nodo != nullptr) {
        destruirArbol(nodo->izq);
        destruirArbol(nodo->der);
        delete nodo;
    }
}

bool ArbolBinario::estaVacio() {
    return raiz == nullptr;
}


void ArbolBinario::insertar(Entidad p) {
    raiz = insertarRec(raiz, p);
}

Nodo* ArbolBinario::insertarRec(Nodo* nodo, Entidad p) {
    
    if (nodo == nullptr) {
        return new Nodo(p);
    }
    
    if (p.getEdad() < nodo->dato.getEdad()) {
        nodo->izq = insertarRec(nodo->izq, p);
    } 
    
    else {
        nodo->der = insertarRec(nodo->der, p);
    }
    return nodo;
}


void ArbolBinario::eliminar(int edad) {
    raiz = eliminarRec(raiz, edad);
}

Nodo* ArbolBinario::encontrarMinimo(Nodo* nodo) {
    Nodo* actual = nodo;
    while (actual && actual->izq != nullptr) {
        actual = actual->izq; 
    }
    return actual;
}

Nodo* ArbolBinario::eliminarRec(Nodo* nodo, int edadBusqueda) {
    if (nodo == nullptr) return nodo;

   
    if (edadBusqueda < nodo->dato.getEdad()) {
        nodo->izq = eliminarRec(nodo->izq, edadBusqueda);
    } else if (edadBusqueda > nodo->dato.getEdad()) {
        nodo->der = eliminarRec(nodo->der, edadBusqueda);
    } 
    
    else {
     
        if (nodo->izq == nullptr) {
            Nodo* temp = nodo->der;
            delete nodo;
            return temp;
        } else if (nodo->der == nullptr) {
            Nodo* temp = nodo->izq;
            delete nodo;
            return temp;
        }
      
        Nodo* temp = encontrarMinimo(nodo->der);
       
        nodo->dato = temp->dato;
       
        nodo->der = eliminarRec(nodo->der, temp->dato.getEdad());
    }
    return nodo;
}


void ArbolBinario::mostrarInOrden() {
    if (estaVacio()) cout << "El arbol esta vacio.\n";
    else { inOrdenRec(raiz); cout << "\n"; }
}
void ArbolBinario::inOrdenRec(Nodo* nodo) {
    if (nodo != nullptr) {
        inOrdenRec(nodo->izq);
        cout << "[ "; nodo->dato.mostrar(); cout << " ]\n";
        inOrdenRec(nodo->der);
    }
}

void ArbolBinario::mostrarPreOrden() {
    if (estaVacio()) cout << "El arbol esta vacio.\n";
    else { preOrdenRec(raiz); cout << "\n"; }
}
void ArbolBinario::preOrdenRec(Nodo* nodo) {
    if (nodo != nullptr) {
        cout << "[ "; nodo->dato.mostrar(); cout << " ]\n";
        preOrdenRec(nodo->izq);
        preOrdenRec(nodo->der);
    }
}

void ArbolBinario::mostrarPostOrden() {
    if (estaVacio()) cout << "El arbol esta vacio.\n";
    else { postOrdenRec(raiz); cout << "\n"; }
}
void ArbolBinario::postOrdenRec(Nodo* nodo) {
    if (nodo != nullptr) {
        postOrdenRec(nodo->izq);
        postOrdenRec(nodo->der);
        cout << "[ "; nodo->dato.mostrar(); cout << " ]\n";
    }
}



void ArbolBinario::guardarPreOrdenCSV(Nodo* nodo, ofstream& archivo) {
    if (nodo != nullptr) {
        archivo << nodo->dato.getNombre() << "," << nodo->dato.getEdad() << "\n";
        guardarPreOrdenCSV(nodo->izq, archivo);
        guardarPreOrdenCSV(nodo->der, archivo);
    }
}
void ArbolBinario::guardarPreOrdenTXT(Nodo* nodo, ofstream& archivo) {
    if (nodo != nullptr) {
        archivo << nodo->dato.getNombre() << "\n" << nodo->dato.getEdad() << "\n";
        guardarPreOrdenTXT(nodo->izq, archivo);
        guardarPreOrdenTXT(nodo->der, archivo);
    }
}
void ArbolBinario::guardarPreOrdenXML(Nodo* nodo, ofstream& archivo) {
    if (nodo != nullptr) {
        archivo << "  <entidad>\n    <nombre>" << nodo->dato.getNombre() << "</nombre>\n"
                << "    <edad>" << nodo->dato.getEdad() << "</edad>\n  </entidad>\n";
        guardarPreOrdenXML(nodo->izq, archivo);
        guardarPreOrdenXML(nodo->der, archivo);
    }
}
void ArbolBinario::guardarPreOrdenJSON(Nodo* nodo, ofstream& archivo, bool& primero) {
    if (nodo != nullptr) {
        if (!primero) archivo << ",\n";
        archivo << "  {\n    \"nombre\": \"" << nodo->dato.getNombre() << "\",\n"
                << "    \"edad\": " << nodo->dato.getEdad() << "\n  }";
        primero = false;
        guardarPreOrdenJSON(nodo->izq, archivo, primero);
        guardarPreOrdenJSON(nodo->der, archivo, primero);
    }
}

// --- CSV ---
void ArbolBinario::escribirCSV(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) { archivo << "Nombre,Edad\n"; guardarPreOrdenCSV(raiz, archivo); archivo.close(); cout << "Arbol guardado en CSV.\n"; }
}
void ArbolBinario::leerCSV(string ruta) {
    ifstream archivo(ruta); string linea, nombre, edadStr;
    if (archivo.is_open()) {
        destruirArbol(raiz); raiz = nullptr; getline(archivo, linea);
        while (getline(archivo, linea)) {
            stringstream ss(linea); getline(ss, nombre, ','); getline(ss, edadStr, ',');
            if (!nombre.empty() && !edadStr.empty()) insertar(Entidad(nombre, stoi(edadStr)));
        }
        archivo.close(); cout << "Arbol cargado desde CSV.\n";
    } else { cout << "No se pudo abrir el archivo CSV.\n"; }
}

// --- TXT ---
void ArbolBinario::escribirTXT(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) { guardarPreOrdenTXT(raiz, archivo); archivo.close(); cout << "Arbol guardado en TXT.\n"; }
}
void ArbolBinario::leerTXT(string ruta) {
    ifstream archivo(ruta); string nombre, edadStr;
    if (archivo.is_open()) {
        destruirArbol(raiz); raiz = nullptr;
        while (getline(archivo, nombre) && getline(archivo, edadStr)) {
            if (!nombre.empty() && !edadStr.empty()) insertar(Entidad(nombre, stoi(edadStr)));
        }
        archivo.close(); cout << "Arbol cargado desde TXT.\n";
    } else { cout << "No se pudo abrir el archivo TXT.\n"; }
}

// --- XML ---
void ArbolBinario::escribirXML(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        archivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<entidades>\n";
        guardarPreOrdenXML(raiz, archivo); archivo << "</entidades>\n"; archivo.close(); cout << "Arbol guardado en XML.\n";
    }
}
void ArbolBinario::leerXML(string ruta) {
    ifstream archivo(ruta); string linea, nombre, edadStr;
    if (archivo.is_open()) {
        destruirArbol(raiz); raiz = nullptr;
        while (getline(archivo, linea)) {
            if (linea.find("<nombre>") != string::npos) nombre = linea.substr(linea.find("<nombre>") + 8, linea.find("</nombre>") - (linea.find("<nombre>") + 8));
            else if (linea.find("<edad>") != string::npos) {
                edadStr = linea.substr(linea.find("<edad>") + 6, linea.find("</edad>") - (linea.find("<edad>") + 6));
                insertar(Entidad(nombre, stoi(edadStr)));
            }
        }
        archivo.close(); cout << "Arbol cargado desde XML.\n";
    } else { cout << "No se pudo abrir el archivo XML.\n"; }
}

// --- JSON ---
void ArbolBinario::escribirJSON(string ruta) {
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        archivo << "[\n"; bool primero = true; guardarPreOrdenJSON(raiz, archivo, primero);
        archivo << "\n]\n"; archivo.close(); cout << "Arbol guardado en JSON.\n";
    }
}
void ArbolBinario::leerJSON(string ruta) {
    ifstream archivo(ruta); string linea, nombre, edadStr;
    if (archivo.is_open()) {
        destruirArbol(raiz); raiz = nullptr;
        while (getline(archivo, linea)) {
            if (linea.find("\"nombre\": \"") != string::npos) nombre = linea.substr(linea.find("\"nombre\": \"") + 11, linea.find("\"", linea.find("\"nombre\": \"") + 11) - (linea.find("\"nombre\": \"") + 11));
            else if (linea.find("\"edad\": ") != string::npos) {
                edadStr = ""; for (size_t i = linea.find(": ") + 2; i < linea.length(); i++) { if (isdigit(linea[i])) edadStr += linea[i]; else break; }
                if (!nombre.empty() && !edadStr.empty()) insertar(Entidad(nombre, stoi(edadStr)));
            }
        }
        archivo.close(); cout << "Arbol cargado desde JSON.\n";
    } else { cout << "No se pudo abrir el archivo JSON.\n"; }
}