#include "PeYPoo.h"
#include <fstream>

AutoPOO::AutoPOO(int p, int a) {
    precio = p;
    anio = a;
}

AutoPOO::~AutoPOO() {
}

int AutoPOO::getPrecio() {
    return precio;
}

int AutoPOO::getAnio() {
    return anio;
}

void AutoPOO::mostrar() {
    cout << "Auto POO: $" << precio << ", Anio: " << anio << "\n";
}

PersonaPOO::PersonaPOO(const char n[], const char p[], const char m[], char g, int e) {
    strcpy(nombre, n);
    strcpy(ap, p);
    strcpy(am, m);
    genero = g;
    edad = e;
}

PersonaPOO::~PersonaPOO() {
}

const char* PersonaPOO::getNombre() {
    return nombre;
}

const char* PersonaPOO::getAp() {
    return ap;
}

const char* PersonaPOO::getAm() {
    return am;
}

char PersonaPOO::getGenero() {
    return genero;
}

int PersonaPOO::getEdad() {
    return edad;
}

void PersonaPOO::mostrar() {
    cout << "Persona Nombre: " << nombre << " " << ap << " " << am
         << ", Genero: " << genero << ", Edad: " << edad << "\n";
}

void generarTXT(AutoPE autoPE, PersonaPE personaPE, AutoPOO autoPOO, PersonaPOO personaPOO) {
    ofstream archivo("practica7.txt");

    archivo << "PRACTICA 7 - CREACION DE DATO EN PE Y POO\n\n";

    archivo << "PROGRAMACION ESTRUCTURADA\n";
    archivo << "AutoPE: Precio $" << autoPE.precio << ", Anio " << autoPE.anio << "\n";
    archivo << "PersonaPE: " << personaPE.nombre << " " << personaPE.ap << " " << personaPE.am
            << ", Genero " << personaPE.genero << ", Edad " << personaPE.edad << "\n\n";

    archivo << "PROGRAMACION ORIENTADA A OBJETOS\n";
    archivo << "AutoPOO: Precio $" << autoPOO.getPrecio() << ", Anio " << autoPOO.getAnio() << "\n";
    archivo << "PersonaPOO: " << personaPOO.getNombre() << " " << personaPOO.getAp() << " " << personaPOO.getAm()
            << ", Genero " << personaPOO.getGenero() << ", Edad " << personaPOO.getEdad() << "\n\n";

    archivo << "PRACTICA 7 BIS - TAMANOS EN MEMORIA\n";
    archivo << "char: " << sizeof(char) << " bytes\n";
    archivo << "short: " << sizeof(short) << " bytes\n";
    archivo << "int: " << sizeof(int) << " bytes\n";
    archivo << "long: " << sizeof(long) << " bytes\n";
    archivo << "float: " << sizeof(float) << " bytes\n";
    archivo << "double: " << sizeof(double) << " bytes\n";
    archivo << "AutoPE: " << sizeof(AutoPE) << " bytes\n";
    archivo << "PersonaPE: " << sizeof(PersonaPE) << " bytes\n";
    archivo << "AutoPOO: " << sizeof(AutoPOO) << " bytes\n";
    archivo << "PersonaPOO: " << sizeof(PersonaPOO) << " bytes\n";

    archivo.close();

    cout << "Archivo practica7.txt generado.\n";
}

