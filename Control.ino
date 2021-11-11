/**
 * @file      Control.ino
 * @brief     LED midi Switch
 * @note      
 * @author    shigara
 * @copyright 
 */

#include "common.h"

static int g_command_done = 0;
int Control_GetCommandDone(void){return g_command_done;}
void Control_SetCommandDone(void){g_command_done = 1;}
void Control_ClearCommandDone(void){g_command_done = 0;}

typedef struct SW_command_info
{
  int i_switch_num;
  int i_looper_command_num;
  int i_control_command_num;
}SW_command_info;

static const SW_command_info c_SW_command_table [2]=
{
  {1,e_loop_reverse,e_control_sw1},
  {2,e_loop_speed,e_control_sw2}
};

void Control_Setup(void)
{
  SetupButton();
  SetupMidi();
}

void ControlMain(void)
{
  int i_button_num = 0;
  int i_command_num = 0;

  i_button_num  = GetButtonInfo();
  if(i_button_num  < 0){    
    return;
  }

  //Serial.println(i_button_num);
  SendCommandLooper(c_SW_command_table[i_button_num].i_looper_command_num);

  Control_SetCommandDone();
}
