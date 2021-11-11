/**
 * @file      switch.ino
 * @brief     switch setting
 * @note      
 * @author    shigara
 * @copyright 
 */
#include "common.h"
#include <Bounce2.h>

#define BOUNCE_WITH_PROMPT_DETECTION

//button define
#define NUM_BUTTONS 2

//button settings
Bounce * g_buttons = new Bounce[NUM_BUTTONS];

/*
1 2 power midd
*/

//
void SetupButton(void)
{
    //convert mpu pins
    const uint8_t c_button_pins[NUM_BUTTONS] = {d_SWITCH_PORT1,d_SWITCH_PORT2};
    
    //setup the bounce instance for the current button
    for (int i = 0; i < NUM_BUTTONS; i++) {
        g_buttons[i].attach( c_button_pins[i] , INPUT_PULLUP);
        g_buttons[i].interval(5);
    }
    
    return;
}

//
int GetButtonInfo(void)
{
    //single button detect
    for (int j = 0; j < NUM_BUTTONS; j++){
        g_buttons[j].update();
        if (g_buttons[j].fell()){
            //Serial.println("button fell");
            //Serial.println(j);
            return(j);
        }
    }
    //Serial.println("NoButton");
    return(-1);
}
