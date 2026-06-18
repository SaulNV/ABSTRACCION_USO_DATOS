#include "NumsPunArr.h"
#include <fstream>
#include <iostream>

using namespace std;

Numeros::Numeros(float v[]) {

    p = datos;

    for(int i=0; i<5; i++) {
        *(p+i) = v[i];
    }
}

Numeros::~Numeros() {
}

float Numeros::suma() {

    float s = 0;

    for(int i=0; i<5; i++) {
        s += *(p+i);
    }

    return s;
}

float Numeros::promedio() {
    return suma()/5.0;
}

float Numeros::media() {
    return promedio();
}

float Numeros::maximo() {

    float m = *p;

    for(int i=1; i<5; i++) {

        if(*(p+i) > m)
            m = *(p+i);
    }

    return m;
}

float Numeros::minimo() {

    float m = *p;

    for(int i=1; i<5; i++) {

        if(*(p+i) < m)
            m = *(p+i);
    }

    return m;
}

float Numeros::getDato(int i) {
    return *(p+i);
}

void generarTXT(Numeros op) {

    ofstream archivo("practica10.txt");

    archivo << "PRACTICA 10 - PUNTEROS AL ARREGLO\n\n";

    for(int i=0; i<5; i++) {

        archivo << "Numero "
                << i+1
                << ": "
                << op.getDato(i)
                << "\n";
    }

    archivo << "\nSuma: " << op.suma();
    archivo << "\nPromedio: " << op.promedio();
    archivo << "\nMedia: " << op.media();
    archivo << "\nMaximo: " << op.maximo();
    archivo << "\nMinimo: " << op.minimo();

    archivo.close();

    cout << "Archivo practica10.txt generado.\n";
}

void generarJSON(Numeros op) {

    ofstream archivo("practica10.json");

    archivo << "{\n";
    archivo << "\"Numeros\":[\n";

    for(int i=0; i<5; i++) {

        archivo << op.getDato(i);

        if(i<4)
            archivo << ",";

        archivo << "\n";
    }

    archivo << "],\n";

    archivo << "\"Resultados\":{\n";
    archivo << "\"suma\":" << op.suma() << ",\n";
    archivo << "\"promedio\":" << op.promedio() << ",\n";
    archivo << "\"media\":" << op.media() << ",\n";
    archivo << "\"maximo\":" << op.maximo() << ",\n";
    archivo << "\"minimo\":" << op.minimo() << "\n";
    archivo << "}\n";
    archivo << "}";

    archivo.close();

    cout << "Archivo practica10.json generado.\n";
}

void generarXML(Numeros op) {

    ofstream archivo("practica10.xml");

    archivo << "<?xml version=\"1.0\"?>\n";
    archivo << "<Practica10>\n";

    archivo << "<Numeros>\n";

    for(int i=0; i<5; i++) {

        archivo << "<Numero>"
                << op.getDato(i)
                << "</Numero>\n";
    }

    archivo << "</Numeros>\n";

    archivo << "<Resultados>\n";
    archivo << "<Suma>" << op.suma() << "</Suma>\n";
    archivo << "<Promedio>" << op.promedio() << "</Promedio>\n";
    archivo << "<Media>" << op.media() << "</Media>\n";
    archivo << "<Maximo>" << op.maximo() << "</Maximo>\n";
    archivo << "<Minimo>" << op.minimo() << "</Minimo>\n";
    archivo << "</Resultados>\n";

    archivo << "</Practica10>";

    archivo.close();

    cout << "Archivo practica10.xml generado.\n";
}

void generarHTML(Numeros op) {

    ofstream archivo("practica10.html");

    archivo << "<!DOCTYPE html>\n";
    archivo << "<html>\n";
    archivo << "<head>\n";
    archivo << "<title>Practica 10</title>\n";
    archivo << "</head>\n";
    archivo << "<body>\n";

    archivo << "<h1>Practica 10 - Punteros al arreglo</h1>\n";

    archivo << "<h2>Numeros</h2>\n";
    archivo << "<ul>\n";

    for(int i=0; i<5; i++) {

        archivo << "<li>"
                << op.getDato(i)
                << "</li>\n";
    }

    archivo << "</ul>\n";

    archivo << "<h2>Resultados</h2>\n";

    archivo << "<p>Suma: "
            << op.suma()
            << "</p>\n";

    archivo << "<p>Promedio: "
            << op.promedio()
            << "</p>\n";

    archivo << "<p>Media: "
            << op.media()
            << "</p>\n";

    archivo << "<p>Maximo: "
            << op.maximo()
            << "</p>\n";

    archivo << "<p>Minimo: "
            << op.minimo()
            << "</p>\n";

    archivo << "</body>\n";
    archivo << "</html>";

    archivo.close();

    cout << "Archivo practica10.html generado.\n";
}
