/*
 ============================================================================
 Título      : Lectura básica de sensor de flexión con Arduino
 Descripción : Este código permite leer la señal analógica generada por un 
               sensor flexible (Flex Sensor) al ser doblado. La lectura se 
               muestra en el monitor serial y representa la variación de 
               resistencia según el ángulo de flexión.
 ----------------------------------------------------------------------------
 Docente     : Renzo Chan Ríos / Lewis De La Cruz
 Curso       : Fundamentos de Biodiseño
 Universidad : Universidad Peruana Cayetano Heredia (UPCH)
 Año         : 2025
 Versión     : 0.1
 ============================================================================
*/

// Se define el pin analógico al que se conecta el sensor.
// El Flex Sensor se conecta en un divisor de voltaje junto con una resistencia fija.
// El voltaje de salida de ese divisor se mide en el pin A0.
const int flexPin = A0;

void setup() {
  // Se inicia la comunicación serial a 9600 baudios.
  // Esta comunicación permite enviar datos desde el Arduino a la computadora
  // y observarlos en el monitor serial del IDE.
  Serial.begin(9600);
}

void loop() {
  // Se lee el valor analógico del pin A0.
  // La función analogRead() convierte el voltaje (0V a 5V) en un valor entre 0 y 1023.
  // Este valor está relacionado con la resistencia del Flex Sensor, que cambia al doblarse.
  int flexValue = analogRead(flexPin);

  // Se imprime en el monitor serial el valor leído.
  // A mayor flexión, mayor resistencia -> menor voltaje -> menor valor leído.
  Serial.print("Flex Sensor Value: ");
  Serial.println(flexValue);

  // Se incluye un retardo de 200 milisegundos para que la lectura no sea muy rápida,
  // facilitando su visualización en tiempo real y reduciendo el "ruido" visual en los datos.
  delay(200);
}
