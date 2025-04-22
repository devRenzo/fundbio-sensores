/*
 ============================================================================
 Título      : Lectura básica de sensor FSR con Arduino
 Descripción : Este código permite leer la señal analógica generada por un 
               sensor de fuerza resistivo (FSR) cuando se aplica presión. 
               El valor se visualiza en el monitor serial para análisis.
 ----------------------------------------------------------------------------
 Docente     : Renzo Chan Ríos / Lewis De La Cruz
 Curso       : Fundamentos de Biodiseño
 Universidad : Universidad Peruana Cayetano Heredia (UPCH)
 Año         : 2025
 Versión     : 0.1
 ============================================================================
*/

// Se define el pin analógico al que está conectado el FSR
const int fsrPin = A0;  // A0 es uno de los pines de entrada analógica del Arduino

void setup() {
  // Se inicia la comunicación serial a 9600 baudios.
  // Esto permite enviar datos desde el Arduino al computador
  // para visualizarlos en el monitor serial.
  Serial.begin(9600);
}

void loop() {
  // Se lee el valor analógico en el pin A0.
  // El valor puede estar entre 0 (sin presión) y 1023 (máxima presión).
  int fsrValue = analogRead(fsrPin);

  // Se imprime el valor leído en el monitor serial.
  // Esto permite observar en tiempo real cómo cambia el valor
  // al aplicar diferente cantidad de presión sobre el sensor.
  Serial.print("FSR Value: ");
  Serial.println(fsrValue);

  // Se agrega un retardo de 200 milisegundos para que la lectura
  // sea más estable y legible en pantalla.
  delay(200);
}
