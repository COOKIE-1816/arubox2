#include "Arduino.h"
#include "lib/power/power.h"

void Power::begin() {
    CIOBS ciobs;

    reset_pin = ciobs.values.reset_pin;
    pooff_pin = ciobs.values.power_off_pin;

    pinMode(reset_pin, OUTPUT);
    pinMode(pooff_pin, OUTPUT);
}

void Power::off() {
    digitalWrite(pooff_pin, HIGH);
    delay(5000);

    if(pmnr_show) {
        Serial.println("Power manager not responding...");
        pmnr_show = false;
    }

    Power::off();
}

void Power::reset() {
    digitalWrite(reset_pin, HIGH);
    delay(5000);

    if(pmnr_show) {
        Serial.println("Power manager not responding...");
        pmnr_show = false;
    }

    Power::off();
}

void Power::sigtermf_recieved() {
    signal_handler(001, 524);
}