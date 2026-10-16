# Propuesta de mejora: Mantenimiento preventivo del lente

**Propuesta de mejora elaborada por:** Yair Alberto Flores Peña

## 1. Impacto

**¿Es una mejora o una corrección?**

Es una mejora porque agrega una advertencia para realizar
mantenimiento antes de que el lente provoque una falla.

**¿Qué observaste en la solución del equipo que dio origen a la propuesta?**

En la cortadora actual, cada pieza procesada acumula suciedad
en el lente. Cuando alcanza su limite, la maquina reporta
una falla y se apaga.

Actualmente no existe una advertencia que permita detectar
la necesidad de limpieza antes de llegar a ese punto.

**¿Qué mejora o qué corrige, y por qué vale la pena?**

Permite identificar cuando el lente esta cerca de su limite
y realizar una limpieza entre piezas, antes de que quede opaco.

Por ejemplo, si el limite es de 10 puntos, se puede establecer
una advertencia desde los 8 puntos.

Esto reduce las fallas por suciedad durante la produccion.
La limpieza sigue contando como un paro por mantenimiento;
no se eliminan los mantenimientos, se anticipan.

## 2. Qué implica

**Clases nuevas:**

No se necesitan clases nuevas. Se modificaria el diseño
de Lente, CortadoraLaser y Planta.

**Comportamiento nuevo en clases existentes:**

En Lente se agregaria:

- Un atributo privado umbralAviso de tipo int.
- Un metodo publico requiereLimpiezaPreventiva() de tipo bool,
  que sea const.

El umbral debe ser mayor que cero y menor que limiteSuciedad.
Para utilizar esta mejora, el limite debe ser al menos 2.

El metodo devolveria verdadero cuando la suciedad acumulada
sea mayor o igual al umbral.

En CortadoraLaser se agregaria:

- Un metodo publico necesitaMantenimientoPreventivo() de tipo
  bool, que sea const.

Este metodo consultaria al lente sin exponer directamente
el componente.

En Planta se agregaria:

- Un metodo revisarCortadora(cortadora: CortadoraLaser&),
  sin valor de retorno.

La planta llamaria este metodo entre piezas. Si detecta
una advertencia y la cortadora no esta en falla, realizaria
el mantenimiento preventivo.

Conservaria el estado de encendido anterior: solo volveria
a encender la cortadora si estaba encendida antes de limpiarla.
La atencion de fallas existentes conservaria su flujo actual.

**Interacciones nuevas entre objetos:**

1. Planta consulta a CortadoraLaser entre piezas.
2. CortadoraLaser consulta el nivel de advertencia de su Lente.
3. Si se alcanzo el umbral, Planta solicita
   realizarMantenimiento().
4. La cortadora limpia el lente y registra un paro utilizando
   registrarMantenimiento() de Maquina.
5. Si estaba encendida antes de la limpieza, Planta la enciende
   nuevamente para continuar.

**Relaciones nuevas (herencia, composición o agregación) y por qué son de ese tipo:**

No se agregan relaciones nuevas de herencia, composicion
o agregacion.

Se conserva la herencia de CortadoraLaser respecto de Maquina
y la composicion entre CortadoraLaser y Lente.

Se agrega una dependencia de uso de Planta hacia CortadoraLaser:
el metodo revisarCortadora() recibe una referencia temporal.
Esto no implica que Planta sea propietaria de la cortadora.

La composicion con Lente se conserva porque el componente
es un atributo por valor y su ciclo de vida depende
del objeto CortadoraLaser.

## 3. Diagrama de clases

El diagrama distingue en verde los atributos y metodos propuestos.
Los elementos existentes conservan su color original.

![Diagrama de la propuesta de mejora](diagrama_mejora.png)