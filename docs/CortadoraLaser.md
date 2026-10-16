# Documentación de la clase: CortadoraLaser

**Elaborada por:** Yair Alberto Flores Peña

**Matrícula:** 25317

**Bloque:** 2

## 1. Propósito

**¿Qué máquina representa tu clase y qué operación hace sobre la pieza?**

Representa una cortadora láser que realiza un corte sobre cada pieza.
Cada corte exitoso suma una pieza procesada y acumula el tiempo
de trabajo correspondiente.

**¿Cuál es su componente y por qué no existe sin la máquina?**

Su componente es un Lente. En este modelo, el lente pertenece
a la cortadora mediante composición: es un atributo por valor,
se construye junto con ella y se destruye cuando ella se destruye.
No se comparte con otras máquinas.

## 2. Decisiones de diseño

**Atributos propios de tu clase y validación de cada uno:**

- tiempoPorPieza: segundos necesarios para cortar una pieza.
  Si el constructor recibe cero o un número negativo, se utiliza 1.
- potenciaWatts: potencia configurada del láser. Inicia en 1000 W.
  El método calibrarPotencia solamente acepta valores positivos.
- lente: objeto de la clase Lente. Su constructor valida que
  el límite de suciedad sea positivo; de lo contrario utiliza 1.

La potencia es un parámetro de configuración. En esta versión
no modifica el tiempo por pieza ni la acumulación de suciedad.

**Métodos propios (los que la clase base no tiene):**

- calibrarPotencia(int watts): cambia la potencia del láser
  cuando recibe un valor mayor que cero.

**Método de la base que redefines, y cómo reutilizas la versión de la base:**

Redefino mostrarEstado() y primero llamo a Maquina::mostrarEstado()
para mostrar los datos generales. Después muestro el tiempo por pieza,
la potencia y la suciedad y opacidad del lente.

También implemento procesarPieza() y realizarMantenimiento(),
declarados como virtuales puros en Maquina. Estos métodos no tienen
una implementación en la base; mi clase define su comportamiento.

**¿Cómo modelaste el desgaste del componente y por qué así?**

El deterioro del lente se representa mediante suciedad acumulada.
Cada corte exitoso agrega un punto de suciedad, sin superar el límite.

Cuando alcanza el límite, el lente se considera opaco y la cortadora
reporta una falla y se apaga. La pieza que acaba de cortar sí cuenta
como procesada, porque la falla se registra después de terminarla.

El mantenimiento limpia el lente, elimina la falla y registra un paro.
Si la máquina estaba apagada, permanece apagada hasta llamar
a encender().

Este modelo permite simular la necesidad de mantenimiento de forma
sencilla y predecible.

**¿Qué usa tu clase de Maquina y qué agrega?**

Utiliza puedeProcesar() para comprobar si puede trabajar,
registrarPieza() para contar la producción, agregarTiempo()
para acumular segundos, reportarFalla() para activar una falla
y registrarMantenimiento() para quitarla y contar un paro.

También utiliza getNombre() para los mensajes y
Maquina::mostrarEstado() para mostrar los datos generales.

Agrega el tiempo por corte, la potencia del láser y el lente,
junto con la lógica de suciedad, limpieza y calibración.

## 3. Diagrama

Pendiente: crear en draw.io el diagrama de CortadoraLaser y Lente,
incluyendo la herencia de Maquina y la composición con Lente.
Exportarlo como docs/diagrama_cortadora.png.

Cuando se guarde la imagen, reemplazar este texto por:

![Diagrama de CortadoraLaser y Lente](diagrama_cortadora.png)

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

Una duda fue cómo permitir que Planta manejara diferentes máquinas
mediante apuntadores a Maquina. Se añadieron las declaraciones
virtuales de procesarPieza() y realizarMantenimiento() a la base.

Otra duda fue cuándo contar una pieza si el lente alcanza su límite.
Se decidió contar el corte terminado y después reportar la falla,
para evitar repetir una pieza que ya fue procesada.

**Errores que encontraste y cómo los corregiste:**

Al revisar Maquina.cpp se detectó que los estados y contadores
no se inicializaban. Se corrigió el constructor para iniciar
la máquina apagada, sin falla y con los contadores en cero.

También se encontró una comparación que no activaba la falla.
Se reemplazó por la asignación enFalla = true.

Se agregaron las implementaciones faltantes de registrarPieza()
y agregarTiempo(), y se corrigió registrarMantenimiento()
para que eliminara la falla y sumara un paro.

Se compilo y ejecuto una prueba individual de la cortadora.
Se verifico el rechazo estando apagada, la falla por suciedad,
el bloqueo durante la falla y la recuperacion con mantenimiento.
El resultado fue de 4 piezas, 40 segundos y 1 paro.
Todas las comprobaciones de la prueba pasaron.