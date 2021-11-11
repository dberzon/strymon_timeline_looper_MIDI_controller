/**
 * @file      midi_command.ino
 * @brief     midi command
 * @note      This command for TimeLine by strymon 
 *            If you want use anoter effector controller, 
 *            change this command.
 * @author    shigara
 * @copyright 
 */

#include <MIDI.h>

//select midi ch
#define d_MIDI_CH 1

MIDI_CREATE_DEFAULT_INSTANCE();

void SetupMidi(void)
{
  //If you want to do serial debug.
  //Remove this MIDI.begin line.(Because MIDI also use TX RX lines.)
  MIDI.begin();
}

//For TIMELINE

//you should read TimeLine manual
void SendCommandLooper(int i_command_num)
{
  switch(i_command_num){
    case e_loop_rec://test for HX stomp tuner
      MIDI.sendControlChange(68, 127, d_MIDI_CH); 
    break;
    
    case e_loop_play:// Looper redo
      MIDI.sendControlChange(90, 127, d_MIDI_CH); 
    break;

    case e_loop_stop:// Looper undo
      MIDI.sendControlChange(89, 0, d_MIDI_CH); 
    break;

    case e_loop_dubb:// Looper pre post toggle
      MIDI.sendControlChange(96, 0, d_MIDI_CH); 
    break;

    case e_loop_speed://looper half/full
      MIDI.sendControlChange(95, 0, d_MIDI_CH); 
    break;

    case e_loop_reverse:// Looper reverse
      MIDI.sendControlChange(94, 0, d_MIDI_CH); 
    break;
  }
}
