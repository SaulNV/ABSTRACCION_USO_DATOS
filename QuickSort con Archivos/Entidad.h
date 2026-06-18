#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <iostream>
#include <string>

using namespace std;

class Entidad {
private:
    string nombre;
    int edad;

public:
    Entidad(string n = "", int e = 0) {
        nombre = n;
        edad = e;
    }

    string getNombre() { return nombre; }
    int getEdad() { return edad; }

    void mostrar() {
        cout << "  -> Nombre: " << nombre << "\t| Edad: " << edad << "\n";
    }
};

#endif