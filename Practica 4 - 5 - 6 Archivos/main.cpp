#include <stdio.h>
#include <iostream>
#include <string>
#include "CalculadoRAS.h"
#include "CalculadoraNueva.h"

using namespace std;

// Estructura global para almacenar variables y resultados reales
int tipoCalculadora = 1; // 1 = Base, 2 = Nueva (Práctica 6)
int cantidadParametros = 0;
int num1 = 0, num2 = 0, num3 = 0;

int resSuma = 0;
int resResta = 0;
int resMultiplicacion = 0;
float resDivision = 0.0f;
int resPotencia = 0;
bool datosIngresados = false;

// Declaración de funciones del generador
void generarXML();
void generarJSON();
void generarHTML();
void generarTXT();

int main() {
    int opcionMenu;
    Calculadora calcBase;
    CalculadoraNueva calcNueva;

    do {
        printf("\n==================================================\n");
        printf("    GENERADOR DINAMICO: SOBRECARGA Y HERENCIA     \n");
        printf("==================================================\n");
        if (datosIngresados) {
            printf("[Calculadora]: %s | [Parametros]: %d\n", (tipoCalculadora == 1) ? "Base (Sobrecarga)" : "Nueva (Sobreescritura)", cantidadParametros);
            if (cantidadParametros == 0) printf("[Valores]: Ninguno (0 parametros)\n");
            if (cantidadParametros == 2) printf("[Valores]: Num1=%d, Num2=%d\n", num1, num2);
            if (cantidadParametros == 3) printf("[Valores]: Num1=%d, Num2=%d, Num3=%d\n", num1, num2, num3);

            printf("[Resultados]: Suma:%d", resSuma);
            if (cantidadParametros != 3 || tipoCalculadora == 1) {
                printf(" | Resta:%d | Mult:%d | Div:%.2f", resResta, resMultiplicacion, resDivision);
            }
            if (tipoCalculadora == 2 && cantidadParametros == 2) {
                printf(" | Pot:%d", resPotencia);
            }
            printf("\n--------------------------------------------------\n");
        } else {
            printf("[!] NOTA: Ejecute primero las operaciones en la Opcion 1.\n");
            printf("--------------------------------------------------\n");
        }

        printf("1. EJECUTAR OPERACIONES INTERACTIVAS (Capturar datos)\n");
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
                printf("Seleccione la Calculadora:\n1. Base (Sobrecarga Tradicional)\n2. Nueva (Herencia y Sobreescritura - Practica 6)\nOpcion: ");
                scanf("%d", &tipoCalculadora);

                printf("¿Cuantos parametros desea procesar? (0, 2 o 3): ");
                scanf("%d", &cantidadParametros);

                if (cantidadParametros != 0 && cantidadParametros != 2 && cantidadParametros != 3) {
                    printf("[Error]: Cantidad de parametros incorrecta.\n");
                    datosIngresados = false;
                    break;
                }

                // Captura de datos condicional
                if (cantidadParametros >= 2) {
                    printf("Ingrese el primer numero: "); scanf("%d", &num1);
                    printf("Ingrese el segundo numero: "); scanf("%d", &num2);
                }
                if (cantidadParametros == 3) {
                    printf("Ingrese el tercer numero: "); scanf("%d", &num3);
                }

                // Procesamiento dinámico según el objeto seleccionado
                if (tipoCalculadora == 1) { // Clase Base
                    if (cantidadParametros == 0) {
                        resSuma = calcBase.sumar(); resResta = calcBase.restar();
                        resMultiplicacion = calcBase.multiplicar(); resDivision = calcBase.dividir();
                    } else if (cantidadParametros == 2) {
                        resSuma = calcBase.sumar(num1, num2); resResta = calcBase.restar(num1, num2);
                        resMultiplicacion = calcBase.multiplicar(num1, num2); resDivision = calcBase.dividir(num1, num2);
                    } else if (cantidadParametros == 3) {
                        resSuma = calcBase.sumar(num1, num2, num3); resResta = calcBase.restar(num1, num2, num3);
                        resMultiplicacion = calcBase.multiplicar(num1, num2, num3); resDivision = calcBase.dividir(num1, num2, num3);
                    }
                } else { // Clase Derivada (CalculadoraNueva)
                    if (cantidadParametros == 0) {
                        resSuma = calcNueva.sumar(); // Heredado
                    } else if (cantidadParametros == 2) {
                        resSuma = calcNueva.sumar(num1, num2);          // Heredado
                        resResta = calcNueva.restar(num1, num2);        // Heredado
                        resMultiplicacion = calcNueva.multiplicar(num1, num2); // Sobreescrito
                        resDivision = calcNueva.dividir(num1, num2);        // Sobreescrito
                        resPotencia = calcNueva.potencia(num1, num2);        // Nuevo método
                    } else if (cantidadParametros == 3) {
                        resSuma = calcNueva.sumar(num1, num2, num3);    // Heredado
                    }
                }
                datosIngresados = true;
                printf("\n[!] ¡Calculos hechos con exito! Listos para empaquetar.\n");
                break;

            case 2: if(!datosIngresados) { printf("Error: Use la opcion 1 primero.\n"); break; } generarXML(); break;
            case 3: if(!datosIngresados) { printf("Error: Use la opcion 1 primero.\n"); break; } generarJSON(); break;
            case 4: if(!datosIngresados) { printf("Error: Use la opcion 1 primero.\n"); break; } generarHTML(); break;
            case 5: if(!datosIngresados) { printf("Error: Use la opcion 1 primero.\n"); break; } generarTXT(); break;
            case 6:
                if(!datosIngresados) { printf("Error: Use la opcion 1 primero.\n"); break; }
                generarXML(); generarJSON(); generarHTML(); generarTXT();
                printf("\n[!] Exito: Todos los reportes dinámicos de polimorfismo se guardaron.\n");
                break;
            case 7:
                printf("Saliendo del laboratorio de POO. ¡Excelente trabajo!\n");
                break;
            default:
                printf("Opcion incorrecta.\n");
        }
    } while (opcionMenu != 7);

    return 0;
}

