

#ifndef _RESERVATION_STATION_H_
#define _RESERVATION_STATION_H_

// Libraries
#include "global_vars.h"

// Just a single reservation station
class ReservationStation {

	public:

		// Reservetion Station name
		bit3 tag;
		bit2 parentTag;
		// Func variable
		bit2 func;

		// Busy
		bool busy;
		bool running;

		// Renaming Register
		//union Register { // Vivado problems
		struct Register {
			bit5 Q;
			bit32 V;
		};

		// Actual renaming registers
		Register s, t;
		// Value loaded
		bool s_value, t_value;

		

		
		// Init Reservation Station
		void init (bit2 parenTag, bit3 tag);

		// Clear
		void clear ();
		// Check if busy
		bool isBusy ();
		// Check if ready
		bool isReady ();
		// Check if running
		bool isRunning ();

		// Set func
		void setFunc (bit2 func);
		// Set Q of Rs
		void setQs (bit5 Q);
		// Set Q of Rt
		void setQt (bit5 Q);
		// Set V of Rs
		void setVs (bit32 V);
		// Set V of Rt
		void setVt (bit32 V);
		
		// Set running
		void setAsRunning ();

		// Check broadcast
		void checkBroadcast (bit5 Q, bit32 V);

		// Get V of Rs
		bit32 getVs ();
		// Get V of Rt
		bit32 getVt ();
		// Get name
		bit5 getName ();
		// Get func
		bit5 getFunc ();
};

#endif // _RESERVATION_STATION_H_
