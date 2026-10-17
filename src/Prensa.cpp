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

    if (fuerzaTension <= 0) {
        this->fuerzaTension = 100; 
    } else {
        this->fuerzaTension = fuerzaTension;
    }
}

bool Prensa::doblarPieza() {
    if (!puedeProcesar()) {
        return false;
    }

    if (troquel.getVidaUtilRestante() <= 0) {
        reportarFalla();
        registrarMantenimiento();
        getParos();
        return false;
    }

    troquel.desgastar();
    registrarPieza();
    agregarTiempo(tiempoPorPieza);

    if (troquel.getVidaUtilRestante() == 0) {
        reportarFalla();
    }

    return true;
}

void Prensa::realizarMantenimiento() {
    troquel.restaurar();
    registrarMantenimiento();
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
bool Prensa::procesarPieza(){
    return doblarPieza();
}
