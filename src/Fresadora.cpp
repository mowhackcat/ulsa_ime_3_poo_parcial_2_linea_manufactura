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
bool Fresadora::procesarPieza(){
    return ranurar();
}

bool Fresadora::ranurar() {
    if (!puedeProcesar()) {
        return false;
    }

    if (herramienta.necesitaMantenimiento()) {
        reportarFalla();
        return false;
    }


    registrarPieza();
    agregarTiempo(tiempoPorPieza);
    ++ranurasRealizadas;

    if (herramienta.desgastar()) {
        reportarFalla();
    }

    return true;
}

void Fresadora::realizarMantenimiento() {
    if (!estaEnFalla()) {
        return;
    }

    herramienta.restaurar();
    registrarMantenimiento();

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