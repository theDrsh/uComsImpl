#include "io.h"


Io::Io() {
  // Copy init struct
  for (int i = 0; i < kNumIo; i++) {
    io_map_[i].pin = IO_MAP_INIT[i].pin;
    io_map_[i].port = IO_MAP_INIT[i].port;
  }
  // Enable all GPIO clocks
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();

  for (int gpio = 0; gpio < kNumIo; gpio++) {
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin = io_map_[gpio].pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(io_map_->port, &GPIO_InitStruct);
  }
}

void Io::Set(IoMap_e io, IoState state) {
  HAL_GPIO_WritePin(io_map_[io].port, io_map_[io].pin, static_cast<GPIO_PinState>(state));
}

void Io::Toggle(IoMap_e io) {
  HAL_GPIO_TogglePin(io_map_[io].port, io_map_[io].pin);
}

IoState Io::Get(IoMap_e io) {
  return static_cast<IoState>(HAL_GPIO_ReadPin(io_map_[io].port, io_map_[io].pin));
}
