#include "Troquel.h"

#include <string>
#include <iostream>

#include "Troquel.h"

Troquel::Troquel(int vidaUtilMaxima) {
    if (vidaUtilMaxima <= 0) {
        this->vidaUtilMaxima = 10;
    } else {
        this->vidaUtilMaxima = vidaUtilMaxima;
    }
    this->vidaUtilRestante = this->vidaUtilMaxima;
}

bool Troquel::desgastar() {
    if (vidaUtilRestante > 0) {
        vidaUtilRestante--;
        return true;
    }
    return false;
}

void Troquel::restaurar() {
    vidaUtilRestante = vidaUtilMaxima;
}

int Troquel::getVidaUtilRestante() const {
    return vidaUtilRestante;
}

int Troquel::getVidaUtilMaxima() const {
    return vidaUtilMaxima;
}

double Troquel::getPorcentajeVida() const {
    return (static_cast<double>(vidaUtilRestante) / vidaUtilMaxima) * 100.0;
}