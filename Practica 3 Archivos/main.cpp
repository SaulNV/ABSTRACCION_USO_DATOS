#include <stdio.h>
#include <iostream>
#include "Calculadora.h"

using namespace std;

// Variables globales para almacenar los datos dinámicos del usuario
int valorA = 0;
int valorB = 0;

int resSuma = 0;
int resResta = 0;
int resMultiplicacion = 0;
float resDivision = 0.0f;
bool datosIngresados = false; // Bandera de control

// Declaración de las funciones para los reportes
void generarXML();
void generarJSON();
void generarHTML();
void generarTXT();

int main() {
    int opcionMenu;
    Calculadora calc; // Instancia de nuestra clase Calculadora

    do {
        printf("\n==================================================\n");
        printf("    SISTEMA DINAMICO DE REPORTES (CALCULADORA)    \n");
        printf("==================================================\n");
        if (datosIngresados) {
            printf("[Valores Actuales]: A = %d , B = %d\n", valorA, valorB);
            printf("[Resultados]: +:%d | -:%d | *:%d | /:%.2f\n", resSuma, resResta, resMultiplicacion, resDivision);
            printf("--------------------------------------------------\n");
        } else {
            printf("[!] NOTA: Primero ingrese los numeros en la Opcion 1.\n");
            printf("--------------------------------------------------\n");
        }
        printf("1. INGRESAR VALORES (Calcular en vivo)\n");
        printf("2. Generar Reporte XML\n");
        printf("3. Generar Reporte JSON\n");
        printf("4. Generar Reporte HTML\n");
        printf("5. Generar Reporte TXT\n");
        printf("6. Exportar TODOS los formatos de golpe\n");
        printf("7. Salir del programa\n");
        printf("Seleccione una opcion (1-7): ");

        if (scanf("%d", &opcionMenu) != 1) {
            while (getchar() != '\n'); // Limpia el buffer de entrada
            opcionMenu = 0;
        }
        printf("--------------------------------------------------\n");

        switch (opcionMenu) {
            case 1:
                printf("Ingrese el primer numero (Valor A): ");
                scanf("%d", &valorA);
                printf("Ingrese el segundo numero (Valor B): ");
                scanf("%d", &valorB);

                // Ejecutamos las operaciones de la clase en tiempo real
                resSuma = calc.sumar(valorA, valorB);
                resResta = calc.restar(valorA, valorB);
                resMultiplicacion = calc.multiplicar(valorA, valorB);
                resDivision = calc.dividir(valorA, valorB);
                datosIngresados = true;

                printf("\n[!] ¡Calculos completados! Ya puedes exportar tus reportes.\n");
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
                printf("\n[!] Exito: Todos los formatos dinamicos han sido exportados.\n");
                break;
            case 7:
                printf("Saliendo del sistema de la calculadora. ¡Hasta luego!\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcionMenu != 7);

    return 0;
}

// ============================================================================
// IMPLEMENTACIÓN DE GENERADORES DINÁMICOS CON VALORES EN TIEMPO REAL
// ============================================================================

void generarXML() {
    FILE *archivo = fopen("reporte_calculadora.xml", "w");
    if (archivo == NULL) { printf("Error al crear el archivo XML.\n"); return; }

    fprintf(archivo, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    fprintf(archivo, "<ReporteCalculadora>\n");
    fprintf(archivo, "    <Variables>\n");
    fprintf(archivo, "        <VariableA>%d</VariableA>\n", valorA);
    fprintf(archivo, "        <VariableB>%d</VariableB>\n", valorB);
    fprintf(archivo, "    </Variables>\n");
    fprintf(archivo, "    <Resultados>\n");
    fprintf(archivo, "        <Suma>%d</Suma>\n", resSuma);
    fprintf(archivo, "        <Resta>%d</Resta>\n", resResta);
    fprintf(archivo, "        <Multiplicacion>%d</Multiplicacion>\n", resMultiplicacion);
    if (valorB == 0) {
        fprintf(archivo, "        <Division>Indefinida (Division entre cero)</Division>\n");
    } else {
        fprintf(archivo, "        <Division>%.2f</Division>\n", resDivision);
    }
    fprintf(archivo, "    </Resultados>\n");
    fprintf(archivo, "</ReporteCalculadora>\n");

    fclose(archivo);
    printf("-> ¡Archivo 'reporte_calculadora.xml' DINAMICO generado!\n");
}

void generarJSON() {
    FILE *archivo = fopen("reporte_calculadora.json", "w");
    if (archivo == NULL) { printf("Error al crear el archivo JSON.\n"); return; }

    fprintf(archivo, "{\n");
    fprintf(archivo, "  \"proyecto\": \"CalculadoraPOO\",\n");
    fprintf(archivo, "  \"entradas\": { \"a\": %d, \"b\": %d },\n", valorA, valorB);
    fprintf(archivo, "  \"operaciones_realizadas\": {\n");
    fprintf(archivo, "    \"suma\": %d,\n", resSuma);
    fprintf(archivo, "    \"resta\": %d,\n", resResta);
    fprintf(archivo, "    \"multiplicacion\": %d,\n", resMultiplicacion);
    if (valorB == 0) {
        fprintf(archivo, "    \"division\": \"Indefinida\"\n");
    } else {
        fprintf(archivo, "    \"division\": %.2f\n", resDivision);
    }
    fprintf(archivo, "  }\n");
    fprintf(archivo, "}\n");

    fclose(archivo);
    printf("-> ¡Archivo 'reporte_calculadora.json' DINAMICO generado!\n");
}

void generarHTML() {
    FILE *archivo = fopen("reporte_calculadora.html", "w");
    if (archivo == NULL) { printf("Error al crear el archivo HTML.\n"); return; }

    fprintf(archivo, "<!DOCTYPE html>\n<html lang=\"es\">\n<head>\n    <meta charset=\"UTF-8\">\n    <title>Reporte de Calculadora</title>\n    <style>\n");
    fprintf(archivo, "        body { font-family: 'Segoe UI', sans-serif; margin: 40px; background-color: #f4f7f6; color: #333; }\n");
    fprintf(archivo, "        h1 { color: #2c3e50; border-bottom: 3px solid #16a085; padding-bottom: 10px; }\n");
    fprintf(archivo, "        .panel { background: white; padding: 20px; border-radius: 8px; box-shadow: 0 4px 6px rgba(0,0,0,0.05); margin-bottom: 20px; }\n");
    fprintf(archivo, "        table { width: 100%%; border-collapse: collapse; margin-top: 15px; }\n");
    fprintf(archivo, "        th, td { padding: 12px; text-align: left; border-bottom: 1px solid #ddd; }\n");
    fprintf(archivo, "        th { background-color: #16a085; color: white; }\n");
    fprintf(archivo, "    </style>\n</head>\n<body>\n    <h1>Reporte Operacional - Clase Calculadora</h1>\n");
    fprintf(archivo, "    <div class=\"panel\">\n");
    fprintf(archivo, "        <p>Valores de entrada procesados: <strong>A = %d</strong> | <strong>B = %d</strong></p>\n", valorA, valorB);
    fprintf(archivo, "    </div>\n");

    fprintf(archivo, "    <table>\n");
    fprintf(archivo, "        <thead>\n            <tr><th>Simbolo</th><th>Operacion</th><th>Resultado</th></tr>\n        </thead>\n        <tbody>\n");
    fprintf(archivo, "            <tr><td>+</td><td>Suma</td><td>%d</td></tr>\n", resSuma);
    fprintf(archivo, "            <tr><td>-</td><td>Resta</td><td>%d</td></tr>\n", resResta);
    fprintf(archivo, "            <tr><td>*</td><td>Multiplicacion</td><td>%d</td></tr>\n", resMultiplicacion);
    if (valorB == 0) {
        fprintf(archivo, "            <tr><td>/</td><td>Division</td><td><span style=\"color:red;\">Indefinida (Error: /0)</span></td></tr>\n");
    } else {
        fprintf(archivo, "            <tr><td>/</td><td>Division</td><td><strong>%.2f</strong></td></tr>\n", resDivision);
    }
    fprintf(archivo, "        </tbody>\n    </table>\n</body>\n</html>\n");

    fclose(archivo);
    printf("-> ¡Archivo 'reporte_calculadora.html' DINAMICO generado!\n");
}

void generarTXT() {
    FILE *archivo = fopen("reporte_calculadora.txt", "w");
    if (archivo == NULL) { printf("Error al crear el archivo TXT.\n"); return; }

    fprintf(archivo, "================================================================================\n");
    fprintf(archivo, "            REPORTE DINAMICO DE CALCULADORA - VALORES DE USUARIO                \n");
    fprintf(archivo, "================================================================================\n\n");
    fprintf(archivo, "Valores de entrada configurados en la consola:\n");
    fprintf(archivo, " -> Valor A: %d\n", valorA);
    fprintf(archivo, " -> Valor B: %d\n\n", valorB);

    fprintf(archivo, "Resultados aritmeticos obtenidos a traves de la ejecucion de la clase:\n");
    fprintf(archivo, "--------------------------------------------------------------------------------\n");
    fprintf(archivo, " [+] Suma           : %d\n", resSuma);
    fprintf(archivo, " [-] Resta          : %d\n", resResta);
    fprintf(archivo, " [*] Multiplicacion : %d\n", resMultiplicacion);
    if (valorB == 0) {
        fprintf(archivo, " [/] Division       : Error (Division entre cero)\n");
    } else {
        fprintf(archivo, " [/] Division       : %.2f\n", resDivision);
    }
    fprintf(archivo, "--------------------------------------------------------------------------------\n");
    fprintf(archivo, "================================================================================\n");

    fclose(archivo);
    printf("-> ¡Archivo 'reporte_calculadora.txt' DINAMICO generado!\n");
}
