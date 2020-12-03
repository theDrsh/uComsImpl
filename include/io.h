// Author: Daniel Rush

// Quick class to abstract away pin definitions to a pinmap that matches the board
// currently leaves a lot to be desired, will refactor as I go.
#pragma once
#include "stm32f3xx_hal.h"

enum IoState {
  kIoLow  = 0,
  kIoHigh = 1,
};

enum IoMap_e {
  kLED3 = 0,
  kLED4,
  kLED5,
  kLED6,
  kLED7,
  kLED8,
  kLED9,
  kLED10,
  kNumIo,
};

struct IoMap_t{
  uint16_t pin;
  GPIO_TypeDef* port;
};

static const IoMap_t IO_MAP_INIT[kNumIo] = {
  [kLED3] =  {.pin = GPIO_PIN_9,  .port = GPIOE},
  [kLED4] =  {.pin = GPIO_PIN_8,  .port = GPIOE},
  [kLED5] =  {.pin = GPIO_PIN_10, .port = GPIOE},
  [kLED6] =  {.pin = GPIO_PIN_15, .port = GPIOE},
  [kLED7] =  {.pin = GPIO_PIN_11, .port = GPIOE},
  [kLED8] =  {.pin = GPIO_PIN_14, .port = GPIOE},
  [kLED9] =  {.pin = GPIO_PIN_12, .port = GPIOE},
  [kLED10] = {.pin = GPIO_PIN_13, .port = GPIOE},
};

class Io {
 public:
  Io();
  void Set(IoMap_e io, IoState state);
  IoState Get(IoMap_e io);
  void Toggle(IoMap_e io);
 private:
  IoMap_t io_map_[kNumIo];
};
