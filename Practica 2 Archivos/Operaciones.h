#ifndef OPERACIONES_H
#define OPERACIONES_H

class Operaciones {
public:
    Operaciones();
    virtual ~Operaciones();

    int calcularFactorial(int n);
    int obtenerFibonacci(int n);
    bool esPrimo(int numero);
};

#endif // OPERACIONES_H
