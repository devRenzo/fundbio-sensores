/*
 ============================================================================
 Título      : Alerta de presión con doble sensor FSR
 Descripción : Este programa utiliza dos sensores FSR para detectar si se ha
               ejercido presión por encima de un umbral en cualquiera de ellos.
               Si se detecta presión alta, se enciende un LED de alerta.
 ----------------------------------------------------------------------------
 Docente     : Renzo Chan Ríos / Lewis De La Cruz
 Curso       : Fundamentos de Biodiseño
 Universidad : Universidad Peruana Cayetano Heredia (UPCH)
 Año         : 2025
 Versión     : 0.4
 ============================================================================
*/

const int fsr1Pin = A0;       // Primer sensor FSR
const int fsr2Pin = A1;       // Segundo sensor FSR
const int ledPin = 9;         // LED de alerta
const int umbral = 600;       // Valor de presión a partir del cual se activa la alerta

const int muestras = 10;      // Número de lecturas para promedio

// Función para calcular promedio simple
int leerPromedio(int pin) {
  long suma = 0;
  for (int i = 0; i < muestras; i++) {
    suma += analogRead(pin);
    delayMicroseconds(10);  // Estabiliza lectura ADC
  }
  return suma / muestras;
}

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int valorFSR1 = leerPromedio(fsr1Pin);
  int valorFSR2 = leerPromedio(fsr2Pin);

  // Enciende LED si uno de los sensores supera el umbral
  if (valorFSR1 > umbral || valorFSR2 > umbral) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  // Imprimir valores en monitor serial
  Serial.print("FSR1: ");
  Serial.print(valorFSR1);
  Serial.print("   FSR2: ");
  Serial.print(valorFSR2);
  Serial.print("   Estado: ");
  Serial.println((valorFSR1 > umbral || valorFSR2 > umbral) ? "ALTA PRESIÓN" : "NORMAL");

  delay(100);
}
