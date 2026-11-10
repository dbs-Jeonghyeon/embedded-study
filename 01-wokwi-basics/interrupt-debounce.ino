const int BUTTON_PIN = 2;
// Uno에서 인터럽트가 되는 핀은 2번과 3번뿐임

volatile int count = 0;
// volatile : 값이 코드 흐름 밖(ISR)에서 바뀔 수 있으니, 컴파일러가 값을 기억해 두지 않고
// 매번 메모리에서 읽게 하는 키워드. ISR과 loop가 함께 쓰는 변수에 붙임
// count : 버튼을 누른 횟수를 세는 변수

volatile bool ledOn = false;
// LED가 현재 켜져 있는지 기억함, 시작값은 꺼짐(false)

volatile unsigned long lastEdge = 0;
// unsigned long : millis() 값을 담기 위해 사용함
// 마지막으로 핀 값이 "변한" 시각을 ms 단위로 저장함, 튕김으로 변한 것도 모두 기록함

void onChange() {
  // ISR(인터럽트 서비스 루틴): 핀 값이 변하는 순간 자동으로 실행되는 함수
  // 직접 호출하지 않음, 짧게 작성해야 하며 안에서 delay() 사용 금지

  unsigned long now = millis();
  // millis(): 보드가 켜진 뒤 지난 시간(ms)을 돌려주는 함수
  // 지금 시각을 now에 저장해 두고 비교에 사용함

  if (now - lastEdge > 20) {
    // 지금 시각 - 마지막 변화 시각이 20ms보다 크면, 마지막 변화 뒤 20ms 넘게 조용했다는 뜻
    // 이 경우만 튕김이 끝난 새 변화로 보고, 튕김은 간격이 짧아 여기서 걸러짐

    if (digitalRead(BUTTON_PIN) == LOW) {
      // CHANGE로 감시하면 뗄 때(LOW → HIGH)도 ISR이 호출됨
      // 이 조건으로 눌린 상태일 때만 통과시켜, 뗄 때의 변화는 세지 않음

      ledOn = !ledOn;
      // ! : HIGH는 LOW로, LOW는 HIGH로

      digitalWrite(LED_BUILTIN, ledOn);
      // true는 HIGH, false는 LOW로 취급되어 LED가 켜지거나 꺼짐

      count++;
      // count를 1 증가시킴, count = count + 1과 같은 의미
    }
  }

  lastEdge = now;
  // 마지막 변화 시각을 지금으로 갱신함
  // if 바깥에 있어서 if 조건을 통과했든 못했든 항상 실행됨 (
  // 튕김이 이어지는 동안 계속 갱신되어 "아직 조용하지 않음" 상태가 유지됨
}

void setup() {
  Serial.begin(9600);
  // 컴퓨터와 글자를 주고받는 시리얼 통신을 시작함
  // 9600은 전송 속도 설정값이며 시리얼 모니터 설정과 맞아야 함

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), onChange, CHANGE);
  // attachInterrupt: 인터럽트 등록, 세 가지를 지정함
  //  1) digitalPinToInterrupt(BUTTON_PIN): 감시할 핀 (핀 번호를 인터럽트 번호로 변환함)
  //  2) onChange: 변화가 생기면 실행할 함수 이름
  //  3) CHANGE: HIGH → LOW와 LOW → HIGH 두 방향 모두 감시함
  // 뗄 때의 튕김까지 lastEdge에 기록해야 걸러낼 수 있어서 FALLING 대신 CHANGE를 씀
}

void loop() {
  Serial.println(count);
  // count 값을 시리얼 모니터에 한 줄로 출력함 (맨 끝에 줄바꿈이 붙음)

  delay(2000);
  // 인터럽트는 폴링과는 다르게 delay 중에도 변화가 생기는 순간 onChange가 실행됨
}
