/* This is the alu module. The calc() function takes three arguments which are
 * input number 1, input number 2 and function. This module has achieved function
 * ADD, ADDU, and SUB. The return type is AluResult which contains calculation
 * result and the sign of zero.
 */
#ifndef ALU_H
#define ALU_H

#include <iostream>
#include <bitset>
#include "typedefine.h"

using namespace std;

class ALU
{
public:
    ALU();
    AluResult calc(bitset32 num1, bitset32 num2, bitset6 funct);
};

#endif // ALU_H
