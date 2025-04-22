/*
 ============================================================================
 Título      : EMG Gesture Control con filtro de ventana móvil
 Descripción : Enciende un LED si se detecta contracción muscular. Utiliza 
               un filtro de media móvil de 10 lecturas para mayor estabilidad.
 ----------------------------------------------------------------------------
 Docente     : Renzo Chan Ríos / Lewis De La Cruz
 Curso       : Fundamentos de Biodiseño
 Universidad : Universidad Peruana Cayetano Heredia (UPCH)
 Año         : 2025
 Versión     : 0.3
 ============================================================================
*/

const int emgPin = A0;
const int ledPin = 13;
const int threshold = 550;

// Filtro de ventana móvil para estabilizar la señal
const int windowSize = 10;
int readings[windowSize];
int index = 0;
long total = 0;

int readMovingAverage(int pin) {
  total -= readings[index];
  readings[index] = analogRead(pin);
  total += readings[index];
  index = (index + 1) % windowSize;
  return total / windowSize;
}


void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  for (int i = 0; i < windowSize; i++) {
    readings[i] = 0;
  }
}

void loop() {
  int emgValue = readMovingAverage(emgPin);
  Serial.print("EMG filtrado: ");
  Serial.println(emgValue);
  digitalWrite(ledPin, emgValue > threshold ? HIGH : LOW);
  delay(50);
}
