#define SOIL_SENSOR_PIN A0

#define IN3 D2
#define IN4 D3
#define ENB D1

#define WET_THRESHOLD 500  // Below this = WET → motor ON

int soilValue = 0;

void setup() {
  Serial.begin(115200);
  
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  stopMotor();
  
  Serial.println("Soil Moisture Monitor Started");
  delay(1000);
}

void loop() {
  soilValue = analogRead(SOIL_SENSOR_PIN);
  
  int moisturePercent = map(soilValue, 1023, 0, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);

  // Single condition
  if (soilValue < WET_THRESHOLD) {
    runMotor();
    Serial.println("---------------------------");
    Serial.print("Raw Value  : "); Serial.println(soilValue);
    Serial.print("Moisture   : "); Serial.print(moisturePercent); Serial.println("%");
    Serial.println("Status     : WET");
    Serial.println("Motor      : RUNNING");
    Serial.println("---------------------------");
  } else {
    stopMotor();
    Serial.println("---------------------------");
    Serial.print("Raw Value  : "); Serial.println(soilValue);
    Serial.print("Moisture   : "); Serial.print(moisturePercent); Serial.println("%");
    Serial.println("Status     : DRY");
    Serial.println("Motor      : STOPPED");
    Serial.println("---------------------------");
  }

  delay(2000);
}

void runMotor() {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 200);
}

void stopMotor() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}