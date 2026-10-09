#include "Lente.h"

Lente::Lente(int limite) {
    suciedadAcumulada = 0;
    limiteSuciedad = limite > 0 ? limite : 1;
}

void Lente::acumularSuciedad(int puntos) {
    if (puntos > 0) {
        // Acumula sin superar el limite.
        int disponible = limiteSuciedad - suciedadAcumulada;

        if (puntos >= disponible) {
            suciedadAcumulada = limiteSuciedad;
        } else {
            suciedadAcumulada += puntos;
        }
    }
}

void Lente::limpiarLente() {
    suciedadAcumulada = 0;
}

bool Lente::estaOpaco() const {
    return suciedadAcumulada >= limiteSuciedad;
}

int Lente::obtenerSuciedad() const {
    return suciedadAcumulada;
}