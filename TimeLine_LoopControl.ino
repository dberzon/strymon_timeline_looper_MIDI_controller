/**
 * @file      TimeLine_LoopControl.ino
 * @brief     Loop Controler
 * @note      CPU is Arduino Nano
 * @author    shigara
 * @copyright 
 */
#include <Arduino_FreeRTOS.h>
#include "common.h"

// define Tasks
void TaskMainControl( void *pvParameters );
void TaskControlLED( void *pvParameters );

void setup() {
  //Serial.begin(115200); 

  //call device setup
  Control_Setup();
  LED_Setup();

  //create tasks
    xTaskCreate(
    TaskMainControl
    ,  "MainControl" // A name just for humans
    ,  128  // Stack size
    ,  NULL //Parameters for the task
    ,  1  // Priority
    ,  NULL ); //Task Handle
    
    xTaskCreate(
    TaskControlLED
    ,  "ControlLED" // A name just for humans
    ,  128  // Stack size
    ,  NULL //Parameters for the task
    ,  1  // Priority
    ,  NULL ); //Task Handle

  vTaskStartScheduler();
}

void loop() {
  //here empty
}

//below tasks
void TaskMainControl( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
  int i_button_num = 0;
 
  for (;;)
  {
    ControlMain();
    vTaskDelay( 10 / portTICK_PERIOD_MS );
  }
}

void TaskControlLED( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
  static int i_count = 0;
 
  for (;;)
  {
    //after button pushed LED flashes 1sec
    if(Control_GetCommandDone() == 1){
      digitalWrite(d_LED_port, HIGH);
      vTaskDelay( 50 / portTICK_PERIOD_MS );
      digitalWrite(d_LED_port, LOW); 
      vTaskDelay( 50 / portTICK_PERIOD_MS );

      i_count++;

      if(i_count == 10){
        digitalWrite(d_LED_port, HIGH);
        Control_ClearCommandDone();
        i_count = 0;
      }

    }else{//non button pushed
      LED_ControlPWMWidth();
      vTaskDelay( 50 / portTICK_PERIOD_MS );
    }
  }
}
