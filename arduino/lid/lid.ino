#define pinUltrasoundTrig 8
#define pinUltrasoundEcho 7
#define pinFlame A0

long duration, distance;

void setup() {
  Serial.begin(57600);
  pinMode(pinUltrasoundTrig, OUTPUT);
  pinMode(pinUltrasoundEcho, INPUT);

  delay(5);
}

void loop() {
  // Trigger the ultrasound sensor
  digitalWrite(pinUltrasoundTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinUltrasoundTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinUltrasoundTrig, LOW);

  // Wait for signal from sensor
  duration = pulseIn(pinUltrasoundEcho, HIGH, 100000);

  // Calculate distance in centimeters
  // The speed of sound is in cm/us at 25 C
  float speedOfSound = 0.0346;
  distance = duration * speedOfSound / 2;

  Serial.print("distance:");
  Serial.println(distance);


  int flameReading = analogRead(pinFlame);
  Serial.print("flame:");
  Serial.println(flameReading);

  delay(10);
}
