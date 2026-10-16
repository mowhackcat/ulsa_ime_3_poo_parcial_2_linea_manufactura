#include "Maquina.h"
#include <iostream>

Maquina::Maquina(int id, const std::string& nombre)
    : id(id), nombre(nombre), encendida(false), enFalla(false),
      piezasProcesadas(0), tiempoTrabajado(0), paros(0) {
}

void Maquina::encender() {
    encendida = true;
    std::cout << "Se encendio " << nombre << "\n";
}

void Maquina::apagar() {
    encendida = false;
    std::cout << "Se apago " << nombre << "\n";
}

bool Maquina::estaEncendida() const {
    return encendida;
}

bool Maquina::estaEnFalla() const {
    return enFalla;
}

bool Maquina::puedeProcesar() const {
    return encendida && !enFalla;
}

void Maquina::registrarPieza() {
    piezasProcesadas++;
}

void Maquina::agregarTiempo(int segundos) {
    if (segundos >= 0) {
        tiempoTrabajado += segundos;
    }
}

void Maquina::reportarFalla() {
    enFalla = true;
    std::cout << "Falla detectada en " << nombre << "\n";
    apagar();
}

void Maquina::registrarMantenimiento() {
    enFalla = false;
    paros++;
    std::cout << "Mantenimiento registrado en " << nombre << "\n";
}

int Maquina::getId() const {
    return id;
}

std::string Maquina::getNombre() const {
    return nombre;
}

int Maquina::getPiezasProcesadas() const {
    return piezasProcesadas;
}

int Maquina::getTiempoTrabajado() const {
    return tiempoTrabajado;
}

int Maquina::getParos() const {
    return paros;
}

void Maquina::mostrarEstado() const {
    std::cout << "\nMaquina: " << nombre
              << "\nID: " << id
              << "\nEncendida: " << (encendida ? "Si" : "No")
              << "\nEn falla: " << (enFalla ? "Si" : "No")
              << "\nPiezas procesadas: " << piezasProcesadas
              << "\nTiempo trabajado: " << tiempoTrabajado << " segundos"
              << "\nParos: " << paros << "\n";
}