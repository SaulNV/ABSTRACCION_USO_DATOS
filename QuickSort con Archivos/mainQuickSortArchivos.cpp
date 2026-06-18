#include <iostream>
#include <string>
#include "OrdenamientoQuick.h"

using namespace std;

int main() {
    OrdenadorQuick miLista;
    int opcion;

    miLista.agregar(Entidad("Carlos", 25));
    miLista.agregar(Entidad("Ana", 18));
    miLista.agregar(Entidad("Diego", 22));
    miLista.agregar(Entidad("Maria", 19));
    miLista.agregar(Entidad("Beto", 30));

    do {
        cout << " 1. Agregar nueva persona\n";
        cout << " 2. Mostrar todas las personas (RAM)\n";
        cout << " 3. Ordenar por Edad (Algoritmo Quick Sort)\n";
        cout << " -------------------------------------------------\n";
        cout << " 4. Exportar TODO a TXT, CSV, JSON y XML\n";
        cout << " 5. Cargar datos desde CSV hacia el arreglo\n";
        cout << " 6. Cargar datos desde XML hacia el arreglo\n";
        cout << " 7. Cargar datos desde JSON hacia el arreglo\n";
        cout << " 8. Cargar datos desde TXT hacia el arreglo\n";
        cout << " 9. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nom; int ed;
                cout << "Ingresa Nombre: "; cin >> nom;
                cout << "Ingresa Edad: "; cin >> ed;
                miLista.agregar(Entidad(nom, ed));
                break;
            }
            case 2:
                cout << "\nDatos actuales en memoria RAM:\n";
                miLista.mostrarTodo();
                break;
            case 3:
                miLista.ordenar();
                cout << "\nDatos ordenados por metodo Quick Sort.\n";
                break;
            case 4:
                cout << "\nGenerando archivos en el disco duro...\n";
                miLista.escribirTXT("datos.txt");
                miLista.escribirCSV("datos.csv");
                miLista.escribirXML("datos.xml");
                miLista.escribirJSON("datos.json");
                break;
            case 5: miLista.leerCSV("datos.csv"); break;
            case 6: miLista.leerXML("datos.xml"); break;
            case 7: miLista.leerJSON("datos.json"); break;
            case 8: miLista.leerTXT("datos.txt"); break;
            case 9: cout << "Saliendo del sistema...\n"; break;
            default: cout << "Opcion no valida.\n";
        }
    } while (opcion != 9);

    return 0;
}