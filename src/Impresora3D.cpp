#include "Impresora3D.h"

#include <iostream>

Impresora3D::Impresora3D(int id, const std::string& nombre, int limiteExtrusor)
    : Maquina(id, nombre),
      tiempoPorPieza(0),
      temperaturaCelsius(0),
      extrusor(limiteExtrusor) {}

bool Impresora3D::procesarPieza() 
{
    if (!puedeProcesar()) 
    {
        std::cout << "[" << getNombre()
                  << "] Operacion rechazada: Maquina apagada o en falla.\n";
        return false;
    }

    if (extrusor.estaAgotado()) 
    {
        reportarFalla();
        std::cout << "[" << getNombre()
                  << "] FALLA DETECTADA: Extrusor agotado.\n";
        return false;
    }

    registrarPieza();
    agregarTiempo(tiempoPorPieza);
    extrusor.desgastar();

    std::cout << "[" << getNombre() << "] Pieza procesada exitosamente.\n";

    if (extrusor.estaAgotado()) 
    {
        reportarFalla();
        std::cout << "[" << getNombre()
                  << "] FALLA DETECTADA: Extrusor agotado; se requiere mantenimiento.\n";
    }

    return true;
}

void Impresora3D::realizarMantenimiento() 
{
    if (!estaEnFalla()) 
    {
        std::cout << "[" << getNombre()
                  << "] La impresora no presenta fallas.\n";
        return;
    }

    extrusor.restaurar();
    registrarMantenimiento();
    std::cout << "[" << getNombre()
              << "] Mantenimiento completado: Extrusor restaurado.\n";
}

void Impresora3D::mostrarEstado() const 
{
    Maquina::mostrarEstado();
    std::cout << "  - Estado del Extrusor: "
              << (extrusor.estaAgotado() ? "Agotado (Falla)" : "Operativo")
              << '\n';
}

//Esto solo esta para que la clase impresora tenga 2 al menos 2 atributos propios
//(Sección 3.1 del enunciado)
void Impresora3D::calibrarTemperatura(int temp) {
    temperaturaCelsius = temp;
    std::cout << "[" << getNombre()
              << "] Calibrando temperatura del extrusor a "
              << temperaturaCelsius << " C.\n";
}