// ============================================================================
// LOGICA DE IMPRESION DE ARCHIVOS AJUSTADA AL COMPORTAMIENTO INTERACTIVO
// ============================================================================

void generarXML() {
    FILE *archivo = fopen("reporte_polimorfismo.xml", "w");
    if (archivo == NULL) { printf("Error al crear el XML.\n"); return; }

    fprintf(archivo, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    fprintf(archivo, "<ReportePolimorfismo>\n");
    fprintf(archivo, "    <Configuracion>\n");
    fprintf(archivo, "        <CalculadoraSeleccionada>%s</CalculadoraSeleccionada>\n", (tipoCalculadora == 1) ? "Base" : "Nueva (Herencia)");
    fprintf(archivo, "        <ParametrosEvaluados>%d</ParametrosEvaluados>\n", cantidadParametros);
    fprintf(archivo, "    </Configuracion>\n");
    fprintf(archivo, "    <Entradas>\n");
    fprintf(archivo, "        <Num1>%d</Num1>\n<Num2>%d</Num2>\n<Num3>%d</Num3>\n", num1, num2, num3);
    fprintf(archivo, "    </Entradas>\n");
    fprintf(archivo, "    <ResultadosEjecucion>\n");
    fprintf(archivo, "        <Suma>%d</Suma>\n", resSuma);
    if (cantidadParametros != 3 || tipoCalculadora == 1) {
        fprintf(archivo, "        <Resta>%d</Resta>\n", resResta);
        fprintf(archivo, "        <Multiplicacion>%d</Multiplicacion>\n", resMultiplicacion);
        fprintf(archivo, "        <Division>%.2f</Division>\n", resDivision);
    }
    if (tipoCalculadora == 2 && cantidadParametros == 2) {
        fprintf(archivo, "        <Potencia>%d</Potencia>\n", resPotencia);
    }
    fprintf(archivo, "    </ResultadosEjecucion>\n");
    fprintf(archivo, "</ReportePolimorfismo>\n");

    fclose(archivo);
    printf("-> ¡Archivo 'reporte_polimorfismo.xml' DINAMICO guardado!\n");
}

void generarJSON() {
    FILE *archivo = fopen("reporte_polimorfismo.json", "w");
    if (archivo == NULL) { printf("Error al crear el JSON.\n"); return; }

    fprintf(archivo, "{\n");
    fprintf(archivo, "  \"proyecto\": \"PolimorfismoCalculadora\",\n");
    fprintf(archivo, "  \"tipo_objeto\": \"%s\",\n", (tipoCalculadora == 1) ? "CalculadoraBase" : "CalculadoraNueva");
    fprintf(archivo, "  \"parametros_ingresados\": %d,\n", cantidadParametros);
    fprintf(archivo, "  \"valores_origen\": { \"num1\": %d, \"num2\": %d, \"num3\": %d },\n", num1, num2, num3);
    fprintf(archivo, "  \"salidas\": {\n");
    fprintf(archivo, "    \"suma\": %d", resSuma);
    if (cantidadParametros != 3 || tipoCalculadora == 1) {
        fprintf(archivo, ",\n    \"resta\": %d,\n    \"multiplicacion\": %d,\n    \"division\": %.2f", resResta, resMultiplicacion, resDivision);
    }
    if (tipoCalculadora == 2 && cantidadParametros == 2) {
        fprintf(archivo, ",\n    \"potencia\": %d", resPotencia);
    }
    fprintf(archivo, "\n  }\n}\n");

    fclose(archivo);
    printf("-> ¡Archivo 'reporte_polimorfismo.json' DINAMICO guardado!\n");
}

void generarHTML() {
    FILE *archivo = fopen("reporte_polimorfismo.html", "w");
    if (archivo == NULL) { printf("Error al crear el HTML.\n"); return; }

    fprintf(archivo, "<!DOCTYPE html>\n<html lang=\"es\">\n<head>\n    <meta charset=\"UTF-8\">\n    <title>Reporte POO Polimorfismo</title>\n    <style>\n");
    fprintf(archivo, "        body { font-family: sans-serif; margin: 40px; background-color: #f4f6f9; }\n");
    fprintf(archivo, "        h1 { color: #2c3e50; border-bottom: 3px solid #2980b9; padding-bottom: 10px; }\n");
    fprintf(archivo, "        .info { background: #eef2f7; padding: 15px; border-radius: 4px; border-left: 5px solid #2980b9; margin-bottom: 20px; }\n");
    fprintf(archivo, "        table { width: 100%%; border-collapse: collapse; background: #fff; box-shadow: 0 2px 4px rgba(0,0,0,0.08); }\n");
    fprintf(archivo, "        th, td { padding: 12px; text-align: left; border-bottom: 1px solid #ddd; }\n");
    fprintf(archivo, "        th { background-color: #2980b9; color: white; }\n");
    fprintf(archivo, "    </style>\n</head>\n<body>\n    <h1>Reporte Tecnico de Polimorfismo y Herencia</h1>\n");

    fprintf(archivo, "    <div class=\"info\">\n");
    fprintf(archivo, "        <p>Modelo utilizado: <strong>Calculadora %s</strong></p>\n", (tipoCalculadora == 1) ? "Base (Sobrecarga)" : "Nueva (Sobreescritura - Practica 6)");
    fprintf(archivo, "        <p>Valores Procesados: <strong>N1: %d | N2: %d | N3: %d</strong> (%d Parametros)</p>\n", num1, num2, num3, cantidadParametros);
    fprintf(archivo, "    </div>\n");

    fprintf(archivo, "    <table>\n        <thead>\n            <tr><th>Metodo Ejecutado</th><th>Tipo de Enlace</th><th>Resultado</th></tr>\n        </thead>\n        <tbody>\n");
    fprintf(archivo, "            <tr><td>sumar()</td><td>%s</td><td>%d</td></tr>\n", (cantidadParametros == 0) ? "Sobrecarga (0 par)" : (cantidadParametros == 2 ? "Sobrecarga (2 par)" : "Sobrecarga (3 par)"), resSuma);

    if (cantidadParametros != 3 || tipoCalculadora == 1) {
        fprintf(archivo, "            <tr><td>restar()</td><td>Heredado / Base</td><td>%d</td></tr>\n", resResta);
        fprintf(archivo, "            <tr><td>multiplicar()</td><td>%s</td><td>%d</td></tr>\n", (tipoCalculadora == 2 && cantidadParametros == 2) ? "Sobreescrito (Sumas sucesivas)" : "Base", resMultiplicacion);
        fprintf(archivo, "            <tr><td>dividir()</td><td>%s</td><td>%.2f</td></tr>\n", (tipoCalculadora == 2 && cantidadParametros == 2) ? "Sobreescrito (Restas sucesivas)" : "Base", resDivision);
    }
    if (tipoCalculadora == 2 && cantidadParametros == 2) {
        fprintf(archivo, "            <tr><td>potencia()</td><td>Metodo Propio Clase Derivada</td><td>%d</td></tr>\n", resPotencia);
    }

    fprintf(archivo, "        </tbody>\n    </table>\n</body>\n</html>\n");

    fclose(archivo);
    printf("-> ¡Archivo 'reporte_polimorfismo.html' DINAMICO guardado!\n");
}

void generarTXT() {
    FILE *archivo = fopen("reporte_polimorfismo.txt", "w");
    if (archivo == NULL) { printf("Error al crear el TXT.\n"); return; }

    fprintf(archivo, "================================================================================\n");
    fprintf(archivo, "     REPORTE TECNICO - LABORATORIO DE PROGRAMACION ORIENTADA A OBJETOS\n");
    fprintf(archivo, "================================================================================\n\n");
    fprintf(archivo, "CONTEXTO DEL ENTORNO:\n");
    fprintf(archivo, " - Enfoque Analizado: Polimorfismo Estatico (Sobrecarga) y Dinamico (Sobreescritura)\n");
    fprintf(archivo, " - Objeto en Memoria: Calculadora %s\n", (tipoCalculadora == 1) ? "Base" : "Nueva (Subclase)");
    fprintf(archivo, " - Argumentos Capturados: %d parametros\n", cantidadParametros);
    fprintf(archivo, " - Valores Evaluados: [%d], [%d], [%d]\n\n", num1, num2, num3);

    fprintf(archivo, "RESULTADOS DE LAS OPERACIONES TRATADAS:\n");
    fprintf(archivo, "--------------------------------------------------------------------------------\n");
    fprintf(archivo, " [*] Metodo Sumar          : %d\n", resSuma);
    if (cantidadParametros != 3 || tipoCalculadora == 1) {
        fprintf(archivo, " [*] Metodo Restar         : %d\n", resResta);
        fprintf(archivo, " [*] Metodo Multiplicar    : %d (%s)\n", resMultiplicacion, (tipoCalculadora == 2 && cantidadParametros == 2) ? "Sobreescrito" : "Original");
        fprintf(archivo, " [*] Metodo Dividir        : %.2f (%s)\n", resDivision, (tipoCalculadora == 2 && cantidadParametros == 2) ? "Sobreescrito" : "Original");
    }
    if (tipoCalculadora == 2 && cantidadParametros == 2) {
        fprintf(archivo, " [*] Metodo Potencia       : %d (Clase Nueva)\n", resPotencia);
    }
    fprintf(archivo, "--------------------------------------------------------------------------------\n");
    fprintf(archivo, "================================================================================\n");

    fclose(archivo);
    printf("-> ¡Archivo 'reporte_polimorfismo.txt' DINAMICO guardado!\n");
}
