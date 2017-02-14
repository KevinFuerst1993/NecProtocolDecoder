/*
 * Project: WindowOpener
 * File: NecFsm.h
 * Date: 09.02.2017
 * Author: Kevin Fuerst
 */

#ifndef NECFSM_H_
#define NECFSM_H_

//Include
#include "timer.h"

//Forward declarations


class NecFsm 
{
	public:
		enum Event{evRisingEdge, evTimeout, evFrameEnd};
	
    NecFsm();

		void process(Event e);

	private:
		enum State{readyState, startPulseState, frameStartState, oneState, zeroState};
    enum {startPulseMinLength = 13000, startPulseMaxLength = 14000}; 		
    State currentState;
    Timer timer;
};

#endif /* NECFSM_H_ */