void generarJSON(AutoPE autoPE, PersonaPE personaPE, AutoPOO autoPOO, PersonaPOO personaPOO) {
    ofstream archivo("practica7.json");

    archivo << "{\n";
    archivo << "  \"Practica\": \"Practica 7 - Creacion de dato PE y POO\",\n";
    archivo << "  \"ProgramacionEstructurada\": {\n";
    archivo << "    \"AutoPE\": {\n";
    archivo << "      \"precio\": " << autoPE.precio << ",\n";
    archivo << "      \"anio\": " << autoPE.anio << "\n";
    archivo << "    },\n";
    archivo << "    \"PersonaPE\": {\n";
    archivo << "      \"nombre\": \"" << personaPE.nombre << "\",\n";
    archivo << "      \"apellidoPaterno\": \"" << personaPE.ap << "\",\n";
    archivo << "      \"apellidoMaterno\": \"" << personaPE.am << "\",\n";
    archivo << "      \"genero\": \"" << personaPE.genero << "\",\n";
    archivo << "      \"edad\": " << personaPE.edad << "\n";
    archivo << "    }\n";
    archivo << "  },\n";
    archivo << "  \"ProgramacionOrientadaObjetos\": {\n";
    archivo << "    \"AutoPOO\": {\n";
    archivo << "      \"precio\": " << autoPOO.getPrecio() << ",\n";
    archivo << "      \"anio\": " << autoPOO.getAnio() << "\n";
    archivo << "    },\n";
    archivo << "    \"PersonaPOO\": {\n";
    archivo << "      \"nombre\": \"" << personaPOO.getNombre() << "\",\n";
    archivo << "      \"apellidoPaterno\": \"" << personaPOO.getAp() << "\",\n";
    archivo << "      \"apellidoMaterno\": \"" << personaPOO.getAm() << "\",\n";
    archivo << "      \"genero\": \"" << personaPOO.getGenero() << "\",\n";
    archivo << "      \"edad\": " << personaPOO.getEdad() << "\n";
    archivo << "    }\n";
    archivo << "  },\n";
    archivo << "  \"Tamanos\": {\n";
    archivo << "    \"char\": " << sizeof(char) << ",\n";
    archivo << "    \"short\": " << sizeof(short) << ",\n";
    archivo << "    \"int\": " << sizeof(int) << ",\n";
    archivo << "    \"long\": " << sizeof(long) << ",\n";
    archivo << "    \"float\": " << sizeof(float) << ",\n";
    archivo << "    \"double\": " << sizeof(double) << ",\n";
    archivo << "    \"AutoPE\": " << sizeof(AutoPE) << ",\n";
    archivo << "    \"PersonaPE\": " << sizeof(PersonaPE) << ",\n";
    archivo << "    \"AutoPOO\": " << sizeof(AutoPOO) << ",\n";
    archivo << "    \"PersonaPOO\": " << sizeof(PersonaPOO) << "\n";
    archivo << "  }\n";
    archivo << "}\n";

    archivo.close();

    cout << "Archivo practica7.json generado.\n";
}

void generarXML(AutoPE autoPE, PersonaPE personaPE, AutoPOO autoPOO, PersonaPOO personaPOO) {
    ofstream archivo("practica7.xml");

    archivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    archivo << "<Practica7>\n";

    archivo << "  <ProgramacionEstructurada>\n";
    archivo << "    <AutoPE>\n";
    archivo << "      <precio>" << autoPE.precio << "</precio>\n";
    archivo << "      <anio>" << autoPE.anio << "</anio>\n";
    archivo << "    </AutoPE>\n";
    archivo << "    <PersonaPE>\n";
    archivo << "      <nombre>" << personaPE.nombre << "</nombre>\n";
    archivo << "      <apellidoPaterno>" << personaPE.ap << "</apellidoPaterno>\n";
    archivo << "      <apellidoMaterno>" << personaPE.am << "</apellidoMaterno>\n";
    archivo << "      <genero>" << personaPE.genero << "</genero>\n";
    archivo << "      <edad>" << personaPE.edad << "</edad>\n";
    archivo << "    </PersonaPE>\n";
    archivo << "  </ProgramacionEstructurada>\n";

    archivo << "  <ProgramacionOrientadaObjetos>\n";
    archivo << "    <AutoPOO>\n";
    archivo << "      <precio>" << autoPOO.getPrecio() << "</precio>\n";
    archivo << "      <anio>" << autoPOO.getAnio() << "</anio>\n";
    archivo << "    </AutoPOO>\n";
    archivo << "    <PersonaPOO>\n";
    archivo << "      <nombre>" << personaPOO.getNombre() << "</nombre>\n";
    archivo << "      <apellidoPaterno>" << personaPOO.getAp() << "</apellidoPaterno>\n";
    archivo << "      <apellidoMaterno>" << personaPOO.getAm() << "</apellidoMaterno>\n";
    archivo << "      <genero>" << personaPOO.getGenero() << "</genero>\n";
    archivo << "      <edad>" << personaPOO.getEdad() << "</edad>\n";
    archivo << "    </PersonaPOO>\n";
    archivo << "  </ProgramacionOrientadaObjetos>\n";

    archivo << "  <Tamanos>\n";
    archivo << "    <char>" << sizeof(char) << "</char>\n";
    archivo << "    <short>" << sizeof(short) << "</short>\n";
    archivo << "    <int>" << sizeof(int) << "</int>\n";
    archivo << "    <long>" << sizeof(long) << "</long>\n";
    archivo << "    <float>" << sizeof(float) << "</float>\n";
    archivo << "    <double>" << sizeof(double) << "</double>\n";
    archivo << "    <AutoPE>" << sizeof(AutoPE) << "</AutoPE>\n";
    archivo << "    <PersonaPE>" << sizeof(PersonaPE) << "</PersonaPE>\n";
    archivo << "    <AutoPOO>" << sizeof(AutoPOO) << "</AutoPOO>\n";
    archivo << "    <PersonaPOO>" << sizeof(PersonaPOO) << "</PersonaPOO>\n";
    archivo << "  </Tamanos>\n";

    archivo << "</Practica7>\n";

    archivo.close();

    cout << "Archivo practica7.xml generado.\n";
}

