#ifndef CALCULADORA_H
#define CALCULADORA_H

class Calculadora {
public:
    Calculadora();          // Constructor
    virtual ~Calculadora(); // Destructor

    // Métodos de operaciones matemáticas
    int sumar(int a, int b);
    int restar(int a, int b);
    int multiplicar(int a, int b);
    float dividir(int a, int b);
};

#endif // CALCULADORA_H
