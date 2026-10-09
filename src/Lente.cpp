#include "Lente.h"

Lente::Lente(int vidaUtil) {
    this->vidaUtil = vidaUtil > 0 ? vidaUtil : 1;
    this->desgaste = 0;
    this->limpio = true;
}

void Lente::desgastar() {
    if (desgaste < vidaUtil) {
        desgaste++;
    }
}

void Lente::limpiar() {
    limpio = true;
}

void Lente::reemplazar() {
    desgaste = 0;
    limpio = true;
}

bool Lente::estaDesgastado() const {
    return desgaste >= vidaUtil;
}

bool Lente::estaLimpio() const {
    return limpio;
}

int Lente::getVidaUtil() const {
    return vidaUtil;
}

int Lente::getDesgaste() const {
    return desgaste;
}