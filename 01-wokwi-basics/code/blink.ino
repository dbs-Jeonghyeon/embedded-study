void setup() {
  // 전원이 켜진 직후 딱 한 번만 실행되는 초기 설정 함수


  pinMode(LED_BUILTIN, OUTPUT);
  // pinMode(핀, 방향): 핀을 어떤 용도로 쓸지 정함
  // LED_BUILTIN: 보드에 내장된 LED 핀 번호의 이름 (Uno는 13번 핀)
  // 보드마다 내장 LED 핀 번호가 달라서, 이름으로 쓰면 보드를 바꿔도 코드를 안 고쳐도 됨
  // OUTPUT: 보드가 이 핀으로 신호를 내보냄(출력)
}

void loop() {
  // setup이 끝난 뒤 전원을 끌 때까지 계속 반복해서 실행되는 함수

  digitalWrite(LED_BUILTIN, HIGH);
  // digitalWrite(핀, 값): 핀에 HIGH 또는 LOW를 내보냄
  // HIGH: 핀에 전압이 나옴(5V), LED가 켜짐

  delay(1000);
  // delay(시간): 지정한 시간(ms) 동안 아무 일도 하지 않고 대기함
  // 1000ms = 1초 (LED가 켜진 채로 1초 유지됨)

  digitalWrite(LED_BUILTIN, LOW);
  // LOW: 핀에 전압이 나오지 않음(0V), LED가 꺼짐

  delay(1000);
  // 꺼진 채로 1초 대기함
}
