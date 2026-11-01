
/*
 * Obstacle Avoider Robot - Project 2
 * by mkuuCodes | Eldoret, KE
 * Hardware: Arduino Uno, HC-SR04, L298N, 2x DC Motors
 */

// Pins for HC-SR04
#define TRIG_PIN 9
#define ECHO_PIN 10
// Pins for L298N
#define ENA 5
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 11
#define ENB 3

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  // Speed 150/255
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void loop() {
  distance = getDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 20) {
    moveForward();
  } else {
    stopRobot();
    delay(300);
    moveBackward();
    delay(400);
    turnRight();
    delay(500);
  }
}

int getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

void moveForward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}
void moveBackward() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}
void turnRight() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}
void stopRobot() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}
