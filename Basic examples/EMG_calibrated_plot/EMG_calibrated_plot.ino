/*
 ============================================================================
 Título      : Lectura EMG con calibración en reposo y visualización gráfica
 Descripción : Este código permite leer la señal del sensor EMG MyoWare, 
               filtrar la señal con promediado, calcular un nivel de reposo
               automático y visualizar las curvas en el Serial Plotter.
 ----------------------------------------------------------------------------
 Docente     : Renzo Chan Ríos / Lewis De La Cruz
 Curso       : Fundamentos de Biodiseño
 Universidad : Universidad Peruana Cayetano Heredia (UPCH)
 Año         : 2025
 Versión     : 0.2 (Intermedio)
 ============================================================================
*/

// Variables globales para registrar el comportamiento de la señal EMG
int max_analog_dta      = 500;    // Valor máximo estimado (se ajusta dinámicamente)
int min_analog_dta      = 100;    // Valor mínimo estimado
int static_analog_dta   = 0;      // Valor en reposo (calculado en la fase de calibración)

/*
 * Función: getAnalog()
 * Objetivo: Obtener una lectura más estable del sensor EMG promediando múltiples muestras.
 * Método: Se promedian 32 lecturas consecutivas para reducir el ruido de alta frecuencia.
 */
int getAnalog(int pin) {
  long sum = 0;
  for (int i = 0; i < 32; i++) {
    sum += analogRead(pin);  // Lee valor analógico (0–1023) desde el pin especificado
  }

  int dta = sum >> 5;  // División por 32 usando desplazamiento de bits (más eficiente)

  // Se actualizan los máximos y mínimos detectados en tiempo real
  max_analog_dta = (dta > max_analog_dta) ? dta : max_analog_dta;
  min_analog_dta = (dta < min_analog_dta) ? dta : min_analog_dta;

  return dta;
}

void setup() {
  Serial.begin(115200);
  long sum = 0;

  // === CALIBRACIÓN: Determinar el valor promedio en reposo ===
  Serial.println("Iniciando calibración... No contraigas el músculo.");
  
  for (int i = 0; i <= 10; i++) {
    for (int j = 0; j < 100; j++) {
      sum += getAnalog(A0);
      delay(1);
    }
  }

  static_analog_dta = sum / 1100;

  Serial.println("Calibración completa.");
  Serial.print("Valor de reposo estimado: ");
  Serial.println(static_analog_dta);

  delay(1000);
}

void loop() {
  int val = getAnalog(A0);
  int delta = val - static_analog_dta;

  // === Formato nuevo para Serial Plotter: label:value separados por espacio ===
  Serial.print("EMG:");
  Serial.print(val);
  Serial.print(" Reposo:");
  Serial.print(static_analog_dta);
  Serial.print(" Delta:");
  Serial.println(delta);

  delay(10); // ~100 Hz
}
