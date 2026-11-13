int initVar = 5;                          // 초기값이 있는 전역 변수 -> .data 영역 (SRAM)
int zeroVar;                              // 초기값이 없는 전역 변수 -> .bss 영역 (SRAM, 0으로 채워짐)
const char flashStr[] PROGMEM = "hello";  // PROGMEM을 붙이면 SRAM이 아니라 Flash에 저장됨

void printAddr(const char* name, const void* p) {  // 이름과 주소를 출력하는 도우미 함수
  Serial.print(name);                     // 변수 이름 출력
  Serial.print(": 0x");                   // 16진수임을 알리는 접두사 출력
  Serial.println((unsigned int)p, HEX);   // 주소를 16진수로 출력하고 줄바꿈
}                                         // 도우미 함수 끝

void setup() {                            // 전원을 켜면 한 번 실행되는 함수 시작
  Serial.begin(9600);                     // 시리얼 통신 시작
  int localVar = 1;                       // 함수 안의 지역 변수 -> 스택
  int* heapVar = (int*)malloc(2);         // malloc으로 2바이트 요청 -> 힙에서 할당

  printAddr("initVar  (.data)", &initVar);   // .data 변수의 주소 출력
  printAddr("zeroVar  (.bss) ", &zeroVar);   // .bss 변수의 주소 출력
  printAddr("heapVar  (heap) ", heapVar);    // 힙에서 받은 메모리의 주소 출력
  printAddr("localVar (stack)", &localVar);  // 스택에 있는 지역 변수의 주소 출력
  printAddr("flashStr (flash)", flashStr);   // Flash에 있는 문자열의 주소 출력
}                                         // setup 함수 끝

void loop() { }

/* 
 *  실험 결과
 *  initVar  (.data): 0x100
 *  zeroVar  (.bss) : 0x178
 *  heapVar  (heap) : 0x226
 *  localVar (stack): 0x8FA
 *  flashStr (flash): 0x68
 */
