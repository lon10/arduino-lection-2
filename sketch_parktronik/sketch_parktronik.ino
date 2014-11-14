#define ledPin 3
#define trigPin 13
#define echoPin 12

void setup() {            
  Serial.begin (9600);  
  pinMode(ledPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
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

void blink(int onTime, long offTime) {
  digitalWrite(ledPin, HIGH);   
  delay(onTime);              
  digitalWrite(ledPin, LOW);    
  delay(offTime);
}

void loop() {
  long distance = readLen();
  Serial.print(distance);
  Serial.println(" cm");
  if (distance <= 180) {
    blink(10, distance * 3); 
  }
}

