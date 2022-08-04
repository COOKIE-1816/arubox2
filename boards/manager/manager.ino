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
int button;

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
        static bool isActive() {
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
        static void readConfig() {};
        static void startSetup() {
            Serial.begin(bps);
        };
    */
};

class Clock {
    public:
        int sec = 0;
        int min = 0;
        int hrs = 0;

        static void inform() {
            Clock clk;

            analogWrite(seconds, clk.sec);
            analogWrite(minutes, clk.min);
            analogWrite(hours, clk.hrs);
        };

        static void reset() {
            Clock clk;

            clk.sec = 0;
            clk.min = 0;
            clk.hrs = 0;
        };

        static void increase(int seconds) {
            Clock clk;

            if(clk.sec == 59) {  //ok
                if(clk.min == 59) { //ok
                    if(clk.hrs == 23) {
                        clk.reset();
                    } else {
                        clk.hrs = clk.hrs + 1;
                        clk.min = 0;
                        clk.sec = 0;
                    }
                } else {
                    clk.min = clk.min + 1;
                    clk.sec = 0;
                }
            } else {
                clk.sec = clk.sec + 1;
            }
        };
};

class Power {
    public:
        static void sigtermf() {
            Serial.println("Send signal: SIGTERMf");

            digitalWrite(signalizator, HIGH);
            delay(200);
            digitalWrite(signalizator, LOW);

            for(int i = 0; i < 61; i++) {
                if(!isActive()) {
                    Power::power(false);                                                            // Power off
                }
            }

            Power::power(false);                                                                    // Power off
        };

        static void power(bool power_) {
            if(power_) {
                Serial.println("Power on...");

                digitalWrite(board, HIGH);
                exceptedBoardStatus = HIGH;
            } else {
                Serial.println("Power off...");

                digitalWrite(board, LOW);
                exceptedBoardStatus = LOW;
            }
        };

        static void reset(bool force) {
            if(force) {
                Power::power(false);
            } else {
                Power::sigtermf();
            }

            //delay(500);
            Power::power(true);
        }
};

void setup() {
    Serial.begin(bps);
}

void loop() {
    if(digitalRead(button) != LOW) {
        if((digitalRead(boardStatusIndicator) == exceptedBoardStatus) == false) {
            if(attemp > 10) {
                exceptedBoardStatus = digitalRead((boardStatusIndicator));
                int attemp = 0;

                Serial.println("Fatal: could not update board status!");
            } else {
                digitalWrite(board, exceptedBoardStatus);
                attemp++;
            }
        }
        Clock::increase(1);
        Clock::inform();

        delay(1000);
    } else {
        unsigned long duration = pulseInLong(button, HIGH, duration);
        if(duration > 2999) {
            Power::power(false);
        } else {
            Power::sigtermf();
        }
    }
}