void generarHTML(AutoPE autoPE, PersonaPE personaPE, AutoPOO autoPOO, PersonaPOO personaPOO) {
    ofstream archivo("practica7.html");

    archivo << "<!DOCTYPE html>\n";
    archivo << "<html lang=\"es\">\n";
    archivo << "<head>\n";
    archivo << "  <meta charset=\"UTF-8\">\n";
    archivo << "  <title>Practica 7</title>\n";
    archivo << "</head>\n";
    archivo << "<body>\n";

    archivo << "  <h1>Practica 7 - Creacion de dato PE y POO</h1>\n";

    archivo << "  <h2>Programacion Estructurada</h2>\n";
    archivo << "  <p>AutoPE: Precio $" << autoPE.precio << ", Anio " << autoPE.anio << "</p>\n";
    archivo << "  <p>PersonaPE: " << personaPE.nombre << " " << personaPE.ap << " " << personaPE.am
            << ", Genero " << personaPE.genero << ", Edad " << personaPE.edad << "</p>\n";

    archivo << "  <h2>Programacion Orientada a Objetos</h2>\n";
    archivo << "  <p>AutoPOO: Precio $" << autoPOO.getPrecio() << ", Anio " << autoPOO.getAnio() << "</p>\n";
    archivo << "  <p>PersonaPOO: " << personaPOO.getNombre() << " " << personaPOO.getAp() << " " << personaPOO.getAm()
            << ", Genero " << personaPOO.getGenero() << ", Edad " << personaPOO.getEdad() << "</p>\n";

    archivo << "  <h2>Tamanos en memoria</h2>\n";
    archivo << "  <ul>\n";
    archivo << "    <li>char: " << sizeof(char) << " bytes</li>\n";
    archivo << "    <li>short: " << sizeof(short) << " bytes</li>\n";
    archivo << "    <li>int: " << sizeof(int) << " bytes</li>\n";
    archivo << "    <li>long: " << sizeof(long) << " bytes</li>\n";
    archivo << "    <li>float: " << sizeof(float) << " bytes</li>\n";
    archivo << "    <li>double: " << sizeof(double) << " bytes</li>\n";
    archivo << "    <li>AutoPE: " << sizeof(AutoPE) << " bytes</li>\n";
    archivo << "    <li>PersonaPE: " << sizeof(PersonaPE) << " bytes</li>\n";
    archivo << "    <li>AutoPOO: " << sizeof(AutoPOO) << " bytes</li>\n";
    archivo << "    <li>PersonaPOO: " << sizeof(PersonaPOO) << " bytes</li>\n";
    archivo << "  </ul>\n";

    archivo << "</body>\n";
    archivo << "</html>\n";

    archivo.close();

    cout << "Archivo practica7.html generado.\n";
}