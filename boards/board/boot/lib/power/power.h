#ifndef Library_h
#define Library_h

#include "Arduino.h"

class Power {
    public:
        void begin();

        void reset();
        void off();
        void sigtermf_recieved();
    private:
        int reset_pin;
        int pooff_pin;
};

#endif