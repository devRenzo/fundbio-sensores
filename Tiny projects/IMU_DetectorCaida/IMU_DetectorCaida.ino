/*
 ============================================================================
 Título      : Detección de caídas con IMU MPU6050 y Arduino
 Descripción : Este código mide la aceleración en 3 ejes usando el sensor 
               MPU6050 y calcula la magnitud total. Detecta posibles caídas 
               a partir de picos de aceleración seguidos de quietud, y envía 
               el estado al monitor serial para su visualización.
 ----------------------------------------------------------------------------
 Docente     : Renzo Chan Ríos / Lewis De La Cruz
 Curso       : Fundamentos de Biodiseño
 Universidad : Universidad Peruana Cayetano Heredia (UPCH)
 Año         : 2025
 Versión     : 0.1
 ============================================================================
*/

#include <Wire.h>
#include <MPU6050.h>  // Librería para el sensor IMU MPU6050

MPU6050 mpu;  // Objeto del sensor

unsigned long lastFallTime = 0;  // Marca temporal del último pico
bool fallDetected = false;       // Estado del evento de caída

void setup() {
  Serial.begin(115200);  // Velocidad adecuada para Serial Plotter
  Wire.begin();           // Inicializa la comunicación I2C

  mpu.initialize();       // Inicializa el MPU6050
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 no conectado");
    while (1);  // Detiene el programa si el sensor falla
  }

  Serial.println("MPU6050 conectado correctamente");
}

void loop() {
  int16_t ax, ay, az;

  // Lectura de aceleración en los tres ejes (valores crudos de 16 bits)
  mpu.getAcceleration(&ax, &ay, &az);

  // Conversión a unidades de gravedad (g)
  // El MPU6050 entrega 16384 LSB por cada g
  float ax_g = ax / 16384.0;
  float ay_g = ay / 16384.0;
  float az_g = az / 16384.0;

  // Cálculo de la magnitud total del vector aceleración (teorema de Pitágoras)
  float a_total = sqrt(ax_g * ax_g + ay_g * ay_g + az_g * az_g);

  // Enviar datos al Serial Plotter para análisis visual
  Serial.print("Aceleracion_g: ");
  Serial.print(a_total);
  Serial.print("\tEstado: ");
  Serial.println(fallDetected ? "CAIDA" : "NORMAL");

  // Detección de pico de aceleración (por ejemplo, una caída o golpe)
  if (a_total > 2.0) {  // Umbral configurable
    lastFallTime = millis();  // Guarda el tiempo del pico
    fallDetected = true;
  }

  // Verifica si luego del pico hay un estado de quietud prolongada
  if (fallDetected && (millis() - lastFallTime > 500)) {
    if (a_total < 0.4) {
      Serial.println(">>> ¡CAÍDA DETECTADA! <<<");
      // Aquí se podría agregar: buzzer, LED, comunicación por Bluetooth, etc.
    }
    fallDetected = false;  // Reinicia el estado de caída
  }

  delay(100);  // Controla la frecuencia de muestreo (10 Hz)
}

