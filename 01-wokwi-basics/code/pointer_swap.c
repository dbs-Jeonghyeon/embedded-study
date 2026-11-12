#include <stdio.h>
 
// 값 복사 방식
// a, b는 x, y의 복사본이라 함수 안에서 바꿔도 원본은 그대로 유지됨
void swap_wrong(int a, int b) {
    int tmp = a;      // a의 값을 임시 보관
    a = b;            // 복사본 a에 b의 값 대입
    b = tmp;          // 복사본 b에 tmp 대입 (함수가 끝나면 a, b는 사라짐)
}
 
// 주소 전달 방식
// a, b는 x, y의 주소를 받아 원본 칸을 직접 바꿈
void swap(int *a, int *b) {
    int tmp = *a;     // a가 가리키는 값(x)을 임시 보관
    *a = *b;          // a가 가리키는 칸(x)에 b가 가리키는 값(y)을 넣기
    *b = tmp;         // b가 가리키는 칸(y)에 tmp를 넣기
}
 
int main(void) {
    int x = 3, y = 7;                                 
 
    swap_wrong(x, y);                                  // x, y의 값(3, 7)이 복사되어 전달됨
    printf("잘못된 경우 : x=%d, y=%d\n", x, y);        // 원본은 안 바뀌어 x=3, y=7
 
    swap(&x, &y);                                      // &x, &y: x, y의 주소를 전달
    printf("옳게 된 경우 : x=%d, y=%d\n", x, y);       // 원본이 바뀌어 x=7, y=3
 
    return 0;         // 프로그램 정상 종료
}
