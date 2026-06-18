#ifndef CALCULADORAD_H
#define CALCULADORAD_H

class Calculadora {
public:
    Calculadora();
    virtual ~Calculadora();

    // Polimorfismo Estático: Sobrecarga de Métodos
    int sumar();
    int sumar(int a, int b);
    int sumar(int a, int b, int c);

    int restar();
    int restar(int a, int b);
    int restar(int a, int b, int c);

    int multiplicar();
    int multiplicar(int a, int b);
    int multiplicar(int a, int b, int c);

    float dividir();
    float dividir(int a, int b);
    float dividir(int a, int b, int c);
};

#endif // CALCULADORAD_H
