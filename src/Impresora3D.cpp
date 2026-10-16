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
        return false;
    }

    registrarPieza();
    agregarTiempo(tiempoPorPieza);
    extrusor.desgastar();

    if (extrusor.estaAgotado()) 
    {
        reportarFalla();
        realizarMantenimiento();
    }

    return true;
}

void Impresora3D::realizarMantenimiento() 
{
    if (!estaEnFalla()) 
    {
        return;
    }

    extrusor.restaurar();
    registrarMantenimiento();
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
