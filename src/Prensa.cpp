#include "Prensa.h"
#include <string>
#include <iostream>

Prensa::Prensa(int id, const std::string& nombre, int tiempoPorPieza, int vidaTroquel, int fuerzaTension)
    : Maquina(id, nombre), troquel(vidaTroquel) {
    
    if (tiempoPorPieza <= 0) {
        this->tiempoPorPieza = 15; 
    } else {
        this->tiempoPorPieza = tiempoPorPieza;
    }

    if (fuerzaTension <= 0.0) {
        this->fuerzaTension = 100.0; 
    } else {
        this->fuerzaTension = fuerzaTension;
    }
}

bool Prensa::doblarPieza() {
    if (!puedeProcesar()) {
        std::cout << "[" << getNombre() << "] Rechazo de operación: la máquina está apagada o en falla.\n";
        return false;
    }

    if (troquel.getVidaUtilRestante() <= 0) {
        reportarFalla();
        std::cout << "[" << getNombre() << "] FALLA: El troquel ha alcanzado su límite de desgaste.\n";
        return false;
    }

    troquel.desgastar();
    registrarPieza();
    agregarTiempo(tiempoPorPieza);

    std::cout << "[" << getNombre() << "] Pieza doblada con éxito (" << fuerzaTension << " kN).\n";

    if (troquel.getVidaUtilRestante() == 0) {
        reportarFalla();
        std::cout << "[" << getNombre() << "] ALERTA: Troquel desgastado por completo. Se requiere mantenimiento.\n";
    }

    return true;
}

void Prensa::realizarMantenimiento() {
    troquel.restaurar();
    registrarMantenimiento();
    std::cout << "[" << getNombre() << "] Mantenimiento realizado: Troquel reemplazado/restaurado exitosamente.\n";
}

void Prensa::mostrarEstado() const {
    Maquina::mostrarEstado();
    
    std::cout << "--- Detalles de Prensa ---" << std::endl;
    std::cout << "Fuerza de prensado: " << fuerzaTension << " kN" << std::endl;
    std::cout << "Tiempo por pieza: " << tiempoPorPieza << " s" << std::endl;
    std::cout << "Estado del Troquel: " << troquel.getVidaUtilRestante() << "/" 
              << troquel.getVidaUtilMaxima() << " usos restantes (" 
              << troquel.getPorcentajeVida() << "% vida util)" << std::endl;
}

void Prensa::setFuerzaTension(int fuerza) {
    if (fuerza > 0) {
        this->fuerzaTension = fuerza;
    }
}

int Prensa::getFuerzaTension() const {
    return fuerzaTension;
}

const Troquel& Prensa::getTroquel() const {
    return troquel;
}