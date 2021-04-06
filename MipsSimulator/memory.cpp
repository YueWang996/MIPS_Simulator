#include "memory.h"
#include "utilities.h"
#include <fstream>

Memory::Memory()
{

}

void Memory::loadInstructions(string fileName) {
    uint32_t pc = 0x400000;
    ifstream in(fileName);
    string line;
    if(in) {
        while(getline(in, line)) {
            memory[bitset32(pc)] = Utilities::hexStr2Bitset8(line.substr(0, 2));
            pc++;
            memory[bitset32(pc)] = Utilities::hexStr2Bitset8(line.substr(2, 2));
            pc++;
            memory[bitset32(pc)] = Utilities::hexStr2Bitset8(line.substr(4, 2));
            pc++;
            memory[bitset32(pc)] = Utilities::hexStr2Bitset8(line.substr(6, 2));
            pc++;
        }
    } else {
        cout << "No such file." << endl;
    }
    memory[bitset32(pc)] = bitset8(0xff);
    pc++;
    memory[bitset32(pc)] = bitset8(0xff);
    pc++;
    memory[bitset32(pc)] = bitset8(0xff);
    pc++;
    memory[bitset32(pc)] = bitset8(0xff);
    /*
    unordered_map<bitset32, bitset8>::iterator iter;
        for(iter=memory.begin();iter!=memory.end();iter++)
            cout<<iter->first<<"->"<<iter->second<<endl;
    */
}

void Memory::writeData(bitset32 address, bitset32 data) {
    bitset8 data0(data.to_string().substr(24, 8));
    bitset8 data1(data.to_string().substr(16, 8));
    bitset8 data2(data.to_string().substr(8, 8));
    bitset8 data3(data.to_string().substr(0, 8));
    memory[bitset32(address.to_ulong())] = data3;
    memory[bitset32(address.to_ulong()+1)] = data2;
    memory[bitset32(address.to_ulong()+2)] = data1;
    memory[bitset32(address.to_ulong()+3)] = data0;
}

bitset<32> Memory::getMemData(bitset32 address) {
    return bitset32(
            memory[bitset32(address.to_ulong())].to_string() +
            memory[bitset32(address.to_ulong()+1)].to_string() +
            memory[bitset32(address.to_ulong()+2)].to_string() +
            memory[bitset32(address.to_ulong()+3)].to_string());
}
