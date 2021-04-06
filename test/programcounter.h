/* If countIncreament is called the value of counter will increased by 4.
 * setCount() can set the counter to any value.
 * getCount() returns the current value of the counter.
 */
#ifndef PROGRAMCOUNTER_H
#define PROGRAMCOUNTER_H

#define INIT_COUNT 0x00400000
#include <iostream>

class ProgramCounter
{
private:
    uint32_t count;
public:
    ProgramCounter() { count = INIT_COUNT; }
    uint32_t getCount() { return count; }
    void setCount(uint32_t value) { count = value; };
    void countIncreament() { count = count + 4; };
};

#endif // PROGRAMCOUNTER_H
