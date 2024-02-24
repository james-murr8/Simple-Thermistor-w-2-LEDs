
int thermaPin = A0;
int ledPin1 = 4; 
int ledPin2 = 5; 

void setup() {
  
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

}

void loop() {

  int thermaReading = analogRead(thermaPin);
  Serial.println(thermaReading);

  double tempK = log(10000.0 * ((1024.0/thermaReading-1)));
  tempK = 1/(0.001129148+(0.000234125+(0.0000000876741*tempK*tempK))*tempK);
  float tempC = tempK -273.15;
  float tempF = (tempC*9.0)/5.0+32.0;

  if (tempC < -75) {
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin1, LOW);
  }
  else{ 
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
    }

Serial.print("Degrees in Celcius(C) =  ");
Serial.println(tempC);

Serial.print("Degrees in Farenheitf(F) = ");
Serial.println(tempF);

delay(1000);
}
