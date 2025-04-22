/*
 ============================================================================
 Título      : Flex Glove Dual con promedio simple
 Descripción : Este programa usa dos sensores Flex para controlar dos LEDs 
               según el promedio de varias lecturas. Esto suaviza los datos 
               y hace que el brillo del LED sea más estable.
 ----------------------------------------------------------------------------
 Docente     : Renzo Chan Ríos / Lewis De La Cruz
 Curso       : Fundamentos de Biodiseño
 Universidad : Universidad Peruana Cayetano Heredia (UPCH)
 Año         : 2025
 Versión     : 0.6
 ============================================================================
*/

// Pines donde se conectan los sensores Flex
const int flex1 = A0;
const int flex2 = A1;

// Pines PWM donde se conectan los LEDs
const int ledVerde = 9;
const int ledRojo = 10;

// Número de muestras para calcular el promedio
const int muestras = 10;

/*
 * Función: leerPromedio
 * Lee 'muestras' veces un pin analógico y devuelve el promedio.
 * Se utiliza para filtrar el ruido y mejorar la estabilidad del valor leído.
 * Se añade un pequeño retardo entre lecturas para estabilizar el ADC.
 */
int leerPromedio(int pin) {
  long suma = 0;
  for (int i = 0; i < muestras; i++) {
    suma += analogRead(pin);       // Leer el valor del sensor
    delayMicroseconds(10);         // Pequeña pausa para estabilidad del ADC
  }
  return suma / muestras;          // Retorna el promedio
}

void setup() {
  // Se definen los pines de salida para los LEDs
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);

  // Inicializa el monitor serial para ver los datos
  Serial.begin(9600);
}

void loop() {
  // Leer el promedio de ambos sensores
  int valor1 = leerPromedio(flex1);  // Flexión del primer dedo
  delayMicroseconds(50);             // Pausa entre sensores (opcional)
  int valor2 = leerPromedio(flex2);  // Flexión del segundo dedo

  // Convertir los valores leídos a un rango de brillo (PWM)
  int brilloVerde = map(valor1, 400, 800, 0, 255);
  int brilloRojo  = map(valor2, 400, 800, 0, 255);

  // Limitar los valores a entre 0 y 255 por seguridad
  brilloVerde = constrain(brilloVerde, 0, 255);
  brilloRojo  = constrain(brilloRojo, 0, 255);

  // Enviar el valor al LED (control de brillo proporcional)
  analogWrite(ledVerde, brilloVerde);
  analogWrite(ledRojo, brilloRojo);

  // Mostrar los valores en el monitor serial
  Serial.print("Flex1: ");
  Serial.print(valor1);
  Serial.print(" -> LED Verde: ");
  Serial.print(brilloVerde);

  Serial.print("    Flex2: ");
  Serial.print(valor2);
  Serial.print(" -> LED Rojo: ");
  Serial.println(brilloRojo);

  delay(100);  // Pausa general entre ciclos de lectura
}
