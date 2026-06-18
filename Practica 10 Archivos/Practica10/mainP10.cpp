#include <iostream>
#include "NumsPunArr.h"

using namespace std;

int main() {

    float valores[5];

    for(int i=0; i<5; i++) {
        cout << "Ingresa el numero " << i+1 << ": ";
        cin >> valores[i];
    }

    Numeros op(valores);

    int opcion;

    do {

        cout << "\n===== PRACTICA 10 =====\n";
        cout << "1. Mostrar resultados\n";
        cout << "2. Generar TXT\n";
        cout << "3. Generar JSON\n";
        cout << "4. Generar XML\n";
        cout << "5. Generar HTML\n";
        cout << "6. Generar TODOS\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1:

                cout << "\nRESULTADOS\n";

                cout << "Suma: "
                     << op.suma()
                     << "\n";

                cout << "Promedio: "
                     << op.promedio()
                     << "\n";

                cout << "Media: "
                     << op.media()
                     << "\n";

                cout << "Maximo: "
                     << op.maximo()
                     << "\n";

                cout << "Minimo: "
                     << op.minimo()
                     << "\n";

                break;

            case 2:
                generarTXT(op);
                break;

            case 3:
                generarJSON(op);
                break;

            case 4:
                generarXML(op);
                break;

            case 5:
                generarHTML(op);
                break;

            case 6:

                generarTXT(op);
                generarJSON(op);
                generarXML(op);
                generarHTML(op);

                cout << "\nTodos los archivos fueron generados.\n";

                break;

            case 0:
                cout << "\nSaliendo...\n";
                break;

            default:
                cout << "\nOpcion invalida\n";
        }

    } while(opcion != 0);

    return 0;
}