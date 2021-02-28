

// Libraries
#include "global_vars.h"
#include "RegisterFile.h"

// Init Register File
void RegisterFile::init () {
	// Init registers
	for (int i = 0; i < 32; ++i){
		this->registers[i].value = 0b0;
	}
};

// Read a register
bit32 RegisterFile::read (bit5 reg) {
	// Return value
	return this->registers[reg].value;
};

// Write a register
void RegisterFile::write (bit5 reg, bit32 value) {
	// If not R0
	if (reg != 0b0) {
		// Save
		this->registers[reg].value = value;
	}
};
