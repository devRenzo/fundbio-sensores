/*
 ============================================================================
 Título      : Lectura básica de sensor de flexión con Arduino
 Descripción : Este código permite leer la señal analógica generada por un 
               sensor flexible (Flex Sensor) al ser doblado. La lectura se 
               muestra en el monitor serial y representa la variación de 
               resistencia según el ángulo de flexión.
 ----------------------------------------------------------------------------
 Docente     : Renzo Chan Rios
 Curso       : Fundamentos de Biodiseño
 Universidad : Universidad Peruana Cayetano Heredia (UPCH)
 Año         : 2025
 Versión     : 0.1
 ============================================================================
*/

// Definir el pin analógico donde está conectado el Flex Sensor
const int flexPin = A0;

void setup() {
  // Inicia la comunicación serial para visualizar los datos en el monitor serial
  Serial.begin(9600);
}

void loop() {
  // Leer el valor analógico (rango de 0 a 1023) del Flex Sensor
  int flexValue = analogRead(flexPin);

  // Mostrar el valor leído en el monitor serial
  Serial.print("Flex Sensor Value: ");
  Serial.println(flexValue);

  // Pequeño retardo para estabilizar la lectura
  delay(200);
}
