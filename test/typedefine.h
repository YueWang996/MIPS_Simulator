/* Define some names of variables and structs.
 */
#ifndef TYPEDEFINE_H
#define TYPEDEFINE_H

#include <bitset>
#include <iostream>

using namespace std;

typedef bitset<32> bitset32;
typedef bitset<26> bitset26;
typedef bitset<16> bitset16;
typedef bitset<8> bitset8;
typedef bitset<6> bitset6;
typedef bitset<5> bitset5;
typedef bitset<1> bitset1;

struct AluResult {
    bitset1 zero;
    bitset32 result;
    bool operator==(const AluResult aluResult) const {
        return (this->result == aluResult.result) & (this->zero == aluResult.zero);
    }
    friend ostream & operator<<(ostream &, AluResult &r) {
        cout << "Result: " << r.result << " IsZero: " << r.zero << endl;
        return cout;
    }
};

struct InstReg {
    bitset6 opcode;
    bitset5 rs;
    bitset5 rt;
    bitset5 rd;
    bitset5 shamt;
    bitset6 funct;
    bitset16 imm;
    bitset26 address;
    bitset32 inst;
};

#endif // TYPEDEFINE_H
