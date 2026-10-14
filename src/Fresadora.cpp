
#include "Fresadora.h"
#include <iostream>
#include <stdexcept>

HerramientaCorte::HerramientaCorte(int limite)
    : vidaUtil(0), limiteDesgaste(limite) {
    if (limite <= 0) {
        throw std::invalid_argument(
            "El limite de desgaste debe ser mayor que cero.");
    }
}

bool HerramientaCorte::desgastar() {
    ++vidaUtil;
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

Fresadora::Fresadora(int id, const std::string& nombre,
                     int tiempo, int limiteDesgaste)
    : Maquina(id, nombre),
      herramienta(limiteDesgaste),
      tiempoPorPieza(tiempo),
      ranurasRealizadas(0) {
    if (tiempo <= 0) {
        throw std::invalid_argument(
            "El tiempo por pieza debe ser mayor que cero.");
    }
}

bool Fresadora::ranurar() {
    if (!puedeProcesar()) {
        std::cout
            << "Fresadora: no se puede ranurar. "
            << "La maquina esta apagada o presenta una falla.\n";
        return false;
    }

    std::cout << "Fresadora: ranurando pieza...\n";

    registrarPieza();
    agregarTiempo(tiempoPorPieza);
    ++ranurasRealizadas;

    if (herramienta.desgastar()) {
        reportarFalla();
        std::cout
            << "Falla: la herramienta de corte alcanzo "
            << "su limite de desgaste.\n";
    }

    return true;
}

void Fresadora::realizarMantenimiento() {
    if (!estaEnFalla()) {
        std::cout
            << "La fresadora no necesita mantenimiento.\n";
        return;
    }

    herramienta.restaurar();
    registrarMantenimiento();

    std::cout
        << "Mantenimiento completado. "
        << "Herramienta de corte restaurada.\n";
}

void Fresadora::mostrarEstado() const {
    Maquina::mostrarEstado();

    std::cout << "--- Estado de la fresadora ---\n";
    std::cout << "Ranuras realizadas: "
              << ranurasRealizadas << '\n';
    std::cout << "Tiempo por pieza: "
              << tiempoPorPieza << " segundos\n";
    std::cout << "Desgaste de herramienta: "
              << herramienta.getVidaUtil() << '/'
              << herramienta.getLimiteDesgaste() << '\n';
}

int Fresadora::getRanurasRealizadas() const {
    return ranurasRealizadas;
}

int Fresadora::getTiempoPorPieza() const {
    return tiempoPorPieza;
}
