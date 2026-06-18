#include <iostream>
#include <string>
#include "Pila.h"

using namespace std;

int main() {
    PilaEstatica miPila;
    int opcion;

    miPila.apilar(Entidad("Carlos", 25));
    miPila.apilar(Entidad("Ana", 18));
    miPila.apilar(Entidad("Diego", 22));

    do {
        cout << " 1. Apilar elemento (Push)\n";
        cout << " 2. Desapilar elemento (Pop)\n";
        cout << " 3. Mostrar Pila (Desde Tope a Base)\n";
        cout << " ---------------------------------------------\n";
        cout << " 4. Exportar Pila a TXT, CSV, JSON y XML\n";
        cout << " 5. Cargar datos desde CSV hacia la pila\n";
        cout << " 6. Cargar datos desde XML hacia la pila\n";
        cout << " 7. Cargar datos desde JSON hacia la pila\n";
        cout << " 8. Cargar datos desde TXT hacia la pila\n";
        cout << " 9. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nom; int ed;
                cout << "Ingresa Nombre: "; cin >> nom;
                cout << "Ingresa Edad: "; cin >> ed;
                miPila.apilar(Entidad(nom, ed));
                break;
            }
            case 2:
                miPila.desapilar();
                cout << "Elemento superior desapilado.\n";
                break;
            case 3:
                cout << "\nEstado actual de la Pila:\n";
                miPila.mostrarTodo();
                break;
            case 4:
                cout << "\nGenerando archivos en el disco duro...\n";
                miPila.escribirTXT("pila.txt");
                miPila.escribirCSV("pila.csv");
                miPila.escribirXML("pila.xml");
                miPila.escribirJSON("pila.json");
                break;
            case 5: miPila.leerCSV("pila.csv"); break;
            case 6: miPila.leerXML("pila.xml"); break;
            case 7: miPila.leerJSON("pila.json"); break;
            case 8: miPila.leerTXT("pila.txt"); break;
            case 9: cout << "Saliendo del sistema...\n"; break;
            default: cout << "Opcion no valida.\n";
        }
    } while (opcion != 9);

    return 0;
}