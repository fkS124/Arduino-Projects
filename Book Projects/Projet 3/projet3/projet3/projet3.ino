const int sensorPin = A0;
const float baselineTemp = 20.0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);

  Serial.print("Valeur capteur:");
  Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0) * 5.0;

  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degres C :");

  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);


  int val1 = LOW;
  int val2 = LOW;
  int val3 = LOW;
   
  if (temperature < baselineTemp) {
    val1 = LOW;
  } else if (temperature >= baselineTemp+2 && temperature < baselineTemp+4) {
    val1 = HIGH;
  } else if (temperature >= baselineTemp+4 && temperature < baselineTemp+6) {
    val1 = HIGH;
    val2 = HIGH;
  } else if (temperature >= baselineTemp+6) {
    val1 = HIGH;
    val2 = HIGH;
    val3 = HIGH;
  }
   
   digitalWrite(2, val1);
   digitalWrite(3, val2);
   digitalWrite(4, val3);

   delay(1);
  
}
