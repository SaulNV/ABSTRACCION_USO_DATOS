#include <iostream>
#include <string>
#include "Cola.h"

using namespace std;

int main() {
    ColaEstatica miCola;
    int opcion;

    miCola.insertar(Entidad("Carlos", 25));
    miCola.insertar(Entidad("Ana", 18));
    miCola.insertar(Entidad("Diego", 22));

    do {
     
        cout << " 1. Insertar elemento (Enqueue)\n";
        cout << " 2. Eliminar elemento (Dequeue)\n";
        cout << " 3. Mostrar estructura completa (RAM)\n";
        cout << " ---------------------------------------------\n";
        cout << " 4. Exportar estructura a TXT, CSV, JSON y XML\n";
        cout << " 5. Cargar datos desde CSV hacia la cola\n";
        cout << " 6. Cargar datos desde XML hacia la cola\n";
        cout << " 7. Cargar datos desde JSON hacia la cola\n";
        cout << " 8. Cargar datos desde TXT hacia la cola\n";
        cout << " 9. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nom; int ed;
                cout << "Ingresa Nombre: "; cin >> nom;
                cout << "Ingresa Edad: "; cin >> ed;
                miCola.insertar(Entidad(nom, ed));
                break;
            }
            case 2:
                miCola.eliminar();
                cout << "Elemento desencolado.\n";
                break;
            case 3:
                cout << "\nElementos actuales en la cola (Frente -> Final):\n";
                miCola.mostrarTodo();
                break;
            case 4:
                cout << "\nGenerando archivos en el disco duro...\n";
                miCola.escribirTXT("cola.txt");
                miCola.escribirCSV("cola.csv");
                miCola.escribirXML("cola.xml");
                miCola.escribirJSON("cola.json");
                break;
            case 5: miCola.leerCSV("cola.csv"); break;
            case 6: miCola.leerXML("cola.xml"); break;
            case 7: miCola.leerJSON("cola.json"); break;
            case 8: miCola.leerTXT("cola.txt"); break;
            case 9: cout << "Saliendo del sistema...\n"; break;
            default: cout << "Opcion no valida.\n";
        }
    } while (opcion != 9);

    return 0;
}