# 📘 Sensor EMG MyoWare – Lectura con Calibración y Visualización Gráfica

Este ejemplo permite leer la señal analógica del sensor **EMG MyoWare**, calcular un valor de reposo automático mediante calibración, aplicar un **filtro por promediado**, y visualizar la señal en tiempo real utilizando el **Serial Plotter** de Arduino IDE.

---

## 🧪 ¿Qué es un sensor EMG?

El sensor **EMG (Electromiografía)** MyoWare permite medir la actividad eléctrica generada por los músculos esqueléticos cuando se contraen. Esta señal bioeléctrica es amplificada y filtrada por el sensor, entregando una **salida analógica proporcional** a la fuerza de contracción muscular.

---

## 🔬 Principio de funcionamiento

- Los músculos generan **potenciales de acción** (señales eléctricas de baja amplitud) al contraerse.
- El sensor MyoWare captura esta señal con **electrodos de superficie**, la amplifica y la filtra.
- La salida resultante puede variar de aproximadamente **0.5 V en reposo** hasta **3.5 V en contracción fuerte**.
- Arduino lee esta señal a través de su convertidor ADC (analógico a digital), con resolución de 10 bits (0–1023).

---

## 🧠 Conceptos clave aplicados

### 1. Promediado como filtrado

Para reducir el **ruido de alta frecuencia** e interferencias en la señal EMG, se realiza un **promediado de 32 muestras** consecutivas:

```cpp
for (int i = 0; i < 32; i++) {
  sum += analogRead(pin);
}
```

Esto actúa como un **filtro digital de paso bajo simple**, suavizando la señal sin perder la información relevante sobre la contracción.

### 2. Calibración del valor en reposo

Durante el arranque, el sistema realiza una fase de **calibración automática** leyendo la señal del EMG en estado de reposo muscular. Esto permite establecer un **nivel base personalizado**, adaptado a cada usuario:

```cpp
static_analog_dta = sum / 1100;
```

Esto mejora la precisión de sistemas posteriores de detección de contracción.

### 3. Muestreo temporal

El sistema toma lecturas cada **10 ms**, lo que equivale a una **frecuencia de muestreo de 100 Hz**. Esto es adecuado para señales EMG, que generalmente tienen componentes útiles hasta 150–400 Hz. Se evita el aliasing y se permite una representación en tiempo real.

---

## 💻 Código del ejemplo

Consulta el archivo: `emg-calibrated-plot.ino`

Este programa:
- Promedia lecturas para filtrar ruido.
- Calcula el valor de referencia en reposo.
- Imprime valores **EMG**, **Reposo** y **Delta** separados por tabulaciones para graficarlos en el **Serial Plotter**.

---

## 📈 Visualización

- Utiliza el **Serial Plotter** de Arduino IDE (velocidad: 115200 baudios).
- Podrás visualizar tres curvas:
  - **EMG**: señal cruda (filtrada)
  - **Reposo**: línea base
  - **Delta**: diferencia respecto al reposo (indicador de activación)

---

## 📎 Requisitos

- Sensor **EMG MyoWare**
- 3 electrodos adhesivos de gel
- Arduino UNO o compatible
- Protoboard y cables
- Alcohol isopropílico para limpieza de piel
- Arduino IDE 1.8.x o 2.x

---

## 📈 Aplicaciones biomédicas

- **Prótesis mioeléctricas**
- **Interfaces musculares** para control de dispositivos
- **Monitoreo de actividad en rehabilitación muscular**
- **Sistemas de entrenamiento con biofeedback**

---

## 🧑‍🏫 Créditos

Este ejemplo fue desarrollado para el curso **Fundamentos de Biodiseño**  
Docentes: **Renzo Chan Ríos** / **Lewis De La Cruz**  
Universidad Peruana Cayetano Heredia (UPCH) — 2025  
Versión: 0.2 (intermedio)

---
