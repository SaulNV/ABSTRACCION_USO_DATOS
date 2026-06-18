#include "Numeros.h"
#include <iostream>
#include <fstream>

using namespace std;

Numeros::Numeros(float a, float b, float c, float d, float e) {
    n1 = a;
    n2 = b;
    n3 = c;
    n4 = d;
    n5 = e;
}

Numeros::~Numeros() {
}

float Numeros::suma() {
    return n1 + n2 + n3 + n4 + n5;
}

float Numeros::promedio() {
    return suma() / 5.0;
}

float Numeros::media() {
    return suma() / 5.0;
}

float Numeros::maximo() {
    float m = n1;

    if (n2 > m) m = n2;
    if (n3 > m) m = n3;
    if (n4 > m) m = n4;
    if (n5 > m) m = n5;

    return m;
}

float Numeros::minimo() {
    float m = n1;

    if (n2 < m) m = n2;
    if (n3 < m) m = n3;
    if (n4 < m) m = n4;
    if (n5 < m) m = n5;

    return m;
}

float Numeros::getN1() { return n1; }
float Numeros::getN2() { return n2; }
float Numeros::getN3() { return n3; }
float Numeros::getN4() { return n4; }
float Numeros::getN5() { return n5; }

// TXT
void generarTXT(Numeros op) {

    ofstream archivo("practica8.txt");

    archivo << "PRACTICA 8 - NUMEROS\n\n";

    archivo << "Numero 1: " << op.getN1() << "\n";
    archivo << "Numero 2: " << op.getN2() << "\n";
    archivo << "Numero 3: " << op.getN3() << "\n";
    archivo << "Numero 4: " << op.getN4() << "\n";
    archivo << "Numero 5: " << op.getN5() << "\n\n";

    archivo << "Suma: " << op.suma() << "\n";
    archivo << "Promedio: " << op.promedio() << "\n";
    archivo << "Media: " << op.media() << "\n";
    archivo << "Maximo: " << op.maximo() << "\n";
    archivo << "Minimo: " << op.minimo() << "\n";

    archivo.close();

    cout << "Archivo practica8.txt generado.\n";
}

// JSON
void generarJSON(Numeros op) {

    ofstream archivo("practica8.json");

    archivo << "{\n";
    archivo << "  \"Practica\": \"Practica 8\",\n";
    archivo << "  \"Numeros\": [\n";
    archivo << "    " << op.getN1() << ",\n";
    archivo << "    " << op.getN2() << ",\n";
    archivo << "    " << op.getN3() << ",\n";
    archivo << "    " << op.getN4() << ",\n";
    archivo << "    " << op.getN5() << "\n";
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

    cout << "Archivo practica8.json generado.\n";
}

// XML
void generarXML(Numeros op) {

    ofstream archivo("practica8.xml");

    archivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    archivo << "<Practica8>\n";

    archivo << "  <Numeros>\n";
    archivo << "    <Numero1>" << op.getN1() << "</Numero1>\n";
    archivo << "    <Numero2>" << op.getN2() << "</Numero2>\n";
    archivo << "    <Numero3>" << op.getN3() << "</Numero3>\n";
    archivo << "    <Numero4>" << op.getN4() << "</Numero4>\n";
    archivo << "    <Numero5>" << op.getN5() << "</Numero5>\n";
    archivo << "  </Numeros>\n";

    archivo << "  <Resultados>\n";
    archivo << "    <Suma>" << op.suma() << "</Suma>\n";
    archivo << "    <Promedio>" << op.promedio() << "</Promedio>\n";
    archivo << "    <Media>" << op.media() << "</Media>\n";
    archivo << "    <Maximo>" << op.maximo() << "</Maximo>\n";
    archivo << "    <Minimo>" << op.minimo() << "</Minimo>\n";
    archivo << "  </Resultados>\n";

    archivo << "</Practica8>\n";

    archivo.close();

    cout << "Archivo practica8.xml generado.\n";
}

// HTML
void generarHTML(Numeros op) {

    ofstream archivo("practica8.html");

    archivo << "<!DOCTYPE html>\n";
    archivo << "<html lang=\"es\">\n";
    archivo << "<head>\n";
    archivo << "  <meta charset=\"UTF-8\">\n";
    archivo << "  <title>Practica 8</title>\n";
    archivo << "</head>\n";
    archivo << "<body>\n";

    archivo << "<h1>Practica 8 - Numeros</h1>\n";

    archivo << "<h2>Numeros ingresados</h2>\n";
    archivo << "<ul>\n";
    archivo << "<li>" << op.getN1() << "</li>\n";
    archivo << "<li>" << op.getN2() << "</li>\n";
    archivo << "<li>" << op.getN3() << "</li>\n";
    archivo << "<li>" << op.getN4() << "</li>\n";
    archivo << "<li>" << op.getN5() << "</li>\n";
    archivo << "</ul>\n";

    archivo << "<h2>Resultados</h2>\n";
    archivo << "<p>Suma: " << op.suma() << "</p>\n";
    archivo << "<p>Promedio: " << op.promedio() << "</p>\n";
    archivo << "<p>Media: " << op.media() << "</p>\n";
    archivo << "<p>Maximo: " << op.maximo() << "</p>\n";
    archivo << "<p>Minimo: " << op.minimo() << "</p>\n";

    archivo << "</body>\n";
    archivo << "</html>\n";

    archivo.close();

    cout << "Archivo practica8.html generado.\n";
}