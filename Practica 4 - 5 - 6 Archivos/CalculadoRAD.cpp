#include "CalculadoRAS.h"
#include <iostream>

Calculadora::Calculadora() {}
Calculadora::~Calculadora() {}

int Calculadora::sumar() { return 0; }
int Calculadora::sumar(int a, int b) { return a + b; }
int Calculadora::sumar(int a, int b, int c) { return a + b + c; }

int Calculadora::restar() { return 0; }
int Calculadora::restar(int a, int b) { return a - b; }
int Calculadora::restar(int a, int b, int c) { return a - b - c; }

int Calculadora::multiplicar() { return 0; }
int Calculadora::multiplicar(int a, int b) { return a * b; }
int Calculadora::multiplicar(int a, int b, int c) { return a * b * c; }

float Calculadora::dividir() { return 0; }
float Calculadora::dividir(int a, int b) {
    if (b == 0) return 0;
    return (float)a / b;
}
float Calculadora::dividir(int a, int b, int c) {
    if (b == 0 || c == 0) return 0;
    return (float)a / b / c;
}
