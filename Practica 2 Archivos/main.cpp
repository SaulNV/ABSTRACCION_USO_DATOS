#include <stdio.h>
#include <iostream>
#include "Operaciones.h"

using namespace std;

// Variables globales para recordar los datos ingresados por el usuario y sus resultados
int numFactorial = 0;
int numFibonacci = 0;
int numPrimo = 0;

int resultadoFactorial = 1;
int resultadoFibonacci = 0;
bool resultadoPrimo = false;
bool datosIngresados = false; // Indica si el usuario ya metió números

// Declaración de las funciones de reportes
void generarXML();
void generarJSON();
void generarHTML();
void generarTXT();

int main() {
    int opcionMenu;
    Operaciones op; // Instancia de la clase

    do {
        printf("\n==================================================\n");
        printf("    SISTEMA DINAMICO DE REPORTES (OPERACIONES)    \n");
        printf("==================================================\n");
        if (datosIngresados) {
            printf("[Datos Actuales]: Fact(%d)=%d | Fib(%d)=%d | ¿Primo(%d)?=%s\n",
                   numFactorial, resultadoFactorial, numFibonacci, resultadoFibonacci, numPrimo, resultadoPrimo ? "SI" : "NO");
            printf("--------------------------------------------------\n");
        } else {
            printf("[!] NOTA: Primero ingrese datos en la Opcion 1.\n");
            printf("--------------------------------------------------\n");
        }
        printf("1. INGRESAR NUMEROS (Calcular en vivo)\n");
        printf("2. Generar Reporte XML\n");
        printf("3. Generar Reporte JSON\n");
        printf("4. Generar Reporte HTML\n");
        printf("5. Generar Reporte TXT\n");
        printf("6. Exportar TODOS los formatos de golpe\n");
        printf("7. Salir del programa\n");
        printf("Seleccione una opcion (1-7): ");

        if (scanf("%d", &opcionMenu) != 1) {
            while (getchar() != '\n');
            opcionMenu = 0;
        }
        printf("--------------------------------------------------\n");

        switch (opcionMenu) {
            case 1:
                printf("Ingrese un numero para calcular su Factorial (ej. 5): ");
                scanf("%d", &numFactorial);
                printf("Ingrese la posicion para la serie Fibonacci (ej. 7): ");
                scanf("%d", &numFibonacci);
                printf("Ingrese un numero para verificar si es Primo (ej. 13): ");
                scanf("%d", &numPrimo);

                // Realizamos los cálculos usando la clase POO en tiempo real
                resultadoFactorial = op.calcularFactorial(numFactorial);
                resultadoFibonacci = op.obtenerFibonacci(numFibonacci);
                resultadoPrimo = op.esPrimo(numPrimo);
                datosIngresados = true;

                printf("\n[!] ¡Calculos realizados con exito! Ya puedes exportar.\n");
                break;

            case 2:
                if(!datosIngresados) { printf("Error: Primero debes ingresar numeros en la opcion 1.\n"); break; }
                generarXML();
                break;
            case 3:
                if(!datosIngresados) { printf("Error: Primero debes ingresar numeros en la opcion 1.\n"); break; }
                generarJSON();
                break;
            case 4:
                if(!datosIngresados) { printf("Error: Primero debes ingresar numeros en la opcion 1.\n"); break; }
                generarHTML();
                break;
            case 5:
                if(!datosIngresados) { printf("Error: Primero debes ingresar numeros en la opcion 1.\n"); break; }
                generarTXT();
                break;
            case 6:
                if(!datosIngresados) { printf("Error: Primero debes ingresar numeros en la opcion 1.\n"); break; }
                generarXML();
                generarJSON();
                generarHTML();
                generarTXT();
                printf("\n[!] Exito: Todos los archivos dinamicos han sido exportados.\n");
                break;
            case 7:
                printf("Saliendo del sistema interactivo. ¡Adios Samanta!\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcionMenu != 7);

    return 0;
}

// ============================================================================
// GENERADORES CONFIGURADOS CON LOS VALORES EN TIEMPO REAL DEL USUARIO
// ============================================================================

void generarXML() {
    FILE *archivo = fopen("reporte_operaciones.xml", "w");
    if (archivo == NULL) { printf("Error al crear el archivo XML.\n"); return; }

    fprintf(archivo, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    fprintf(archivo, "<ReporteOperaciones>\n");
    fprintf(archivo, "    <Metadatos>\n");
    fprintf(archivo, "        <ClaseEstructura>OperacionesPOO</ClaseEstructura>\n");
    fprintf(archivo, "    </Metadatos>\n");
    fprintf(archivo, "    <ResultadosEnVivo>\n");
    fprintf(archivo, "        <Factorial numero=\"%d\">%d</Factorial>\n", numFactorial, resultadoFactorial);
    fprintf(archivo, "        <Fibonacci posicion=\"%d\">%d</Fibonacci>\n", numFibonacci, resultadoFibonacci);
    fprintf(archivo, "        <Primo numero=\"%d\">%s</Primo>\n", numPrimo, resultadoPrimo ? "Verdadero" : "Falso");
    fprintf(archivo, "    </ResultadosEnVivo>\n");
    fprintf(archivo, "</ReporteOperaciones>\n");

    fclose(archivo);
    printf("-> ¡Archivo 'reporte_operaciones.xml' DINAMICO generado!\n");
}

void generarJSON() {
    FILE *archivo = fopen("reporte_operaciones.json", "w");
    if (archivo == NULL) { printf("Error al crear el archivo JSON.\n"); return; }

    fprintf(archivo, "{\n");
    fprintf(archivo, "  \"proyecto\": \"OperacionesPOO\",\n");
    fprintf(archivo, "  \"resultados_usuario\": {\n");
    fprintf(archivo, "    \"factorial\": { \"entrada\": %d, \"resultado\": %d },\n", numFactorial, resultadoFactorial);
    fprintf(archivo, "    \"fibonacci\": { \"posicion\": %d, \"resultado\": %d },\n", numFibonacci, resultadoFibonacci);
    fprintf(archivo, "    \"primo\": { \"entrada\": %d, \"es_primo\": %s }\n", numPrimo, resultadoPrimo ? "true" : "false");
    fprintf(archivo, "  }\n");
    fprintf(archivo, "}\n");

    fclose(archivo);
    printf("-> ¡Archivo 'reporte_operaciones.json' DINAMICO generado!\n");
}

void generarHTML() {
    FILE *archivo = fopen("reporte_operaciones.html", "w");
    if (archivo == NULL) { printf("Error al crear el archivo HTML.\n"); return; }

    fprintf(archivo, "<!DOCTYPE html>\n<html lang=\"es\">\n<head>\n    <meta charset=\"UTF-8\">\n    <title>Resultados de Operaciones</title>\n    <style>\n");
    fprintf(archivo, "        body { font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; margin: 40px; background-color: #f7f9fc; color: #333; }\n");
    fprintf(archivo, "        h1 { color: #2c3e50; border-bottom: 3px solid #8e44ad; padding-bottom: 10px; }\n");
    fprintf(archivo, "        table { width: 100%%; border-collapse: collapse; margin-top: 20px; background: white; border-radius: 8px; overflow: hidden; box-shadow: 0 4px 6px rgba(0,0,0,0.05); }\n");
    fprintf(archivo, "        th, td { padding: 15px; text-align: left; border-bottom: 1px solid #edf2f7; }\n");
    fprintf(archivo, "        th { background-color: #8e44ad; color: white; font-weight: bold; }\n");
    fprintf(archivo, "        tr:hover { background-color: #f8f1fa; }\n");
    fprintf(archivo, "    </style>\n</head>\n<body>\n    <h1>Reporte Ejecutivo de Operaciones Matematicas</h1>\n");
    fprintf(archivo, "    <p>Este reporte contiene los calculos procesados dinamicamente por la clase <strong>Operaciones</strong> basados en los valores provistos por el usuario.</p>\n");

    fprintf(archivo, "    <table>\n");
    fprintf(archivo, "        <thead>\n            <tr><th>Operacion Realizada</th><th>Valor Ingresado</th><th>Resultado Obtenido</th></tr>\n        </thead>\n        <tbody>\n");
    fprintf(archivo, "            <tr><td>Factorial (Recursivo)</td><td>%d</td><td>%d</td></tr>\n", numFactorial, resultadoFactorial);
    fprintf(archivo, "            <tr><td>Termino Fibonacci</td><td>%d</td><td>%d</td></tr>\n", numFibonacci, resultadoFibonacci);
    fprintf(archivo, "            <tr><td>Evaluacion de Numero Primo</td><td>%d</td><td><strong>%s</strong></td></tr>\n", numPrimo, resultadoPrimo ? "ES PRIMO" : "NO ES PRIMO");
    fprintf(archivo, "        </tbody>\n    </table>\n</body>\n</html>\n");

    fclose(archivo);
    printf("-> ¡Archivo 'reporte_operaciones.html' DINAMICO generado!\n");
}

void generarTXT() {
    FILE *archivo = fopen("reporte_operaciones.txt", "w");
    if (archivo == NULL) { printf("Error al crear el archivo TXT.\n"); return; }

    fprintf(archivo, "================================================================================\n");
    fprintf(archivo, "             REPORTE DINAMICO DE USUARIO - CLASE OPERACIONES                    \n");
    fprintf(archivo, "================================================================================\n\n");
    fprintf(archivo, "Los siguientes datos fueron calculados a traves del Menu interactivo:\n\n");

    fprintf(archivo, "1. FACTORIAL:\n");
    fprintf(archivo, "   - Entrada: %d\n", numFactorial);
    fprintf(archivo, "   - Resultado: %d\n\n", resultadoFactorial);

    fprintf(archivo, "2. SERIE FIBONACCI:\n");
    fprintf(archivo, "   - Posicion solicitada: %d\n", numFibonacci);
    fprintf(archivo, "   - Valor en la posicion: %d\n\n", resultadoFibonacci);

    fprintf(archivo, "3. PRUEBA DE PRIMALIDAD:\n");
    fprintf(archivo, "   - Numero evaluado: %d\n", numPrimo);
    fprintf(archivo, "   - Resultado: %s\n\n", resultadoPrimo ? "SI ES PRIMO" : "NO ES PRIMO");

    fprintf(archivo, "================================================================================\n");
    fprintf(archivo, "FIN DEL REPORTE GENERADO AUTOMATICAMENTE\n");
    fprintf(archivo, "================================================================================\n");

    fclose(archivo);
    printf("-> ¡Archivo 'reporte_operaciones.txt' DINAMICO generado!\n");
}
