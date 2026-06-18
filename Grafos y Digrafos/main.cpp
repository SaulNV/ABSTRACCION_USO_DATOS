#include <iostream>
#include <string>
#include "Grafo.h"

using namespace std;

void ejecutarSimulacion(GrafoBase* mapa) {
    int opcion;
    
    mapa->agregarRuta(0, 1, "Arista_A", 10, 50);
    mapa->agregarRuta(0, 2, "Arista_B", 15, 20);
    mapa->agregarRuta(1, 3, "Arista_C", 5, 100);
    mapa->agregarRuta(2, 3, "Arista_D", 30, 10);

    do {
        cout << " 1. Registrar nueva conexion (Ruta)\n";
        cout << " 2. Mostrar mapa de conexiones\n";
        cout << " 3. Calcular ruta mas rapida (Dijkstra por Tiempo)\n";
        cout << " 4. Calcular ruta mas barata (Dijkstra por Costo)\n";
        cout << " -------------------------------------------------\n";
        cout << " 5. Exportar Mapa a TXT, CSV, JSON y XML\n";
        cout << " 6. Cargar datos desde CSV hacia el grafo\n";
        cout << " 7. Cargar datos desde XML hacia el grafo\n";
        cout << " 8. Cargar datos desde JSON hacia el grafo\n";
        cout << " 9. Cargar datos desde TXT hacia el grafo\n";
        cout << " 10. Regresar al menu principal\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int ini, fin, t, c; string nombre;
                cout << "Nodo Inicial (ID entero): "; cin >> ini;
                cout << "Nodo Final (ID entero): "; cin >> fin;
                cout << "Nombre de la Arista: "; cin >> nombre;
                cout << "Tiempo de traslado (minutos): "; cin >> t;
                cout << "Costo de traslado (pesos): "; cin >> c;
                mapa->agregarRuta(ini, fin, nombre, t, c);
                break;
            }
            case 2:
                cout << "\n--- CONJUNTO DE CONEXIONES REGISTRADAS ---\n";
                mapa->mostrarRutas();
                break;
            case 3: {
                int orig;
                cout << "Ingresa el ID del nodo origen: "; cin >> orig;
                mapa->calcularDijkstra(orig, false);
                break;
            }
            case 4: {
                int orig;
                cout << "Ingresa el ID del nodo origen: "; cin >> orig;
                mapa->calcularDijkstra(orig, true);
                break;
            }
            case 5:
                cout << "\nGenerando archivos en el disco duro...\n";
                mapa->escribirTXT("grafo.txt");
                mapa->escribirCSV("grafo.csv");
                mapa->escribirXML("grafo.xml");
                mapa->escribirJSON("grafo.json");
                break;
            case 6: mapa->leerCSV("grafo.csv"); break;
            case 7: mapa->leerXML("grafo.xml"); break;
            case 8: mapa->leerJSON("grafo.json"); break;
            case 9: mapa->leerTXT("grafo.txt"); break;
            case 10: cout << "Saliendo de la simulacion actual...\n"; break;
            default: cout << "Opcion no valida.\n";
        }
    } while (opcion != 10);
}

int main() {
    int tipoGrafo;
    do {
        cout << " 1. Trabajar con Practica: GRAFO (No Dirigido)\n";
        cout << " 2. Trabajar con Practica: DIGRAFO (Dirigido)\n";
        cout << " 3. Finalizar Todo\n";
        cout << "Elige una opcion: ";
        cin >> tipoGrafo;

        if (tipoGrafo == 1) {
            cout << "\n[Cargando estructura de Grafo No Dirigido]\n";
            GrafoNoDirigido miGrafo;
            ejecutarSimulacion(&miGrafo);
        } else if (tipoGrafo == 2) {
            cout << "\n[Cargando estructura de Digrafo Dirigido]\n";
            DigrafoDirigido miDigrafo;
            ejecutarSimulacion(&miDigrafo);
        }
    } while (tipoGrafo != 3);

    return 0;
}