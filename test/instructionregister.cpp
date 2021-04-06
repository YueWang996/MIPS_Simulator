#include "instructionregister.h"

InstructionRegister::InstructionRegister()
{
}

InstReg InstructionRegister::instructionDecomposition(bitset32 instruction) {
    string insStr = instruction.to_string();
    InstReg instReg;
    instReg.opcode = bitset6(insStr.substr(0, 6));
    instReg.rs = bitset5(insStr.substr(6, 5));
    instReg.rt = bitset5(insStr.substr(11, 5));
    instReg.rd = bitset5(insStr.substr(16, 5));
    instReg.shamt = bitset5(insStr.substr(21, 5));
    instReg.funct = bitset6(insStr.substr(26, 6));
    instReg.imm = bitset16(insStr.substr(16, 16));
    instReg.address = bitset26(insStr.substr(6, 26));
    instReg.inst = instruction;
    return instReg;
}
