#include <Servo.h>

Servo servoMotor;

const int trigPin  = 6;     // 고정 정수인 핀번호 6
const int echoPin  = 7;     // 고정 정수인 핀번호 7
const int redLED   = 8; 	// 고정 정수인 핀번호 8
const int greenLED = 9;     // 고정 정수인 핀번호 9

long duration;
int distance;

void setup() 
{
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  servoMotor.attach(10);
  servoMotor.write(0); // 초기 서보모터 위치 닫힘
  
  digitalWrite(redLED, HIGH); // 빨간 LED 초기값
  delay(5000); // 5초 유지
  digitalWrite(redLED, LOW);
}

void loop() 
{
  // 초음파 센서를 통한 거리 측정
  digitalWrite(trigPin, LOW);  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // 거리 = '반환시간 × 음속 ÷ 2' (단위: cm)

  if (distance < 10)		// 만약 화물이 아직 있다면
  { 
    digitalWrite(greenLED, HIGH);
    delay(4000); // 4초 유지
    digitalWrite(greenLED, LOW);

    // 화물이 지나간 후 서보모터 닫기
    servoMotor.write(90); // 서보모터 열림
    delay(2000); // 화물이 빠져나가도록 기다림
    servoMotor.write(0); // 서보모터 닫기
  }

  // 빨간 LED 카운터 리셋
  digitalWrite(redLED, HIGH);
  delay(5000);
  digitalWrite(redLED, LOW);
}
