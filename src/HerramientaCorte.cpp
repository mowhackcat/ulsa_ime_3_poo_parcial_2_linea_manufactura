#include "HerramientaCorte.h"
#include <stdexcept>

HerramientaCorte::HerramientaCorte(int limite)
    : vidaUtil(0), limiteDesgaste(limite) {
    if (limite <= 0) {
        throw std::invalid_argument(
            "El limite de desgaste debe ser mayor que cero.");
    }
}

bool HerramientaCorte::desgastar() {
    if (vidaUtil < limiteDesgaste) {
        ++vidaUtil;
    }

    return necesitaMantenimiento();
}

void HerramientaCorte::restaurar() {
    vidaUtil = 0;
}

int HerramientaCorte::getVidaUtil() const {
    return vidaUtil;
}

int HerramientaCorte::getLimiteDesgaste() const {
    return limiteDesgaste;
}

bool HerramientaCorte::necesitaMantenimiento() const {
    return vidaUtil >= limiteDesgaste;
}