/*
 ============================================================================
 Título      : Lectura básica de acelerómetro y giroscopio con MPU6050
 Descripción : Este programa obtiene valores crudos (RAW) del acelerómetro y
               giroscopio integrados en el sensor MPU6050, usando la librería 
               I2Cdev. Los datos se muestran en el monitor serial en formato 
               tabulado para ser visualizados fácilmente con Serial Plotter.
 ----------------------------------------------------------------------------
 Docente     : Renzo Chan Ríos / Lewis De La Cruz
 Curso       : Fundamentos de Biodiseño
 Universidad : Universidad Peruana Cayetano Heredia (UPCH)
 Año         : 2025
 Versión     : 0.1
 ============================================================================
*/

// Librerías para comunicación I2C y control del MPU6050
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

// Crear objeto del sensor (por defecto en dirección 0x68)
MPU6050 sensor;

// Variables para almacenar lecturas del acelerómetro y giroscopio
int ax, ay, az;  // Aceleraciones en los ejes X, Y, Z
int gx, gy, gz;  // Velocidades angulares en los ejes X, Y, Z

void setup() {
  Serial.begin(57600);     // Inicializa el puerto serie
  Wire.begin();            // Inicializa el bus I2C
  sensor.initialize();     // Inicializa el sensor MPU6050

  // Verifica si el sensor está conectado correctamente
  if (sensor.testConnection())
    Serial.println("Sensor iniciado correctamente");
  else
    Serial.println("Error al iniciar el sensor");
}

void loop() {
  // Leer datos crudos del acelerómetro y giroscopio
  sensor.getAcceleration(&ax, &ay, &az);
  sensor.getRotation(&gx, &gy, &gz);

  // Mostrar valores separados por tabulaciones para el Serial Plotter
  Serial.print("a[x y z] g[x y z]:	");
  Serial.print(ax); Serial.print("\t");
  Serial.print(ay); Serial.print("\t");
  Serial.print(az); Serial.print("\t");
  Serial.print(gx); Serial.print("\t");
  Serial.print(gy); Serial.print("\t");
  Serial.println(gz);

  delay(100);  // Control de frecuencia de muestreo (~10 Hz)
}
