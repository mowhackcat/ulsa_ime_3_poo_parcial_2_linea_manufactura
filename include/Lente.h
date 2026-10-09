#ifndef LENTE_H
#define LENTE_H

class Lente {
private:
    int suciedadAcumulada;
    int limiteSuciedad;

public:
    Lente(int limite);

    void acumularSuciedad(int puntos);
    void limpiarLente();

    bool estaOpaco() const;
    int obtenerSuciedad() const;
};

#endif
