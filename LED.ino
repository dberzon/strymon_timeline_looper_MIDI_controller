/**
   @file      LED.ino
   @brief     LED control
   @note
   @author    shigara
   @copyright
*/

#include "common.h"

void LED_Setup(void)
{
  pinMode(d_LED_port, OUTPUT);
  analogWrite(d_LED_port, 100);
}

void LED_ControlPWMWidth()
{

  static int flag = 0;
  static int count = 0;  

  //increase PWM width
  if (flag == 0) {
    ++count;
    if (count == 10) {
      flag = 1;
    }
  } else { //decrease PWM width
    --count;
    if (count == 0) {
      flag = 0;
    }
  }
  
  analogWrite(d_LED_port, count);
}