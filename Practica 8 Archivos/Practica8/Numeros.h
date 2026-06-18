#ifndef NUMEROS_H
#define NUMEROS_H

class Numeros {
private:
    float n1, n2, n3, n4, n5;

public:
    Numeros(float a, float b, float c, float d, float e);
    ~Numeros();

    float suma();
    float promedio();
    float media();
    float maximo();
    float minimo();

    float getN1();
    float getN2();
    float getN3();
    float getN4();
    float getN5();
};

void generarTXT(Numeros op);
void generarJSON(Numeros op);
void generarXML(Numeros op);
void generarHTML(Numeros op);

#endif