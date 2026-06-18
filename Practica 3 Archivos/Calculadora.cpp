#include "Calculadora.h"

Calculadora::Calculadora() {}
Calculadora::~Calculadora() {}

int Calculadora::sumar(int a, int b) {
    return a + b;
}

int Calculadora::restar(int a, int b) {
    return a - b;
}

int Calculadora::multiplicar(int a, int b) {
    return a * b;
}

float Calculadora::dividir(int a, int b) {
    if (b == 0) return 0.0f; // Validación de seguridad
    return (float)a / b;
}
