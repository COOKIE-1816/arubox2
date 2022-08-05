#ifndef Memory_h
#define Memory_h

#include "Arduino.h"

class Memory {
    public:
        void begin();
        void fill(int value);
        void clear();
    private:
        int bits[8] = {
            "N", "N", "N", "N",
            "N", "N", "N", "N"
        };

        int size_ = 0;

        int slclr;
        int ser;
        int oe;
        int rclk;
        int srclk;
}

#endif