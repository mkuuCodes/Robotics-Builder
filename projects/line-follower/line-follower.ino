cpp
/*
  Line Follower Robot - by mkuuCodes | Eldoret, KE
  2x IR Sensors + L298N + Arduino Uno
  Affordable build - 2026
*/

// IR Sensors
#define LEFT_SENSOR A0
#define RIGHT_SENSOR A1

// L298N Motor Driver
#define ENA 9
#define IN1 8
#define IN2 7
#define IN3 6
#define IN4 5
#define ENB 3

void setup() {
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("mkuuCodes Line Follower Ready!");
}

void loop() {
  int left = digitalRead(LEFT_SENSOR);
  int right = digitalRead(RIGHT_SENSOR);

  // Both sensors on black line -> Go Forward
  if (left == 0 && right == 0) {
    forward();
  }
  // Left out -> Turn Right
  else if (left == 1 && right == 0) {
    turnRight();
  }
  // Right out -> Turn Left
  else if (left == 0 && right == 1) {
    turnLeft();
  }
  // Both white -> Stop
  else {
    stopBot();
  }
}

void forward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  analogWrite(ENA, 150); analogWrite(ENB, 150);
}

void turnLeft() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  analogWrite(ENA, 120); analogWrite(ENB, 120);
}

void turnRight() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  analogWrite(ENA, 120); analogWrite(ENB, 120);
}

void stopBot() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}
