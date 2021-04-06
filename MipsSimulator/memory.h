/* Memory is defined by an unordered_map instead an array. Because array
 * is ordered and address of the memery can be up to 0x7fffffc. If an array
 * is used it will be too large. Unordered_map can solve this problem perfectly
 * because map can store pairs of key and value. Here key is address and value
 * is data stred in this address.
 */
#ifndef MEMORY_H
#define MEMORY_H

#include <bitset>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include "typedefine.h"

using namespace std;

class Memory
{
public:
    Memory();

    // Return the memory.
    unordered_map<bitset32, bitset8> getMemory() { return this->memory; }

    // Load instructions to the instruction memory.
    void loadInstructions(string fileName);

    // Write data to address
    void writeData(bitset32 address, bitset32 data);

    // Read data from address.
    bitset32 getMemData(bitset32 address);

private:
    unordered_map<bitset32, bitset8> memory;
};

#endif // MEMORY_H
