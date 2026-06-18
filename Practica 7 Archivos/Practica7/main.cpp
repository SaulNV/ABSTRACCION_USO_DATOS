#include <iostream>
#include <cstring>
#include "PeYPoo.h"

using namespace std;

int main() {
    AutoPE op1;
    op1.precio = 152456532;
    op1.anio = 2025;

    PersonaPE op2;
    strcpy(op2.nombre, "Diego");
    strcpy(op2.ap, "Sanchez");
    strcpy(op2.am, "Romero");
    op2.genero = 'H';
    op2.edad = 19;

    AutoPOO op3(4243456, 2024);
    PersonaPOO op4("Samanta", "Rios", "Solorios", 'M', 19);

    int opcion;

    do {
        cout << "\nMENU \n";
        cout << "1. Mostrar datos en pantalla\n";
        cout << "2. Generar TXT\n";
        cout << "3. Generar JSON\n";
        cout << "4. Generar XML\n";
        cout << "5. Generar HTML\n";
        cout << "6. Generar TODOS\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\nPROGRAMACION ESTRUCTURADA\n";
                cout << "Auto Precio: $" << op1.precio << ", Anio: " << op1.anio << "\n";
                cout << "Persona Nombre: " << op2.nombre << " " << op2.ap << " " << op2.am
                     << ", Genero: " << op2.genero << ", Edad: " << op2.edad << "\n\n";

                cout << "PROGRAMACION ORIENTADA A OBJETOS\n";
                op3.mostrar();
                op4.mostrar();

                cout << "\nTAMANOS EN MEMORIA\n";
                cout << "Tamanio char: " << sizeof(char) << " bytes\n";
                cout << "Tamanio short: " << sizeof(short) << " bytes\n";
                cout << "Tamanio int: " << sizeof(int) << " bytes\n";
                cout << "Tamanio long: " << sizeof(long) << " bytes\n";
                cout << "Tamanio float: " << sizeof(float) << " bytes\n";
                cout << "Tamanio double: " << sizeof(double) << " bytes\n\n";

                cout << "Tamanio AutoPE: " << sizeof(AutoPE) << " bytes\n";
                cout << "Tamanio PersonaPE: " << sizeof(PersonaPE) << " bytes\n";
                cout << "Tamanio AutoPOO: " << sizeof(AutoPOO) << " bytes\n";
                cout << "Tamanio PersonaPOO: " << sizeof(PersonaPOO) << " bytes\n";
                break;

            case 2:
                generarTXT(op1, op2, op3, op4);
                break;

            case 3:
                generarJSON(op1, op2, op3, op4);
                break;

            case 4:
                generarXML(op1, op2, op3, op4);
                break;

            case 5:
                generarHTML(op1, op2, op3, op4);
                break;

            case 6:
                generarTXT(op1, op2, op3, op4);
                generarJSON(op1, op2, op3, op4);
                generarXML(op1, op2, op3, op4);
                generarHTML(op1, op2, op3, op4);
                cout << "\nTodos los archivos fueron generados.\n";
                break;

            case 0:
                cout << " ";
                break;

            default:
                cout << "Opcion invalida.\n";
        }

    } while (opcion != 0);

    return 0;
}