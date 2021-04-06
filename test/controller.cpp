#include "controller.h"

#define ADD 0x20
#define ADDU 0x21
#define SUB 0x22

Controller::Controller(ALU alu,
                       InstructionRegister instructionRegister,
                       Memory memory,
                       ProgramCounter programCounter,
                       Register registers,
                       SignExtAndBitShift signExtAndBitShift) {
    this->alu = alu;
    this->instructionRegister = instructionRegister;
    this->memory = memory;
    this-> programCounter = programCounter;
    this->registers = registers;
    this->signExtAndBitShift = signExtAndBitShift;
}

void Controller::startUp() {
    Utilities::createLog();
    while(1) {
        //Instruction Fetch
        instReg = IF();
        if(instReg.inst == 0xffffffff) {
            //Utilities::memoryOutput(memory);
            Utilities::writeInstCount(instCount);
            Utilities::writeMemoryLog(memory);
            Utilities::writeRegisterLog(registers);
            break;
        }

        //Decode
        if(Utilities::InstructionType(instReg.opcode) == "R") {
            //Execution
            rsVal = registers.getRegisterValue(instReg.rs);
            rtVal = registers.getRegisterValue(instReg.rt);
            aluResult = alu.calc(rsVal, rtVal, instReg.funct);

            //Write Back
            WB(instReg.rd, aluResult.result);

            programCounter.countIncreament();

        } else if(Utilities::InstructionType(instReg.opcode) == "j") {
            programCounter.setCount(signExtAndBitShift.shiftLeftBy2(instReg.address).to_ulong());
        } else if(Utilities::InstructionType(instReg.opcode) == "addi") {
            //Execution
            rsVal = registers.getRegisterValue(instReg.rs);
            signExtended = signExtAndBitShift.signExtend(instReg.imm);
            aluResult = alu.calc(rsVal, signExtended, ADD);

            //Write Back
            WB(instReg.rt, aluResult.result);

            programCounter.countIncreament();

        } else if(Utilities::InstructionType(instReg.opcode) == "addiu") {
            //Execution
            rsVal = registers.getRegisterValue(instReg.rs);
            signExtended = signExtAndBitShift.signExtend(instReg.imm);
            aluResult = alu.calc(rsVal, signExtended, ADDU);

            //Write Back
            WB(instReg.rt, aluResult.result);

            programCounter.countIncreament();

        } else if(Utilities::InstructionType(instReg.opcode) == "lui") {
            //Write Back
            shiftedLeftBy16 = signExtAndBitShift.shiftLeftBy16(instReg.imm);
            WB(instReg.rt, shiftedLeftBy16);

            programCounter.countIncreament();

        } else if(Utilities::InstructionType(instReg.opcode) == "sw") {
            //Execution
            rsVal = registers.getRegisterValue(instReg.rs);
            rtVal = registers.getRegisterValue(instReg.rt);
            signExtended = signExtAndBitShift.signExtend(instReg.imm);
            aluResult = alu.calc(rsVal, signExtended, ADDU);

            //Memory
            MEM_W(aluResult.result, rtVal);

            programCounter.countIncreament();

        } else if(Utilities::InstructionType(instReg.opcode) == "beq") {
            //Execution
            rsVal = registers.getRegisterValue(instReg.rs);
            rtVal = registers.getRegisterValue(instReg.rt);
            signExtendedAndShiftedLeftBy2 = signExtAndBitShift.signExtendAndShiftLeftBy2(instReg.imm);
            aluResult = alu.calc(rsVal, rtVal, SUB);

            if(aluResult.zero == 1) {
                programCounter.countIncreament();
                programCounter.setCount((uint32_t) signExtendedAndShiftedLeftBy2.to_ulong() +
                                        programCounter.getCount());
            } else {
                programCounter.countIncreament();
            }
        } else {
            cout << "Error!" << endl;
            break;
        }
        instCount++;
        //Utilities::writeInstLog(instReg);
    }
}

InstReg Controller::IF() {
    pc = programCounter.getCount();
    instruction = memory.getMemData(pc);
    return instructionRegister.instructionDecomposition(instruction);
}

void Controller::WB(bitset5 address, bitset32 result) {
    registers.setRegisters(address, result);
}

void Controller::MEM_W(bitset32 address, bitset32 data) {
    memory.writeData(address, data);
}
