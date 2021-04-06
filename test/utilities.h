/* Provide some useful functions.
 */
#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <bitset>
#include "typedefine.h"
#include "memory.h"
#include "register.h"
#include "instructionregister.h"

using namespace std;

class Utilities
{
public:

    Utilities();

    // Convert hexadecimal string to binary string.
    static string Hex2Bin(string strHex);

    // Parse opcode and return the type of instruction.
    static string InstructionType(bitset6 opcode);

    // Hex(2bit) string to 8-bit binary.
    static bitset8 hexStr2Bitset8(string str);

    // Print data in memory.
    static void memoryOutput(Memory memory);

    // Create logfile.
    static void createLog();

    // Write Register log.
    static void writeRegisterLog(Register registers);

    //Write Memory log.
    static void writeMemoryLog(Memory memory);

    //Write Instruction log.
    static void writeInstLog(InstReg instReg);

    static void writeInstCount(uint64_t count);
};

#endif // UTILITIES_H
