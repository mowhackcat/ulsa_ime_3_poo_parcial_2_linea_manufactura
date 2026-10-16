> Crea una carpeta dentro de `docs/mejoras/` con tu número de matrícula como nombre, copia este archivo ahí como `mejora.md` y llena tu copia. No modifiques la plantilla.
>
> La propuesta es solo diseño: no se programa.

**Propuesta de mejora elaborada por:** [Daniel Alejandro Hernández Sánchez]

## 1. Impacto

**¿Es una mejora o una corrección?**



**¿Qué observaste en la solución del equipo que dio origen a la propuesta?**

Observé que en la solución actual, cuando un componente (como el Troquel de la Prensa) se desgasta y causa una falla, la línea se detiene y requiere que el mantenimiento sea asignado o intervenido de forma manual. Además, no existe un mecanismo de prevención que alerte cuando un componente está a punto de llegar a su límite crítico antes de que la máquina falle por completo.

**¿Qué mejora o qué corrige, y por qué vale la pena?**

Implementa un Sistema de Mantenimiento Predictivo y Alertas Preventivas. Vale la pena porque evita paros no planificados en la planta de manufactura. Al monitorear constantemente el porcentaje de vida útil del Troquel y los demás componentes, el sistema puede programar el mantenimiento de forma automática justo antes de que la pieza falle, optimizando el tiempo total de producción del lote.

## 2. Qué implica

**Clases nuevas:**

SensorDesgaste: Clase que se encarga de monitorear en tiempo real el porcentaje de vida útil restante de un componente.
GestorMantenimiento: Clase que recibe las alertas de los sensores, analiza los umbrales de desgaste (por ejemplo, al llegar al 10% de vida restante) y programa paros preventivos antes de que ocurra una falla destructiva.

**Comportamiento nuevo en clases existentes:**

Maquina / Prensa: Se les agrega el método consultarNivelRiesgo() y la capacidad de enviar un evento o notificación al GestorMantenimiento cuando la vida útil del componente cae por debajo del umbral de seguridad.
Planta: Se integra con el GestorMantenimiento para pausar la línea de manera controlada entre piezas y no a mitad de una falla.

**Interacciones nuevas entre objetos:**

1. La Prensa (o cualquier Maquina) envía su estado de desgaste actual a la clase SensorDesgaste después de procesar cada pieza.
2. El SensorDesgaste notifica al GestorMantenimiento cuando la vida útil cae por debajo del umbral de seguridad (por ejemplo, al llegar al 10%).
3. El GestorMantenimiento se comunica con la Planta para solicitar una pausa controlada al finalizar la pieza en turno, invocando realizarMantenimiento() antes de que la máquina sufra un paro por falla destructiva.

**Relaciones nuevas (herencia, composición o agregación) y por qué son de ese tipo:**

- Composición entre Maquina y SensorDesgaste: Cada máquina posee un SensorDesgaste integrado que no existe ni tiene sentido sin la máquina que está monitoreando.
- Agregación entre Planta y GestorMantenimiento: La Planta utiliza un GestorMantenimiento para coordinar los paros preventivos de las distintas estaciones. El gestor se crea fuera y se registra en la planta, permitiendo que existan de manera independiente.
- Asociación entre SensorDesgaste y GestorMantenimiento: El sensor notifica sus lecturas al gestor sin ser dueño de su ciclo de vida.

## 3. Diagrama de clases

Diagrama hecho en draw.io que muestre la solución con la mejora incorporada. Distingue lo nuevo de lo existente, por ejemplo con otro color. Guarda la imagen en esta misma carpeta y enlázala aquí.

[Inserta aquí tu diagrama]
