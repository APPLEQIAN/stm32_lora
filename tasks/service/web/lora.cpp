/**
 * @brief LoRa wrapper module
 * @author lan
 */

#define LORA_SEMAPHORE
#define LORA_IMPL
#include "service/web/lora.h"

#include <stdio.h>

#include "FreeRTOS.h"
#include "main.h"
#include "semphr.h"
#include "service/web/config.h"
#include "spi.h"
#include "task.h"

// 注意：SPI的大量读写请使用DMA实现，DMA读写过程中使用yield让出CPU

// 信号量
// 用于DMA访问，启动DMA时take，DMA结束时give
SemaphoreHandle_t lora_semaphore;
StaticSemaphore_t lora_semaphore_buffer;

int LoraInit() {}

__attribute__((weak)) void LoraRxCallbackFromISR() {}

int LoraWrite(char *s, int len) {
  configASSERT(len >= 0);
  // 不允许在中断中操作网卡
  configASSERT(xPortIsInsideInterrupt() == pdFALSE);
  UNUSED(s);
  UNUSED(len);
  return -1;
}
int LoraRead(char *s, int len) {
  configASSERT(len >= 0);
  // 不允许在中断中操作网卡
  configASSERT(xPortIsInsideInterrupt() == pdFALSE);
  UNUSED(s);
  UNUSED(len);
  return -1;
}

void LoraD0CallbackFromISR() {}