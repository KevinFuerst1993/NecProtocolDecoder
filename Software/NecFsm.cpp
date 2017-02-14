/*
 * Project: WindowOpener
 * File: NecFsm.cpp
 * Date: 09.02.2017
 * Author: Kevin Fuerst
 */

//Includes
#include "NecFsm.h"

NecFsm::NecFsm(void)
  :currentState(readyState)
{
}

void NecFsm::process(Event e)
{
  switch (currentState)
  {
    
    case readyState:
      if(e == evRisingEdge)
      {
        //todo 
        //timer.start();
        currentState = startPulseState;
      }
      
      break;

    case startPulseState:
      if(e == evRisingEdge)
      {
        if((startPulseMinLength <= timer.getTime()) || (timer.getTime() <= startPulseMaxLength)) 
        {
          timer.reset();
          currentState = frameStartState;
        }
        else
        {
          timer.reset();
          currentState = readyState;
        }     
      }

      if(e == evTimeout)
      {
        timer.reset();
        currentState = readyState;
      }
      break;

    case frameStartState:
      break;

    case oneState:
      break;

    case zeroState:
      break;


  }
}



