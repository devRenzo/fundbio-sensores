#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

const int windowSize = 10;  // Tamaño del filtro de promedio móvil
int axBuffer[windowSize];
int ayBuffer[windowSize];
int azBuffer[windowSize];
int index = 0;
bool bufferFilled = false;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("Error: No se detectó el MPU6050");
    while (1);
  }

  Serial.println("MPU6050 inicializado correctamente");
}

void loop() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  // Guardar valores crudos en los buffers
  axBuffer[index] = ax;
  ayBuffer[index] = ay;
  azBuffer[index] = az;

  index++;
  if (index >= windowSize) {
    index = 0;
    bufferFilled = true;
  }

  // Calcular promedio sólo si el buffer está lleno
  int avgAx = 0, avgAy = 0, avgAz = 0;
  int samples = bufferFilled ? windowSize : index;

  for (int i = 0; i < samples; i++) {
    avgAx += axBuffer[i];
    avgAy += ayBuffer[i];
    avgAz += azBuffer[i];
  }

  avgAx /= samples;
  avgAy /= samples;
  avgAz /= samples;

  // Imprimir valores en el Serial Plotter
  Serial.print("AX: ");
  Serial.print(ax);
  Serial.print("\tAX_filtro: ");
  Serial.print(avgAx);

  Serial.print("\tAY: ");
  Serial.print(ay);
  Serial.print("\tAY_filtro: ");
  Serial.print(avgAy);

  Serial.print("\tAZ: ");
  Serial.print(az);
  Serial.print("\tAZ_filtro: ");
  Serial.println(avgAz);

  delay(10);  // ~100 Hz
}
