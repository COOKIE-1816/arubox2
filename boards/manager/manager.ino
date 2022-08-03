// --- manager.ino ---
// This file can be used to manage pover
// delivered to motherboard and operate
// hardware clock.

int attemp = 0;
int bps = 9600;
int boardStatusIndicator;
int seconds;
int minutes;
int hours;
int board;
int signalizator;
int exceptedBoardStatus;

bool isActive() {
    // return digitalRead(boardStatusIndicator) == HIGH;
    if(digitalRead(boardStatusIndicator) == HIGH) {
        return true;
    } else {
        return false;
    }
};

/*
class Monitoring {
    public:
        bool isActive() {
            // return digitalRead(boardStatusIndicator) == HIGH;
            if(digitalRead(boardStatusIndicator) == HIGH) {
                return true;
            } else {
                return false;
            }
        }
};
*/

class ManagerBoard {
    /*
    public:
        void readConfig() {};
        void startSetup() {
            Serial.begin(bps);
        };
    */
};

class Clock {
    public:
        int sec = 0;
        int min = 0;
        int hrs = 0;

        void inform() {
            analogWrite(seconds, Clock::sec);
            analogWrite(minutes, Clock::min);
            analogWrite(hours, Clock::hrs);
        };

        void reset() {
            Clock::sec = 0;
            Clock::min = 0;
            Clock::hrs = 0;
        };

        void increase(int seconds) {
            if(Clock::sec == 59) {  //ok
                if(Clock::min == 59) { //ok
                    if(Clock::hrs == 23) {
                        Clock::reset();
                    } else {
                        Clock::hrs = Clock::hrs + 1;
                        Clock::min = 0;
                        Clock::sec = 0;
                    }
                } else {
                    Clock::min = Clock::min + 1;
                    Clock::sec = 0;
                }
            } else {
                Clock::sec = Clock::sec + 1;
            }
        };
};

class Power {
    public:
        void sigtermf() {
            digitalWrite(signalizator, HIGH);
            delay(2500);
            digitalWrite(signalizator, LOW);

            for(int i = 0; i < 301; i++) {
                if(!isActive()) {
                    Power::power(false);                                                            // Power off
                }
            }

            Power::power(false);                                                                    // Power off
        };

        void power(bool power_) {
            if(power_) {
                digitalWrite(board, HIGH);
            } else {
                digitalWrite(board, LOW);
            }
        };

        void reset(bool force) {
            if(force) {
                Power::power(false);
            } else {
                Power::sigtermf();
            }

            delay(500);
            Power::power(true);
        }
};

void setup() {
    Serial.begin(bps);
}

void loop() {
    /*
    if(isActive() == exceptedBoardStatus == HIGH) {
        Clock::increase(1);
    } else {
        digitalWrite(board, exceptedBoardStatus);
    }
    */
}
