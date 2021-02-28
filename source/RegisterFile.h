
#ifndef _REGISTER_FILE_H_
#define _REGISTER_FILE_H_

// Libraries
#include "global_vars.h"

// Register File class
class RegisterFile {

	public:

		// Register
		struct Register {
			bit32 value;
		};

		// List of registers
		Register registers[32];
		
		// Init Register File
		void init ();

		// Read a register
		bit32 read (bit5 reg);

		// Write a register
		void write (bit5 reg, bit32 value);
};


#endif // _REGISTER_FILE_H_
