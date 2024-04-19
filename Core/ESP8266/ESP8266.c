
#include "esp8266.h"

void UART_SendData(int temperature, int humidity)
{
  char uartData[50];
  sprintf(uartData, "%d;%d\r\n", temperature, humidity); // Định dạng dữ liệu

  HAL_UART_Transmit(&huart1, (uint8_t *)uartData, strlen(uartData), HAL_MAX_DELAY); // Gửi dữ liệu qua UART
}
