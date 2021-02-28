

#ifndef _REORDER_BUFFER_H_
#define _REORDER_BUFFER_H_

// Libraries
#include "global_vars.h"
#include "RegisterFile.h"
#include "CommonDataBus.h"

#define _REORDER_BUFFER_SIZE_ 5

// Reorder Buffer class
class ReorderBuffer {

	public:

		// Buffered Command stage
		struct BufferedCommand {
			bool active;

			bool done;
			bit5 tag;
			bit5 destination;
			bit32 result;

			bit32 command;
			bit5 exception_status;
			bit32 PC;
		};
		// List of commands
		BufferedCommand buffer[_REORDER_BUFFER_SIZE_];
		// Commands indexes
		int bufferTop;
		int bufferBottom;

		// Register
		struct RegisterStatus {
			bool reference;
			bit5 tag;
		};
		// List of registers
		RegisterStatus registers[32];

		// Register File pointer
		RegisterFile* rf;
		
		// Init buffer
		void init (RegisterFile* rf);

		// Check if register has reference
		bool hasReference (bit5 reg);
		// Get register's reference
		bit5 readReference (bit5 reg);

		// Check if it is full
		bool isFull ();
		// Load Command
		void load (bit5 tag, bit5 Rd, bit32 command, bit32 pc);


		// Common data bus bind
		CommonDataBus::busBind* cdb;

		// Listen on cdb
		void subscribe (CommonDataBus::busBind* cdb);

		// Send cdb values to rs
		void checkBroadcast ();

		// Save command on register file
		void checkBuffer ();
};


#endif // _REORDER_BUFFER_H_
