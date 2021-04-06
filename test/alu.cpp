#include "alu.h"

ALU::ALU()
{
}

AluResult ALU::calc(bitset32 num1, bitset32 num2, bitset6 funct) {
    if(funct.to_ulong() == 0x20) { //add
        bitset32 result((int32_t) num1.to_ulong() + (int32_t) num2.to_ulong());
        AluResult aluResult;
        if((int32_t) result.to_ulong() == (int32_t) 0) {
            bitset1 zero(1);
            aluResult.zero = zero;
        } else {
            bitset1 zero(0);
            aluResult.zero = zero;
        }
        aluResult.result = result;
        return aluResult;
    } else if(funct.to_ulong() == 0x21) { //addu
        bitset32 result(num1.to_ulong() + num2.to_ulong());
        AluResult aluResult;
        if(result.to_ulong() == 0) {
            bitset1 zero(1);
            aluResult.zero = zero;
        } else {
            bitset1 zero(0);
            aluResult.zero = zero;
        }
        aluResult.result = result;
        return aluResult;
    } else if(funct.to_ulong() == 0x22) { //sub
        bitset32 result((int32_t) num1.to_ulong() - (int32_t) num2.to_ulong());
        AluResult aluResult;
        if((int32_t) result.to_ulong() == (int32_t) 0) {
            bitset1 zero(1);
            aluResult.zero = zero;
        } else {
            bitset1 zero(0);
            aluResult.zero = zero;
        }
        aluResult.result = result;
        return aluResult;
    } else {
        cout << "Invalid funct!" << endl;
        bitset32 result(0);
        bitset1 zero(0);
        AluResult aluResult;
        aluResult.zero = zero;
        aluResult.result = result;
        return aluResult;
    }
}
