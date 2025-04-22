// Grove - EMG Sensor demo adaptado para Serial Plotter
// Sensor EMG conectado a A0

int max_analog_dta      = 500;    // Valor máximo inicial estimado
int min_analog_dta      = 100;    // Valor mínimo inicial estimado
int static_analog_dta   = 0;      // Valor en reposo determinado por calibración

// Promedia 32 lecturas para reducir ruido
int getAnalog(int pin)
{
    long sum = 0;
    for (int i = 0; i < 32; i++)
    {
        sum += analogRead(pin);
    }
    int dta = sum >> 5;  // equivalente a dividir por 32

    // Actualización dinámica de máximos y mínimos
    max_analog_dta = (dta > max_analog_dta) ? dta : max_analog_dta;
    min_analog_dta = (dta < min_analog_dta) ? dta : min_analog_dta;

    return dta;
}

void setup()
{
    Serial.begin(115200);
    long sum = 0;

    // Fase de calibración: músculo en reposo
    for (int i = 0; i <= 10; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            sum += getAnalog(A0);
            delay(1);
        }
    }

    static_analog_dta = sum / 1100;  // promedio total

    Serial.println("Calibración completa");
    Serial.print("Valor estático: ");
    Serial.println(static_analog_dta);

    delay(1000);
}

void loop()
{
    int val = getAnalog(A0);  // lectura filtrada

    // Opcional: calcular desviación del valor en reposo
    int delta = val - static_analog_dta;

    // Enviar datos al Serial Plotter
    // Separa con TAB para que aparezcan varias curvas en el gráfico
    Serial.print("EMG: ");
    Serial.print(val);
    Serial.print("\tReposo: ");
    Serial.println(static_analog_dta);
//    Serial.print("\tDelta: ");
//    Serial.println(delta);

    delay(10);  // control de frecuencia de muestreo (~100 Hz)
}
