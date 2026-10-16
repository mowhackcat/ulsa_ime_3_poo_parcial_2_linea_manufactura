#include "Planta.h"
#include <iostream>

Planta::Planta(int repeticionesGlobales)
    : repeticionesGlobales(
          repeticionesGlobales > 0 ? repeticionesGlobales : 20),
      totalPiezasTerminadas(0) {
}

bool Planta::agregarMaquina(Maquina* maquina) {
    if (maquina == nullptr) {
        return false;
    }

    for (Maquina* registrada : maquinas) {
        if (registrada == maquina) {
            return false;
        }
    }

    maquinas.push_back(maquina);
    return true;
}

int Planta::cantidadMaquinas() {
    return static_cast<int>(maquinas.size());
}

int Planta::getRepeticionesGlobales() const {
    return repeticionesGlobales;
}

void Planta::encenderMaquinas() {
    for (Maquina* maquina : maquinas) {
        maquina->encender();
    }
}

void Planta::apagarMaquinas() {
    for (Maquina* maquina : maquinas) {
        maquina->apagar();
    }
}

void Planta::mostrar() {
    for (Maquina* maquina : maquinas) {
        maquina->mostrarEstado();
    }
}

void Planta::encenderLinea() {
    encenderMaquinas();
}

void Planta::apagarLinea() {
    apagarMaquinas();
}

void Planta::procesarLote(int numPiezas) {
    if (numPiezas <= 0 || maquinas.empty()) {
        std::cout << "Lote invalido o planta sin maquinas.\n";
        return;
    }

    for (Maquina* maquina : maquinas) {
        if (!maquina->estaEncendida()) {
            std::cout << "Lote rechazado: "
                      << maquina->getNombre()
                      << " esta apagada.\n";
            return;
        }
    }

    for (int pieza = 0; pieza < numPiezas; pieza++) {
        for (Maquina* maquina : maquinas) {
            if (maquina->estaEnFalla()) {
                maquina->realizarMantenimiento();
                maquina->encender();
            }

            bool procesada = maquina->procesarPieza();

            if (!procesada && maquina->estaEnFalla()) {
                maquina->realizarMantenimiento();
                maquina->encender();
                procesada = maquina->procesarPieza();
            }

            if (!procesada) {
                std::cout << "Lote detenido en "
                          << maquina->getNombre()
                          << ". Pieza incompleta.\n";
                return;
            }

            if (maquina->estaEnFalla()) {
                maquina->realizarMantenimiento();
                maquina->encender();
            }
        }

        totalPiezasTerminadas++;
    }
}

void Planta::generarReporteTurno() const {
    int tiempoTotal = 0;
    int totalParos = 0;

    for (const Maquina* maquina : maquinas) {
        tiempoTotal += maquina->getTiempoTrabajado();
        totalParos += maquina->getParos();
    }

    std::cout << "\n=== Reporte del turno ==="
              << "\nPiezas terminadas: " << totalPiezasTerminadas
              << "\nTiempo total: " << tiempoTotal << " s"
              << "\nParos por mantenimiento: " << totalParos
              << "\n";

    for (const Maquina* maquina : maquinas) {
        maquina->mostrarEstado();
    }
}