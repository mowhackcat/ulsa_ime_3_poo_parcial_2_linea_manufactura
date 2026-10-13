#pragma once
#include <iostream>

class Troquel {
private:
    int vidaUtilRestante;
    int vidaUtilMaxima;

public:
    Troquel(int vidaUtilMaxima = 10);

    bool desgastar();
    void restaurar();
    
    int getVidaUtilRestante() const;
    int getVidaUtilMaxima() const;
    double getPorcentajeVida() const;
};

