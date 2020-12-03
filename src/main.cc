#include "stm32f3xx_hal.h"
#include "logger.h"

#define LED_PIN                                GPIO_PIN_14
#define LED_GPIO_PORT                          GPIOE
#define LED_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOE_CLK_ENABLE()

// Global log
Logger g_log;

int main(void)
{
  HAL_Init();

  LED_GPIO_CLK_ENABLE();

  GPIO_InitTypeDef GPIO_InitStruct;

  GPIO_InitStruct.Pin = LED_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);

  while (1)
  {
    HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);

    HAL_Delay(250);
  }
}

#ifdef __cplusplus
extern "C" {
#endif
void SysTick_Handler(void)
{
  HAL_IncTick();
}

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while (1) {}
}


void MemManage_Handler(void)
{
  while (1) {}
}

void BusFault_Handler(void)
{
  while (1) {}
}

void UsageFault_Handler(void)
{
  while (1) {}
}

void SVC_Handler(void)
{
}


void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}
#ifdef __cplusplus
}
#endif
