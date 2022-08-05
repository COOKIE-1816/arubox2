#ifndef Memory_h
#define Memory_h

#include "Arduino.h"
#include <iostream>

class Memory {
    public:
        void begin();

        void fill(int value);
        void clear();

        int getBit(int bit);
        void setBit(int bit, int value);

        void getBinary();
        void setBinary(bin);
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

        int len(string str) {
            int length = 0;

            for(int i = 0; str[i] != "\0"; i++) {
                length++;
            }

            return length;
        };

        void split(string str, char separator) {
            int current = 0, i = 0;
            int start = 0, end = 0;

            while(i <= len(str)) {
                if(str[i] == separator || i == len(str)) {
                    end = i;

                    string subst = "";
                    subst.append(str, start, end - start);
                    strings[current] = subst;

                    current += 1;
                    start = end + 1;
                }

                i++;
            }
        }
}

#endif