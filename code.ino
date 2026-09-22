#define SOIL_PIN A0

#define GREEN_LED D5
#define RED_LED D6

#define MOISTURE_THRESHOLD 512

void setup() {
  Serial.begin(115200);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
}

void loop() {

  int soilValue = analogRead(SOIL_PIN);

  Serial.print("Soil Value: ");
  Serial.print(soilValue);

  if (soilValue > MOISTURE_THRESHOLD) {
    // Water low / Soil dry
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);

    Serial.println(" | WATER LOW");
  }
  else {
    // Water sufficient / Soil wet
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    Serial.println(" | WATER OK");
  }

  delay(1000);
}
