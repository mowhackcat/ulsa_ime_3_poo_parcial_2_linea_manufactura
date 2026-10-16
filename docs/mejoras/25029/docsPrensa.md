# Documentación de la clase: [Inserta aquí el nombre de tu clase]

> Copia este archivo como `docs/<Clase>.md` (por ejemplo, con el nombre de tu máquina) y llena tu copia. No modifiques la plantilla.

**Elaborada por:** [Daniel Alejandro Hernández Sánchez]
**Matrícula:** [25029]
**Bloque:** [Inserta aquí tu número de bloque: 2]

## 1. Propósito

**¿Qué máquina representa tu clase y qué operación hace sobre la pieza?**

[Representa una Prensa industrial dentro de la línea de manufactura. Su función principal es realizar la operación de doblado sobre cada soporte metálico del lote].

**¿Cuál es su componente y por qué no existe sin la máquina?**

[Su componente es el Troquel, el cual sufre desgaste físico con cada operación de doblado realizada. Existe bajo una relación de composición; esto significa que el troquel es una parte intrínseca de la prensa, por lo que su ciclo de vida está totalmente ligado a ella (si la prensa se destruye, el troquel también deja de existir).]

## 2. Decisiones de diseño

**Atributos propios de tu clase y validación de cada uno:**

[tiempoPorPieza : Representa los segundos que tarda la prensa en procesar/doblar una pieza. Validación: En el constructor se verifica que sea mayor a 0; si es menor o igual a 0, se asigna un valor por defecto de 15 segundos.
 fuerzaTension : Indica la fuerza de prensado/doblado en kilonewtons (kN). Validación: Se valida que la fuerza sea positiva (> 0); si no lo es, se asigna por defecto 100 kN.
troquel (objeto de la clase Troquel): Objeto instanciado por composición que gestiona la vida útil restante y máxima de la herramienta.]

**Métodos propios (los que la clase base no tiene):**

[bool doblarPieza(): Realiza el proceso de doblado de la pieza, desgasta el troquel, acumula el tiempo y las piezas procesadas, y reporta fallas si la vida del troquel llega a 0.
void realizarMantenimiento(): Restaura el troquel a su vida útil máxima, quita el estado de falla y registra un paro por mantenimiento.
void setFuerzaTension(int fuerza) y int getFuerzaTension() const: Getters y setters con validación para ajustar la fuerza de la prensa.
const Troquel& getTroquel() const: Permite consultar el estado actual del componente troquel.]

**Método de la base que redefines, y cómo reutilizas la versión de la base:**

[Redefino el método mostrarEstado(). Dentro de la redefinición, ejecuto primero Maquina::mostrarEstado() para imprimir los datos generales provistos por la clase base (identificador, nombre, estado de encendido, piezas procesadas, tiempo y paros). Posteriormente, añado la información específica de la clase Prensa, mostrando la fuerza de doblado en kN, el tiempo por pieza y la vida útil restante/porcentaje del Troquel.]

**¿Cómo modelaste el desgaste del componente y por qué así?**

[Se modeló de manera determinista utilizando la clase Troquel. Cada vez que la prensa ejecuta doblarPieza(), invoca al método desgastar() del troquel, reduciendo su contador de vida útil en 1 unidad por pieza procesada. Al llegar a 0, la máquina entra automáticamente en estado de falla mediante reportarFalla() y detiene el procesamiento hasta recibir mantenimiento. Se diseñó así para permitir un cálculo determinista exacto sobre cuándo ocurrirá un paro dentro del turno simulado.]

**¿Qué usa tu clase de `Maquina` y qué agrega?**

[Usa de Maquina: Los atributos de estado (encendida, enFalla), el identificador, el nombre y los métodos protegidos registrarPieza(), agregarTiempo(), reportarFalla() y registrarMantenimiento(). También invoca a puedeProcesar() antes de cada operación.
Agrega: La operación específica de doblado (doblarPieza()), el mantenimiento del componente (realizarMantenimiento()), la especificación de fuerza en kN (fuerzaTension), el tiempo por pieza y la composición directa con la clase Troquel.]

## 3. Diagrama

Diagrama de tu clase y su componente, hecho en draw.io. Debe mostrar la relación de herencia con `Maquina` y la de composición con tu componente. Guarda la imagen en `docs/` y enlázala aquí.

https://drive.google.com/file/d/1OhBFn_Ac7pTGeXph8IEZ6SHfegyPflS_/view?usp=sharing

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

[Duda: ¿En qué momento exacto se debe marcar la falla del troquel?
Solución: Se determinó que al procesar la última pieza útil (cuando la vida llega a 0), la pieza actual se termina con éxito y se marca la falla inmediatamente al final para rechazar la siguiente pieza hasta dar mantenimiento.]

**Errores que encontraste y cómo los corregiste:**

[Error: Olvidar invocar la versión base del método redefinido, lo que provocaba que al llamar a mostrarEstado() no se imprimiera el identificador ni las estadísticas acumuladas de la clase base Maquina.
Corrección: Se agregó la llamada explícita Maquina::mostrarEstado(); al inicio del método mostrarEstado() en Prensa.cpp.]
