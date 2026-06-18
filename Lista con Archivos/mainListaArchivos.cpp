#include <iostream>
#include <string>
#include "Lista.h"

using namespace std;

int main() {
    ListaEstatica miLista;
    int opcion;

    miLista.agregar(Entidad("Carlos", 25));
    miLista.agregar(Entidad("Ana", 18));
    miLista.agregar(Entidad("Diego", 22));

    do {

        cout << " 1. Agregar elemento a la lista\n";
        cout << " 2. Eliminar elemento por posicion\n";
        cout << " 3. Mostrar estructura completa (RAM)\n";
        cout << " ---------------------------------------------\n";
        cout << " 4. Exportar estructura a TXT, CSV, JSON y XML\n";
        cout << " 5. Cargar datos desde CSV hacia la lista\n";
        cout << " 6. Cargar datos desde XML hacia la lista\n";
        cout << " 7. Cargar datos desde JSON hacia la lista\n";
        cout << " 8. Cargar datos desde TXT hacia la lista\n";
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
            case 2: {
                int pos;
                cout << "Ingresa la posicion a eliminar (ej. 0, 1, 2...): ";
                cin >> pos;
                miLista.eliminarEnPosicion(pos);
                break;
            }
            case 3:
                cout << "\nElementos actuales en la lista:\n";
                miLista.mostrarTodo();
                break;
            case 4:
                cout << "\nGenerando archivos en el disco duro...\n";
                miLista.escribirTXT("lista.txt");
                miLista.escribirCSV("lista.csv");
                miLista.escribirXML("lista.xml");
                miLista.escribirJSON("lista.json");
                break;
            case 5: miLista.leerCSV("lista.csv"); break;
            case 6: miLista.leerXML("lista.xml"); break;
            case 7: miLista.leerJSON("lista.json"); break;
            case 8: miLista.leerTXT("lista.txt"); break;
            case 9: cout << "Saliendo del sistema...\n"; break;
            default: cout << "Opcion no valida.\n";
        }
    } while (opcion != 9);

    return 0;
}