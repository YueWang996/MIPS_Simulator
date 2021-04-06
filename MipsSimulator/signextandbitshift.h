/* This module is a combination of sign extend, shift left 2 and shift left 16.
 * signExtend will extend a 16-bit value to 32-bit.
 * shiftLeftBy16 will shift a 16-bit value to left by 16-bit.
 * shiftLeftBy2 will shift a 26-bit value to left by 2-bit.
 * signExtendAndShiftLeftBy2 will extend a 16-bit value to 32 bit then shift it left by 2.
 */
#ifndef SIGNEXTANDBITSHIFT_H
#define SIGNEXTANDBITSHIFT_H

#include "typedefine.h"

class SignExtAndBitShift
{
public:
    SignExtAndBitShift();
    bitset32 signExtend(bitset16 val);
    bitset32 shiftLeftBy16(bitset16 val);
    bitset32 shiftLeftBy2(bitset26 val);
    bitset32 signExtendAndShiftLeftBy2(bitset16 val);
};

#endif // SIGNEXTANDBITSHIFT_H
