C 복습 01
  - 포인터, 구조체, 비트 연산, 레지스터로 LED 제어
  - 2026/11/12
  - 환경 : 온라인 C 컴파일러, Wokwi 시뮬레이터, Arduino Uno
  - 링크 : https://wokwi.com/projects/480479460636014593

## 한 일
- 포인터 기초 (&, *) -> 값 전달(swap_wrong)과 주소 전달(swap)을 비교 -> 배열을 포인터로 순회하며 합 구하기
- 구조체 Sensor 정의 -> 구조체 포인터와 '->'로 원본 수정 -> 구조체 배열에 check 함수 적용
- 비트 연산자 정리 -> 특정 비트 켜기/끄기/뒤집기/확인하기 -> Wokwi에서 DDRB, PORTB로 13번 핀 LED 깜빡이기

## 개념 정리
- 포인터 : 변수의 주소를 담는 변수
    x가 사는 칸의 주소를 p가 들고 있으면 p는 x를 가리킨다고 함
- & 와 * : &는 변수의 주소, *는 주소를 따라가면 나오는 그 칸의 값
    p : x의 주소
    *p : x의 값
    &p : p 자신의 주소
- 값 전달과 주소 전달 : C 함수는 인자를 복사해서 받기 때문에 값으로 넘기면 복사본만 바뀌고 원본은 그대로
    원본을 바꾸려면 주소를 넘기고 *로 접근해야 함 (swap(&x, &y))
- 배열과 포인터 : 배열 이름은 첫 칸의 주소처럼 쓰임
    p + 1은 1바이트가 아니라 자료형 한 칸만큼 이동
- 구조체 : 여러 값을 하나로 묶은 자료형
    구조체 변수는 '.'으로, 구조체 포인터는 '->'로 멤버에 접근 (ps->temp = (*ps).temp)
- 비트 마스크 : 1 << n은 n번 비트만 1인 값
    켜기 : reg |= (1 << n)    (OR)
    끄기 : reg &= ~(1 << n)   (AND)
    뒤집기 : reg ^= (1 << n)  (XOR)
    마스크 자리만 바뀌고 나머지 비트는 그대로 유지
- 레지스터 : DDRB는 방향 설정(1이면 출력, 0이면 입력), PORTB는 출력값(1이면 HIGH)
    DDRB와 PORTB는 고정 주소의 8비트 칸

## 실습
- 배운 점 : 비트 연산은 마스크로 원하는 비트만 바꾸고 나머지는 유지하는 방식
    digitalWrite도 결국 레지스터의 특정 비트를 바꾸는 일

## 코드
- [pointer_basic.c](code/pointer_basic.c) : 포인터 기초 (&, *)
- [pointer_swap.c](code/pointer_swap.c) : 값 전달과 주소 전달 비교
- [pointer_array_sum.c](code/pointer_array_sum.c) : 배열을 포인터로 순회해 합 구하기
- [struct_sensor.c](code/struct_sensor.c) : 구조체와 '->' 로 원본 수정
- [bit_ops_simple.c](code/bit_ops_simple.c) : 비트 켜기, 끄기, 뒤집기
- [register-blink.ino](code/register-blink.ino) : DDRB, PORTB로 LED 깜빡이기
