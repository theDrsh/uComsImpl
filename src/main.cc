#include "stm32f3xx_hal.h"
#include "logger.h"
#include "io.h"

// Global log
Logger g_log;
// Global Io map
Io g_io;

int main(void)
{
  HAL_Init();
  int i = 0;
  while (1)
  {
    g_io.Toggle(static_cast<IoMap_e>(i));
    g_log.Printf(kLogInfo, "Hello %d", i);
    HAL_Delay(250);
    i++;
    if(i > 7) {
      i = 0;
    }
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
