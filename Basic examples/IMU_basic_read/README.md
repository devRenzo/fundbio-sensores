# 📟 Lectura básica de acelerómetro y giroscopio con MPU6050

Este proyecto muestra cómo utilizar el sensor **MPU6050** con Arduino para leer datos crudos (RAW) tanto del **acelerómetro** como del **giroscopio** en los tres ejes (X, Y, Z).

---

## 🎯 Objetivo

- Adquirir datos en tiempo real desde el **MPU6050** usando el protocolo I2C.
- Visualizar aceleraciones lineales y velocidades angulares.
- Explorar el uso de sensores MEMS en aplicaciones biomédicas y de movimiento.

---

## 🔬 ¿Qué es el MPU6050?

El **MPU6050** es un sensor MEMS que combina:
- **Acelerómetro de 3 ejes**
- **Giroscopio de 3 ejes**
- Comunicación por **I2C** (dirección por defecto: `0x68`)

Permite detectar movimientos lineales y rotacionales, comúnmente utilizado en:
- Robots móviles
- Wearables
- Rehabilitación y biomecánica

---

## 📦 Contenido

El archivo `mpu6050-lectura-basica.ino` contiene:

- Lectura de aceleración: `ax`, `ay`, `az`
- Lectura de rotación: `gx`, `gy`, `gz`
- Visualización en monitor serial con separación por tabuladores (compatible con Serial Plotter)

---

## ⚙️ Requisitos

- Sensor **MPU6050**
- Arduino UNO, Nano o compatible
- Librerías necesarias:
  - [`Wire.h`](https://www.arduino.cc/en/Reference/Wire)
  - [`I2Cdev.h`](https://github.com/jrowberg/i2cdevlib)
  - [`MPU6050.h`](https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/MPU6050)

---

## 🔌 Conexiones básicas

| MPU6050 | Arduino |
|---------|---------|
| VCC     | 5V      |
| GND     | GND     |
| SDA     | A4      |
| SCL     | A5      |

> 📌 Nota: Verifica si el pin SDA/SCL cambia según tu placa (Ej: ESP32, Leonardo).

---

## 📈 Visualización

Usa el **Serial Plotter** del IDE de Arduino a **57600 baudios** para observar las curvas de aceleración y giroscopio en tiempo real.

---

## 🧪 Aplicaciones sugeridas

- Registro de caídas o colisiones
- Monitoreo de postura corporal
- Entrenamiento deportivo y feedback de movimiento
- Interfaces hombre-máquina

---

## 🎥 Material Complementario

A continuación se presentan algunos videos recomendados para reforzar los conceptos abordados:

- 📄 [Tutorial MPU6050: Acelerómetro y Giroscopio – Naylamp Mechatronics](https://naylampmechatronics.com/blog/45_tutorial-mpu6050-acelerometro-y-giroscopio.html)
- 📺 [How does an Accelerometer work? | 3D Animation (Inglés)](https://www.youtube.com/watch?v=KuekQ-m9xpw)
- 📺 [How Gyroscope Sensor Works ? | 3D Animated (Inglés)](https://www.youtube.com/watch?v=REVp33SwwHE)

---

## 👨‍🏫 Créditos

Desarrollado para el curso **Fundamentos de Biodiseño**  
Docentes: **Renzo Chan Ríos** / **Lewis De La Cruz**  
Universidad Peruana Cayetano Heredia (UPCH) — 2025  
Versión: 0.1

---
