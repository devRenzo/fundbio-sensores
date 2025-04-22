# fundbio-sensores

Este repositorio contiene ejemplos de código para el curso **Fundamentos de Biodiseño**, orientados al uso de sensores con Arduino en aplicaciones biomédicas.

## 📦 Contenido del repositorio

El repositorio está organizado en los siguientes directorios:

### 1. **`basic-examples/`**  
Ejemplos básicos para la lectura y procesamiento de sensores:
- **EMG**: Ejemplo básico de lectura de un sensor EMG de Grove.
- **FSR**: Ejemplo básico de lectura de un sensor de presión FSR.
- **Flex**: Lectura de ángulo a partir de un sensor Flex.
- **IMU**: Lectura de datos sin procesar de un sensor IMU (MPU6050).

### 2. **`tiny-projects/`**  
Proyectos pequeños que integran uno o más sensores para realizar tareas específicas:
- **Fall Detection**: Detección de caídas utilizando un sensor IMU (MPU6050).
- **EMG Gesture Control**: Control de un LED o dispositivo basado en gestos detectados por el sensor EMG.
- **Flex Glove**: Uso de un sensor Flex para controlar un dispositivo o realizar mediciones de flexión de los dedos.
- **FSR Pressure Alert**: Alerta basada en umbral de presión usando un sensor FSR.

### 3. **`documentation/`**  
Documentación adicional para los proyectos y sensores:
- **sensors-reference.md**: Información técnica y enlaces a hojas de datos de los sensores EMG, FSR, Flex e IMU.
- **installation.md**: Instrucciones para instalar las bibliotecas necesarias y configurar el entorno de desarrollo de Arduino.
- **class-outline.md**: Resumen del contenido y objetivos del curso **Fundamentos de Biodiseño**.

---

## 🛠️ Requisitos

- **Arduino UNO** o compatible
- Sensores:
  - **Grove - EMG Sensor**
  - **FSR Sensor**
  - **Flex Sensor**
  - **MPU6050 IMU Sensor**
- **Bibliotecas necesarias**:
  - `MPU6050.h` ([Instalar desde el Library Manager](https://github.com/jrowberg/i2cdevlib))
  - `Wire.h` (Incluida por defecto en el IDE de Arduino)
  - Cualquier otra biblioteca específica mencionada en cada ejemplo.

## 🚀 Instalación

1. Clona el repositorio en tu máquina local:
   ```bash
   git clone https://github.com/devRenzo/fundbio-sensores.git
