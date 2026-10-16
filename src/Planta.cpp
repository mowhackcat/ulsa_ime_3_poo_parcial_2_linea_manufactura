#include "Planta.h"
#include <iostream>

Planta::Planta()
    : totalPiezasTerminadas(0), tiempoTotalTurno(0) {
}

void Planta::agregarMaquina(Maquina* maquina) {
    if (maquina == nullptr) {
        return;
    }

    for (Maquina* registrada : maquinas) {
        if (registrada == maquina) {
            return;
        }
    }

    maquinas.push_back(maquina);
}

void Planta::encenderLinea() {
    for (Maquina* maquina : maquinas) {
        maquina->encender();
    }
}

void Planta::apagarLinea() {
    for (Maquina* maquina : maquinas) {
        maquina->apagar();
    }
}

void Planta::procesarLote(int numPiezas) {
    if (numPiezas <= 0 || maquinas.empty()) {
        std::cout << "Lote invalido o planta sin maquinas.\n";
        return;
    }

    // Rechaza el lote antes de procesar si alguna esta apagada.
    for (Maquina* maquina : maquinas) {
        if (!maquina->estaEncendida()) {
            std::cout << "Lote rechazado: "
                      << maquina->getNombre()
                      << " esta apagada.\n";
            return;
        }
    }

    for (int pieza = 0; pieza < numPiezas; pieza++) {
        std::cout << "\n--- Pieza "
                  << totalPiezasTerminadas + 1 << " ---\n";

        for (Maquina* maquina : maquinas) {
            if (maquina->estaEnFalla()) {
                maquina->realizarMantenimiento();
                maquina->encender();
            }

            int tiempoAntes = maquina->getTiempoTrabajado();
            bool procesada = maquina->procesarPieza();

            tiempoTotalTurno +=
                maquina->getTiempoTrabajado() - tiempoAntes;

            // Si fallo antes de terminar, reintenta una sola vez.
            if (!procesada && maquina->estaEnFalla()) {
                maquina->realizarMantenimiento();
                maquina->encender();

                tiempoAntes = maquina->getTiempoTrabajado();
                procesada = maquina->procesarPieza();

                tiempoTotalTurno +=
                    maquina->getTiempoTrabajado() - tiempoAntes;
            }

            if (!procesada) {
                std::cout << "Lote detenido en "
                          << maquina->getNombre()
                          << ". La pieza no se termino.\n";
                return;
            }

            // Puede terminar la pieza y alcanzar su limite justo despues.
            if (maquina->estaEnFalla()) {
                maquina->realizarMantenimiento();
                maquina->encender();
            }
        }

        totalPiezasTerminadas++;
    }
}

void Planta::generarReporteTurno() const {
    int totalParos = 0;

    for (const Maquina* maquina : maquinas) {
        totalParos += maquina->getParos();
    }

    std::cout << "\n=== Reporte del turno ==="
              << "\nPiezas terminadas: " << totalPiezasTerminadas
              << "\nTiempo total: " << tiempoTotalTurno << " s"
              << "\nParos por mantenimiento: " << totalParos
              << "\n";

    for (const Maquina* maquina : maquinas) {
        maquina->mostrarEstado();
    }
}