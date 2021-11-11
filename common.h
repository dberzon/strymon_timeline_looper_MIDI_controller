/**
 * @file      common.h
 * @brief     LED midi Switch
 * @note      
 * @author    shigara
 * @copyright 
 */

#ifndef _COMMON_H_
#define _COMMON_H_

#define d_LED_port 3
#define d_SWITCH_PORT1 4
#define d_SWITCH_PORT2 5

enum e_loop_command
{
    e_loop_rec = 1,
    e_loop_play = 2,
    e_loop_stop = 3,
    e_loop_dubb = 4,
    e_loop_speed = 5,
    e_loop_reverse = 6
};

enum e_control_command
{
    e_control_sw1 = 1,
    e_control_sw2 = 2,
    e_control_sw3 = 3,
    e_control_sw4 = 4,
    e_control_sw5 = 5,
    e_control_exp1 = 6,
    e_control_exp2 = 7,
    e_control_tuner = 8,
    e_control_tap = 9
};

#endif
