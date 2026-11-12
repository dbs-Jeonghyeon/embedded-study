#include <stdio.h>

// p: 배열의 첫 칸 주소를 받는 포인터, n: 원소 개수
int sum(int *p, int n) {
    int total = 0;                  // 합계를 저장할 변수 (0으로 시작)
    for (int i = 0; i < n; i++) {   // i = 0, 1, 2, ... n-1 까지 반복
        total += *(p + i);          // (p + i): 첫 칸에서 i칸 떨어진 칸의 주소
                                    // *(p + i): 그 칸의 값 -> total에 더함
                                    // 괄호가 없으면 *p + i (첫 칸 값 + i)가 되어 틀림
    }
    return total;                   // 다 더한 합계를 돌려줌
}

int main(void) {
    int arr[5] = {1, 2, 3, 4, 5};           // int 칸 5개가 연속으로 놓인 배열
    printf("합: %d\n", sum(arr, 5));        // arr = 첫 칸의 주소를 넘김 -> 1+2+3+4+5 = 15
    return 0;                               // 프로그램 정상 종료
}
