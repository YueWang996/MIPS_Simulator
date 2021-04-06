#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites
#include <boost/test/unit_test.hpp>


#include "alu.h"
BOOST_AUTO_TEST_SUITE(ALU_TEST)

#define ADD bitset6(0x20)
#define ADDU bitset6(0x21)
#define SUB bitset6(0x22)

ALU alu;

BOOST_AUTO_TEST_CASE(ADD_TEST)
{
    AluResult add_result1;
    add_result1.result = bitset32(10);
    add_result1.zero = bitset1(0);
    BOOST_CHECK(alu.calc(bitset32(2), bitset32(8), ADD) == add_result1);
    BOOST_TEST_MESSAGE("alu.calc(bitset32(2), bitset32(8), ADD)="<< (int32_t) alu.calc(bitset32(2), bitset32(8), ADD).result.to_ulong()
        << ", expected: " <<  (int32_t) add_result1.result.to_ulong());

    AluResult add_result2;
    add_result2.result = bitset32(0);
    add_result2.zero = bitset1(1);
    BOOST_CHECK(alu.calc(bitset32(5), bitset32(-5), ADD) == add_result2);
    BOOST_TEST_MESSAGE("alu.calc(bitset32(5), bitset32(-5), ADD)="<< (int32_t) alu.calc(bitset32(5), bitset32(-5), ADD).result.to_ulong()
        << ", expected: " << (int32_t) add_result2.result.to_ulong());

    AluResult add_result3;
    add_result3.result = bitset32(-5);
    add_result3.zero = bitset1(0);
    BOOST_CHECK(alu.calc(bitset32(2), bitset32(-7), ADD) == add_result3);
    BOOST_TEST_MESSAGE("alu.calc(bitset32(2), bitset32(-7), ADD)="<< (int32_t) alu.calc(bitset32(2), bitset32(-7), ADD).result.to_ulong()
        << ", expected: " << (int32_t) add_result3.result.to_ulong());
}

BOOST_AUTO_TEST_CASE(ADDU_TEST)
{
    AluResult addu_result1;
    addu_result1.result = bitset32(100);
    addu_result1.zero = bitset1(0);
    BOOST_CHECK(alu.calc(bitset32(20), bitset32(80), ADDU) == addu_result1);
    BOOST_TEST_MESSAGE("alu.calc(bitset32(20), bitset32(80), ADDU)="<< alu.calc(bitset32(20), bitset32(80), ADDU).result.to_ulong()
        << ", expected: " << addu_result1.result.to_ulong());

    AluResult addu_result2;
    addu_result2.result = bitset32(0);
    addu_result2.zero = bitset1(1);
    BOOST_CHECK(alu.calc(bitset32(0), bitset32(0), ADDU) == addu_result2);
    BOOST_TEST_MESSAGE("alu.calc(bitset32(0), bitset32(0), ADDU)="<< alu.calc(bitset32(0), bitset32(0), ADDU).result.to_ulong()
        << ", expected: " << addu_result2.result.to_ulong());
}

BOOST_AUTO_TEST_CASE(SUB_TEST)
{
    AluResult sub_result1;
    sub_result1.result = bitset32(-6);
    sub_result1.zero = bitset1(0);
    BOOST_CHECK(alu.calc(bitset32(2), bitset32(8), SUB) == sub_result1);
    BOOST_TEST_MESSAGE("alu.calc(bitset32(2), bitset32(8), SUB)="<< (int32_t) alu.calc(bitset32(2), bitset32(8), SUB).result.to_ulong()
        << ", expected: " <<  (int32_t) sub_result1.result.to_ulong());

    AluResult sub_result2;
    sub_result2.result = bitset32(0);
    sub_result2.zero = bitset1(1);
    BOOST_CHECK(alu.calc(bitset32(5), bitset32(5), SUB) == sub_result2);
    BOOST_TEST_MESSAGE("alu.calc(bitset32(5), bitset32(5), SUB)="<< (int32_t) alu.calc(bitset32(5), bitset32(5), SUB).result.to_ulong()
        << ", expected: " << (int32_t) sub_result2.result.to_ulong());

    AluResult sub_result3;
    sub_result3.result = bitset32(-5);
    sub_result3.zero = bitset1(0);
    BOOST_CHECK(alu.calc(bitset32(-15), bitset32(-10), SUB) == sub_result3);
    BOOST_TEST_MESSAGE("alu.calc(bitset32(-15), bitset32(-10), SUB)="<< (int32_t) alu.calc(bitset32(-15), bitset32(-10), SUB).result.to_ulong()
        << ", expected: " << (int32_t) sub_result3.result.to_ulong());
}

