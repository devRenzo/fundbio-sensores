# 📘 Lectura Básica de Sensor FSR con Arduino

Este ejemplo muestra cómo utilizar un **sensor de fuerza resistivo (FSR)** para medir la presión aplicada sobre una superficie, utilizando una placa Arduino UNO. Los datos se leen a través de un pin analógico y se visualizan en el **monitor serial**.

---

## 🧪 ¿Qué es un sensor FSR?

Un **FSR (Force Sensitive Resistor)** es un sensor que cambia su resistencia eléctrica en función de la presión aplicada sobre su superficie activa. A mayor presión, **menor resistencia**.

### 🔬 Principio de funcionamiento

El FSR se basa en el **efecto piezorresistivo**:  
- En reposo, su resistencia puede ser mayor a 10 MΩ.  
- Al aplicar presión, esta disminuye progresivamente hasta unos pocos cientos de ohmios.

Este cambio resistivo se convierte en un **voltaje variable** mediante un **divisor de voltaje**, que es leído por el pin analógico del microcontrolador.

## 🔧 Esquema de conexión

```plaintext
 +5V -----> FSR --------+----------> A0 (Arduino)
                        |
                      10kΩ
                        |
                      GND
```
## 🔄 Explicación

- Se conecta el FSR en serie con una resistencia de 10kΩ.
- El nodo común va al pin analógico A0.
- Se forma así un **divisor resistivo**, que entrega un voltaje proporcional a la presión aplicada.

---

## 💻 Código del ejemplo

Consulta el archivo: `FSR_basic_read.ino`

Este programa:
- Lee el valor del pin analógico A0.
- Imprime el valor en el monitor serial cada 200 ms.
- El valor varía entre 0 (sin presión) y 1023 (presión máxima).

---

## 📈 Aplicaciones biomédicas

- **Monitoreo de presión plantar** en plantillas ortopédicas.
- **Detección de presión prolongada** para evitar úlceras por presión en sillas de ruedas.
- **Sistemas de biofeedback** para terapia física y ocupacional.
- **Evaluación de fuerza de agarre** o apoyo en bastones inteligentes.

---

## 📎 Requisitos

- 1 sensor FSR (cualquiera de SparkFun, Adafruit, etc.)
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
