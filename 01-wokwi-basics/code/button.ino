const int BUTTON_PIN = 2;
// const: 실행 중 값이 바뀌지 않는 상수라는 표시
// 버튼을 연결한 핀 번호를 BUTTON_PIN이라는 이름으로 저장함
// 배선과 반드시 같은 번호여야 함

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  // INPUT: 핀으로 들어오는 신호를 읽겠다는 뜻 (입력)
  // PULLUP: 내부 풀업 저항을 켜서 핀을 약하게 HIGH 쪽으로 붙잡아 둠
  // 안 누르면 HIGH로 유지되고, 누르면 GND와 연결되어 LOW가 됨 (LOW = 눌림)
}

void loop() {
  int state = digitalRead(BUTTON_PIN);
  // digitalRead(핀): 핀의 현재 값을 읽어 HIGH 또는 LOW를 돌려줌
  // int state: 읽은 값을 담아 두는 변수(이름 붙은 상자)를 만듦

  if (state == LOW) {
    // if (조건): 조건이 참이면 중괄호 안을 실행함
    // 풀업이라 눌렀을 때 LOW이므로, "눌렸다면"이라는 뜻
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    // else: 위 조건이 거짓일 때(안 눌렸을 때) 실행함
    digitalWrite(LED_BUILTIN, LOW);
  }
  // delay가 없어서 쉬지 않고 계속 반복해서 버튼 상태를 확인함 (폴링)
}
