#include "utilities.h"

#include <sstream>
#include <bitset>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>


Utilities::Utilities()
{

}

string Utilities::Hex2Bin(string strHex){
    stringstream ss;
    ss << hex << strHex;
    string bin;
    string s;

    unsigned int n;
    while(ss >> n){
       for (int i = strHex.length()*4-1; i >= 0; i--)
        //cout << ((n >> i) & 1) ? "1" : "0";
           s += ((n >> i) & 1) ? "1" : "0";

     //cout << std::endl;
    }
    return s;
}

string Utilities::InstructionType(bitset6 opcode) {
    if(opcode == 0x0) {
        return "R";
    } else if(opcode == 0x2) {
        return "j";
    } else if(opcode == 0x8) {
        return "addi";
    } else if(opcode == 0x9) {
        return "addiu";
    } else if(opcode == 0xf) {
        return "lui";
    } else if(opcode == 0x2b) {
        return "sw";
    } else if(opcode == 0x23) {
        return "lw";
    } else if(opcode == 0x4) {
        return "beq";
    } else {
        return "Invalid Operation Code: " + opcode.to_string();
    }
}

bitset8 Utilities::hexStr2Bitset8(string str) {
    bitset8 bs(Utilities::Hex2Bin(str));
    return bs;
}

void Utilities::memoryOutput(Memory memory) {
    unordered_map<bitset32, bitset8> temp = memory.getMemory();
    vector<unsigned long> keys;
    string data = "";

    keys.reserve(temp.size());
    for(auto& it: temp) {
        keys.push_back(it.first.to_ulong());
    }
    sort(keys.begin(), keys.end());
    for(auto& it: keys) {
        if(it >= 0x400000 && it < 0x10000000) {
            if(it % 4 == 3) {
                data += memory.getMemory()[it].to_string();
                cout << "Text: 0x" << setfill('0') << setw(8) << hex << it-3 << ": " << bitset32(data) << endl;
                data = "";
            } else {
                data += memory.getMemory()[it].to_string();
            }
        } else if(it >= 0x10000000 && it < 0x10008000) {
            if(it % 4 == 3) {
                data += memory.getMemory()[it].to_string();
                cout << "StaticData: 0x" << setfill('0') << setw(8) << hex << it-3 << ": " << dec << (int32_t) bitset32(data).to_ulong() << endl;
                data = "";
            } else {
                data += memory.getMemory()[it].to_string();
            }
        } else if(it >= 0x10008000 && it < 0x7ffffffc) {
            cout << "Stack: " << endl;
        } else {
            cout << "Memory error!" << endl;
        }

    }
}

void Utilities::createLog() {
    ofstream log("log.txt", ios_base::out | ios_base::trunc);
}

void Utilities::writeRegisterLog(Register registers) {
    ofstream registerLog;
    registerLog.open("log.txt", ios::out | ios::app);
    registerLog << "+-------------------------------------";
    registerLog << "+-------------------------------------";
    registerLog << "+-------------------------------------";
    registerLog << "+-------------------------------------+" << endl;
    for(uint32_t i = 0; i < registers.getRegisters().size(); i++) {
        if(i % 4 == 3) {
            registerLog << "|r" << setfill('0') << setw(2) << i << ": " << registers.getRegisterValue(i) << "|" << endl;
            registerLog << "+-------------------------------------";
            registerLog << "+-------------------------------------";
            registerLog << "+-------------------------------------";
            registerLog << "+-------------------------------------+" << endl;
        } else {
            registerLog << "|r" << setfill('0') << setw(2) << i << ": " << registers.getRegisterValue(i);
        }
    }
    registerLog << endl;
    registerLog.close();
}

void Utilities::writeMemoryLog(Memory memory) {
    ofstream registerLog;
    registerLog.open("log.txt", ios::out | ios::app);
    unordered_map<bitset32, bitset8> temp = memory.getMemory();
    vector<unsigned long> keys;
    string data = "";

    keys.reserve(temp.size());
    for(auto& it: temp) {
        keys.push_back(it.first.to_ulong());
    }
    sort(keys.begin(), keys.end());
    for(auto& it: keys) {
        if(it >= 0x400000 && it < 0x10000000) {
            if(it % 4 == 3) {
                data += memory.getMemory()[it].to_string();
                registerLog << "Text: 0x" << setfill('0') << setw(8) << hex << it-3 << ": " << bitset32(data) << endl;
                data = "";
            } else {
                data += memory.getMemory()[it].to_string();
            }
        } else if(it >= 0x10000000 && it < 0x10008000) {
            if(it % 4 == 3) {
                data += memory.getMemory()[it].to_string();
                registerLog << "StaticData: 0x" << setfill('0') << setw(8) << hex << it-3 << ": " << dec << (int32_t) bitset32(data).to_ulong() << endl;
                data = "";
            } else {
                data += memory.getMemory()[it].to_string();
            }
        } else if(it >= 0x10008000 && it < 0x7ffffffc) {
            registerLog << "Stack: " << endl;
        } else {
            registerLog << "Memory error!" << endl;
        }
    }
    registerLog << endl;
    registerLog.close();
}

void Utilities::writeInstLog(InstReg instReg) {
    ofstream registerLog;
    registerLog.open("log.txt", ios::out | ios::app);
    registerLog << "Instruction: " << instReg.inst << "  Instruction Name: "
                << Utilities::InstructionType(instReg.opcode) << endl;
    registerLog << endl;
    registerLog.close();
}

void Utilities::writeInstCount(uint64_t count) {
    ofstream registerLog;
    registerLog.open("log.txt", ios::out | ios::app);
    registerLog << count << " instructions had been executed!" << endl;
    registerLog << endl;
    registerLog.close();
}
