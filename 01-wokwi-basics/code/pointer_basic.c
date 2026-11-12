#include <stdio.h>
 
int main(void) {
    int x = 10;       // int 변수 x 선언, 값 10 저장
    int *p = &x;      // 포인터 p 선언: &x(x의 주소)를 p에 저장 -> p는 x를 가리킴
 
    printf("x의 값: %d\n", x);                    // x에 들어 있는 값 (10)
    printf("x의 주소: %p\n", (void *)&x);         // &x: x 칸의 주소
    printf("p에 저장된 값: %p\n", (void *)p);     // p에 든 값 = x의 주소 (위 줄과 같음)
    printf("p가 가리키는 값: %d\n", *p);          // *p: p가 가리키는 칸의 값 = x (10)
 
    *p = 20;          // p가 가리키는 칸(x)에 20 저장 -> x가 직접 바뀜
    printf("*p = 20 이후 x: %d\n", x);            // x는 20
 
    *p = *p + 5;      // x의 현재 값(20)에 5를 더해 다시 x에 저장 -> 25
    printf("x: %d\n", x);                         // x는 25
 
    return 0;         // 프로그램 정상 종료
}
