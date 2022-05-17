STM32CubeIDE Settings
Enable USART1 asynchronous
  
  /* USER CODE BEGIN Includes */
#include <string.h>
#include <stdio.h>
/* USER CODE END Includes */

  /* USER CODE BEGIN 2 */
  char mobileNumber[] = "+61498749497";  // Enter the Mobile Number you want to send to
  char ATcommand[80];
  uint8_t buffer[30] = {0};
  uint8_t ATisOK = 0;
  while(!ATisOK){
  		sprintf(ATcommand,"AT\r\n");
  		HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
  		HAL_UART_Receive (&huart1, buffer, 30, 100);
  		HAL_Delay(1000);
  		if(strstr((char *)buffer,"OK")){
  			ATisOK = 1;
  		}
  		HAL_Delay(1000);
  		memset(buffer,0,sizeof(buffer));
  }
  sprintf(ATcommand,"AT+CMGF=1\r\n");
  HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
  HAL_UART_Receive (&huart1, buffer, 30, 100);
  HAL_Delay(1000);
  memset(buffer,0,sizeof(buffer));
  sprintf(ATcommand,"AT+CMGS=\"%s\"\r\n",mobileNumber);
  HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
  HAL_Delay(100);
  sprintf(ATcommand,"Hello World, STM32 started%c",0x1a);
  HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
  HAL_UART_Receive (&huart1, buffer, 30, 100);
  memset(buffer,0,sizeof(buffer));
  HAL_Delay(4000);
  /* USER CODE END 2 */
