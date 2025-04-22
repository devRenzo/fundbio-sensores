# 📘 Lectura Básica de Sensor de Flexión con Arduino

Este ejemplo muestra cómo utilizar un **Flex Sensor** para medir el ángulo de curvatura de una superficie, conectándolo a una placa Arduino UNO. El valor leído varía en función del grado de flexión y se visualiza a través del **monitor serial**.

---

## 🧪 ¿Qué es un sensor de flexión?

Un **Flex Sensor** es un sensor resistivo que **cambia su resistencia al ser doblado**. Cuanto más se curva, mayor es su resistencia. Se utiliza comúnmente en aplicaciones donde se necesita medir la posición o el movimiento de articulaciones, dedos, o dispositivos portables.

---

## 🔬 Principio de funcionamiento

- El sensor está fabricado con un material flexible y una capa conductora interna.  
- Cuando el sensor está recto, su resistencia es baja (entre 10kΩ y 20kΩ).  
- Al doblarse, la resistencia puede aumentar a más de 70kΩ.  
- Este cambio de resistencia se traduce en un voltaje variable mediante un **divisor de voltaje**, y puede leerse con un pin analógico del Arduino.

## 🔧 Esquema de conexión

```plaintext
 +5V -----> Flex Sensor --------+----------> A0 (Arduino)
                                |
                              10kΩ
                                |
                              GND
```
## 🔄 Explicación

- El Flex Sensor se conecta en serie con una resistencia de 10kΩ.
- Juntos forman un divisor de voltaje que convierte la resistencia variable en una señal analógica proporcional al ángulo de flexión.
- La lectura se realiza en el pin A0 del Arduino.

---

## 💻 Código del ejemplo

Consulta el archivo: `flex-basic-read.ino`

Este programa:
- Lee el valor del pin analógico A0 donde está conectado el Flex Sensor.
- Imprime el valor en el monitor serial cada 200 ms.
- Permite observar en tiempo real cómo el ángulo de curvatura afecta la señal.

---

## 📈 Aplicaciones biomédicas

- **Guantes de rehabilitación para terapia de mano** (seguimiento de rango articular).
- **Monitoreo de flexión de dedos o codo** para pacientes post-operatorios.
- **Control de prótesis o exoesqueletos** a partir de movimientos naturales.
- **Interfaz gestual wearable** para asistencia en movilidad o comunicación.

---

## 📎 Requisitos

- 1 Flex Sensor (2.2" o 4.5" de SparkFun, Adafruit u otro proveedor)
- 1 resistencia de 10kΩ
- 1 placa Arduino UNO o compatible
- Protoboard y cables Dupont
- Arduino IDE instalado (v1.8.x o 2.x)

---

## 🧑‍🏫 Créditos

Este ejemplo fue desarrollado para el curso **Fundamentos de Biodiseño**  
Docentes: **Renzo Chan Ríos** / **Lewis De La Cruz**  
Universidad Peruana Cayetano Heredia (UPCH) — 2025  
Versión: 0.1

---

