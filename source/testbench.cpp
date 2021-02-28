

// Libraries
#include "testbench.h"
// Debug Libraries
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>


/*
 * Define testbench helper functions
 * for ease of use in the testbenches
 */


/*
 * Print bits function
 *
 * Parameters
 *     bit32 bits      Bits variable
 *     int size        Number of bits to print
 */
void printBits(bit32 bits, int size) {
	// For each bit to print
	for (int i = size - 1; i >= 0; --i) {
		// Print bit
		printf("%d", 0b1 & (bits >> i));
	}
}
