// --- manager.ino ---
// This file can be used to manage pover
// delivered to motherboard and operate
// hardware clock.

int attemp = 0;
int bps = 9600;

class Monitoring {
    public:
        bool isActive() {
            return bool digitalRead(boardStatusIndicator) == HIGH;
        }
}

class ManagerBoard {
    void readConfig() {};
    void startSetup() {
        Serial.begin(bps);
        Serial1.begin(bps);
        Serial2.begin(bps);
    };
}

class Power {
    void sigtermf() {
        digitalWrite(signalizator, HIGH);
        delay(2500);
        digitalWrite(signalizator, LOW);

        for(int i = 0; i < 301; i++) {
            if(Monitoring::isActive() == false) {
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

        return Monitoring::isActive();
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
}

void setup() {
    ManagerBoard::startSetup();
}

void loop() {
    if(Monitoring::isActive() == (exceptedBoardStatus == HIGH)) {}
}