# 📘 Detección de Caídas con Sensor IMU MPU6050 y Arduino

Este ejemplo demuestra cómo utilizar un **sensor inercial MPU6050** para detectar caídas basadas en picos de aceleración seguidos de estados de quietud. El sistema se implementa con una placa Arduino UNO y puede visualizarse en tiempo real mediante el **Serial Plotter** del IDE de Arduino.

---

## 🧪 ¿Qué es un sensor IMU?

Una **Unidad de Medición Inercial (IMU)** combina acelerómetros y giroscopios para medir el movimiento y la orientación de un objeto en el espacio. El **MPU6050** es un módulo popular que incluye:

- Acelerómetro de 3 ejes
- Giroscopio de 3 ejes
- Comunicación por protocolo I2C

En este ejemplo solo se utiliza el **acelerómetro**.

---

## 🔬 Principio de funcionamiento

- El acelerómetro mide la aceleración en los ejes X, Y y Z.
- Se calcula la **magnitud total del vector aceleración** para obtener el valor global de movimiento:

\[
a_{total} = \sqrt{a_x^2 + a_y^2 + a_z^2}
\]

- Una caída puede caracterizarse por:
  - Un **pico de aceleración** (mayor a 2g)
  - Un **período posterior de quietud** (menor a 0.4g)

El algoritmo detecta este patrón y genera un aviso por el monitor serial.

---

## 💡 ¿Por qué se utiliza la magnitud total?

La aceleración puede ocurrir en cualquier dirección. Al utilizar la **norma del vector**, se garantiza que se detecten caídas en cualquier orientación del cuerpo o del dispositivo, sin depender de un solo eje.

---

## 💻 Código del ejemplo

Consulta el archivo: `imu-fall-detection.ino`

Este programa:
- Lee datos de aceleración del MPU6050 en 3 ejes.
- Calcula la magnitud total del vector.
- Detecta caídas como eventos de pico seguidos de reposo.
- Imprime estado y valores en el Serial Plotter.

---

## 📈 Visualización

Utiliza el **Serial Plotter** a 115200 baudios para graficar:

- **Aceleracion_g**: magnitud total (puede mostrar picos de caída)
- **Estado**: texto "CAIDA" o "NORMAL"

---

## 📎 Requisitos

- Sensor IMU **MPU6050**
- Arduino UNO o compatible
- Cables Dupont y protoboard
- Arduino IDE con librería `MPU6050.h` instalada

---

## 📈 Aplicaciones biomédicas

- Sistemas de **detección de caídas en adultos mayores**
- **Monitoreo de movilidad y postura**
- **Prótesis inteligentes** con respuesta ante impacto
- **Evaluación de equilibrio y estabilidad** en rehabilitación

---

## 🧑‍🏫 Créditos

Este ejemplo fue desarrollado para el curso **Fundamentos de Biodiseño**  
Docentes: **Renzo Chan Ríos** / **Lewis De La Cruz**  
Universidad Peruana Cayetano Heredia (UPCH) — 2025  
Versión: 0.1

---
