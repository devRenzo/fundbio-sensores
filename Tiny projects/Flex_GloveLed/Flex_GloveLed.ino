/*
 ============================================================================
 Título      : Flex Glove con LED indicador
 Descripción : Enciende un LED cuando el dedo se flexiona más allá de un 
               cierto ángulo, usando un Flex Sensor. Puede representar control 
               gestual o biofeedback visual en aplicaciones de rehabilitación.
 ----------------------------------------------------------------------------
 Docente     : Renzo Chan Ríos / Lewis De La Cruz
 Curso       : Fundamentos de Biodiseño
 Universidad : Universidad Peruana Cayetano Heredia (UPCH)
 Año         : 2025
 Versión     : 0.1
 ============================================================================
*/

const int flexPin = A0;     // Pin donde está conectado el sensor flex
const int ledPin = 13;      // LED para indicar flexión detectada
const int threshold = 500;  // Umbral de flexión (ajustable por pruebas)

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int flexValue = analogRead(flexPin);

  Serial.print("Flex: ");
  Serial.println(flexValue);

  if (flexValue > threshold) {
    digitalWrite(ledPin, HIGH);  // Flexión detectada
  } else {
    digitalWrite(ledPin, LOW);   // Sin flexión significativa
  }

  delay(50);
}
