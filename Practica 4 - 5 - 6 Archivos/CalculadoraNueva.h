#ifndef CALCULADORANUEVA_H
#define CALCULADORANUEVA_H

#include "CalculadoRAS.h"

// Aplicación de Herencia Básica
class CalculadoraNueva : public Calculadora {
public:
    CalculadoraNueva();
    ~CalculadoraNueva();

    // Polimorfismo Dinámico: Sobreescritura (Práctica 6)
    int multiplicar(int a, int b);
    float dividir(int a, int b);
    int potencia(int base, int exp);
};

#endif // CALCULADORANUEVA_H
