/* by Joshua Liu
 *  ideahacks 2021
 *  some code for distance sensor from https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
 */ 
// distance sensor
const int trigPin = A0;
const int echoPin = A1;
long duration;
int distance;
//buzzer
const int buzzer = 11;
//led's
const int redled = 9;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(redled, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;

  //conditionals
  if (distance > 9) {
    tone(buzzer, 11000);
    digitalWrite(redled, HIGH);
    delay(50);
    digitalWrite(redled, LOW);
    delay(50);
  }

  if (distance <= 9) {
    noTone(buzzer);
    digitalWrite(redled, LOW);
  }
  Serial.print(distance);
  
}
