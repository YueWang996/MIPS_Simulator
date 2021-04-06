/* This module decompose a single instruction to several parts.
 * The basic instruction formats are
 *          +------+----+----+----+-----+-----+
 * R type   |opcode| rs | rt | rd |shamt|funct|
 *          +------+----+----+----+-----+-----+
 * I type   |opcode| rs | rt |    immediate   |
 *          +------+----+----+----+-----+-----+
 * J type   |opcode|          address         |
 *          +------+----+----+----+-----+-----+
 *          31     26   21   16   11    6     0
 * The return value of instructionDecomposition() is a InstReg type and
 * the defination can be find in typedefine.h library.
 */
#ifndef INSTRUCTIONREGISTER_H
#define INSTRUCTIONREGISTER_H

#include "typedefine.h"
#include <vector>
#include <string>

class InstructionRegister
{
public:
    InstructionRegister();
    InstReg instructionDecomposition(bitset32 instruction);
    InstReg getInstReg() { return instReg; }
private:
    InstReg instReg;
};

#endif // INSTRUCTIONREGISTER_H
