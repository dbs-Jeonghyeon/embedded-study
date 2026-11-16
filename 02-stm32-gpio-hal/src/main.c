/*
 * 날짜: 2026-11-16
 * 목적: NUCLEO-F446RE 사용자 LED(LD2, PA5)를 0.5초 간격으로 깜빡이기 (HAL 버전)
 * 실험 결과: (보드가 도착하면 직접 실행해 보고 작성)
 */

#include "stm32f4xx_hal.h"                // HAL 라이브러리 헤더 포함

void SysTick_Handler(void)                // 1ms마다 자동 호출되는 SysTick 인터럽트 핸들러
{
    HAL_IncTick();                        // HAL이 경과 시간(ms)을 셀 수 있게 카운터를 1 증가
}

int main(void)
{
    HAL_Init();                           // HAL 초기화 (SysTick을 1ms 주기로 설정 등)

    __HAL_RCC_GPIOA_CLK_ENABLE();         // GPIOA 포트에 클럭 공급 (켜야 레지스터 사용 가능)

    GPIO_InitTypeDef gpio = {0};          // GPIO 설정 구조체를 0으로 초기화
    gpio.Pin   = GPIO_PIN_5;              // 설정할 핀: PA5 (보드의 LD2 LED)
    gpio.Mode  = GPIO_MODE_OUTPUT_PP;     // 푸시풀 출력 모드
    gpio.Pull  = GPIO_NOPULL;             // 내부 풀업/풀다운 사용 안 함
    gpio.Speed = GPIO_SPEED_FREQ_LOW;     // 출력 속도: 낮음 (LED에는 충분)
    HAL_GPIO_Init(GPIOA, &gpio);          // 위 설정을 GPIOA에 적용

    while (1)                             // 무한 반복
    {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);  // PA5 출력을 반전 (켜짐 ↔ 꺼짐)
        HAL_Delay(500);                   // 500ms 대기
    }
}
