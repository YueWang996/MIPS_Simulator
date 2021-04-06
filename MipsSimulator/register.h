/* Initialize a 32 * 32 register file.
*  It is defined by a vector and each element is a type of bitset<32>.
*  setRegister can be used to set the data in the register by register number.
*  getRegisterValue can be used to get the value in the register by register number.
*  getRegisters will return the whole register array.
*/
#ifndef REGISTER_H
#define REGISTER_H

#include <vector>
#include <string>
#include <iostream>
#include <bitset>
#include "typedefine.h"

using namespace std;

class Register
{
public:
    Register();
    void setRegisters(bitset5 registerNumber, bitset32 data);
    vector<bitset32> getRegisters() { return registers; }
    bitset32 getRegisterValue(bitset5 registerNumber);
private:
    vector<bitset32> registers;
};

#endif // REGISTER_H
