// Proyecto Parcial 2: Simulador de una Planta de Manufactura Automatizada
//
// Programa principal del equipo (bloque 6).
// La guía completa está en PROYECTO.md, sección 2.5.
//
// Compilar:
//   g++ -Wall -Wextra -std=c++17 -Iinclude src/*.cpp -o planta
// Ejecutar:
//   ./planta

#include <iostream>
#include "../include/Planta.h"
#include "../include/TornoCNC.h"
#include "../include/Prensa.h"
#include "../include/Fresadora.h"
//include
#include "../include/Impresora3D.h"

int main() {
    // 1. Crear las máquinas y registrarlas en la planta.

Torno torno1(1, "TornoCnC");

//
Prensa prensa1(4, "Prensa", 30, 10, 100);
Impresora3D impresora3d1(5,"Bambu Labs", 15);
Fresadora fresadora1(3,"Fresadora", 100, 5);
Planta planta1(20);

planta1.agregarMaquina(&torno1);
planta1.agregarMaquina(&fresadora1);
planta1.agregarMaquina(&prensa1);

planta1.agregarMaquina(&impresora3d1);

planta1.encenderMaquinas();

for(int x =0; x < planta1.getRepeticionesGlobales();x++)
{
torno1.procesarPieza();
fresadora1.procesarPieza();
prensa1.procesarPieza();
impresora3d1.procesarPieza();
}

planta1.mostrar();
planta1.apagarMaquinas();


    // 2. Intentar procesar una pieza con las máquinas apagadas,
    //    para mostrar el rechazo.

    // 3. Encender todas las máquinas.

    // 4. Procesar un lote de 20 piezas.

    // 5. Mostrar el reporte del turno y apagar.

    return 0;
}