/*
 ============================================================================
 Título      : Alerta de presión con sensor FSR
 Descripción : Este programa activa una alerta (LED o buzzer) si se detecta 
               una presión mayor a un umbral determinado, usando un sensor FSR.
 ----------------------------------------------------------------------------
 Docente     : Renzo Chan Ríos / Lewis De La Cruz
 Curso       : Fundamentos de Biodiseño
 Universidad : Universidad Peruana Cayetano Heredia (UPCH)
 Año         : 2025
 Versión     : 0.1
 ============================================================================
*/

const int fsrPin = A0;      // Pin conectado al sensor FSR
const int ledPin = 13;      // LED o buzzer conectado
const int threshold = 600;  // Umbral de presión

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int fsrValue = analogRead(fsrPin);

  Serial.print("FSR: ");
  Serial.println(fsrValue);

  if (fsrValue > threshold) {
    digitalWrite(ledPin, HIGH);  // Presión excede el umbral
  } else {
    digitalWrite(ledPin, LOW);   // Presión normal
  }

  delay(50);
}
