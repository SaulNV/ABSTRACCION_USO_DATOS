#include <iostream>
#include <string>
#include "Arbol.h"

using namespace std;

int main() {
    ArbolBinario miArbol;
    int opcion;

    miArbol.insertar(Entidad("Diego", 22));  
    miArbol.insertar(Entidad("Ana", 18));    
    miArbol.insertar(Entidad("Carlos", 25)); 
    miArbol.insertar(Entidad("Beto", 20));   
    miArbol.insertar(Entidad("Luis", 15));   

    do {
        cout << " 1. Insertar nueva persona\n";
        cout << " 2. Eliminar persona (por Edad)\n";
        cout << " ---------------------------------------------\n";
        cout << " 3. Mostrar IN-ORDEN (De menor a mayor edad)\n";
        cout << " 4. Mostrar PRE-ORDEN (Raiz primero)\n";
        cout << " 5. Mostrar POST-ORDEN (Hojas primero)\n";
        cout << " ---------------------------------------------\n";
        cout << " 6. Exportar Arbol a TXT, CSV, JSON y XML\n";
        cout << " 7. Cargar datos desde CSV hacia el arbol\n";
        cout << " 8. Cargar datos desde XML hacia el arbol\n";
        cout << " 9. Cargar datos desde JSON hacia el arbol\n";
        cout << " 10. Cargar datos desde TXT hacia el arbol\n";
        cout << " 11. Salir\n";
        cout << "==============================================\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nom; int ed;
                cout << "Ingresa Nombre: "; cin >> nom;
                cout << "Ingresa Edad: "; cin >> ed;
                miArbol.insertar(Entidad(nom, ed));
                cout << "\nEntidad insertada en la estructura.\n";
                break;
            }
            case 2: {
                int ed;
                cout << "Ingresa la Edad de la persona a eliminar: ";
                cin >> ed;
                miArbol.eliminar(ed);
                cout << "\nProceso de eliminacion ejecutado.\n";
                break;
            }
            case 3:
                cout << "\n--- RECORRIDO IN-ORDEN ---\n";
                miArbol.mostrarInOrden();
                break;
            case 4:
                cout << "\n--- RECORRIDO PRE-ORDEN ---\n";
                miArbol.mostrarPreOrden();
                break;
            case 5:
                cout << "\n--- RECORRIDO POST-ORDEN ---\n";
                miArbol.mostrarPostOrden();
                break;
            case 6:
                cout << "\nGenerando archivos en el disco duro...\n";
                miArbol.escribirTXT("arbol.txt");
                miArbol.escribirCSV("arbol.csv");
                miArbol.escribirXML("arbol.xml");
                miArbol.escribirJSON("arbol.json");
                break;
            case 7: miArbol.leerCSV("arbol.csv"); break;
            case 8: miArbol.leerXML("arbol.xml"); break;
            case 9: miArbol.leerJSON("arbol.json"); break;
            case 10: miArbol.leerTXT("arbol.txt"); break;
            case 11: cout << "Saliendo del sistema...\n"; break;
            default: cout << "Opcion no valida.\n";
        }
    } while (opcion != 11);

    return 0;
}