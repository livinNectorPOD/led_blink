#include <Arduino.h>
#include <stm32c0xx_hal.h> 
#include <stm32c031xx.h>

// This example is just to demonstrate the flexibility
// gpio is operated using bare metal code
// Delay using the systemClk timer is done using HAL delay.
// UART serial port is operated using Arduino core

// project can be built by removing any of those also.


int main()
{
  HAL_Init();
  // Reset and Clock Control (RCC)
  // I/O Port Enable Register
  RCC->IOPENR = 0b01; // LSB corresponds to GPIOA port

  // Setting Mode Register Bits for pin 5 and 6 of GPIOA
  GPIOA->MODER = 0b0101 << (5 * 2); // 01 - Output mode
  GPIOA->OSPEEDR = 0b0101 << (5 * 2); // 01 - Output modeGPIOA->MODER = 0b0101 << (5 * 2); // 01 - Output mode

  // Setting Output of pin 5 to high
  GPIOA->ODR= 0b01<<5;
  Serial.begin(115200);

  while (1)
  {
    GPIOA->ODR ^= 0b11 << 5; // toggles both pin 5 and 6
    HAL_Delay(1000);
    Serial.println("Toggle");
    HAL_Delay(1000);
  }

}