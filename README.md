# 🧬 Fundamentos de Biodiseño – Sensores con Arduino

Este repositorio contiene ejemplos de código, documentación técnica y proyectos básicos desarrollados en el curso **Fundamentos de Biodiseño**, orientados al uso de sensores electrónicos aplicados al diseño de dispositivos biomédicos.

---

## 📦 Contenido del repositorio

El repositorio se organiza en tres bloques principales:

### 1. `basic-examples/`
Ejemplos introductorios para la lectura y visualización de datos de sensores biomédicos con Arduino:

- **EMG**: Lectura básica de señales musculares usando el sensor MyoWare.
- **FSR**: Medición de presión con sensor resistivo FSR.
- **Flex**: Interpretación del ángulo de flexión con sensor flexible resistivo.
- **IMU (MPU6050)**: Lectura de aceleración y rotación cruda vía I2C.

### 2. `tiny-projects/`
Proyectos de baja complejidad enfocados en la resolución de problemas biomédicos concretos mediante prototipos funcionales:

- **Fall Detection**: Detección de caídas utilizando datos de aceleración del MPU6050.
- **EMG Gesture Control**: Activación de un LED u otro actuador mediante contracción muscular.
- **Flex Glove**: Control de dispositivo o feedback visual a partir de la flexión del dedo.
- **FSR Pressure Alert**: Alarma de presión que supera un umbral predefinido.

### 3. `documentation/`
Documentos de apoyo, referencias técnicas y lineamientos del curso:

- `sensors-reference.md`: Información técnica y enlaces a hojas de datos de EMG, FSR, Flex e IMU.
- `installation.md`: Instrucciones de instalación de bibliotecas y configuración del entorno Arduino.
- `class-outline.md`: Estructura, objetivos y metodología del curso **Fundamentos de Biodiseño**.

---

## 🎓 Metodología del curso

El curso adopta un enfoque basado en el **aprendizaje activo**, integrando:

- ✅ **Aprendizaje Basado en Proyectos (PBL)**
- ✅ **Design Thinking**
- ✅ **Prototipado electrónico iterativo**

Los estudiantes desarrollan competencias en exploración creativa, resolución técnica de problemas reales del entorno clínico, y validación de conceptos mediante dispositivos funcionales.

---

## 🛠️ Requisitos técnicos

### Hardware
- Arduino UNO o placa compatible
- Sensores:
  - EMG Sensor – **MyoWare**
  - **FSR** – Force Sensitive Resistor
  - **Flex Sensor**
  - **MPU6050** – Acelerómetro y giroscopio (IMU)

### Software
- **Arduino IDE** (1.8.x o 2.x)
- Bibliotecas requeridas:
  - [`MPU6050.h`](https://github.com/jrowberg/i2cdevlib) – para comunicación I2C
  - `Wire.h` – incluida por defecto en el IDE
  - Otras especificadas en cada ejemplo

---

## 🚀 Instalación

1. Clona el repositorio en tu entorno de trabajo local:

```bash
git clone https://github.com/devRenzo/fundbio-sensores.git
```
   
2. Abre los archivos .ino con Arduino IDE.

3. Conecta tu placa Arduino y carga el código.

4. Consulta la documentación incluida para el esquema de conexión y notas técnicas.

## 📜 Licencia

Este repositorio está licenciado bajo **MIT License**.  
Puede ser reutilizado, adaptado y compartido libremente para fines educativos, citando la fuente original.

---


## 👤 Autor

**[RENZO CHAN RIOS]**  
Docente del curso *Fundamentos de Biodiseño*  
FACULTAD DE CIENCIAS E INGENIERÍA – [UPCH]  
[renzo.chan@upch.pe]
