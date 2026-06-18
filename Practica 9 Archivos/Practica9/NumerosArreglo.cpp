#include "NumerosArreglo.h"
#include <iostream>
#include <fstream>

using namespace std;

Numeros::Numeros(float v[]) {
    for (int i = 0; i < 5; i++) {
        datos[i] = v[i];
    }
}

Numeros::~Numeros() {
}

float Numeros::suma() {
    float s = 0;

    for (int i = 0; i < 5; i++) {
        s += datos[i];
    }

    return s;
}

float Numeros::promedio() {
    return suma() / 5.0;
}

float Numeros::media() {
    return suma() / 5.0;
}

float Numeros::maximo() {
    float m = datos[0];

    for (int i = 1; i < 5; i++) {
        if (datos[i] > m) {
            m = datos[i];
        }
    }

    return m;
}

float Numeros::minimo() {
    float m = datos[0];

    for (int i = 1; i < 5; i++) {
        if (datos[i] < m) {
            m = datos[i];
        }
    }

    return m;
}

float Numeros::getDato(int i) {
    return datos[i];
}

void generarTXT(Numeros op) {
    ofstream archivo("practica9.txt");

    archivo << "PRACTICA 9 - ARREGLOS\n\n";

    for (int i = 0; i < 5; i++) {
        archivo << "Numero " << i + 1 << ": " << op.getDato(i) << "\n";
    }

    archivo << "\nRESULTADOS\n";
    archivo << "Suma: " << op.suma() << "\n";
    archivo << "Promedio: " << op.promedio() << "\n";
    archivo << "Media: " << op.media() << "\n";
    archivo << "Maximo: " << op.maximo() << "\n";
    archivo << "Minimo: " << op.minimo() << "\n";

    archivo.close();

    cout << "Archivo practica9.txt generado.\n";
}

void generarJSON(Numeros op) {
    ofstream archivo("practica9.json");

    archivo << "{\n";
    archivo << "  \"Practica\": \"Practica 9 - Arreglos\",\n";
    archivo << "  \"Numeros\": [\n";

    for (int i = 0; i < 5; i++) {
        archivo << "    " << op.getDato(i);

        if (i < 4) {
            archivo << ",";
        }

        archivo << "\n";
    }

    archivo << "  ],\n";
    archivo << "  \"Resultados\": {\n";
    archivo << "    \"suma\": " << op.suma() << ",\n";
    archivo << "    \"promedio\": " << op.promedio() << ",\n";
    archivo << "    \"media\": " << op.media() << ",\n";
    archivo << "    \"maximo\": " << op.maximo() << ",\n";
    archivo << "    \"minimo\": " << op.minimo() << "\n";
    archivo << "  }\n";
    archivo << "}\n";

    archivo.close();

    cout << "Archivo practica9.json generado.\n";
}

void generarXML(Numeros op) {
    ofstream archivo("practica9.xml");

    archivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    archivo << "<Practica9>\n";

    archivo << "  <Numeros>\n";

    for (int i = 0; i < 5; i++) {
        archivo << "    <Numero>" << op.getDato(i) << "</Numero>\n";
    }

    archivo << "  </Numeros>\n";

    archivo << "  <Resultados>\n";
    archivo << "    <Suma>" << op.suma() << "</Suma>\n";
    archivo << "    <Promedio>" << op.promedio() << "</Promedio>\n";
    archivo << "    <Media>" << op.media() << "</Media>\n";
    archivo << "    <Maximo>" << op.maximo() << "</Maximo>\n";
    archivo << "    <Minimo>" << op.minimo() << "</Minimo>\n";
    archivo << "  </Resultados>\n";

    archivo << "</Practica9>\n";

    archivo.close();

    cout << "Archivo practica9.xml generado.\n";
}

void generarHTML(Numeros op) {
    ofstream archivo("practica9.html");

    archivo << "<!DOCTYPE html>\n";
    archivo << "<html lang=\"es\">\n";
    archivo << "<head>\n";
    archivo << "    <meta charset=\"UTF-8\">\n";
    archivo << "    <title>Practica 9</title>\n";
    archivo << "</head>\n";
    archivo << "<body>\n";

    archivo << "    <h1>Practica 9 - Arreglos</h1>\n";

    archivo << "    <h2>Numeros ingresados</h2>\n";
    archivo << "    <ul>\n";

    for (int i = 0; i < 5; i++) {
        archivo << "        <li>Numero " << i + 1 << ": " << op.getDato(i) << "</li>\n";
    }

    archivo << "    </ul>\n";

    archivo << "    <h2>Resultados</h2>\n";
    archivo << "    <p>Suma: " << op.suma() << "</p>\n";
    archivo << "    <p>Promedio: " << op.promedio() << "</p>\n";
    archivo << "    <p>Media: " << op.media() << "</p>\n";
    archivo << "    <p>Maximo: " << op.maximo() << "</p>\n";
    archivo << "    <p>Minimo: " << op.minimo() << "</p>\n";

    archivo << "</body>\n";
    archivo << "</html>\n";

    archivo.close();

    cout << "Archivo practica9.html generado.\n";
}