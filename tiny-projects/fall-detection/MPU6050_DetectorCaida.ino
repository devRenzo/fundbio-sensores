#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

unsigned long lastFallTime = 0;
bool fallDetected = false;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 no conectado");
    while (1);
  }

  Serial.println("MPU6050 conectado correctamente");
}

void loop() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  // Convertir a g (9.81 m/s^2) usando sensibilidad del sensor (LSB/g = 16384)
  float ax_g = ax / 16384.0;
  float ay_g = ay / 16384.0;
  float az_g = az / 16384.0;

  // Magnitud total de la aceleración
  float a_total = sqrt(ax_g * ax_g + ay_g * ay_g + az_g * az_g);

  // Enviar al Serial Plotter
  Serial.print("Aceleracion_g: ");
  Serial.print(a_total);
  Serial.print("\tEstado: ");
  Serial.println(fallDetected ? "CAIDA" : "NORMAL");

  // Detección de pico de aceleración
  if (a_total > 2.0) {
    lastFallTime = millis();
    fallDetected = true;
  }

  // Verificar si se mantiene en quietud después del pico
  if (fallDetected && (millis() - lastFallTime > 500)) {
    if (a_total < 0.4) {
      Serial.println(">>> ¡CAÍDA DETECTADA! <<<");
      // Aquí podrías activar un buzzer, LED o enviar un SMS/Bluetooth
    }
    fallDetected = false;  // Reiniciar el estado
  }

  delay(100);  // 10 Hz
}
