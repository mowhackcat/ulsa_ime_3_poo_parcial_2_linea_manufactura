#include "CortadoraLaser.h"
#include <cassert>
#include <iostream>

int main() {
    CortadoraLaser cortadora(1, "Cortadora Laser", 10, 3);

    // Apagada: debe rechazar la pieza.
    assert(!cortadora.procesarPieza());
    assert(cortadora.getPiezasProcesadas() == 0);

    cortadora.encender();

    // Tres piezas alcanzan el limite del lente.
    for (int i = 0; i < 3; i++) {
        assert(cortadora.procesarPieza());
    }

    assert(cortadora.estaEnFalla());
    assert(!cortadora.estaEncendida());
    assert(cortadora.getPiezasProcesadas() == 3);
    assert(cortadora.getTiempoTrabajado() == 30);

    // En falla: no debe procesar otra pieza.
    assert(!cortadora.procesarPieza());
    assert(cortadora.getPiezasProcesadas() == 3);

    cortadora.realizarMantenimiento();

    assert(!cortadora.estaEnFalla());
    assert(cortadora.getParos() == 1);
    assert(!cortadora.estaEncendida());

    cortadora.encender();
    assert(cortadora.procesarPieza());

    assert(cortadora.getPiezasProcesadas() == 4);
    assert(cortadora.getTiempoTrabajado() == 40);

    cortadora.mostrarEstado();
    cortadora.apagar();

    std::cout << "\nPRUEBA COMPLETADA CORRECTAMENTE\n";

    return 0;
}