volatile bool pressed = false;   // 버튼 눌림 플래그. volatile: 인터럽트가 바꿀 수 있으니 매번 메모리에서 읽으라는 지시

void onPress() { pressed = true; }   // 인터럽트 함수: 버튼이 눌리면 자동 실행되어 플래그를 true로 바꿈

void setup() {                       // 전원을 켜면 한 번만 실행되는 함수 시작
  Serial.begin(9600);                // 시리얼 통신 시작 (속도 9600)
  pinMode(2, INPUT_PULLUP);          // 2번 핀을 입력으로 설정, 내부 풀업 저항 사용 (안 눌림=HIGH, 눌림=LOW)
  attachInterrupt(digitalPinToInterrupt(2), onPress, FALLING);  // 2번 핀이 HIGH→LOW로 떨어질 때 onPress를 호출하도록 등록

  Serial.println("waiting...");      // 대기 시작을 알리는 문구 출력
  while (!pressed) { }               // 버튼 누를 때까지 대기. pressed가 false인 동안 빈 루프 반복
  Serial.println("pressed!");        // 루프를 빠져나오면(버튼이 인식되면) 문구 출력
}                                    // setup 함수 끝

void loop() { } 
