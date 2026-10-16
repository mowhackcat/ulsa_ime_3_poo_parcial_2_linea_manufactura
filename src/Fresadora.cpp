#include "Fresadora.h"
#include <iostream>
#include <stdexcept>

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
            << "No se puede ranurar: maquina apagada o en falla.\n";
        return false;
    }

    if (herramienta.necesitaMantenimiento()) {
        reportarFalla();
        std::cout << "Falla: herramienta de corte desgastada.\n";
        return false;
    }

    std::cout << "Fresadora: ranurando pieza...\n";

    registrarPieza();
    agregarTiempo(tiempoPorPieza);
    ++ranurasRealizadas;

    if (herramienta.desgastar()) {
        reportarFalla();
        std::cout
            << "Falla: la herramienta alcanzo su limite de desgaste.\n";
    }

    return true;
}

void Fresadora::realizarMantenimiento() {
    if (!estaEnFalla()) {
        std::cout << "La fresadora no presenta fallas.\n";
        return;
    }

    herramienta.restaurar();
    registrarMantenimiento();

    std::cout
        << "Mantenimiento completado. Herramienta restaurada.\n";
}

void Fresadora::mostrarEstado() const {
    Maquina::mostrarEstado();

    std::cout << "\n--- Estado de la fresadora ---\n";
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