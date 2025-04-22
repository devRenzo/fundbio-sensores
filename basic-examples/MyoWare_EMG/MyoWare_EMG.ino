/*
  Myoware Muscle Sensor Test
  myoware-test.ino
  Demo of Myoware Muscle Sensor
  Output to Serial Monitor
  Use battery-powered computer or USB isolator for safety!
  DroneBot Workshop 2021
  https://dronebotworkshop.com
*/

// Connection to Myoware sensor
#define SENSOR_PIN 0

// Integer for sensor value
int sensorValue;


void setup() {
  
  // Set up serial port
  Serial.begin(9600);

}

void loop() {
 
  // Read sensor value
  sensorValue = analogRead(SENSOR_PIN);
  
  // Print value to Serial Monitor
  Serial.println(sensorValue);
}