BOOST_AUTO_TEST_SUITE_END()


#include "instructionregister.h"
BOOST_AUTO_TEST_SUITE(INSTRUCTION_REGISTER_TEST)

InstructionRegister instructionRegister;

BOOST_AUTO_TEST_CASE(INSTRUCTION_DECOMPOSITION_TEST)
{
    bitset6 opcode("000101");
    bitset5 rs("00010");
    bitset5 rt("01010");
    bitset5 rd("10000");
    bitset5 shamt("11000");
    bitset6 funct("101000");
    bitset16 imm("1000011000101000");
    bitset26 address("00010010101000011000101000");
    bitset32 inst("00010100010010101000011000101000");

    BOOST_CHECK(instructionRegister.instructionDecomposition(inst).opcode == opcode);
    BOOST_TEST_MESSAGE("instructionRegister.instructionDecomposition(inst).opcode="
        << instructionRegister.instructionDecomposition(inst).opcode << ", expected: " << opcode);

    BOOST_CHECK(instructionRegister.instructionDecomposition(inst).rs == rs);
    BOOST_TEST_MESSAGE("instructionRegister.instructionDecomposition(inst).rs="
        << instructionRegister.instructionDecomposition(inst).rs << ", expected: " << rs);

    BOOST_CHECK(instructionRegister.instructionDecomposition(inst).rt == rt);
    BOOST_TEST_MESSAGE("instructionRegister.instructionDecomposition(inst).tr="
        << instructionRegister.instructionDecomposition(inst).rt << ", expected: " << rt);

    BOOST_CHECK(instructionRegister.instructionDecomposition(inst).rd == rd);
    BOOST_TEST_MESSAGE("instructionRegister.instructionDecomposition(inst).rd="
        << instructionRegister.instructionDecomposition(inst).rd << ", expected: " << rd);

    BOOST_CHECK(instructionRegister.instructionDecomposition(inst).shamt == shamt);
    BOOST_TEST_MESSAGE("instructionRegister.instructionDecomposition(inst).shmat="
        << instructionRegister.instructionDecomposition(inst).shamt << ", expected: " << shamt);

    BOOST_CHECK(instructionRegister.instructionDecomposition(inst).funct == funct);
    BOOST_TEST_MESSAGE("instructionRegister.instructionDecomposition(inst).funct="
        << instructionRegister.instructionDecomposition(inst).funct << ", expected: " << funct);

    BOOST_CHECK(instructionRegister.instructionDecomposition(inst).imm == imm);
    BOOST_TEST_MESSAGE("instructionRegister.instructionDecomposition(inst).imm="
        << instructionRegister.instructionDecomposition(inst).imm << ", expected: " << imm);

    BOOST_CHECK(instructionRegister.instructionDecomposition(inst).address == address);
    BOOST_TEST_MESSAGE("instructionRegister.instructionDecomposition(inst).address="
        << instructionRegister.instructionDecomposition(inst).address << ", expected: " << address);
}
BOOST_AUTO_TEST_SUITE_END()


#include "memory.h"
BOOST_AUTO_TEST_SUITE(MEMORY_TEST)

Memory memory;

