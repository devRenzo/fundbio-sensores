# 💪 EMG Gesture Control con Arduino

Este proyecto permite activar un LED (u otro actuador) mediante la contracción muscular detectada con el **sensor EMG MyoWare**. Es una introducción práctica al uso de señales biológicas como entrada para control de dispositivos.

---

## 🧠 Objetivo

Detectar una contracción muscular y traducirla en una acción digital simple (encender un LED) utilizando un umbral de activación.

---

## 🔬 Principio de funcionamiento

- El sensor EMG mide la señal eléctrica del músculo.
- Cuando el valor supera un **umbral** predefinido, se considera una contracción muscular.
- La señal se adquiere por el pin A0 del Arduino.
- Un LED conectado al pin 13 se activa si el músculo se contrae.

---

## 📎 Requisitos

- Sensor **EMG MyoWare**
- 3 electrodos autoadhesivos
- Arduino UNO o compatible
- LED, resistencia 220Ω
- Protoboard y cables

---

## 📈 Aplicaciones

- Control de prótesis
- Interfaces activadas por músculo
- Ejercicios de rehabilitación con feedback

---

## 🧑‍🏫 Créditos

Docentes: Renzo Chan Ríos / Lewis De La Cruz  
Curso: Fundamentos de Biodiseño  
UPCH – 2025
