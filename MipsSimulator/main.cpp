#include "controller.h"

int main()
{
    /* Initialize all components including
     * ALU, Register, ProgramCounter, Sign Extand and Bit Shift,
     * Instruction Register and Memory.
     *
     * Then construct a Controller object with all the initialized components.
     *
     * Supported operations:
     * add, addu, addi, addiu, lui, beq, j, sw
     */

    // Initialize components.
    string fileName = "demo.txt";
    ALU alu;
    Register registers;
    ProgramCounter programCounter;
    SignExtAndBitShift signExtAndBitShift;
    InstructionRegister instructionRegister;
    Memory memory;

    // Load instructions from the file to the memory.
    // All of the instructions will be stroed in the instruction memory (0x0040,0000 - 0x1000,0000).
    memory.loadInstructions(fileName);

    // Connect all components to the controller.
    Controller controller(
                alu,
                instructionRegister,
                memory,
                programCounter,
                registers,
                signExtAndBitShift);

    // Start running the machine code.
    controller.startUp();

    return 0;
}
