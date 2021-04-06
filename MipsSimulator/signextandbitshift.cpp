#include "signextandbitshift.h"
#include <iostream>
SignExtAndBitShift::SignExtAndBitShift()
{
}

bitset32 SignExtAndBitShift::signExtend(bitset16 val) {
    bitset32 result((int16_t) val.to_ulong());
    return result;
}

bitset32 SignExtAndBitShift::shiftLeftBy16(bitset16 val) {
    bitset32 result(val.to_string());
    return (result << 16);
}

bitset32 SignExtAndBitShift::shiftLeftBy2(bitset26 val) {
    bitset32 result(val.to_string());
    return (result << 2);
}

bitset32 SignExtAndBitShift::signExtendAndShiftLeftBy2(bitset16 val) {
    return (bitset32(signExtend(val)) << 2);
}