BOOST_AUTO_TEST_CASE(MEMORY_RW_TEST)
{
    bitset32 address(0x10001000);
    bitset32 data(2500);
    memory.writeData(address, data);
    BOOST_CHECK((int32_t) memory.getMemData(address).to_ulong() == (int32_t) data.to_ulong());
    BOOST_TEST_MESSAGE("(int32_t) memory.getMemData(address).to_ulong()=" << (int32_t) memory.getMemData(address).to_ulong()
        << ", expected: " << (int32_t) data.to_ulong());
}

BOOST_AUTO_TEST_SUITE_END()


#include "register.h"
BOOST_AUTO_TEST_SUITE(MEMORY_TEST)

Register registers;

BOOST_AUTO_TEST_CASE(REGISTER_RW_TEST)
{
    bitset32 data(100);
    bitset5 registerNumber(10);
    registers.setRegisters(registerNumber, data);
    BOOST_CHECK((int32_t) registers.getRegisterValue(registerNumber).to_ulong() == (int32_t) data.to_ulong());
    BOOST_TEST_MESSAGE("(int32_t) registers.getRegisterValue(registerNumber).to_ulong()="
        << (int32_t) registers.getRegisterValue(registerNumber).to_ulong() << ", expected: "
        << (int32_t) data.to_ulong());
}

BOOST_AUTO_TEST_SUITE_END()


#include "utilities.h"
BOOST_AUTO_TEST_SUITE(UTILITY_TEST)
BOOST_AUTO_TEST_CASE(Hex2Bin_TEST)
{
    string hexStr("ABC123");
    string binStr("101010111100000100100011");
    BOOST_CHECK(Utilities::Hex2Bin(hexStr) == binStr);
    BOOST_TEST_MESSAGE("Utilities::Hex2Bin(hexStr)=" << Utilities::Hex2Bin(hexStr)
        << ", expected: " << binStr);
}

BOOST_AUTO_TEST_CASE(hexStr2Bitset8_TEST)
{   
    string hexStr("AB");
    bitset8 bs("10101011");
    BOOST_CHECK(Utilities::hexStr2Bitset8(hexStr) == bs);
    BOOST_TEST_MESSAGE("Utilities::hexStr2Bitset8(hexStr)=" << Utilities::hexStr2Bitset8(hexStr)
        << ", expected: " << bs);
}

BOOST_AUTO_TEST_SUITE_END()


#include "programcounter.h"
BOOST_AUTO_TEST_SUITE(PROGRAM_COUNTER_TEST)

ProgramCounter programCounter;

BOOST_AUTO_TEST_CASE(SET_TEST)
{
    uint32_t count(0x00400010);
    programCounter.setCount(count);
    BOOST_CHECK(programCounter.getCount() == count);
    BOOST_TEST_MESSAGE("programCounter.getCount()=" << programCounter.getCount()
        << ", expected: " << count);
}

BOOST_AUTO_TEST_CASE(COUNT_TEST)
{
    uint32_t count(0x00400014);
    programCounter.setCount(count);
    programCounter.countIncreament();
    BOOST_CHECK(programCounter.getCount() == count+4);
    programCounter.setCount(count);
    programCounter.countIncreament();
    BOOST_TEST_MESSAGE("programCounter.countIncreament()=" << programCounter.getCount()
        << ", expected: " << count+4);
}

BOOST_AUTO_TEST_SUITE_END()


#include "signextandbitshift.h"
BOOST_AUTO_TEST_SUITE(SIGN_EXT_AND_BIT_SHIFT_TEST)

SignExtAndBitShift signExtAndBitShift;

BOOST_AUTO_TEST_CASE(SIGN_EXT_TEST)
{
    bitset32 signExtendedPos("00000000000000000000011111010000");
    bitset16 dataPos("0000011111010000");
    BOOST_CHECK(signExtAndBitShift.signExtend(dataPos) == signExtendedPos);
    BOOST_TEST_MESSAGE("signExtAndBitShift.signExtend(dataPos)=" << signExtAndBitShift.signExtend(dataPos)
        << ", expected: " << signExtendedPos);

    bitset32 signExtendedNeg("11111111111111111000011111010000");
    bitset16 dataNeg("1000011111010000");
    BOOST_CHECK(signExtAndBitShift.signExtend(dataNeg) == signExtendedNeg);
    BOOST_TEST_MESSAGE("signExtAndBitShift.signExtend(dataNeg)=" << signExtAndBitShift.signExtend(dataNeg)
        << ", expected: " << signExtendedNeg);
}

