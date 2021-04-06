#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "alu.h"
#include "instructionregister.h"
#include "memory.h"
#include "programcounter.h"
#include "register.h"
#include "signextandbitshift.h"
#include "typedefine.h"
#include "utilities.h"

class Controller
{
public:
    Controller(ALU alu,
        InstructionRegister instructionRegister,
        Memory memory,
        ProgramCounter programCounter,
        Register registers,
        SignExtAndBitShift signExtAndBitShift);

    void startUp();

    InstReg IF();

    void MEM_W(bitset32 address, bitset32 data);

    void WB(bitset5 address, bitset32 result);

    Memory getMemory() { return memory; }

private:
    ALU alu;
    InstructionRegister instructionRegister;
    Memory memory;
    ProgramCounter programCounter;
    Register registers;
    SignExtAndBitShift signExtAndBitShift;

    // Temp values.
    InstReg instReg;
    uint32_t pc;
    bitset32 instruction;
    AluResult aluResult;
    bitset32 rsVal;
    bitset32 rtVal;
    bitset32 signExtended;
    bitset32 shiftedLeftBy2;
    bitset32 shiftedLeftBy16;
    bitset32 signExtendedAndShiftedLeftBy2;
    uint64_t instCount = 0;
};

#endif // CONTROLLER_H
