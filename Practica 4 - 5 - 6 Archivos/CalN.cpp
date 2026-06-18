#include "CalculadoraNueva.h"
#include <iostream>

CalculadoraNueva::CalculadoraNueva() {}
CalculadoraNueva::~CalculadoraNueva() {}

// Sobreescritura: Multiplicación mediante sumas sucesivas
int CalculadoraNueva::multiplicar(int a, int b) {
    int res = 0;
    for (int i = 0; i < b; i++) {
        res = sumar(res, a); // Usa el método heredado
    }
    return res;
}

// Sobreescritura: División mediante restas sucesivas
float CalculadoraNueva::dividir(int a, int b) {
    if (b == 0) return 0;

    int c = 0;
    int r = a;
    while (r >= b) {
        r = restar(r, b); // Usa el método heredado
        c++;
    }
    return (float)c;
}

// Nuevo Método: Potencia utilizando multiplicaciones repetidas
int CalculadoraNueva::potencia(int base, int exp) {
    if (exp == 0) return 1;

    int res = 1;
    for (int i = 0; i < exp; i++) {
        res = multiplicar(res, base); // Invoca al método sobreescrito
    }
    return res;
}
