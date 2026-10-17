#include "CortadoraLaser.h"
#include <iostream>

CortadoraLaser::CortadoraLaser(
    int id, const std::string& nombre,
    int tiempo, int limiteLente)
    : Maquina(id, nombre),
      tiempoPorPieza(tiempo > 0 ? tiempo : 1),
      potenciaWatts(1000),
      lente(limiteLente) {
}

bool CortadoraLaser::procesarPieza() {
    if (!puedeProcesar()) {
        return false;
    }

    if (lente.estaOpaco()) {
        reportarFalla();
        return false;
    }

    registrarPieza();
    agregarTiempo(tiempoPorPieza);
    lente.acumularSuciedad(1);


    if (lente.estaOpaco()) {
        reportarFalla();
    }

    return true;
}

void CortadoraLaser::realizarMantenimiento() {
    lente.limpiarLente();
    registrarMantenimiento();

    std::cout << "Lente limpio. "
              << getNombre() << " lista para encender.\n";
}

void CortadoraLaser::mostrarEstado() const {
    Maquina::mostrarEstado();

    std::cout << "Tiempo por pieza: "
              << tiempoPorPieza << " segundos"
              << "\nPotencia: " << potenciaWatts << " watts"
              << "\nSuciedad del lente: " << lente.obtenerSuciedad()
              << "\nLente opaco: "
              << (lente.estaOpaco() ? "Si" : "No") << "\n";
}

void CortadoraLaser::calibrarPotencia(int watts) {
    if (watts > 0) {
        potenciaWatts = watts;
        std::cout << "Potencia ajustada a "
                  << potenciaWatts << " watts.\n";
    } else {
        std::cout << "La potencia debe ser mayor que cero.\n";
    }
}