BOOST_AUTO_TEST_CASE(SHIFT_LEFT_BY_16_TEST)
{
    bitset32 shifted("00111000011111010000000000000000");
    bitset16 unshifted("0011100001111101");
    BOOST_CHECK(signExtAndBitShift.shiftLeftBy16(unshifted) == shifted);
    BOOST_TEST_MESSAGE("signExtAndBitShift.shiftLeftBy16(unshifted)=" << signExtAndBitShift.shiftLeftBy16(unshifted)
        << ", expected: " << shifted);
}

BOOST_AUTO_TEST_CASE(SHIFT_LEFT_BY_2_TEST)
{
    bitset32 shifted("00001111000011111010000000000000");
    bitset26 unshifted("11110000111110100000000000");
    BOOST_CHECK(signExtAndBitShift.shiftLeftBy2(unshifted) == shifted);
    BOOST_TEST_MESSAGE("signExtAndBitShift.shiftLeftBy2(unshifted)=" << signExtAndBitShift.shiftLeftBy2(unshifted)
        << ", expected: " << shifted);
}

BOOST_AUTO_TEST_CASE(SIGN_EXT_AND_SHIFT_LEFT_BY_2_TEST)
{
    bitset32 shifted("11111111111111111010000000000000");
    bitset16 unshifted("1110100000000000");
    BOOST_CHECK(signExtAndBitShift.signExtendAndShiftLeftBy2(unshifted) == shifted);
    BOOST_TEST_MESSAGE("signExtAndBitShift.signExtendAndShiftLeftBy2(unshifted)=" << signExtAndBitShift.signExtendAndShiftLeftBy2(unshifted)
        << ", expected: " << shifted);
}

BOOST_AUTO_TEST_SUITE_END()


#include "controller.h"
BOOST_AUTO_TEST_SUITE(CONTROLLER_TEST)
BOOST_AUTO_TEST_CASE(RESULTS_TEST)
{
    string fileName = "demo.txt";
    ALU alu;
    Register registers;
    ProgramCounter programCounter;
    programCounter.setCount(0x400000);
    SignExtAndBitShift signExtAndBitShift;
    InstructionRegister instructionRegister;
    Memory memory;
    memory.loadInstructions(fileName);
    Controller controller(alu, instructionRegister, memory,
                programCounter, registers, signExtAndBitShift);
    controller.startUp();

    // Result comparison
    vector<int> squareArray;
    for(int i = 0; i < 100; i++) {
        squareArray.push_back(i * i);
    }

    vector<int> mipsSimResult;
    unordered_map<bitset32, bitset8> temp = controller.getMemory().getMemory();
    vector<unsigned long> keys;
    string data = "";
    keys.reserve(temp.size());
    for(auto& it: temp) {
        keys.push_back(it.first.to_ulong());
    }
    sort(keys.begin(), keys.end());
    for(auto& it: keys) {
        if(it >= 0x10000000 && it < 0x10008000) {
            if(it % 4 == 3) {
                data += controller.getMemory().getMemory()[it].to_string();
                mipsSimResult.push_back((int32_t) bitset32(data).to_ulong());
                data = "";
            } else {
                data += controller.getMemory().getMemory()[it].to_string();
            }
        }
    }
    
    
    BOOST_CHECK(mipsSimResult == squareArray);
    if(mipsSimResult == squareArray) {
        BOOST_TEST_MESSAGE("mipsSimResult == squareArray, test passed!");
    } else {
        BOOST_TEST_MESSAGE("mipsSimResult != squareArray, test failed!");
    }

}
BOOST_AUTO_TEST_SUITE_END()