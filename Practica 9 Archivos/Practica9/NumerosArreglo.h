#ifndef NUMEROSARREGLO_H
#define NUMEROSARREGLO_H

class Numeros {
private:
    float datos[5];

public:
    Numeros(float v[]);
    ~Numeros();

    float suma();
    float promedio();
    float media();
    float maximo();
    float minimo();

    float getDato(int i);
};

void generarTXT(Numeros op);
void generarJSON(Numeros op);
void generarXML(Numeros op);
void generarHTML(Numeros op);

#endif