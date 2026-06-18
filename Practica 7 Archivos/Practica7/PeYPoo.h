#ifndef PEYPOO_H
#define PEYPOO_H

#include <iostream>
#include <cstring>
using namespace std;

// PROGRAMACION ESTRUCTURADA
struct AutoPE {
    int precio;
    int anio;
};

struct PersonaPE {
    char nombre[20];
    char ap[20];
    char am[20];
    char genero;
    int edad;
};

// PROGRAMACION ORIENTADA A OBJETOS
class AutoPOO {
private:
    int precio;
    int anio;

public:
    AutoPOO(int p, int a);
    virtual ~AutoPOO();

    int getPrecio();
    int getAnio();
    void mostrar();
};

class PersonaPOO {
private:
    char nombre[20];
    char ap[20];
    char am[20];
    char genero;
    int edad;

public:
    PersonaPOO(const char n[], const char p[], const char m[], char g, int e);
    virtual ~PersonaPOO();

    const char* getNombre();
    const char* getAp();
    const char* getAm();
    char getGenero();
    int getEdad();

    void mostrar();
};

// FUNCIONES PARA GENERAR ARCHIVOS
void generarTXT(AutoPE autoPE, PersonaPE personaPE, AutoPOO autoPOO, PersonaPOO personaPOO);
void generarJSON(AutoPE autoPE, PersonaPE personaPE, AutoPOO autoPOO, PersonaPOO personaPOO);
void generarXML(AutoPE autoPE, PersonaPE personaPE, AutoPOO autoPOO, PersonaPOO personaPOO);
void generarHTML(AutoPE autoPE, PersonaPE personaPE, AutoPOO autoPOO, PersonaPOO personaPOO);

#endif