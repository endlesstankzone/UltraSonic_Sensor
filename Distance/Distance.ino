

#define trigPin 13
#define echoPin 12
#define Rled 10
#define Gled 11

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(Rled, OUTPUT);
  pinMode(Gled, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance > 20 && distance < 24) {
    digitalWrite(Gled, HIGH);
    digitalWrite(Rled, LOW);
  } else {
    digitalWrite(Gled, LOW);
    digitalWrite(Rled, HIGH);
  }
 
  if (distance > 30) {
    Serial.println("Out Of Range");
  }


  delay(50);



}
