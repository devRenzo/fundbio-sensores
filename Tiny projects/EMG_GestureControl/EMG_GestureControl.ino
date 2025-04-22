/*
 ============================================================================
 Título      : EMG Gesture Control con LED
 Descripción : Este código enciende un LED si se detecta una contracción 
               muscular fuerte usando el sensor EMG MyoWare. Utiliza un umbral 
               configurable para determinar el nivel de activación muscular.
 ----------------------------------------------------------------------------
 Docente     : Renzo Chan Ríos / Lewis De La Cruz
 Curso       : Fundamentos de Biodiseño
 Universidad : Universidad Peruana Cayetano Heredia (UPCH)
 Año         : 2025
 Versión     : 0.1
 ============================================================================
*/

const int emgPin = A0;      // Pin de entrada del sensor EMG
const int ledPin = 13;      // Pin de salida para LED indicador
const int threshold = 550;  // Umbral de activación (ajustable)

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int emgValue = analogRead(emgPin);

  // Mostrar la señal en el monitor serial
  Serial.print("EMG: ");
  Serial.println(emgValue);

  // Activar LED si se supera el umbral
  if (emgValue > threshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(50);  // Pequeño retardo para suavizar visualización
}
