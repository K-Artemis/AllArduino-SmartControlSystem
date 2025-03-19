# AllArduino-SmartControlSystem


[준비물]
- 아두이노 우노 보드
- 초음파 거리 센서 (HC-SR04)
- 서보모터 (SG90 또는 MG90S)
- 빨간색 LED 1개
- 초록색 LED 1개
- 저항 (220Ω, LED 보호용)
- 브레드보드
- 점퍼 와이어
- USB 케이블 (아두이노 연결용)


[회로 구성 방법]
01 LED: 빨간색과 초록색 LED 각각을 220Ω 저항과 연결하여 아두이노 디지털 핀에 연결합니다. (예: 빨간색 LED는 핀 8, 초록색 LED는 핀 9)
02 서보모터: 서보모터의 신호선은 아두이노 디지털 핀에 연결합니다. (예: 핀 10)
03 초음파 센서: Trig 핀은 핀 6에, Echo 핀은 핀 7에 연결합니다.
04 모든 부품의 GND와 5V는 아두이노 보드와 적절히 연결합니다.

[코드 구현 설명]
- 빨간색 LED는 5초 동안 켜지고, 이후 초록색 LED가 4초 동안 켜지도록 설정합니다.
- 초음파 센서를 이용해 화물의 거리를 확인합니다.
- 거리가 특정 값(예: 10cm)보다 작으면 화물이 있다고 판단합니다.
- 화물이 모두 빠져나가면 서보모터가 닫히도록 동작합니다.
