#include <stdio.h>

// 센서 1개의 정보를 묶은 구조체
struct Sensor {
    int id;         // 센서 번호
    int temp;       // 온도
    int status;     // 상태 (0: 정상, 1: 경고)
};

// 구조체의 주소를 받아 원본의 status를 바꾸는 함수
void check(struct Sensor *ps) {
    if (ps->temp > 50) {        // ps->temp: ps가 가리키는 센서의 온도
        ps->status = 1;         // 50 초과면 원본의 status를 경고(1)로 변경
    }
}

int main(void) {
    // 바깥 { }는 배열 전체, 안쪽 { }는 센서 1개 (id, temp, status 순서)
    struct Sensor sensors[3] = { {1, 25, 0}, {2, 80, 0}, {3, 40, 0} };

    for (int i = 0; i < 3; i++) {
        check(&sensors[i]);     // i번째 센서의 주소를 넘김 (원본이 바뀜)
    }

    for (int i = 0; i < 3; i++) {
        printf("id=%d, temp=%d, status=%d\n",
               sensors[i].id, sensors[i].temp, sensors[i].status);
    }

    return 0;
}
