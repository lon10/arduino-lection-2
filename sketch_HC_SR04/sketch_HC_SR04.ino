#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

long readLen() {
  long duration, distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);//read signal from HC-SR04
  distance = (duration/2) / 29.1;//The Pace of Sound = 1 / Speed of Sound = 1 / 0.03435 = 29.1 ss/cm
  return distance;
}

void loop() {
  long distance = readLen();
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
}
