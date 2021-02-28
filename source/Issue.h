

#ifndef _ISSUE_H_
#define _ISSUE_H_

// Libraries
#include "global_vars.h"
#include "FunctionalUnit.h"
#include "CommonDataBus.h"
#include "RegisterFile.h"
#include "ReorderBuffer.h"

// Define command codes
#define _ISSUE_AU_CODE_ 0b01
#define _ISSUE_LU_CODE_ 0b00

// Issue class
class Issue {

	public:

		// Register file variable
		RegisterFile rf;

		// Reorder buffer variable
		ReorderBuffer rb;

		// Functional Units variables
		FunctionalArithmeticUnit fau;
		FunctionalLogicUnit flu;

		// Common Data Bus variable
		CommonDataBus cdb;

		
		// Init issue unit
		void init ();

		// Command issue
		bool issue (bit2 type, bit2 func, bit5 Rd, bit5 Rs, bit5 Rt);

};


#endif // _ISSUE_H_
