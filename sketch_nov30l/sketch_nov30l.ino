#include <Servo.h>

const int trigPin=A5;
const int echoPin=A4;
long duracion;
int distancia;

Servo servo;

void setup() {
  // put your setup code here, to run once:
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
    servo.attach(11);

}

void loop() {
  // put your main code here, to run repeatedly:
    for (int i=15;i<=165;i++){ // que i vaya desde los grados 15 a 165, y que se forme con estos angulos un area conica //
    servo.write(i);
    delay(30);
    distancia=distanciacalculada();
    Serial.print(i);
    Serial.print(","); // para que sea mas estetico //
    Serial.print(distancia);
    Serial.print(".");
    }
    for (int i=165;i>15;i--){ // que i vaya desde los grados 15 a 165, y que se forme con estos angulos un area conica //
    servo.write(i);
    delay(30);
    distancia=distanciacalculada();
    Serial.print(i);
    Serial.print(","); // para que sea mas estetico //
    Serial.print(distancia);
    Serial.print(".");
    }
}

int distanciacalculada(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duracion=pulseIn(echoPin, HIGH);
  distancia=duracion *0.034/2;
  return distancia;
}
