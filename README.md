# Simulador de una Planta de Manufactura Automatizada

Proyecto del Parcial 2 de Programación Orientada a Objetos.

La guía completa del proyecto está en [PROYECTO.md](PROYECTO.md). Léanla antes de empezar.

## 1. Equipo

| Bloque | Matrícula | Nombre | Usuario de GitHub | Máquina | Componente |
| --- | --- | --- | --- | --- | --- |
| 1 | 25317 | Yair Alberto Flores Peña | yairflores09 | cortadora laser | lente |
| 2 | 22038 | Jesús René Pamanes Ferreira | TacocraftG | Impresora 3D | Extrusor |
| 3 | 25029| Daniel Alejandro Hernandez Sanchez | danielhernandez | prensa | Tronquel |
| 4 | 25132 | Arturo Lugo Rodriguez |ArturoLugoRodriguez |Fresa|Heramienta de corte|
| 5 | 25238 | Daniel Guerra  | mowhackcat| Torno CNC| Husillo|

## 2. Orden de la línea

Escriban el orden en que una pieza recorre las estaciones.

[TornoCNC--> Cortadora Laser--> Fresadora --> Prensa --> Impresora 3D]

## 3. Cómo compilar y ejecutar

Escriban el comando exacto que usa el equipo para compilar y el comando para ejecutar.

// Compilar:
 g++ -Wall -Wextra -std=c++17 -Iinclude src/*.cpp -o planta
// Ejecutar:
 ./planta

## 4. Reglas de la simulación

**¿En qué momento exacto falla una máquina?**

cuando su componente que llega a sufrir de desgasta falla. ejemplo: Extrusor Fallo.

**¿El mantenimiento suma tiempo al turno? ¿Cuánto?**

En nuestro caso no suma tiempo.

## 5. Cálculo a mano del reporte

Lote de 20 piezas. Una fila por máquina.

| Máquina | Segundos por pieza | Límite del componente | Fallas en 20 piezas | Tiempo trabajado |
| --- | ---: | ---: | ---: | ---: |
| Torno CNC | 30 | 8 | 2 | 600 |
| CortadoraLaser | 300 | 15 | 5 | 4500 |
| fresadora | 100 | 5 | 15 | 500 |
| Prensa | 30 | 10 | 2 | 300 |
| Impresora3D | 120 | 15 | 1 | 2400 |

**Reporte esperado (piezas terminadas, tiempo total y paros):**
TornoCnC1..........20piezas  600segundos  2paros.
CortadoraLaser.....20piezas 4500segundos  5paros.
Fresadora .........20piezas  500segundos 15paros.
Prensa.............20pezas   300segundos  2paros.
Bambu Labs5........20piezas 2400segundos  1paros.

**¿Coincide con lo que imprime el programa? Si no coincidió al primer intento, ¿qué encontraron?**
TornoCNC si coincide
Impresora 3D si coincide
Prensa si coincide
Fresadora si coincide
CortadorLaser si coincide
## 6. Diagrama general

Diagrama de clases de la solución completa, hecho en draw.io. Guarden la imagen como `docs/diagrama_general.png`.

![Diagrama general](docs/diagrama_general.png)

## 7. Documentación individual

| Integrante | Documentación de su clase | Propuesta de mejora |
| --- | --- | --- |

| | `docs/<Clase>.md` | `docs/mejoras/<matrícula>/mejora.md` |
|Daniel guerra | `docs/TornoCNC.md`| `docs/mejoras/25238/mantenimiento.md`|
| Daniel Alejandro Hernandez Sanchez | [Prensa.md](docs/mejoras/25029/docsPrensa.md)  | [mejora.md](docs/mejoras/25029/mejora.md)  |
| Jesús René Pamanes Ferreira | [Impresora3D.md](docs/mejoras/22038/Impresora3D.md) | [mejora.md](docs/mejoras/22038/mejora.md) |
| Arturo Lugo Rodriguez| [Fresadora.md](docs/docsFresa.md) | [mejora.md](docs/mejoras/25162/mejora.md) |
|Yair Alberto Flores Peña | [CortadoraLaser.md](docs/CortadoraLaser.md) | [mejora.md](docs/mejoras/25317/mejora.md) |


## 8. Cambios a `Maquina.h`

Si el equipo modificó la interfaz de la clase base, expliquen qué cambió y por qué. Si no hubo cambios, escriban "Sin cambios".

no se realizo ninguno cambio a la clase maquina.
