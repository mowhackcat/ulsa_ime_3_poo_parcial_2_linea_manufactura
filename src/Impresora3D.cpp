#include "Impresora3D.h"

#include <iostream>

Impresora3D::Impresora3D(int id, const std::string& nombre,
                         int limiteExtrusor)
    : Maquina(id, nombre),
      extrusor(limiteExtrusor) 
{}

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
        realizarMantenimiento();
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
        realizarMantenimiento();
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
    std::cout << "  - Tiempo por pieza: " << tiempoPorPieza << " segundos\n"
              << "  - Desgaste del Extrusor: "
              << extrusor.getUsoActual() << '/'
              << extrusor.getLimiteUso() << " usos ("
              << (extrusor.estaAgotado() ? "Agotado (Falla)" : "Operativo")
              << ")\n";
}
