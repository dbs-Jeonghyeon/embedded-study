void recurse(int depth) {                    // 재귀 함수: 호출할 때마다 스택에 새 프레임이 쌓임
  volatile int local = depth;                // 이 호출만의 지역 변수 (volatile: 컴파일러가 최적화로 지우지 못하게 함)
  Serial.print("depth ");                    // 현재 깊이 출력 시작
  Serial.print(depth);                       // 깊이 숫자 출력
  Serial.print("  local addr: 0x");          // 주소 앞 문구 출력
  Serial.println((unsigned int)&local, HEX); // 지역 변수의 주소를 16진수로 출력
  if (depth < 4) recurse(depth + 1);         // 4까지 한 단계 더 깊이 호출
  Serial.print("back ");                     // 호출에서 돌아올 때 출력 (재귀 뒤에 할 일이 있어야 스택이 유지됨)
  Serial.println(depth);                     // 돌아온 깊이 출력
}                                            // 함수 끝

void setup() {                               // 전원을 켜면 한 번 실행되는 함수 시작
  Serial.begin(9600);                        // 시리얼 통신 시작

  Serial.println("== 1. 스택 성장 방향 ==");   // 실험 1 제목 출력
  recurse(0);                                // 깊이 0부터 재귀 시작

  Serial.println("== 2. 힙 소진 ==");          // 실험 2 제목 출력
  int count = 0;                             // 성공한 malloc 횟수를 세는 변수
  while (true) {                             // 실패할 때까지 반복
    char* p = (char*)malloc(100);            // 힙에서 100바이트 요청
    if (p == NULL) break;                    // NULL이면 힙이 바닥난 것이므로 반복 종료
    *(volatile char*)p = 1;                  // 받은 메모리에 실제로 값을 써서 최적화로 사라지지 않게 함
    count++;                                 // 성공 횟수 증가
  }                                          // while 끝
  Serial.print("100바이트 할당 성공 횟수: "); // 결과 문구 출력
  Serial.println(count);                     // 성공 횟수 출력
}                                            // setup 함수 끝

void loop() { } 

/*
 *  실험 결과
 *  depth 0  local addr: 0x8F6
 *  depth 1  local addr: 0x8EE
 *  depth 2  local addr: 0x8E6
 *  depth 3  local addr: 0x8DE
 *  depth 4  local addr: 0x8D6
 *  100바이트 할당 성공 횟수: 15
 */
