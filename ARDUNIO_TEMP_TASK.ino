// Pin definitions
const int tempPin = A0;      // Analog pin for LM35 (temperature sensor)
const int ledPin = 13;       // Pin for LED
const int buzzerPin = 12;    // Pin for Buzzer

// Threshold temperature
const float thresholdTemp = 50.0;

void setup() {
  // Initialize the LED and Buzzer as outputs
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Start serial communication for debugging (optional)
  Serial.begin(9600);
}

void loop() {
  // Read the analog temperature value from the LM35 sensor
  int sensorValue = analogRead(tempPin);
  
  // Convert the sensor value to temperature (LM35 gives 10mV per °C)
  // Since the ATmega328P ADC has 10-bit resolution (0-1023), we calculate the temperature
  float voltage = sensorValue * (5.0 / 1023.0);  // Convert ADC value to voltage
  float temperatureC = voltage * 100.0;  // LM35 gives 10mV per degree Celsius
  
  // Print temperature to serial monitor for debugging (optional)
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  // Check if temperature exceeds the threshold
  if (temperatureC > thresholdTemp) {
    // Turn on LED and Buzzer if temperature exceeds threshold
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    // Otherwise, turn them off
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  // Add a delay to avoid flooding serial output and debounce the system
  delay(500);  // Delay in milliseconds (500ms)
}
