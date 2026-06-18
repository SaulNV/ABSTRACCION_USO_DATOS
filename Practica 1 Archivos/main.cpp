#include <stdio.h>
#include <iostream>
#include "hola.h" // Enlace obligatorio con tu clase externa

using namespace std;

// Declaración de las funciones del generador de reportes
void generarXML();
void generarJSON();
void generarHTML();
void generarTXT();

int main() {
    int opcionMenu;

    do {
        printf("\n==================================================\n");
        printf("     SISTEMA GENERADOR DE REPORTES (HOLA)         \n");
        printf("==================================================\n");
        printf("1. Generar Reporte XML\n");
        printf("2. Generar Reporte JSON\n");
        printf("3. Generar Reporte HTML\n");
        printf("4. Generar Reporte TXT\n");
        printf("5. Generar TODOS los formatos de golpe\n");
        printf("6. Probar método decirHola() de la clase\n");
        printf("7. Salir del programa\n");
        printf("Seleccione una opcion (1-7): ");

        if (scanf("%d", &opcionMenu) != 1) {
            while (getchar() != '\n'); // Limpia el buffer por si introducen letras
            opcionMenu = 0;
        }
        printf("--------------------------------------------------\n");

        switch (opcionMenu) {
            case 1: generarXML(); break;
            case 2: generarJSON(); break;
            case 3: generarHTML(); break;
            case 4: generarTXT(); break;
            case 5:
                generarXML();
                generarJSON();
                generarHTML();
                generarTXT();
                printf("\n[!] Exito: Todos los formatos han sido exportados.\n");
                break;
            case 6:
                printf("\n[Ejecutando metodo de la clase]:\n");
                {
                    Hola objetoHola;
                    objetoHola.decirHola();
                }
                break;
            case 7:
                printf("Saliendo del generador de reportes. ¡Adios!\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcionMenu != 7);

    return 0;
}

// ============================================================================
// IMPLEMENTACIÓN COMPLETA DE GENERADORES DE ARCHIVOS (ESTRICTOS)
// ============================================================================

void generarXML() {
    FILE *archivo = fopen("reporte_hola.xml", "w");
    if (archivo == NULL) { printf("Error al crear el archivo XML.\n"); return; }

    fprintf(archivo, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    fprintf(archivo, "<Proyecto Nombre=\"HolaPOO\">\n");
    fprintf(archivo, "    <Archivos>\n");

    // Contenido de hola.h
    fprintf(archivo, "        <Archivo Nombre=\"hola.h\" Tipo=\"Header\">\n");
    fprintf(archivo, "            <Contenido><![CDATA[#ifndef HOLA_H\n#define HOLA_H\n\nclass Hola {\npublic:\n    Hola();\n    virtual ~Hola();\n    void decirHola();\n};\n\n#endif]]></Contenido>\n");
    fprintf(archivo, "        </Archivo>\n");

    // Contenido de Hola.cpp
    fprintf(archivo, "        <Archivo Nombre=\"Hola.cpp\" Tipo=\"Source\">\n");
    fprintf(archivo, "            <Contenido><![CDATA[#include \"hola.h\"\n#include <iostream>\n\nusing namespace std;\n\nHola::Hola() {}\nHola::~Hola() {}\n\nvoid Hola::decirHola() {\n    cout << \"¡Hola Mundo desde una Clase Orientada a Objetos!\" << endl;\n}]]></Contenido>\n");
    fprintf(archivo, "        </Archivo>\n");

    fprintf(archivo, "    </Archivos>\n");
    fprintf(archivo, "</Proyecto>\n");

    fclose(archivo);
    printf("-> ¡Archivo 'reporte_hola.xml' generado con exito!\n");
}

void generarJSON() {
    FILE *archivo = fopen("reporte_hola.json", "w");
    if (archivo == NULL) { printf("Error al crear el archivo JSON.\n"); return; }

    fprintf(archivo, "{\n  \"proyecto\": \"HolaPOO\",\n  \"archivos\": [\n");

    fprintf(archivo, "    {\n      \"nombre\": \"hola.h\",\n      \"tipo\": \"header\",\n      \"contenido\": \"#ifndef HOLA_H\\n#define HOLA_H\\n\\nclass Hola {\\npublic:\\n    Hola();\\n    virtual ~Hola();\\n    void decirHola();\\n};\\n\\n#endif\"\n    },\n");

    fprintf(archivo, "    {\n      \"nombre\": \"Hola.cpp\",\n      \"tipo\": \"source\",\n      \"contenido\": \"#include \\\"hola.h\\\"\\n#include <iostream>\\n\\nusing namespace std;\\n\\nHola::Hola() {}\\nHola::~Hola() {}\\n\\nvoid Hola::decirHola() {\\n    cout << \\\"¡Hola Mundo desde una Clase Orientada a Objetos!\\\" << endl;\\n}\"\n    }\n  ]\n}\n");

    fclose(archivo);
    printf("-> ¡Archivo 'reporte_hola.json' generado con exito!\n");
}

void generarHTML() {
    FILE *archivo = fopen("reporte_hola.html", "w");
    if (archivo == NULL) { printf("Error al crear el archivo HTML.\n"); return; }

    fprintf(archivo, "<!DOCTYPE html>\n<html lang=\"es\">\n<head>\n    <meta charset=\"UTF-8\">\n    <title>Estructura Hola POO</title>\n    <style>\n");
    fprintf(archivo, "        body { font-family: sans-serif; margin: 40px; background-color: #f4f6f9; }\n");
    fprintf(archivo, "        h1 { color: #2c3e50; border-bottom: 2px solid #2980b9; padding-bottom: 10px; }\n");
    fprintf(archivo, "        .card { background: #fff; border-radius: 6px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); margin-bottom: 20px; overflow: hidden; }\n");
    fprintf(archivo, "        .header { background: #2980b9; color: white; padding: 10px 15px; font-family: monospace; font-weight: bold; }\n");
    fprintf(archivo, "        pre { margin: 0; padding: 15px; background: #282c34; color: #abb2bf; overflow-x: auto; font-family: monospace; }\n");
    fprintf(archivo, "    </style>\n</head>\n<body>\n    <h1>Reporte Tecnico: Clase Hola</h1>\n");

    fprintf(archivo, "    <div class=\"card\">\n        <div class=\"header\">hola.h</div>\n        <pre><code>#ifndef HOLA_H\n#define HOLA_H\n\nclass Hola {\npublic:\n    Hola();\n    virtual ~Hola();\n    void decirHola();\n};\n#endif</code></pre>\n    </div>\n");

    fprintf(archivo, "    <div class=\"card\">\n        <div class=\"header\">Hola.cpp</div>\n        <pre><code>#include \"hola.h\"\n#include &lt;iostream&gt;\n\nusing namespace std;\n\nHola::Hola() {}\nHola::~Hola() {}\n\nvoid Hola::decirHola() {\n    cout << \"¡Hola Mundo desde una Clase Orientada a Objetos!\" << endl;\n}</code></pre>\n    </div>\n</body>\n</html>\n");

    fclose(archivo);
    printf("-> ¡Archivo 'reporte_hola.html' generado con exito!\n");
}

void generarTXT() {
    FILE *archivo = fopen("reporte_hola.txt", "w");
    if (archivo == NULL) { printf("Error al crear el archivo TXT.\n"); return; }

    fprintf(archivo, "================================================================================\n");
    fprintf(archivo, "REPORTE DE CODIGO FUENTE - ESTRUCTURA HOLA POO\n");
    fprintf(archivo, "================================================================================\n\n");

    fprintf(archivo, "[ARCHIVO]: hola.h\n--------------------------------------------------------------------------------\n");
    fprintf(archivo, "#ifndef HOLA_H\n#define HOLA_H\n\nclass Hola {\npublic:\n    Hola();\n    virtual ~Hola();\n    void decirHola();\n};\n#endif\n\n");

    fprintf(archivo, "[ARCHIVO]: Hola.cpp\n--------------------------------------------------------------------------------\n");
    fprintf(archivo, "#include \"hola.h\"\n#include <iostream>\n\nusing namespace std;\nHola::Hola() {}\nHola::~Hola() {}\nvoid Hola::decirHola() {\n    cout << \"¡Hola Mundo desde una Clase Orientada a Objetos!\" << endl;\n}\n\n");

    fprintf(archivo, "================================================================================\n");
    fprintf(archivo, "FIN DEL REPORTE\n");
    fprintf(archivo, "================================================================================\n");

    fclose(archivo);
    printf("-> ¡Archivo 'reporte_hola.txt' generado con exito!\n");
}
