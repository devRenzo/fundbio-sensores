/*
 ============================================================================
 Título      : Lectura básica del sensor EMG MyoWare con Arduino
 Descripción : Este código permite leer la señal analógica generada por el 
               sensor EMG MyoWare, que detecta la actividad eléctrica del 
               músculo esquelético durante contracción. Los valores se 
               muestran en el monitor serial para su análisis.
 ----------------------------------------------------------------------------
 Docente     : Renzo Chan Ríos / Lewis De La Cruz
 Curso       : Fundamentos de Biodiseño
 Universidad : Universidad Peruana Cayetano Heredia (UPCH)
 Año         : 2025
 Versión     : 0.1
 ============================================================================
*/

// Pin analógico donde se conecta la salida del sensor EMG
const int emgPin = A0;

void setup() {
  // Inicializa la comunicación serial a 9600 baudios.
  // Esto permite observar los valores leídos en el monitor serial del IDE.
  Serial.begin(9600);
}

void loop() {
  // Lee el valor analógico de la señal EMG (rango 0 a 1023)
  int emgValue = analogRead(emgPin);

  // Muestra el valor leído en el monitor serial.
  // A mayor contracción muscular, mayor será el valor observado.
  Serial.print("EMG Value: ");
  Serial.println(emgValue);

  // Retardo breve para estabilizar la visualización
  delay(100);
}

