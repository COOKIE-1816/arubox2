#include "Arduino.h"
#include "lib/memory/memory.h"
#include <iostream>

void Memory::begin() {
    CIOBS ciobs;

    size_ = ciobs.values.memory_size;

    bits[0] = ciobs.values.memory_bit0;
    bits[1] = ciobs.values.memory_bit1;
    bits[2] = ciobs.values.memory_bit2;
    bits[3] = ciobs.values.memory_bit3;
    bits[4] = ciobs.values.memory_bit4;
    bits[5] = ciobs.values.memory_bit5;
    bits[6] = ciobs.values.memory_bit6;
    bits[7] = ciobs.values.memory_bit7;

    for(int current = 0; current < size_; current++) {
        pinMode(bits[current], INPUT);
    }


    slclr = ciobs.values.memory_slclr;
    ser = ciobs.values.memory_ser;
    oe = ciobs.values.memory_oe;
    rclk = ciobs.values.rclk;
    srclk = ciobs.values.srclk;

    pinMode(slclr, OUTPUT);
    pinMode(ser, OUTPUT);
    pinMode(oe, OUTPUT);
    pinMode(rclk, OUTPUT);
    pinMode(srclk, OUTPUT);

    int latchPin = rclk;
    int clockPin = srclk;
    int dataPin = ser;
}

void Memory::getBinary() {
    Memory memory;

    string bin = "";

    for(int current = 0; current < size_; current++) {
        if(memory.getBit(current) == 1) {
            bin = bin + "1";
        } else {
            bin = bin + "0";
        }
    }

    return bin;
}

void Memory::setBinary(bin /*binary*/) {
    digitalWrite(latchPin, LOW);

    shiftOut(dataPin, clockPin, MSBFIRST, bin);

    digitalWrite(latchPin, HIGH);
    delay(50);
}

void Memory::setBit(int bit, char value) {
    digitalWrite(latchPin, LOW);

    value_ Memory.getBinary();
    value_[bit + 1] = value;
    value = "B" + value_;

    shiftOut(dataPin, clockPin, MSBFIRST, value_);

    digitalWrite(latchPin, HIGH);
    delay(50);
}

void Memory::getBit(int bit) {
    if(digitalRead(bits[bit]) == HIGH) {
        return 1;
    } else {
        return 0;
    }
}

void Memory::clear() {
    Memory memory;

    for(int current = 0; current < size_; current++) {
        memory.setBit(current, "0");
    }
}

void Memory::fill(int value) {
    if(value == 0) {
        Memory memory;
        memory.clear();
    }
}