#include "register.h"

Register::Register()
{
    bitset32 val(0x0);
    for(int i = 0; i < 32; i++) {
        registers.push_back(val);
    }

    setRegisters(bitset5(28), bitset32(0x10008000));
    setRegisters(bitset5(29), bitset32(0x7ffffffc));
}

bitset32 Register::getRegisterValue(bitset5 registerNumber) {
    bitset32 data(
            registers[registerNumber.to_ulong()].to_string() +
            registers[registerNumber.to_ulong()+1].to_string() +
            registers[registerNumber.to_ulong()+2].to_string() +
            registers[registerNumber.to_ulong()+3].to_string());
    return data;
}

void Register::setRegisters(bitset5 registerNumber, bitset32 data) {
    uint8_t regNum = registerNumber.to_ulong();
    registers[regNum] = data;
}
