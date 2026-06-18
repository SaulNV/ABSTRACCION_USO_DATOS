#include "Operaciones.h"

Operaciones::Operaciones() {}
Operaciones::~Operaciones() {}

int Operaciones::calcularFactorial(int n) {
    if (n <= 1) return 1;
    return n * calcularFactorial(n - 1);
}

int Operaciones::obtenerFibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return obtenerFibonacci(n - 1) + obtenerFibonacci(n - 2);
}

bool Operaciones::esPrimo(int numero) {
    if (numero <= 1) return false;
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) return false;
    }
    return true;
}
